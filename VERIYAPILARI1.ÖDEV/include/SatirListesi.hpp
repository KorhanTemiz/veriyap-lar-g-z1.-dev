#ifndef SatirListesi_hpp
#define SatirListesi_hpp

#include "SatirListesiNode.hpp"
#include "NoSuchElement.hpp"
#include "iostream"
#include "string.h"
#include <bits/stdc++.h>
#include "windows.h"
using namespace std;

class SatirListesi
{
	
	private:
    SatirListesiNode *head;
    int size;
    SatirListesiNode *FindPreviousByPosition(int index);
	
public:
    double listAverage;
    void calAverage(); // Bir siranin aritmetik ortalamasini hesaplar
    SatirListesi();
    int Count() const;     // Bir siradaki eleman sayisini dondurur.
    bool isEmpty() const;  // Siranin bos olup olmadigini kontrol eder.
    void add(int);         // Listeye eleman ekler.
    void insert(int, int); // Listede istenilen indexe eleman ekler.
    int indexOf(int);      // Istenilen elamanin indexini dondurur.
    void remove(int);      // Listeden istenilen elemani cikarir.
    void removeAt(int);    // Listeden istenilen indexteki elemani siler.
    int elementAt(int);    // Listede istenilen indexteki elemani dondurur.
    void clear();          // Listeyi temizler.
    void print(int coordX, int coordY);
    void gotoxy(int x, int y);
    ~SatirListesi();


};

#endif