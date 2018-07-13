#include <iostream>
#include <boost/circular_buffer.hpp>
using namespace std;
using namespace boost;

int main()
{
    circular_buffer<int> cb(5);
    
    for(int i=0;i<7;i++)
    {
        cb.push_back(i);
    }
    for(auto i=cb.begin();i!=cb.end();i++)
    {
        cout << *i << endl;
    }

    return 0;
}

