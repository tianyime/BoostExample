#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;

int main()
{
    //1.trim,trim_left,trim_right
    string s1("    spaces to the left, spaces to the right    ");
    cout << "trim left copy" << trim_left_copy(s1) << "|" << endl;
    cout << "trim tighr copy" << trim_right_copy(s1) << "|" << endl;
    cout << "trim left copy" << trim_copy(s1) << "|" << endl;    
    
    //2.trim_if
    string s2("_______underscores to the left, ampersands to the right&&&&&&&"); 
    cout << s2 << endl;
    cout << "trim left: " << trim_left_copy_if(s2,is_any_of("_")) << endl;
    trim_if(s2,is_any_of("_&"));
    cout << s2 << endl;

    return 0;
}

