#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;

int main()
{
    string s("dog--Dog--DOG--cat--frog--doG--");

    //1.Find all instances of dog; ignoring case
    typedef find_iterator<string::iterator> find_iterator_string_t;
    cout << "Dogs found:" << endl;
    for(auto itr = make_find_iterator(s, first_finder("dog",is_iequal()));itr != find_iterator_string_t();itr++)
    {
        cout << *itr << endl;
    }
    
    //2.Split iterator
    typedef split_iterator<string::iterator> split_iterator_string_t;
    cout << "Split on --:" << endl;
    for(auto itr = make_split_iterator(s,first_finder("--",is_equal()));itr != split_iterator_string_t();itr++)
    {
        cout << *itr << endl;
    }
    
    return 0;
}

