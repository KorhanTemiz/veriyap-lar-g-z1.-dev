#ifndef ScreenLayout_hpp
#define ScreenLayout_hpp

#include "YoneticiListesi.hpp"

class ScreenLayout
{

public:
    ScreenLayout(YoneticiListesi *);

    void gotoxy(int x, int y);
    void Layout();              // Sayfa duzenlemede baslangic ve bitis konumlandirmalarini yapmada yardimci olur.
    void PageItr(int);          // Sayfada dolasmayi saglar.
    void NodeItr(int);          // Yonetici listesi dugumlerini dolasmayi saglar.
    void printList();           // Listeyi yazdirir.
    void currentNode(int, int); // Mevcut dugumu yazdirir.
    int printRandomNode();      // Satir listesinden silme islemini yaparken secili dugumun gosterilmesini saglar.
    void RemoveRandom(int);     // Satir listesinden rastgele secilen elemani siler.
    void RemoveList();          // Yonetici listesinden eleman siler.

private:
    YoneticiListesi *Yoneticilistesi;
    int selectedNode;
    int startposition;
    int finishPosition;
};

#endif