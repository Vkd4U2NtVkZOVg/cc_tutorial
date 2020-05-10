// Generated by commsdsl2comms v3.4.0

/// @file
/// @brief Contains definition of <b>"Message"</b> interface class.

#pragma once

#include "comms/Message.h"
#include "comms/options.h"
#include "tutorial3/MsgId.h"

namespace tutorial3
{

/// @brief Definition of <b>"Message"</b> common interface class.
/// @tparam TOpt Interface definition options
/// @headerfile "tutorial3/Message.h"
template <typename... TOpt>
using Message =
    comms::Message<
        TOpt...,
        comms::option::def::BigEndian,
        comms::option::def::MsgIdType<tutorial3::MsgId>
    >;

} // namespace tutorial3

