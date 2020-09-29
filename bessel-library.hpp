#ifndef BESSEL_LIBRARY_HPP
#define BESSEL_LIBRARY_HPP

#define C_1_SQRTPI 0.5641895835477562869480794515607725L

#include <complex>
#include <cmath>

namespace bessel
{

template<typename T>
std::complex<T> __cyl_j0_ascending_series( const std::complex<T> _z )
{
    // Ascending Series from G. N. Watson 'A treatise on the
    //  theory of Bessel functions', 2ed, Cambridge, 1996,
    //  Chapter II, equation (3); or from Equation 9.1.12 of
    //  M. Abramowitz, I. A. Stegun 'Handbook of Mathematical
    //  Functions'; and using Kahan summation algorithm.
    const T epsilon = std::numeric_limits<T>::epsilon();
    std::complex<T> J0 = T(1);
    std::complex<T> sm = T(1);
    std::complex<T> err = T(0);
    for ( int m = 1; std::abs(sm/J0) >= epsilon; m++ )
    {
        sm *= - _z*_z / ( T(4)*T(m)*T(m) );
        std::complex<T> y = sm - err;
        std::complex<T> t = J0 + y;
        err = ( t - J0 ) - y ;
        J0 = t;
    }
    return J0;
}

template<typename T>
std::complex<T> __cyl_j0_semiconvergent_series( 
                            const std::complex<T> _z, const int m_max )
{
    // Stokes Semiconvergent Series from A. Gray, G. B. Mathews 'A
    //  treatise on Bessel functions and their applications to
    //  physics, 1895.
    std::complex<T> Pm = T(1);
    std::complex<T> Qm = T(0.125)/_z;
    std::complex<T> P = Pm;
    std::complex<T> Q = Qm;

    for ( int m=1; m<=m_max; m++ )
    {
        T pim = T(4*m-3)*T(4*m-3)*T(4*m-1)*T(4*m-1) / ( T(2*m-1)*T(128*m) );
        Pm = -Pm*pim/(_z*_z);

        T xim = T(4*m-1)*T(4*m-1)*T(4*m+1)*T(4*m+1) / ( T(2*m+1)*T(128*m) );
        Qm = -Qm*xim/(_z*_z);

        P += Pm;
        Q += Qm;
    }

    return T(C_1_SQRTPI) * ( cos(_z)*(P-Q) + sin(_z)*(P+Q) ) / sqrt( _z );
    
}

template<typename T>
T cyl_j0( T _z )
{
    // Implementation from C++17
    return std::cyl_bessel_j(0, _z);
}

template<typename T>
std::complex<T> cyl_j0( std::complex<T> _z )
{

    if ( std::real(_z) < T(0) )
    {
        _z = -_z; // Since J0(-z) = J0(z)
    }
    
    // Note: for 5 <= x <= 20, the routine does not reach
    //  sufficient digits of accuracy for long double type,
    //  although it does reach sufficient digits for
    //  float (6 digits) and double (15 digits).

    if ( std::abs(_z) == T(0) )
    {
        return std::complex<T> (T(1), T(0));
    }
    else if ( std::real(_z) <= T(12) )
    {
        return __cyl_j0_ascending_series( _z );
    }
    else if ( std::real(_z) <= T(50) )
    {
        return __cyl_j0_semiconvergent_series( _z, 12 );
    }
    else if ( std::real(_z) <= T( 1000 ) )
    {
        return __cyl_j0_semiconvergent_series( _z,  6 );
    }
    else if ( std::real(_z) <= T( 25000 ) )
    {
        return __cyl_j0_semiconvergent_series( _z,  3 );
    }
    else
    {
        return __cyl_j0_semiconvergent_series( _z,  1 );
    }

}

}

#endif