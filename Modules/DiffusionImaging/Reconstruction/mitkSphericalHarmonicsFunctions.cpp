/*=========================================================================

Program:   Medical Imaging & Interaction Toolkit
Language:  C++
Date:      $Date: 2009-07-14 19:11:20 +0200 (Tue, 14 Jul 2009) $
Version:   $Revision: 18127 $

Copyright (c) German Cancer Research Center, Division of Medical and
Biological Informatics. All rights reserved.
See MITKCopyright.txt or http://www.mitk.org/copyright.html for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#include <boost/version.hpp>

#define _USE_MATH_DEFINES
#include <math.h>

#if BOOST_VERSION / 100000 > 0
#if BOOST_VERSION / 100 % 1000 > 34
#include <boost/math/special_functions/legendre.hpp>
#include <boost/math/special_functions/spherical_harmonic.hpp>
#endif
#endif

#include "mitkSphericalHarmonicsFunctions.h"
namespace mitk{

#define SPHERICAL_HARMONICS_PI       M_PI

double mitk::mitk_sh_functions::factorial(int number) {
    if(number <= 1) return 1;
    double result = 1.0;
    for(int i=1; i<=number; i++)
        result *= i;
    return result;
}

void mitk::mitk_sh_functions::Cart2Sph(double x, double y, double z, double *cart)
{
    double phi, th, rad;
    rad = sqrt(x*x+y*y+z*z);
    th = atan2(z,sqrt(x*x+y*y));
    phi = atan2(y,x);
    th = -th+SPHERICAL_HARMONICS_PI/2;
    phi = -phi+SPHERICAL_HARMONICS_PI;
    cart[0] = phi;
    cart[1] = th;
    cart[2] = rad;
}

double mitk::mitk_sh_functions::legendre0(int l)
{
    if( l%2 != 0 )
    {
        return 0;
    }
    else
    {
        double prod1 = 1.0;
        for(int i=1;i<l;i+=2) prod1 *= i;
        double prod2 = 1.0;
        for(int i=2;i<=l;i+=2) prod2 *= i;
        return pow(-1.0,l/2.0)*(prod1/prod2);
    }
}


double mitk::mitk_sh_functions::Yj(int m, int k, double theta, double phi)
{
    if( -k <= m && m < 0 )
    {
        return sqrt(2.0) * ::boost::math::spherical_harmonic_r<double, double>(k,m,theta,phi);;
    }

    if( m == 0 )
        return  ::boost::math::spherical_harmonic_r<double, double>(k,m,theta,phi);

    if( 0 < m && m <= k )
    {
        return sqrt(2.0) * ::boost::math::spherical_harmonic_i<double, double>(k,m,theta,phi);
    }

    return 0;
}

}
