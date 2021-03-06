//
// This file is auto-generated, please do not modify directly!
//

#pragma once

/// \file vec4f.h
/// \ingroup gm_types_vector

#include <gm/gm.h>

#include <cmath>
#include <cstring>
#include <sstream>

#include <gm/base/almost.h>
#include <gm/base/diagnostic.h>

GM_NS_OPEN

/// \class Vec4f
/// \ingroup gm_types_vector
///
/// Class definition of a vector with 4 float elements.
class Vec4f final
{
public:
    /// \typedef ElementType
    ///
    /// Convenience type definition of \ref Vec4f's elements.
    using ElementType = float;

    // --------------------------------------------------------------------- //
    /// \name Construction
    // --------------------------------------------------------------------- //

    /// Default constructor, initializing all of the element values to 0.
    GM_HOST_DEVICE constexpr inline Vec4f() = default;

    /// Element-wise constructor.
    GM_HOST_DEVICE explicit constexpr inline Vec4f( const float& i_element0,
                                                    const float& i_element1,
                                                    const float& i_element2,
                                                    const float& i_element3 )
        : m_elements{i_element0, i_element1, i_element2, i_element3}
    {
        GM_ASSERT( !HasNaNs() );
    }

    // --------------------------------------------------------------------- //
    /// \name Indexed element access
    // --------------------------------------------------------------------- //

    /// Indexed element write access.
    ///
    /// \param i_index index of the element.
    ///
    /// \pre \p i_index must be less than 4.
    ///
    /// \return mutable element value.
    GM_HOST_DEVICE inline float& operator[]( size_t i_index )
    {
        GM_ASSERT( !HasNaNs() );
        GM_ASSERT( i_index < 4 );
        return m_elements[ i_index ];
    }

    /// Indexed element read access.
    ///
    /// \param i_index index of the element.
    ///
    /// \pre \p i_index must be less than 4.
    ///
    /// \return immutable element value.
    GM_HOST_DEVICE inline const float& operator[]( size_t i_index ) const
    {
        GM_ASSERT( !HasNaNs() );
        GM_ASSERT( i_index < 4 );
        return m_elements[ i_index ];
    }

    // --------------------------------------------------------------------- //
    /// \name Named element access.
    // --------------------------------------------------------------------- //

    /// Convenience named const accessor for the element at index 0.
    ///
    /// \return Const reference to the element at index 0.
    GM_HOST_DEVICE inline const float& X() const
    {
        GM_ASSERT( !HasNaNs() );
        return m_elements[ 0 ];
    }

    /// Convenience named mutable accessor for the element at index
    ///
    /// \return Mutable reference to the element at index 0.
    GM_HOST_DEVICE inline float& X()
    {
        GM_ASSERT( !HasNaNs() );
        return m_elements[ 0 ];
    }
    /// Convenience named const accessor for the element at index 1.
    ///
    /// \return Const reference to the element at index 1.
    GM_HOST_DEVICE inline const float& Y() const
    {
        GM_ASSERT( !HasNaNs() );
        return m_elements[ 1 ];
    }

    /// Convenience named mutable accessor for the element at index
    ///
    /// \return Mutable reference to the element at index 1.
    GM_HOST_DEVICE inline float& Y()
    {
        GM_ASSERT( !HasNaNs() );
        return m_elements[ 1 ];
    }
    /// Convenience named const accessor for the element at index 2.
    ///
    /// \return Const reference to the element at index 2.
    GM_HOST_DEVICE inline const float& Z() const
    {
        GM_ASSERT( !HasNaNs() );
        return m_elements[ 2 ];
    }

    /// Convenience named mutable accessor for the element at index
    ///
    /// \return Mutable reference to the element at index 2.
    GM_HOST_DEVICE inline float& Z()
    {
        GM_ASSERT( !HasNaNs() );
        return m_elements[ 2 ];
    }
    /// Convenience named const accessor for the element at index 3.
    ///
    /// \return Const reference to the element at index 3.
    GM_HOST_DEVICE inline const float& W() const
    {
        GM_ASSERT( !HasNaNs() );
        return m_elements[ 3 ];
    }

