#include <iostream>
#include <string>
#include <boost/numeric/conversion/cast.hpp>
using namespace std;
using namespace boost;
using namespace boost::numeric;

int main()
{
    double s = 555.22;
    float f = -3.14159f;
    
    //1. basic conversion with negative and positive overflow
    try{
        int s2 = numeric_cast<int>(s);
        cout << s2 << endl;
    }
    catch (negative_overflow& e){   //"underflow", i.e. below min
        cout << e.what() << endl;
    }
    catch (positive_overflow& e){   //"overflow", i.e. above max
        cout << e.what() << endl;
    }
    
    //2. unsigned numeric_cast and bad_numeric_cast exception
    try{
        unsigned int ui= numeric_cast<unsigned int>(f);
        cout << ui << endl;
    }
    catch (bad_numeric_cast& e){    //bad conversion including under/over errors
        cout << e.what() << endl;
    }
        
    return 0;
}

