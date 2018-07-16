#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;

int main()
{
    //1. erase_first, _last, _nth, _all, _regex, _head, _tail
    string s("2018-07-15");
    cout << s << endl;
    erase_all(s,"-");   //remove the hyphens - 20180715
    cout << "ISO date format without hyphens: " << s << endl;
    cout << "Day: " << erase_head_copy(s,6) <<endl;
    cout << "Year: " << erase_tail_copy(s,4) << endl;
    
    //2. replace_fisrt, _last, _nth, _all, _regex, _head, _tail
    string s1("The quick brown fox. The quick brown rabbit.");
    cout << "Original s1: " << s1 << endl;
    replace_first(s1,"brown","red");
    cout << "After replace_fisrt(brown -> red): " << s1 << endl;
    
    //3. replace nth is zero_indexed
    string s2("one two three one tow three");
    cout << "Original s2: " << s2 << endl;
    cout << "Replace 1st 'one' (with 'seven'): " << replace_nth_copy(s2,"one",0,"seven") << endl;
    cout << "Replace last 'three'(with 'eight'): " << replace_last_copy(s2,"three","eight") << endl;
    
    return 0;
}

