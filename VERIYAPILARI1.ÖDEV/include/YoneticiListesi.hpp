#ifndef YoneticiListesi_hpp
#define YoneticiListesi_hpp

#include "YoneticiListesiNode.hpp"
#include "SatirListesi.hpp"
#include "ReadAndAdd.hpp"
#include "NoSuchElement.hpp"
#include "iostream"
#include "string.h"
#include <bits/stdc++.h>
#include "windows.h"

using namespace std;

class YoneticiListesi
{
public:
    YoneticiListesiNode *head;
    YoneticiListesi(string);
    void sortFile();          // Yonetici listesi elemanlarini siralar.
    void removeAt(int index); // Yonetici listesinden istenilen indexteki elemani cikarir.
    bool isEmpty() const;     // Yonetici listesinin bos olup olmadigini kontrol eder.
    int Count() const;        // Yonetici listesinin eleman sayisini kontrol eder .
    ~YoneticiListesi();
    void insert(int index, SatirListesi *item);                                       // Yonetici listesinde istenilen indexe eleman ekler.
    void add(SatirListesi *item);                                                     // Yonetici listesinin sonuna eleman ekler.
    SatirListesi *elementAt(int index);                                               // Yonetici listesi icerisinde istenilen indexteki satir listesini dondurur.
    void clear();                                                                     // Listeyi bosaltır
    int randomIndex(int index);                                                       // Yonetici listesi icindeki satirlistesinden random sekilde eleman silmek icin sayi verir.
    void removeRandomNode(int, int);                                                  // Satir listesi icinden random eleman siler.
    void PrintNode(int, int, int);                                                    // Bir dugumu yazdirir.
    int CountLines();                                                                 // En bastaki toplam satir sayisini dondurur.
    void calAverage(SatirListesi *);                                                  // Yonetici listesi icerisindeki satir listelerinin aritmetik ortalamasini dondurur.
    void swapNodes(YoneticiListesiNode **listHead, SatirListesi *x, SatirListesi *y); // Yonetici listelerini siralarken dugumlerin yer degistirmesini saglar.
    YoneticiListesiNode *getNodeIndex(int index);                                     // Istenilen indexteki dugumu getirir.
    void gotoxy(int x, int y);                                                        // Elemanlari yazdirirken konumlandirmayi saglar.
private:
    int size; // Eleman sayisini tutar.
    YoneticiListesiNode *FindPreviousByPosition(int index);
    string filename;
    SatirListesi **list;
};

#endif