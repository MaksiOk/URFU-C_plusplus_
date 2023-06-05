#pragma once
#include <iostream> 
using namespace std;

class Location {
    friend ostream& operator<<(ostream&, const Location&);
private:
    short _line;
    short _col;
public: 
    Location() = default;
    Location(int, int) {};

friend ostream& operator <<(ostream& os, const Location& lc)
{
    // объект Loc выводится в виде:  < 10,37 > 
    os << " <" << lc._line
        << " ," << lc._col << " >  ";

    return os;
}
};