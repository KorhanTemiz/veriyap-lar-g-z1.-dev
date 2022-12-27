/**
* @file SatirListesiNode.cpp
* @description Satir listesi yapısını olurturmamizi saglar.
* @course 1. Ogretim A Grubu
* @assignment 1.Odev
* @date 05.11.2022
* @author Korhan Temiz	/ korhan.temiz@ogr.sakarya.edu.tr
*/
#include "SatirListesiNode.hpp"

SatirListesiNode::SatirListesiNode(int data, SatirListesiNode *next, SatirListesiNode *prev)
{
    this->data = data;
    this->next = next;
    this->prev = prev;
}