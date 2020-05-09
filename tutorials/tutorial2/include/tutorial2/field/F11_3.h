// Generated by commsdsl2comms v3.4.0

/// @file
/// @brief Contains definition of <b>"F11_3"</b> field.

#pragma once

#include <tuple>
#include "comms/field/Bitfield.h"
#include "comms/options.h"
#include "tutorial2/field/F11_1.h"
#include "tutorial2/field/F11_2.h"
#include "tutorial2/field/F11_3Common.h"
#include "tutorial2/field/FieldBase.h"
#include "tutorial2/options/DefaultOptions.h"

namespace tutorial2
{

namespace field
{

/// @brief Scope for all the member fields of
///     @ref F11_3 bitfield.
/// @tparam TOpt Protocol options.
template <typename TOpt = tutorial2::options::DefaultOptions>
struct F11_3Members
{
    /// @brief Definition of <b>"Field 11_1"</b> field.
    using M1 =
        tutorial2::field::F11_1<
            TOpt,
            comms::option::def::FixedBitLength<5U>
        >;
    
    /// @brief Definition of <b>"M2"</b> field.
    struct M2 : public
        tutorial2::field::F11_2<
            TOpt,
            comms::option::def::FixedBitLength<3U>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return tutorial2::field::F11_3MembersCommon::M2Common::name();
        }
        
    };
    
    /// @brief All members bundled in @b std::tuple.
    using All =
        std::tuple<
           M1,
           M2
        >;
};

/// @brief Definition of <b>"F11_3"</b> field.
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = tutorial2::options::DefaultOptions, typename... TExtraOpts>
class F11_3 : public
    comms::field::Bitfield<
        tutorial2::field::FieldBase<>,
        typename F11_3Members<TOpt>::All,
        TExtraOpts...
    >
{
    using Base = 
        comms::field::Bitfield<
            tutorial2::field::FieldBase<>,
            typename F11_3Members<TOpt>::All,
            TExtraOpts...
        >;
public:
    /// @brief Allow access to internal fields.
    /// @details See definition of @b COMMS_FIELD_MEMBERS_NAMES macro
    ///     related to @b comms::field::Bitfield class from COMMS library
    ///     for details.
    ///
    ///     The generated types and access functions are:
    ///     @li @b Field_m1 type and @b field_m1() access function -
    ///         for F11_3Members::M1 member field.
    ///     @li @b Field_m2 type and @b field_m2() access function -
    ///         for F11_3Members::M2 member field.
    COMMS_FIELD_MEMBERS_NAMES(
        m1,
        m2
    );
    
    /// @brief Name of the field.
    static const char* name()
    {
        return tutorial2::field::F11_3Common::name();
    }
    
};

} // namespace field

} // namespace tutorial2

