#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <boost/bimap.hpp>
using namespace std;
using namespace boost;

int main()
{
    //1. typedef
    typedef bimap<int,string> bm_int_string;
    typedef bm_int_string::value_type value_type;
    
    //2. constructor
    bm_int_string bm;       //bimap<int,string>
    
    //3. insert
    bm.insert(value_type(1,"Steve"));
    bm.insert(value_type(2,"Jane"));
    bm.insert(value_type(3,"Bob"));
    
    //4. access
    cout << "size of bm: " << bm.size() << endl;
    cout << "First place is: " << bm.left.at(1) << endl;
    cout << "Bob finished in: " << bm.right.at("Bob") << endl;
    
    //5. iterate
    cout << "Left iterator: " << endl;
    for(auto i = bm.left.begin(); i != bm.left.end(); i++)
    {
        cout << i->first << ":" << i->second << endl;
    }
    cout << "Right iterator: " << endl;
    for(auto i = bm.right.begin(); i != bm.right.end(); i++)
    {
        cout << i->first << ":" << i->second << endl;
    }
    
    //6. uniqueness
    bm.insert(value_type(3,"Lucy"));    //warning - does nothing
    bm.left.replace_data(bm.left.find(3),"Lucy");
    auto itr = bm.right.find("Steve");
    bm.right.replace_data(itr,4);
    cout << "After replacing: " << endl;
    for(auto i = bm.left.begin(); i != bm.left.end(); i++)
    {
        cout << i->first << ":" << i->second << endl;
    }
    
    return 0;
}

