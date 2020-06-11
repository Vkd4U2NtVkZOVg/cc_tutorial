// Generated by commsdsl2comms v3.4.1

/// @file
/// @brief Contains dispatch to handling function(s) for client input messages.

#pragma once

#include <type_traits>
#include "tutorial9/MsgId.h"
#include "tutorial9/input/ClientInputMessages.h"

namespace tutorial9
{

namespace dispatch
{

/// @brief Dispatch message object to its appropriate handling function.
/// @details @b switch statement based (on message ID) cast and dispatch functionality.
/// @tparam TProtOptions Protocol options struct used for the application,
///     like @ref tutorial9::options::DefaultOptions.
/// @param[in] id Numeric message ID.
/// @param[in] msg Message object held by reference to its interface class.
/// @param[in] handler Reference to handling object. Must define
///     @b handle() member function for every message type it exects
///     to handle and one for the interface class as well.
///     @code
///     using MyInterface = tutorial9::Message<...>;
///     using MyMsg2 = tutorial9::message::Msg2<MyInterface, tutorial9::options::DefaultOptions>;
///     using MyMsg4 = tutorial9::message::Msg4<MyInterface, tutorial9::options::DefaultOptions>;
///     struct MyHandler {
///         void handle(MyMsg2& msg) {...}
///         void handle(MyMsg4& msg) {...}
///         ...
///         // Handle all unexpected or irrelevant messages.
///         void handle(MyInterface& msg) {...}
///     };
///     @endcode
///     Every @b handle() function may return a value, but every
///     function must return the @b same type.
/// @note Defined in tutorial9/dispatch/DispatchClientInputMessage.h
template<typename TProtOptions, typename TMsg, typename THandler>
auto dispatchClientInputMessage(
    tutorial9::MsgId id,
    TMsg& msg,
    THandler& handler) -> decltype(handler.handle(msg))
{
    using InterfaceType = typename std::decay<decltype(msg)>::type;
    switch(id) {
    case tutorial9::MsgId_M2:
    {
        using MsgType = tutorial9::message::Msg2<InterfaceType, TProtOptions>;
        return handler.handle(static_cast<MsgType&>(msg));
    }
    case tutorial9::MsgId_M4:
    {
        using MsgType = tutorial9::message::Msg4<InterfaceType, TProtOptions>;
        return handler.handle(static_cast<MsgType&>(msg));
    }
    default:
        break;
    };

    return handler.handle(msg);
}

/// @brief Dispatch message object to its appropriate handling function.
/// @details Same as other dispatchClientInputMessage(), but receives extra @b idx parameter.
/// @tparam TProtOptions Protocol options struct used for the application,
///     like @ref tutorial9::options::DefaultOptions.
/// @param[in] id Numeric message ID.
/// @param[in] idx Index of the message among messages with the same ID.
///     Expected to be @b 0.
/// @param[in] msg Message object held by reference to its interface class.
/// @param[in] handler Reference to handling object.
/// @see dispatchClientInputMessage()
/// @note Defined in tutorial9/dispatch/DispatchClientInputMessage.h
template<typename TProtOptions, typename TMsg, typename THandler>
auto dispatchClientInputMessage(
    tutorial9::MsgId id,
    std::size_t idx,
    TMsg& msg,
    THandler& handler) -> decltype(handler.handle(msg))
{
    if (idx != 0U) {
        return handler.handle(msg);
    }
    return dispatchClientInputMessage<TProtOptions>(id, msg, handler);
}

/// @brief Dispatch message object to its appropriate handling function.
/// @details Same as other dispatchClientInputMessage(), but passing
///     tutorial9::options::DefaultOptions as first template parameter.
/// @param[in] id Numeric message ID.
/// @param[in] msg Message object held by reference to its interface class.
/// @param[in] handler Reference to handling object.
/// @see dispatchClientInputMessage()
/// @note Defined in tutorial9/dispatch/DispatchClientInputMessage.h
template<typename TMsg, typename THandler>
auto dispatchClientInputMessageDefaultOptions(
    tutorial9::MsgId id,
    TMsg& msg,
    THandler& handler) -> decltype(handler.handle(msg))
{
    return dispatchClientInputMessage<tutorial9::options::DefaultOptions>(id, msg, handler);
}

/// @brief Dispatch message object to its appropriate handling function.
/// @details Same as other dispatchClientInputMessageDefaultOptions(), 
///     but receives extra @b idx parameter.
/// @param[in] id Numeric message ID.
/// @param[in] idx Index of the message among messages with the same ID.
/// @param[in] msg Message object held by reference to its interface class.
/// @param[in] handler Reference to handling object.
/// @see dispatchClientInputMessageDefaultOptions()
/// @note Defined in tutorial9/dispatch/DispatchClientInputMessage.h
template<typename TMsg, typename THandler>
auto dispatchClientInputMessageDefaultOptions(
    tutorial9::MsgId id,
    std::size_t idx,
    TMsg& msg,
    THandler& handler) -> decltype(handler.handle(msg))
{
    return dispatchClientInputMessage<tutorial9::options::DefaultOptions>(id, idx, msg, handler);
}

/// @brief Message dispatcher class to be used with
///     @b comms::processAllWithDispatchViaDispatcher() function (or similar).
/// @tparam TProtOptions Protocol options struct used for the application,
///     like @ref tutorial9::options::DefaultOptions.
/// @headerfile "tutorial9/dispatch/DispatchClientInputMessage.h"
template <typename TProtOptions>
struct ClientInputMsgDispatcher
{
    /// @brief Class detection tag
    using MsgDispatcherTag = void;

