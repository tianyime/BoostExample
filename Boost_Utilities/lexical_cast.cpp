#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
using namespace std;
using namespace boost;

int main()
{
    int i = 12345;
    string s("Hello");
    
    //1. number to string conversion
    try{
        string i2 = lexical_cast<string>(i);
        cout << "number to string: " << i2 << endl;
    }
    catch (bad_lexical_cast& e){
        cout << e.what() << endl;
    }
    
    //2. string to number conversion
    try{
        int i2 = lexical_cast<int>(s);
        cout << "string to int: " << i2 << endl;
    }
    catch (bad_lexical_cast& e){
        cout << e.what() << endl;
    }
        
    return 0;
}

