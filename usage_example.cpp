#include <iostream>
#include "./bessel.hpp"

using namespace std;

int main()
{
    complex<double> z = complex<double> (100, 12) // z=100+i*12
    cout << bessel::cyl_j0( z );
}
