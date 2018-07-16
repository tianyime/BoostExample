#include <iostream>
#include <iomanip>  //setfill, setw
#include <string>
#include <map>
#include <boost/format.hpp>
using namespace std;
using namespace boost;
using namespace boost::io;  //boost::io::group

int main()
{
    //1. tabulation
    map<double,string> r{{9.63,"Usain Bolt"},{9.75,"Yohan Blake"},{9.79,"Justin Gatlin"}};
    for(auto& p : r)
    {
        cout << format("%1% %|20t|%2%") % p.second % p.first << endl;
    }
    
    //2. grouping manipulators
    cout << setw(10) << setfill('_') << hex << showbase << 12345 << endl;
    cout << format("%1%") % group(setw(10),setfill('_'),hex,showbase,12345) << endl;
        
    return 0;
}

