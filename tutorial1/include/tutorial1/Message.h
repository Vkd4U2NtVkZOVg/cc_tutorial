/// @file
/// @brief Contains definition of <b>"Message"</b> interface class.

#pragma once

#include "comms/Message.h"
#include "comms/options.h"
#include "tutorial1/MsgId.h"

namespace tutorial1
{

/// @brief Definition of <b>"Message"</b> common interface class.
/// @tparam TOpt Interface definition options
/// @headerfile "tutorial1/Message.h"
template <typename... TOpt>
using Message =
    comms::Message<
        TOpt...,
        comms::option::def::BigEndian,
        comms::option::def::MsgIdType<tutorial1::MsgId>
    >;

} // namespace tutorial1


