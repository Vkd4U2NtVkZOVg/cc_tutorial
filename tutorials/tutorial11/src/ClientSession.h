#pragma once

#include <iterator>
#include <vector>

#include "tutorial11/Message.h"
#include "tutorial11/frame/Frame.h"
#include "tutorial11/input/ClientInputMessages.h"
#include "tutorial11/options/ClientDefaultOptions.h"

#include "Session.h"
#include "ProtocolOptions.h"

namespace cc_tutorial
{

class ClientSession : public Session
{
    using Base = Session;
public:
    using Base::Base; // Inherit constructors

    // Common interface class for all the messages
    using Message = tutorial11::Message<>;

    // Protocol options for client
    using ClientProtocolOptions = 
        ProtocolOptionsT<
            tutorial11::options::ClientDefaultOptions
        >;        
        
    // Definition of all the used message classes
    using Msg1 = tutorial11::message::Msg1<Message, ClientProtocolOptions>;
    using Msg2 = tutorial11::message::Msg2<Message, ClientProtocolOptions>;
    using Msg3 = tutorial11::message::Msg3<Message, ClientProtocolOptions>;

    // Handling functions for all the dispatched message objects
    template <typename TMsg>
    void handle(TMsg& msg)
    {
        std::cout << "Received \"" << msg.doName() << "\" with ID=" << (unsigned)msg.doGetId() << '\n';
        doNextStage();
    }

    void handle(Message& msg);

protected:
    virtual bool startImpl() override final;
    virtual std::size_t processInputImpl(const std::uint8_t* buf, std::size_t bufLen) override final;

private:
    enum CommsStage
    {
        CommsStage_Msg1,
        CommsStage_Msg2,
        CommsStage_Msg3,
        CommsStage_NumOfValues
    };

    // Send the message requires knowledge about the full message type
    template <typename TMsg>
    void sendMessage(const TMsg& msg)
    {
        // The statement below uses polymorphic message name and ID retrievals.
        std::vector<std::uint8_t> output;

        // Use polymorphic serialization length calculation to reserve
        // needed capacity
        output.reserve(m_frame.length(msg));

        // Serialize message into the buffer (including framing)
        // The serialization uses polymorphic write functionality.
        auto writeIter = std::back_inserter(output);

        // The frame will use polymorphic message ID retrieval to
        // prefix message payload with message ID
        auto es = m_frame.write(msg, writeIter, output.max_size());
        if (es != comms::ErrorStatus::Success) {
            assert(!"Write operation failed unexpectedly");
            return;
        }

        // Send serialized message back
        sendOutput(&output[0], output.size());

        std::cout << "Sending message \"" << msg.doName() << "\" with ID=" << (unsigned)msg.doGetId() << ": " << std::hex;
        std::copy(output.begin(), output.end(), std::ostream_iterator<unsigned>(std::cout, " "));
        std::cout << std::dec << std::endl;
    }

    void doNextStage();
    void sendMsg1();
    void sendMsg2();
    void sendMsg3();

    // Client specific frame 
    using Frame = 
        tutorial11::frame::Frame<
            Message,
            tutorial11::input::ClientInputMessages<Message, ClientProtocolOptions>,
            ClientProtocolOptions
        >;

    Frame m_frame;
    CommsStage m_currentStage = CommsStage_NumOfValues;
};

} // namespace cc_tutorial
