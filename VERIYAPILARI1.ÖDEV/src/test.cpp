/**
* @file test.cpp
* @description programi calistir.
* @course 1. Ogretim A Grubu
* @assignment 1.Odev
* @date 16.11.2022
* @author  Korhan Temiz / korhan.temiz@ogr.sakarya.edu.tr
*/
#include "SatirListesi.hpp"
#include "ReadAndAdd.hpp"
#include "YoneticiListesi.hpp"
#include "ScreenLayout.hpp"
#include <cstdlib>
#include <iostream>

int main()
{

    SatirListesi **SatirList;
    ReadAndAdd *read = new ReadAndAdd("veriler.txt");
    YoneticiListesi *YoneticiList = new YoneticiListesi("veriler.txt");

    SatirList = read->getLine(); // satirilari siralanmamis bir sekilde alir.
    
    int random = 0;
    char ch = ' ';

    for (int i = 0; i < read->countLines(); i++)
    {
        YoneticiList->add(SatirList[i]); // satirlistelerini yonetici listelerine ekler.
    }

    YoneticiList->sortFile(); // yonetici listesine eklenen elemanlar ortalamaya gore siralanir.
    ScreenLayout *Editor = new ScreenLayout(YoneticiList);

    do
    {
        Editor->printList();

        cin >> ch;

        if (ch == 'z')
        {
            Editor->NodeItr(1);
        }

        else if (ch == 'c')
        {
            Editor->NodeItr(0);
        }

        else if (ch == 'd')
        {
            Editor->PageItr(0);
        }

        else if (ch == 'a')
        {
            Editor->PageItr(1);
        }

        else if (ch == 'k')
        {
            random = Editor->printRandomNode();
            cin >> ch;

            if (ch == 'k')
            {   
                Editor->RemoveRandom(random);

                YoneticiList->sortFile();
            }
        }

        else if (ch == 'p')
        {
            Editor->RemoveList();
        }

    } while (ch != 'x');

    return 0;
}
