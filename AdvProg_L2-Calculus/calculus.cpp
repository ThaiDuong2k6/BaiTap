#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;
using namespace std;


double mySin(double x);
double myCos(double x);
double mySqrt(double x);

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    const int TERMS = 10;
    double result = 1;
    double term = 1;
    for (int n = 1; n <= TERMS; ++n) {
        term *= -1 * x * x / (2 * n * (2 * n - 1));
        result += term;
    }
    return result;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    const int TERMS = 10;
    double result = 0.0;
    double term = x;
    int sign = 1;

    for (int n = 1; n <= TERMS; ++n) {
        result += sign * term;
        term *= x * x / ((2 * n) * (2 * n + 1));
        sign *= -1;
    }

    return result;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    double guess = x / 2.0;
    const double EPSILON = 1e-7;
    while (fabs(guess * guess - x) > EPSILON) {
        guess = (guess + x / guess) / 2.0;
    }
    return guess;
    }

    return 0;
}
