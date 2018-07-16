#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;

/*Some important classifiers
1. is_space    spaces 
2. is_alnum    alphanumeric characters
3. is_alpha    letters
4. is_cntrl    control characters
5. is_lower    lower case characters
6. is_punct    punctuation characters
7. is_upper    uppercase characters
8. is_xdigit   hexadecimal digits
9. is_any_of   any of a sequence of characters
10.is_from_range    characters inside a min..max range
*/

int main()
{
    string s("434261164abcdefghijkl%$^^%&*&((@");
    string s2("lowercaseUPPERCASE1234567890");
    
    cout << "alphanumeric: " << trim_copy_if(s,is_alnum()) << endl;

    cout << "lower: " << trim_copy_if(s,is_lower()) << endl;

    cout << "xdigit: " << trim_copy_if(s,is_xdigit()) << endl;  //hexadecimal

    cout << "43@: " << trim_copy_if(s,is_any_of(string("43@"))) << endl;

    cout << "punctuation: " << trim_copy_if(s,is_punct()) << endl;

    cout << "a-z (s2): " << trim_copy_if(s2,is_from_range('a','z')) << endl;

    cout << "alphanumeric or punctuation: " << trim_copy_if(s,is_alnum() || is_punct()) << endl;
    
    return 0;
}

