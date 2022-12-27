#ifndef ReadAndAdd_hpp
#define ReadAndAdd_hpp

#include "SatirListesi.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class ReadAndAdd
{
private:
    void readLine();
    string filename;
    SatirListesi **lines;

public:
    ReadAndAdd(string);
    ~ReadAndAdd();
    int countLines();          // satir sayisini bulur.
    SatirListesi **sortFile(); // listeyi aritmetik siralanmis getirir.
    SatirListesi **getLine();  // listeyi okundugu sirayla getirir.
};

#endif