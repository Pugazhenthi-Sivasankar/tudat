/*! \file exponentialRandomNumberGenerator.cpp
 *    This source file contains a class definition for generating random
 *    numbers with exponential distribution.
 *
 *    Path              : /Mathematics/RandomNumberGenerators/
 *    Version           : 1
 *    Check status      : Checked
 *
 *    Author            : K. Kumar
 *    Affiliation       : Delft University of Technology
 *    E-mail address    : K.Kumar@tudelft.nl
 *
 *    Checker           : F.M. Engelen
 *    Affiliation       : Delft University of Technology
 *    E-mail address    : F.M.Engelen@student.tudelft.nl
 *
 *    Date created      : 8 July, 2011
 *    Last modified     : 8 July, 2011
 *
 *    References
 *      Press W.H., et al. Numerical Recipes in C++: The Art of
 *          Scientific Computing. Cambridge University Press, February 2002.
 *
 *    Notes
 *      See notes for uniform random number generator.
 *
 *    Copyright (c) 2010-2011 Delft University of Technology.
 *
 *    This software is protected by national and international copyright.
 *    Any unauthorized use, reproduction or modification is unlawful and
 *    will be prosecuted. Commercial and non-private application of the
 *    software in any form is strictly prohibited unless otherwise granted
 *    by the authors.
 *
 *    The code is provided without any warranty; without even the implied
 *    warranty of merchantibility or fitness for a particular purpose.
 *
 *    Changelog
 *      YYMMDD    Author            Comment
 *      110708    K. Kumar          First creation of code.
 *      110905    S. Billemont      Reorganized includes.
 *                                  Moved (con/de)structors and getter/setters to header.
 */

// Include statements.
#include <cmath>
#include "Mathematics/RandomNumberGenerators/exponentialRandomNumberGenerator.h"

//! Default constructor.
ExponentialRandomNumberGenerator::ExponentialRandomNumberGenerator(
        const double& exponentialRandomNumberParameter,
        unsigned long long seed )
            : UniformRandomNumberGenerator( seed ),
              exponentialRandomNumberParameter_(
                      exponentialRandomNumberParameter )
{
}

//! Get exponentially-distributed, normalized, random double.
double ExponentialRandomNumberGenerator::
getExponentiallyDistributedNormalizedRandomDouble( )
{
    // Declare local variables.
    // Declare local uniform random number.
    double uniformRandomNumber_;

    // Get a non-zero normalized exponentially-distributed random double.
    do
    {
        uniformRandomNumber_ = getUniformlyDistributedNormalizedRandomDouble( );
    }
    while ( uniformRandomNumber_ == 0.0 );

    // Return exponentially0distributed, normalized, random double.
    return -log( uniformRandomNumber_ ) / exponentialRandomNumberParameter_;
}

// End of file.