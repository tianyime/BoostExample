#include <iostream>
#include <string>
#include <boost/format.hpp>
using namespace std;
using namespace boost;

int main()
{
    //1. prepare the format stucture
    format fmt("Hello %1%, here is a floating point number: %2%, and an integer: %3%");
    
    //2. operator % is overloaded to convert operands to string in the format object
    fmt % "Setev";  //%1%
    fmt % 1.159;    //%2%
    fmt % 42;       //%3%
    cout << fmt << endl;
    
    //3. one-liner (with repeat %1%)
    cout << format("%1%, %2%, %3%, %1%") % "String" % 3.14159 % 'x' << endl;
    
    //4. printf style formatting
    cout << format("%s: %.1f,%.1f") % "Joe" % 25.35 % 100.29 << endl;   //to 1 decimal place
    
    return 0;
}

