// FILE: statexam.cxx
// Written by Michael Main (main@colorado.edu)
// Modified by Steve Kaminski to correct next_number member and to alter scoring scheme
// This program calls five test functions to test the statisitician class.
// Maximum number of points from executing this program is 20.

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string.h>    // Provides memcpy function
#include "statistician.h"
using namespace std;
using namespace main_savitch_2C;

bool close(double a, double b)
{
    const double EPSILON = 1e-5;
    return (fabs(a-b) < EPSILON);
}

int test1( )
{
    // Test program for basic statistician functions.
    // Returns 20 if everything goes okay; otherwise returns 0.

    statistician s, t;
    int i;
    double r = 0;

    if (s.length( ) || t.length( )) return 0;
    if (s.sum( ) || t.sum( )) return 0;

    for (i = 1; i <= 10000; i++)
    {
	s.next_number(i);
	r += i;
    };

    if (t.length( ) || t.sum( )) return 0;
    if (s.length( ) != 10000) return 0;
    if (!close(s.sum( ), r)) return 0;
    if (!close(s.mean( ), r/10000)) return 0;
    
    // Reset and then retest everything
    s.reset( );
    t.reset( );
    r = 0;
    
    if (s.length( ) || t.length( )) return 0;
    if (s.sum( ) || t.sum( )) return 0;

    for (i = 1; i <= 10000; i++)
    {
	s.next_number(i);
	r += i;
    };

    if (t.length( ) || t.sum( )) return 0;
    if (s.length( ) != 10000) return 0;
    if (!close(s.sum( ), r)) return 0;
    if (!close(s.mean( ), r/10000)) return 0;

    return 12;
}

int test2( )
{
    // Test program for minimum/maximum statistician functions.
    // Returns 2 if everything goes okay; otherwise returns 0.

    statistician s, t, u;
    double r = 1000;
    char n[15] = "10000000000000";

    if (s.length( ) || t.length( )) return 0;
    if (s.sum( ) || t.sum( )) return 0;

    memcpy(&r, n, sizeof(double));
    r = 1/r;
    s.next_number(r);
    if ((s.minimum( ) != r) || (s.maximum( ) != r)) return 0;
    r *= -1;
    t.next_number(r);
    if ((t.minimum( ) != r) || (t.maximum( ) != r)) return 0;

    u.next_number(100); u.next_number(-1); u.next_number(101); u.next_number(3);
    if ((u.minimum( ) != -1) || (u.maximum( ) != 101)) return 0;

    return 2;
}

int test3( )
{
    // Test program for + operator of the statistician
    // Returns 2 if everything goes okay; otherwise returns 0.

    statistician s, t, u, v;

    cout << "\ns.length(): " << s.length() << endl;
    cout << "\nt.length(): " << t.length() << endl;

    if (s.length( ) || t.length( )) return 0;
    if (s.sum( ) || t.sum( )) return 0;
    cout << "\ns.length(): " << s.length() << endl;
    cout << "\nt.length(): " << t.length() << endl;

    t.next_number(5);
    u.next_number(0); u.next_number(10); u.next_number(10); u.next_number(20);

    v = s + s;
    if (v.length( ) || v.sum( )) return 0;
    v = s + u;
    if (!(u == v)) return 0;
    v = t + s;
    if (!(t == v)) return 0;
    v = t + u;
    if (v.length( ) != 5) return 0;
    if (!close(v.sum( ), 45)) return 0;
    if (v.minimum( ) != 0) return 0;
    if (v.maximum( ) != 20) return 0;
    if (!close(v.mean( ), 45.0/5)) return 0;
    v = v + t;
    if (v.length( ) != 6) return 0;
    if (!close(v.sum( ), 50)) return 0;
    if (v.minimum( ) != 0) return 0;
    if (v.maximum( ) != 20) return 0;
    if (!close(v.mean( ), 50.0/6)) return 0;
    return 2;
}

int test4( )
{
    // Test program for * operator of the statistician
    // Returns 2 if everything goes okay; otherwise returns 0.

    statistician s, t, u;

    if (s.length( ) || t.length( )) return 0;
    if (s.sum( ) || t.sum( )) return 0;

    u.next_number(0); u.next_number(10); u.next_number(10); u.next_number(20);

    s = 2*u;
    if (s.length( ) != 4) return 0;
    if (!close(s.sum( ), 80)) return 0;
    if (s.minimum( ) != 0) return 0;
    if (s.maximum( ) != 40) return 0;
    if (!close(s.mean( ), 80.0/4)) return 0;

    s = -2*u;
    if (s.length( ) != 4) return 0;
    if (!close(s.sum( ), -80)) return 0;
    if (s.minimum( ) != -40) return 0;
    if (s.maximum( ) != 0) return 0;
    if (!close(s.mean( ), -80.0/4)) return 0;

    s = 0*u;
    if (s.length( ) != 4) return 0;
    if (!close(s.sum( ), 0)) return 0;
    if (s.minimum( ) != 0) return 0;
    if (s.maximum( ) != 0) return 0;
    if (!close(s.mean( ), 0)) return 0;

    s = 10 * t;
    if (s.length( ) != 0) return 0;
    if (s.sum( ) != 0) return 0;

    return 2;
}

int test5( )
{
    // Test program for == operator of the statistician.
    // Returns 2 if everything goes okay; otherwise returns 0.

    statistician s, t, u, v, w, x;

    if (s.length( ) || t.length( )) return 0;
    if (s.sum( ) || t.sum( )) return 0;

    t.next_number(10);
    u.next_number(0); u.next_number(10); u.next_number(10); u.next_number(20);
    v.next_number(5); v.next_number(0); v.next_number(20); v.next_number(15);
    w.next_number(0);
    x.next_number(0); x.next_number(0);
    
    if (!(s == s)) return 0;
    if (s == t) return 0;
    if (t == s) return 0;
    if (u == t) return 0;
    if (!(u == v)) return 0;
    if (w == x) return 0;

    return 2;
}

int main( )
{
    using namespace std;
    int value = 0;
    int result;
    
    cout << "Running statistician tests:" << endl;
 
    cout << "TEST 1:" << endl;
    cout << "Testing next, reset, length, sum, and mean (12 points).\n";
    result = test1( );
    value += result;
    if (result > 0) cout << "Test 1 passed." << endl << endl;
    else cout << "Test 1 failed." << endl << endl;
 
    cout << "\nTEST 2:" << endl;
    cout << "Testing minimum and maximum member functions (2 points).\n";
    result = test2( );
    value += result;
    if (result > 0) cout << "Test 2 passed." << endl << endl;
    else cout << "Test 2 failed." << endl << endl;
 
    cout << "\nTEST 3:" << endl;
    cout << "Testing the + operator (2 points).\n";
    result = test3( );
    value += result;
    if (result > 0) cout << "Test 3 passed." << endl << endl;
    else cout << "Test 3 failed." << endl << endl;
 
    cout << "\nTEST 4:" << endl;
    cout << "Testing the * operator (2 points).\n";
    result = test4( );
    value += result;
    if (result > 0) cout << "Test 4 passed." << endl << endl;
    else cout << "Test 4 failed." << endl << endl;

    cout << "\nTEST 5:" << endl;
    cout << "Testing the == operator (2 points).\n";
    result = test5( );
    value += result;
    if (result > 0) cout << "Test 5 passed." << endl << endl;
    else cout << "Test 5 failed." << endl << endl;

    cout << "Program scored " << value << " points out of 20 for execution.\n";
    
    system("Pause");
    return EXIT_SUCCESS;

}












