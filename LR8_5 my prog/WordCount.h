#pragma once
#include <vector> 
#include <string> 
#include <iostream> 
#include "Location.h"
using namespace std;

class WordCount {
    friend ostream& operator<<(ostream&, const WordCount&);

public:
    WordCount() {}
    WordCount(const string& word) : _word(word) {}
    WordCount(const string& word, int ln, int col)
        : _word(word) {
        insert_location(ln, col);
    }

    string word()   const { return _word; }
    int    occurs() const { return _occurList.size(); }
    void   found(int ln, int col)
    {
        insert_location(ln, col);
    }

private:
    void insert_location(int ln, int col)
    {
        _occurList.push_back(Location(ln, col));
    }

    string             _word;
    vector< Location > _occurList;
};

