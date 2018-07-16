#include <iostream>
#include <boost/numeric/conversion/converter.hpp>
using namespace std;
using namespace boost;
using namespace boost::numeric;

int main()
{
    typedef converter<int ,double> d2i;
    cout << "d2i(123.0): " << d2i::convert(123.0) << endl;  //calling convert directly
    cout << "d2i()(3.14159): " << d2i()(3.14159) << endl;   //through the function object
    
    try{
        double d = bounds<double>::highest();   //put d out of range of int
        cout << d << endl;
        int i = d2i::convert(d);    //throw positive_overflow
        cout << i << endl;
    }
    catch (positive_overflow& e){
        cout << e.what() << endl;
    }
        
    return 0;
}

