#include <iostream>
#include <string>
#include <boost/variant.hpp>
using namespace std;
using namespace boost;

//return the number of characters or digits depending on the type
class length_visitor : public static_visitor<int>
{
public:
    int operator()(int v) const
    {
        int n=0;
        if(v == 0)  return 1;   //0 digit
        while(v != 0)
        {
            v /=10;
            n++;
        }
        return n;
    }
    int operator()(string& v) const
    {
        return v.length();
    }
};

int main()
{
    //1. construct and assign
    boost::variant<int,string> v;
    v = 1;
    
    //2. get
    int a = 1;
    string s = "world";
    try{
        if(typeid(int) == v.type())
        {
            int * x = get<int>(&v);
            *x += a;                //add ints (modifies v)
            int len = apply_visitor(length_visitor(),v);
            cout << get<int>(v) << endl;
            cout << "length of v(int): " << len << endl;
        }
        v = "Hello ";
        if(typeid(string) == v.type())
        {
            string *t = get<string>(&v);
            *t += s;                //concatenate string (modifies v)
            int len = apply_visitor(length_visitor(),v);
            cout << get<string>(v) << endl;
            cout << "length of v(string): " << len << endl;
        }
    }
    catch (bad_get &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
