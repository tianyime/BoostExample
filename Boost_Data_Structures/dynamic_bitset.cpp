#include <iostream>
#include <string>
#include <bitset>
#include <boost/dynamic_bitset.hpp>
using namespace std;
using namespace boost;

int main()
{
    //1. construct dynamic bitsets
    dynamic_bitset<> db(4,6);   //4 bits with initial bitset: 6 -> 0110 
    dynamic_bitset<> db2(string("1101"));   //construct using a string "1101"(13) with 4 bits
    
    cout << "db: " << db << endl;
    cout << "db2: " << db2 << endl;
    
    //2. compared to std::bitset
    int nbits=6;
    std::bitset<6> bs;  //fixed size, must be defined at compile-time
    boost::dynamic_bitset<> db3(nbits);
    
    db3.resize(12); //ok
    //bs.resize(12);    //error: cannot resize bitset
    
    //3. Logical operations and shifts
    cout << "~db: " << ~db << endl; //complement: 0 -> 1, 1 -> 0
    cout << "OR: db | db2: " << (db | db2) << endl;   //must be the same size
    cout << "AND: db & db2: " << (db & db2) << endl;
    cout << "XOR: db ^ db2: " << (db ^ db2) << endl;
    cout << "Shift left: db <<2: " << (db <<2) << endl;
    cout << "Shift right: db >>2: " << (db >>2) << endl;
    
    //4. set values
    dynamic_bitset<> db4(string("10101010"));
    cout << db4 << endl;
    cout << "Set values: " <<endl;
    db4[0] = 1;         //set the 1 bit         :10101011
    db4[1] = false;     //set the bit to 0      :10101001
    db4[2] = true;      //set the bit to 1      :10101101
    db4[3] -= 1;        //set the bit to 0 if 1 :10100101
    db4[4].flip();      //flip bit 4 only       :10110101
    cout << db4 << endl;
    
    //5. tests
    cout << boolalpha << "Any: " << db4.any() << endl;          //Is any bit set to 3?
    cout << boolalpha << "Test (3): " << db4.test(3) << endl;   //Is bit 3 set to 1?
    cout << boolalpha << "None: " << db4.none() << endl;        //Are all bits 0?
    cout << boolalpha << "Cout: " << db4.count() << endl;       //How many bits are set?
    
    //6. conversion to long
    unsigned long u = db4.to_ulong();
    cout << "Converted to long(base 10): " << u <<endl;
    
    //7. subset adn intersection
    dynamic_bitset<> db5(string("11001100"));
    dynamic_bitset<> db6(string("11000000"));    
    
    cout << boolalpha << "Is db6 a subset of db5? " << db6.is_subset_of(db5) << endl;
    cout << boolalpha << "Is db6 a proper subset of db5? " << db6.is_proper_subset_of(db5) << endl;
    cout << boolalpha << "Does db6 intersect with db5? " << db6.intersects(db5) << endl;

    return 0;
}

