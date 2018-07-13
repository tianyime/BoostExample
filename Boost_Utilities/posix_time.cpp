nclude <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace std;
using namespace boost;
using namespace boost::posix_time;

int main()
{
    ptime p1(time_from_string("2018-07-13 10:50:55.1234545678"));
    ptime p2(from_iso_string("20180713T101122.123456789"));
    ptime p3(second_clock::local_time());
    ptime p4(microsec_clock::universal_time());

    cout << "to_simple_string(p1): " << to_simple_string(p1) << endl;
    cout << "to_iso_string(p2): "<< to_iso_string(p2) << endl;
    cout << "to_iso_extended_string(p3): " << to_iso_extended_string(p3) << endl;
    cout << "to_iso_extended_string(p4): " << to_iso_extended_string(p4) << endl;

    cout << "p1.date(): " << p1.date() << endl;
    cout << "p1.time_of_day(): "<< p1.time_of_day() << endl;

    p1 +=hours(1)+minutes(1)+seconds(1)+milliseconds(1)+microseconds(1);
    cout << "p1 after operation: " << to_simple_string(p1) << endl;

    return 0;
}

