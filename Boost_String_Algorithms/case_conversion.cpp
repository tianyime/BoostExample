#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;

int main()
{
    //1.to_upper,to_lower(mutable)
    string s1("Hello World");
    to_upper(s1);
    cout << "to_upper(s1): " << s1 << endl;
    to_lower(s1);
    cout << "to_lower(s1): " << s1 << endl;
    
    //2.to_upper_copy,to_lower_copy(non-mutable)
    string s2("Hello World");
    cout << "to_upper_copy(s2): " << to_upper_copy(s2) << endl;
    cout << "to_lower_copy(s2): " << to_lower_copy(s2) << endl;   
    cout << "s2: "<< s2 << endl;
    
    return 0;
}

