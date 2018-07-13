#include <iostream>
#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
using namespace std;
using namespace boost;

int main()
{
    //1.Random UUID generator
    uuids::random_generator gen;
    uuids::uuid u1=gen();
    cout << "u1: " << to_string(u1) << endl;

    //2.String generator
    uuids::string_generator sgen;
    uuids::uuid u2=sgen(string("0123456789abcdef0123456789abcdef"));
    cout << "u2: " << to_string(u2) << endl;
    return 0;
}

