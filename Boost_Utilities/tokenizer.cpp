#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>
using namespace std;
using namespace boost;

int main()
{
    //1. tokenize a sentence
    string s = "The cow jumped over the moon.";
    cout << s << endl;
    tokenizer<> tokens(s);
    for(auto i = tokens.begin(); i != tokens.end(); i++)
    {
        cout << *i << endl;
    }
    cout << endl;
    
    //2. specify token delimiters
    s = "separatem,commas,and;semi-colons;end_of_line";
    cout << s << endl;
    //tokenizer<> tokens2(s);     	//use standard delimiters: "punctuation"
    char_separator<char> cs(",;");	//custom delimiters
    tokenizer<char_separator<char>> tokens2(s,cs);
    for(auto i = tokens2.begin(); i != tokens2.end(); i++)
    {
        cout << *i << endl;
    }
    
    return 0;
}

