#pragma once

/// \file memory/index.h
///
/// Memory index operator.

#include <toy/memory/residency.h>
#include <toy/utils/diagnostic.h>
#include <toy/utils/falseType.h>

#include <cuda_runtime.h>

TOY_NS_OPEN

/// \struct Index
///
/// Template prototype for a buffer index operation.
template < Residency ResidencyT >
struct Index
{
};

template <>
struct Index< Host >
{
    template < typename ValueT >
    static inline ValueT& Execute( ValueT* i_buffer, size_t i_index )
    {
        return i_buffer[ i_index ];
    }
};

template <>
struct Index< Cuda >
{
    template < typename ValueT >
    static inline ValueT& Execute( ValueT* i_buffer, size_t i_index )
    {
        static_assert( FalseType< ValueT >::value, "Cannot index into cuda buffer from host code." );
        return ValueT();
    }
};

TOY_NS_CLOSE