    /// @brief Dispatch message to its handler.
    /// @details Uses appropriate @ref dispatchClientInputMessage() function.
    /// @param[in] id ID of the message.
    /// @param[in] idx Index (or offset) of the message among those having the same numeric ID.
    /// @param[in] msg Reference to message object.
    /// @param[in] handler Reference to handler object.
    /// @return What the @ref dispatchClientInputMessage() function returns.
    template <typename TMsg, typename THandler>
    static auto dispatch(tutorial9::MsgId id, std::size_t idx, TMsg& msg, THandler& handler) ->
        decltype(tutorial9::dispatch::dispatchClientInputMessage<TProtOptions>(id, idx, msg, handler))
    {
        return tutorial9::dispatch::dispatchClientInputMessage<TProtOptions>(id, idx, msg, handler);
    }

    /// @brief Complementary dispatch function.
    /// @details Same as other dispatch without @b TAllMessages template parameter,
    ///     used by  @b comms::processAllWithDispatchViaDispatcher().
    template <typename TAllMessages, typename TMsg, typename THandler>
    static auto dispatch(tutorial9::MsgId id, std::size_t idx, TMsg& msg, THandler& handler) ->
        decltype(dispatch(id, idx, msg, handler))
    {
        return dispatch(id, idx, msg, handler);
    }

    /// @brief Dispatch message to its handler.
    /// @details Uses appropriate @ref dispatchClientInputMessage() function.
    /// @param[in] id ID of the message.
    /// @param[in] msg Reference to message object.
    /// @param[in] handler Reference to handler object.
    /// @return What the @ref dispatchClientInputMessage() function returns.
    template <typename TMsg, typename THandler>
    static auto dispatch(tutorial9::MsgId id, TMsg& msg, THandler& handler) ->
        decltype(tutorial9::dispatch::dispatchClientInputMessage<TProtOptions>(id, msg, handler))
    {
        return tutorial9::dispatch::dispatchClientInputMessage<TProtOptions>(id, msg, handler);
    }

    /// @brief Complementary dispatch function.
    /// @details Same as other dispatch without @b TAllMessages template parameter,
    ///     used by  @b comms::processAllWithDispatchViaDispatcher().
    template <typename TAllMessages, typename TMsg, typename THandler>
    static auto dispatch(tutorial9::MsgId id, TMsg& msg, THandler& handler) ->
        decltype(dispatch(id, msg, handler))
    {
        return dispatch(id, msg, handler);
    }
};

/// @brief Message dispatcher class to be used with
///     @b comms::processAllWithDispatchViaDispatcher() function (or similar).
/// @details Same as @ref ClientInputMsgDispatcher, but passing
///     @ref tutorial9::options::DefaultOptions as template parameter.
/// @note Defined in "tutorial9/dispatch/DispatchClientInputMessage.h"
using ClientInputMsgDispatcherDefaultOptions =
    ClientInputMsgDispatcher<tutorial9::options::DefaultOptions>;

} // namespace dispatch

} // namespace tutorial9


