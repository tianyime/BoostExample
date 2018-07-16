#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;

/*
Functions prefixed whit 'i' are case insensitive: e.g. ends_with => iends_with
*/
int main()
{
    //1. starts_with,ends_with
    string str[] = { "tractable","Executable","exited","completed" };
    for(string& s : str)
    {
        cout << s << "begins with: ";
        if(istarts_with(s,"ex"))
        {
            cout << "ex";
        }
        cout << "," << "ends_with: ";
        if(ends_with(s,"able"))
        {
            cout << "able" << ' ';
        }
        if(ends_with(s,"ed"))
        {
            cout << "ed";
        }
        cout << endl;
    }
    
    //2. all
    cout << "All lowercase? " << boolalpha << all("Some string",is_lower()) << endl;
    
    //3. contains
    string s1("The quick brown fox.");
    cout << "Contains? " << boolalpha << contains(s1,"fox") << endl;
 
    return 0;
}