    /// Convenience named mutable accessor for the element at index
    ///
    /// \return Mutable reference to the element at index 3.
    GM_HOST_DEVICE inline float& W()
    {
        GM_ASSERT( !HasNaNs() );
        return m_elements[ 3 ];
    }

    // --------------------------------------------------------------------- //
    /// \name Arithmetic operators
    // --------------------------------------------------------------------- //

    /// Element-wise vector addition.
    ///
    /// Corresponding elements of the current vector and \p i_vector are added to form a new vector.
    ///
    /// \return the new vector.
    GM_HOST_DEVICE inline Vec4f operator+( const Vec4f& i_vector ) const
    {
        GM_ASSERT( !HasNaNs() );
        return Vec4f( m_elements[ 0 ] + i_vector.m_elements[ 0 ],
                      m_elements[ 1 ] + i_vector.m_elements[ 1 ],
                      m_elements[ 2 ] + i_vector.m_elements[ 2 ],
                      m_elements[ 3 ] + i_vector.m_elements[ 3 ] );
    }

    /// Element-wise vector addition assignment.
    GM_HOST_DEVICE inline Vec4f& operator+=( const Vec4f& i_vector )
    {
        GM_ASSERT( !HasNaNs() );
        m_elements[ 0 ] += i_vector.m_elements[ 0 ];
        m_elements[ 1 ] += i_vector.m_elements[ 1 ];
        m_elements[ 2 ] += i_vector.m_elements[ 2 ];
        m_elements[ 3 ] += i_vector.m_elements[ 3 ];
        return *this;
    }

    /// Vector subtraction.
    GM_HOST_DEVICE inline Vec4f operator-( const Vec4f& i_vector ) const
    {
        GM_ASSERT( !HasNaNs() );
        return Vec4f( m_elements[ 0 ] - i_vector.m_elements[ 0 ],
                      m_elements[ 1 ] - i_vector.m_elements[ 1 ],
                      m_elements[ 2 ] - i_vector.m_elements[ 2 ],
                      m_elements[ 3 ] - i_vector.m_elements[ 3 ] );
    }

    /// Vector subtraction assignment.
    GM_HOST_DEVICE inline Vec4f& operator-=( const Vec4f& i_vector )
    {
        GM_ASSERT( !HasNaNs() );
        m_elements[ 0 ] -= i_vector.m_elements[ 0 ];
        m_elements[ 1 ] -= i_vector.m_elements[ 1 ];
        m_elements[ 2 ] -= i_vector.m_elements[ 2 ];
        m_elements[ 3 ] -= i_vector.m_elements[ 3 ];
        return *this;
    }

    /// Scalar multiplication assignment.
    GM_HOST_DEVICE inline Vec4f& operator*=( const float& i_scalar )
    {
        GM_ASSERT( !HasNaNs() );
        m_elements[ 0 ] *= i_scalar;
        m_elements[ 1 ] *= i_scalar;
        m_elements[ 2 ] *= i_scalar;
        m_elements[ 3 ] *= i_scalar;
        return *this;
    }

    /// Scalar division.
    GM_HOST_DEVICE inline Vec4f operator/( const float& i_scalar ) const
    {
        GM_ASSERT( !HasNaNs() );
        GM_ASSERT( i_scalar != 0.0f );
        float reciprocal = 1.0f / i_scalar;
        return Vec4f( m_elements[ 0 ] * reciprocal,
                      m_elements[ 1 ] * reciprocal,
                      m_elements[ 2 ] * reciprocal,
                      m_elements[ 3 ] * reciprocal );
    }

    /// Scalar division assignment.
    GM_HOST_DEVICE inline Vec4f& operator/=( const float& i_scalar )
    {
        GM_ASSERT( !HasNaNs() );
        GM_ASSERT( i_scalar != 0.0f );
        float reciprocal = 1.0f / i_scalar;
        m_elements[ 0 ] *= reciprocal;
        m_elements[ 1 ] *= reciprocal;
        m_elements[ 2 ] *= reciprocal;
        m_elements[ 3 ] *= reciprocal;
        return *this;
    }

