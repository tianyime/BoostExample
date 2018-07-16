#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;

int main()
{
    //1. split
    string s("this;is,a;list~with|varying separators");
    vector<string> v;
    split(v,s,is_any_of(";,~| "));
    for(auto& str : v)
    {
        cout << str << endl;
    }
    
    //2. join
    string result = join(v,",");
    cout << result << endl;
    
    return 0;
}

