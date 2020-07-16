// Generated by commsdsl2comms v3.4.2

/// @file
/// @brief Contains common template parameters independent functionality of
///    fields used in definition of @ref tutorial18::frame::Frame frame.

#pragma once

#include <cstdint>

namespace tutorial18
{

namespace frame
{

/// @brief Common types and functions of fields using in definition of
///     @ref tutorial18::frame::Frame frame.
/// @see tutorial18::frame::FrameLayers
struct FrameLayersCommon
{
    /// @brief Scope for all the common definitions of the fields defined in
    ///     @ref tutorial18::frame::FrameLayers::SyncMembers struct.
    struct SyncMembersCommon
    {
        /// @brief Common types and functions for
        ///     @ref tutorial18::frame::FrameLayers::SyncMembers::Field field.
        struct FieldCommon
        {
            /// @brief Re-definition of the value type used by
            ///     tutorial18::frame::FrameLayers::SyncMembers::Field field.
            using ValueType = std::uint16_t;
        
            /// @brief Name of the @ref tutorial18::frame::FrameLayers::SyncMembers::Field field.
            static const char* name()
            {
                return "Sync";
            }
            
        };
        
    };
    
    /// @brief Scope for all the common definitions of the fields defined in
    ///     @ref tutorial18::frame::FrameLayers::ChecksumMembers struct.
    struct ChecksumMembersCommon
    {
        /// @brief Common types and functions for
        ///     @ref tutorial18::frame::FrameLayers::ChecksumMembers::Field field.
        struct FieldCommon
        {
            /// @brief Re-definition of the value type used by
            ///     tutorial18::frame::FrameLayers::ChecksumMembers::Field field.
            using ValueType = std::uint16_t;
        
            /// @brief Name of the @ref tutorial18::frame::FrameLayers::ChecksumMembers::Field field.
            static const char* name()
            {
                return "Checksum";
            }
            
        };
        
    };
    
    /// @brief Scope for all the common definitions of the fields defined in
    ///     @ref tutorial18::frame::FrameLayers::SizeMembers struct.
    struct SizeMembersCommon
    {
        /// @brief Common types and functions for
        ///     @ref tutorial18::frame::FrameLayers::SizeMembers::Field field.
        struct FieldCommon
        {
            /// @brief Re-definition of the value type used by
            ///     tutorial18::frame::FrameLayers::SizeMembers::Field field.
            using ValueType = std::uint16_t;
        
            /// @brief Name of the @ref tutorial18::frame::FrameLayers::SizeMembers::Field field.
            static const char* name()
            {
                return "Size";
            }
            
        };
        
    };
    
};
} // namespace frame

} // namespace tutorial18

