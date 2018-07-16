#include <iostream>
#include <string>
#include <map>
#include <boost/foreach.hpp>
using namespace std;
using namespace boost;

int main()
{
    //1. string
    cout << "Boost_FOREACH string:" << endl;
    string s = "The quick brown fox.";
    BOOST_FOREACH(char c,s)
    {
        if(c == ' ')
        {
            cout << endl;
        }
        else
        {
            cout << c;
        }
    }
    cout << endl << endl;
    
    //2. array
    cout << "BOOST_FOREACH array:";
    int a[]={1,2,3,4,5};
    BOOST_FOREACH(int& i,a)
    {
        i +=2;
        cout << i << ' ';
    }
    cout << endl << endl;
    
    //3. standard-library container
    cout << "BOOST_FOREACH container:";
    map<int,string> m;
    m.insert(make_pair(1,"Alpha"));
    m.insert(make_pair(2,"Beta"));
    m.insert(make_pair(3,"Gamma"));
    BOOST_FOREACH(auto& i,m)    //i: std::pair
    {
        cout << i.first << ":" << i.second << endl;
    }

    return 0;
}

