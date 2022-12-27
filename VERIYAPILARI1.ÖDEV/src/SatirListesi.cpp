/**
 * @file SatirListesi.cpp
 * @description Satir listesi uzerinde gerekli islemleri yapmamizi saglar.
 * @course  1. Ogretim A Grubu
 * @assignment 1.Odev
 * @date 05.11.2022
 * @author Korhan Temiz	/ korhan.temiz@ogr.sakarya.edu.tr
 */
#include "SatirListesi.hpp"

SatirListesi::SatirListesi()
{
    head = NULL;
    size = 0;
    listAverage = 0;
}

void SatirListesi::gotoxy(int x, int y)
{

    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

SatirListesiNode *SatirListesi::FindPreviousByPosition(int index)
{
    if (index < 0 || index > size)
        throw NoSuchElement("No Such Element");
    SatirListesiNode *prv = head;
    int i = 1;
    for (SatirListesiNode *itr = head; itr->next != NULL && i != index; itr = itr->next, i++)
    {
        prv = prv->next;
    }
    return prv;
}

int SatirListesi::Count() const
{
    return size;
}

void SatirListesi::calAverage()
{
    double sum = 0;
    if (!isEmpty())
    {

        for (int i = 0; i < size; i++)
        {

            sum += elementAt(i);
        }
    }
    listAverage = sum / size;
}

bool SatirListesi::isEmpty() const
{
    return size == 0;
}

void SatirListesi::add(int item)
{
    insert(size, item);
}

void SatirListesi::insert(int index, int item)
{
    if (index < 0 || index > size)
        throw "Index out of Range";
    if (index == 0)
    {
        head = new SatirListesiNode(item, head);
        if (head->next != NULL)
            head->next->prev = head;
    }
    else
    {
        SatirListesiNode *prv = FindPreviousByPosition(index);
        prv->next = new SatirListesiNode(item, prv->next, prv);
        if (prv->next->next != NULL)
            prv->next->next->prev = prv->next;
    }
    size++;
}

int SatirListesi::indexOf(int item)
{
    int index = 0;
    for (SatirListesiNode *itr = head; itr != NULL; itr = itr->next)
    {
        if (itr->data == item)
            return index;
        index++;
    }
    throw NoSuchElement("No Such Element");
}

void SatirListesi::remove(int item)
{
    int index = indexOf(item);
    removeAt(index);
}

void SatirListesi::removeAt(int index)
{
    if (index < 0 || index >= size)
        throw "Index out of Range";
    SatirListesiNode *del;
    if (index == 0)
    {
        del = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
    }
    else
    {
        SatirListesiNode *prv = FindPreviousByPosition(index);
        del = prv->next;
        prv->next = del->next;
        if (del->next != NULL)
            del->next->prev = prv;
    }
    size--;
    delete del;
}

int SatirListesi::elementAt(int index)
{
    if (index < 0 || index >= size)
        throw NoSuchElement("No Such Element");
    if (index == 0)
        return head->data;
    return FindPreviousByPosition(index)->next->data;
}

void SatirListesi::clear()
{
    while (!isEmpty())
        removeAt(0);
}

void SatirListesi::print(int coordX, int coordY)
{
    int yIndex = coordY;
    gotoxy(coordX, yIndex + 1);
    cout << "^^^^^^^^^^^" << endl;
    for (SatirListesiNode *itr = this->head; itr != NULL; itr = itr->next)
    {

        gotoxy(coordX, ++yIndex + 1);
        cout << "|" << itr << " |" << endl;

        gotoxy(coordX, ++yIndex + 1);
        cout << "-----------" << endl;

        gotoxy(coordX, ++yIndex + 1);
        cout << "|" << setw(5) << itr->data << setw(5) << "|" << endl;

        gotoxy(coordX, ++yIndex + 1);
        cout << "-----------" << endl;

        gotoxy(coordX, ++yIndex + 1);
        if (itr->next == NULL)
        {
            cout << "|000000000|" << endl;
        }
        else
        {
            cout << "|" << itr->next << setw(0) << " |" << endl;
        }
        gotoxy(coordX, ++yIndex + 1);
        cout << "-----------" << endl;
        cout << endl;
    }
}

SatirListesi::~SatirListesi()
{
    clear();
}