    /// Unary negation.
    GM_HOST_DEVICE inline Vec4f operator-() const
    {
        GM_ASSERT( !HasNaNs() );
        return Vec4f( -m_elements[ 0 ], -m_elements[ 1 ], -m_elements[ 2 ], -m_elements[ 3 ] );
    }

    // --------------------------------------------------------------------- //
    /// \name Comparison operators
    // --------------------------------------------------------------------- //

    /// Comparison operator
    GM_HOST_DEVICE inline bool operator==( const Vec4f& i_vector ) const
    {
        return AlmostEqual( m_elements[ 0 ], i_vector.m_elements[ 0 ] ) &&
               AlmostEqual( m_elements[ 1 ], i_vector.m_elements[ 1 ] ) &&
               AlmostEqual( m_elements[ 2 ], i_vector.m_elements[ 2 ] ) &&
               AlmostEqual( m_elements[ 3 ], i_vector.m_elements[ 3 ] );
    }

    /// Not equal operator
    GM_HOST_DEVICE inline bool operator!=( const Vec4f& i_vector ) const
    {
        return !( ( *this ) == i_vector );
    }

    // --------------------------------------------------------------------- //
    /// \name Shape
    // --------------------------------------------------------------------- //

    /// Get the number of elements in this vector.
    GM_HOST_DEVICE inline static size_t GetElementSize()
    {
        return 4;
    }

    // --------------------------------------------------------------------- //
    /// \name Debug
    // --------------------------------------------------------------------- //

    /// Are any of the element values NaNs?
    GM_HOST_DEVICE inline bool HasNaNs() const
    {
        return std::isnan( m_elements[ 0 ] ) || std::isnan( m_elements[ 1 ] ) || std::isnan( m_elements[ 2 ] ) ||
               std::isnan( m_elements[ 3 ] );
    }

    /// Get the string representation.  For debugging purposes.
    ///
    /// \param i_classPrefix optional string to prefix class tokens.
    ///
    /// \return descriptive string representing this type instance.
    inline std::string GetString( const std::string& i_classPrefix = std::string() ) const
    {
        std::stringstream ss;
        ss << i_classPrefix << "Vec4f( ";
        ss << m_elements[ 0 ];
        ss << ", ";
        ss << m_elements[ 1 ];
        ss << ", ";
        ss << m_elements[ 2 ];
        ss << ", ";
        ss << m_elements[ 3 ];
        ss << " )";
        return ss.str();
    }

private:
    float m_elements[ 4 ] = {0.0f, 0.0f, 0.0f, 0.0f};
};

/// Vector-scalar multiplication.
GM_HOST_DEVICE inline Vec4f operator*( const Vec4f& i_vector, const float& i_scalar )
{
    GM_ASSERT( !i_vector.HasNaNs() );
    return Vec4f( i_vector[ 0 ] * i_scalar,
                  i_vector[ 1 ] * i_scalar,
                  i_vector[ 2 ] * i_scalar,
                  i_vector[ 3 ] * i_scalar );
}

/// Scalar-vector multiplication.
GM_HOST_DEVICE inline Vec4f operator*( const float& i_scalar, const Vec4f& i_vector )
{
    GM_ASSERT( !i_vector.HasNaNs() );
    return Vec4f( i_vector[ 0 ] * i_scalar,
                  i_vector[ 1 ] * i_scalar,
                  i_vector[ 2 ] * i_scalar,
                  i_vector[ 3 ] * i_scalar );
}

/// Operator overload for << to enable writing the string representation of \p i_vector into an output
/// stream \p o_outputStream.
///
/// \param o_outputStream the output stream to write into.
/// \param i_vector the source vector value type.
///
/// \return the output stream.
inline std::ostream& operator<<( std::ostream& o_outputStream, const Vec4f& i_vector )
{
    o_outputStream << i_vector.GetString();
    return o_outputStream;
}

GM_NS_CLOSE