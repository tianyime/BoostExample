#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;

int main()
{
    string s("A dog followed the boy to THE grocery store.");
    
    //1. iterator range to_upper
    auto r1 = find_first(s,"the");   //return iterator_range
    to_upper(r1);
    auto r2 = find_last(s,"THE");
    to_lower(r2);
    cout << "After :" << s << endl;
    
    //2. find_first as a bool
    if(find_first(s,"boy"))
    {
        cout << "boy found." << endl;
    }
    
    return 0;
}

