/**
* @file YoneticiListesiNode.cpp
* @description Yonetici Listesi yapisini olusturmamizi saglar.
* @course 1. Ogretim A Grubu
* @assignment 1.Odev
* @date 07.11.2022
* @author Korhan Temiz	/ korhan.temiz@ogr.sakarya.edu.tr
*/
#include "YoneticiListesiNode.hpp"

YoneticiListesiNode::YoneticiListesiNode(SatirListesi *data, YoneticiListesiNode *next, YoneticiListesiNode *prev)
{
    this->data = data;
    this->next = next;
    this->prev = prev;
}