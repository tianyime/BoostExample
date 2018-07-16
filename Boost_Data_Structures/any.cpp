#include <iostream>
#include <string>
#include <boost/any.hpp>
using namespace std;
using namespace boost;

/*
boost::any can be thought of as an object-oriented type-safe alternative to void*
*/

int main()
{
    int a = 1;
    double d = 3.14159;
    string s("hello");
    
    //1. assignments and typeid
    any x=a;    //int
    cout << "int type: " << boolalpha << (typeid(int) == x.type()) << endl;
    
    x = d;  //double
    cout << "double type: " << boolalpha << (typeid(double) == x.type()) << endl;
    
    x = s;  //string
    cout << "string type: " << boolalpha << (typeid(string) == x.type()) << endl;
    
    //2. cast
    try{
        x = a;  //int
        cout << "value: " << any_cast<string>(x) << endl; 
    }
    catch(bad_any_cast& e){
        cout << e.what() << endl;
    }
    
    return 0;
}

