#ifndef YoneticiListesiNode_hpp
#define YoneticiListesiNode_hpp
#include "SatirListesi.hpp"
#include <iostream>
using namespace std;

class YoneticiListesiNode
{

public:
    SatirListesi* data;
    YoneticiListesiNode *next;
    YoneticiListesiNode *prev;
    YoneticiListesiNode(SatirListesi*, YoneticiListesiNode *next = NULL, YoneticiListesiNode *prev = NULL);
};

#endif