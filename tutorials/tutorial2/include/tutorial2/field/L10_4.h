// Generated by commsdsl2comms v3.4.0

/// @file
/// @brief Contains definition of <b>"L10_4"</b> field.

#pragma once

#include <algorithm>
#include <cstdint>
#include <iterator>
#include <tuple>
#include <utility>
#include "comms/field/ArrayList.h"
#include "comms/field/Bundle.h"
#include "comms/field/EnumValue.h"
#include "comms/field/IntValue.h"
#include "comms/field/String.h"
#include "comms/options.h"
#include "tutorial2/field/FieldBase.h"
#include "tutorial2/field/L10_4Common.h"
#include "tutorial2/options/DefaultOptions.h"

namespace tutorial2
{

namespace field
{

/// @brief Scope for all the member fields of
///     @ref L10_4 list.
/// @tparam TOpt Protocol options.
template <typename TOpt = tutorial2::options::DefaultOptions>
struct L10_4Members
{
    /// @brief Scope for all the member fields of
    ///     @ref Element bundle.
    struct ElementMembers
    {
        /// @brief Definition of <b>"M1"</b> field.
        struct M1 : public
            comms::field::IntValue<
                tutorial2::field::FieldBase<>,
                std::uint8_t
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return tutorial2::field::L10_4MembersCommon::ElementMembersCommon::M1Common::name();
            }
            
        };
        
        /// @brief Definition of <b>"M2"</b> field.
        /// @see @ref tutorial2::field::L10_4MembersCommon::ElementMembersCommon::M2Val
        class M2 : public
            comms::field::EnumValue<
                tutorial2::field::FieldBase<>,
                tutorial2::field::L10_4MembersCommon::ElementMembersCommon::M2Val,
                comms::option::def::ValidNumValue<5>,
                comms::option::def::ValidNumValue<15>
            >
        {
            using Base = 
                comms::field::EnumValue<
                    tutorial2::field::FieldBase<>,
                    tutorial2::field::L10_4MembersCommon::ElementMembersCommon::M2Val,
                    comms::option::def::ValidNumValue<5>,
                    comms::option::def::ValidNumValue<15>
                >;
        public:
            /// @brief Re-definition of the value type.
            using ValueType = typename Base::ValueType;
        
            /// @brief Name of the field.
            static const char* name()
            {
                return tutorial2::field::L10_4MembersCommon::ElementMembersCommon::M2Common::name();
            }
            
            /// @brief Retrieve name of the enum value
            static const char* valueName(ValueType val)
            {
                return tutorial2::field::L10_4MembersCommon::ElementMembersCommon::M2Common::valueName(val);
            }
            
            /// @brief Retrieve name of the @b current value
            const char* valueName() const
            {
                return valueName(Base::value());
            }
            
        };
        
        /// @brief Definition of <b>"M3"</b> field.
        struct M3 : public
            comms::field::String<
                tutorial2::field::FieldBase<>,
                typename TOpt::field::L10_4Members::ElementMembers::M3
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return tutorial2::field::L10_4MembersCommon::ElementMembersCommon::M3Common::name();
            }
            
        };
        
        /// @brief All members bundled in @b std::tuple.
        using All =
            std::tuple<
               M1,
               M2,
               M3
            >;
    };
    
    /// @brief Definition of <b>"Element"</b> field.
    class Element : public
        comms::field::Bundle<
            tutorial2::field::FieldBase<>,
            typename ElementMembers::All
        >
    {
        using Base = 
            comms::field::Bundle<
                tutorial2::field::FieldBase<>,
                typename ElementMembers::All
            >;
    public:
        /// @brief Allow access to internal fields.
        /// @details See definition of @b COMMS_FIELD_MEMBERS_NAMES macro
        ///     related to @b comms::field::Bundle class from COMMS library
        ///     for details.
        ///
        ///     The generated access types and functions functions are:
        ///     @li @b Field_m1type and @b field_m1() access function -
        ///         for ElementMembers::M1 member field.
        ///     @li @b Field_m2type and @b field_m2() access function -
        ///         for ElementMembers::M2 member field.
        ///     @li @b Field_m3type and @b field_m3() access function -
        ///         for ElementMembers::M3 member field.
        COMMS_FIELD_MEMBERS_NAMES(
            m1,
            m2,
            m3
        );
        
        /// @brief Name of the field.
        static const char* name()
        {
            return tutorial2::field::L10_4MembersCommon::ElementCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"Size"</b> field.
    struct Size : public
        comms::field::IntValue<
            tutorial2::field::FieldBase<>,
            std::uint16_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return tutorial2::field::L10_4MembersCommon::SizeCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"Length"</b> field.
    struct Length : public
        comms::field::IntValue<
            tutorial2::field::FieldBase<>,
            std::uint8_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return tutorial2::field::L10_4MembersCommon::LengthCommon::name();
        }
        
    };
    
};

/// @brief Definition of <b>"L10_4"</b> field.
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = tutorial2::options::DefaultOptions, typename... TExtraOpts>
struct L10_4 : public
    comms::field::ArrayList<
        tutorial2::field::FieldBase<>,
        typename L10_4Members<TOpt>::Element,
        TExtraOpts...,
        typename TOpt::field::L10_4,
        comms::option::def::SequenceSizeFieldPrefix<typename L10_4Members<TOpt>::Size>,
        comms::option::def::SequenceElemSerLengthFieldPrefix<typename L10_4Members<TOpt>::Length>
    >
{
    /// @brief Name of the field.
    static const char* name()
    {
        return tutorial2::field::L10_4Common::name();
    }
    
};

} // namespace field

} // namespace tutorial2

