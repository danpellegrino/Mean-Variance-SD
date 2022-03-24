/*
 * Function: main
 * PURPOSE: TO GRAB 10 USER VALUES AND
 *          OUTPUT THEIR MEAN, VARIANCE,
 *          AND STANDARD DEVIATION
 * Name: Daniel Pellegrino
 * Written: 4/18/2021; Last Modified 4/30/2021
 * Language: C++
 * Compiler: GNU GCC; IDE Code::Blocks 20.03
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX 10

void enterValue( int & );
double mean ( const vector<int> );
double variance( const vector<int> );
double standardDeviation( const vector<int> );

int main( void )
{
    vector<int> values(MAX);

    for_each(values.begin(), values.end(), enterValue);

    cout << endl << "Finding mean... " << endl;
    cout << mean(values) << endl;

    cout << endl << "Finding variance... " << endl;
    cout << variance(values) << endl;

    cout << endl << "Finding standard deviation... " << endl;
    cout << standardDeviation(values) << endl;

    return 0;
}

void enterValue(int &val)
{
    cout << "Enter a value: ";
    cin >> val;

    return;
}

double mean( const vector<int> VALUE )
{ return accumulate(VALUE.begin(), VALUE.end(), 0.0) / VALUE.size(); }

double variance( const vector<int> VALUE )
{
    double vari = 0.0;

    for(int i = 0; i < (int)VALUE.size(); i++)
    {
        vari += pow((VALUE[i] - mean(VALUE)), 2);
    }

    vari /= VALUE.size();

    return vari;
}

double standardDeviation( const vector<int> VALUE )
{ return sqrt(variance(VALUE)); }
