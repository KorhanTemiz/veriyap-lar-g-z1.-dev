/**
* @file YoneticiListesi.cpp
* @description Satir listesindeki elemanlari yonetici listesine ekler, eleman siler, siralar, gerekli yonetici islemlerini gerceklestirir.
* @course 1. Ogretim A Grubu
* @assignment 1.Odev
* @date 08.12.2022
* @author Korhan Temiz / korhan.temiz@ogr.sakarya.edu.tr
*/
#include "YoneticiListesi.hpp"

void YoneticiListesi::gotoxy(int x, int y)
{

    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

YoneticiListesi::YoneticiListesi(string filename)
{
    this->filename = filename;
    head = NULL;
    size = 0;
}

YoneticiListesiNode *YoneticiListesi::FindPreviousByPosition(int index)
{
    if (index < 0 || index > size)
        throw NoSuchElement("No Such Element");

    YoneticiListesiNode *prv = head;
    int i = 1;

    for (YoneticiListesiNode *itr = head; itr->next != NULL && i != index; itr = itr->next, i++)
    {
        prv = prv->next;
    }
    return prv;
}

int YoneticiListesi::randomIndex(int index)
{
    int counter = this->Count();

    if (index < 0 || index >= counter)
        throw "Index out of Range";

    srand(time(NULL));
    SatirListesi *satirListesi = this->elementAt(index);

    int counter1 = satirListesi->Count();

    if (counter1 == 0)
    {
        throw NoSuchElement("No Such Element");
    }
    int randomNumber = rand() % counter1;

    return randomNumber;
}

void YoneticiListesi::removeRandomNode(int index, int SatirListesiIndex)
{

    int counter = this->Count();

    if (index < 0 || index >= counter)
        throw "Index out of Range";

    SatirListesi *satirListesi = this->elementAt(index);

    satirListesi->removeAt(SatirListesiIndex);
    this->calAverage(this->elementAt(index));
}

void YoneticiListesi::insert(int index, SatirListesi *item)
{
    if (index < 0 || index > size)
        throw "Index out of Range";

    if (index == 0)
    {
        head = new YoneticiListesiNode(item, head);
        if (head->next != NULL)
            head->next->prev = head;
    }
    else
    {
        YoneticiListesiNode *prv = FindPreviousByPosition(index);
        prv->next = new YoneticiListesiNode(item, prv->next, prv);
        if (prv->next->next != NULL)
            prv->next->next->prev = prv->next;

    }
    size++;
}

void YoneticiListesi::add(SatirListesi *item)
{
    insert(size, item);
}

void YoneticiListesi::removeAt(int index)
{
    if (index < 0 || index >= size)
        throw "Index out of Range";

    YoneticiListesiNode *del;
    if (index == 0)
    {
        del = head;
        head = head->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }
    }
    else
    {
        YoneticiListesiNode *prv = FindPreviousByPosition(index);
        del = prv->next;
        prv->next = del->next;

        if (del->next != NULL)
        {
            del->next->prev = prv;
        }
    }

    size--;
    delete del;
}

int YoneticiListesi::CountLines()
{
    int count = 0;
    ifstream file(this->filename);
    string lines;

    while (getline(file, lines))
        ++count;

    file.close();
    return count;
}

void YoneticiListesi::calAverage(SatirListesi *list)
{
    double sum = 0;

    for (int i = 0; i < list->Count(); i++)
    {
        sum += list->elementAt(i);
    }

    list->listAverage = sum / list->Count();
}

void YoneticiListesi::sortFile()
{
    for (int i = 0; i < this->Count(); i++)
    {
        this->elementAt(i)->calAverage();
    }
    int rowcounter = Count();

    for (int i = 0; i < rowcounter - 1; i++)
    {

        for (int j = 0; j < rowcounter - 1 - i; j++)
        {
            if (this->elementAt(j)->listAverage > this->elementAt(j + 1)->listAverage)
            {
                swapNodes(&this->head, this->elementAt(j), this->elementAt(j + 1));
            }
        }
    }
}

void YoneticiListesi::swapNodes(YoneticiListesiNode **listHead, SatirListesi *x, SatirListesi *y)
{
    // y ve x aynıysa bir sey yapma
    if (x == y)
        return;

    YoneticiListesiNode *prevX = NULL, *currentX = *listHead;
    while (currentX && currentX->data != x)
    {
        prevX = currentX;
        currentX = currentX->next;
    }

    YoneticiListesiNode *prevY = NULL, *currentY = *listHead;
    while (currentY && currentY->data != y)
    {
        prevY = currentY;
        currentY = currentY->next;
    }

    // x ve y yoksa bir sey yapma
    if (currentX == NULL || currentY == NULL)
        return;

    // x head degilse
    if (prevX != NULL)
        prevX->next = currentY;
    else // y yi yeni head yap
        *listHead = currentY;

    // y listenin headi degilse
    if (prevY != NULL)
        prevY->next = currentX;
    else // x i yeni head yap
        *listHead = currentX;

    // iki pointeri degistir.
    YoneticiListesiNode *temp = currentY->next;
    currentY->next = currentX->next;
    currentX->next = temp;
}

bool YoneticiListesi::isEmpty() const
{
    return size == 0;
}

SatirListesi *YoneticiListesi::elementAt(int index)
{
    if (index < 0 || index >= size)
        throw NoSuchElement("No Such Element");

    if (index == 0)
        return head->data;

    return FindPreviousByPosition(index)->next->data;
}

void YoneticiListesi::clear()
{
    while (!isEmpty())
    {
        removeAt(0);
    }
}

YoneticiListesiNode *YoneticiListesi::getNodeIndex(int index)
{

    if (index < 0 || index >= size)
        throw NoSuchElement("No Such Element");

    return FindPreviousByPosition(index + 1);
}

void YoneticiListesi::PrintNode(int index, int coordX, int coordY)
{
    YoneticiListesiNode *liste = getNodeIndex(index);

    gotoxy(coordX, coordY);
    cout << fixed << setprecision(3);
    cout << " " << liste  << endl;

    gotoxy(coordX, coordY + 1);
    cout << "------------" << endl;

    gotoxy(coordX, coordY + 2);
    cout << "|" << liste->prev << setw(2) << " |" << endl;

    gotoxy(coordX, coordY + 3);
    cout << "------------" << endl;

    gotoxy(coordX, coordY + 4);
    cout << "|" << setw(3) << liste->data->listAverage << setw(4) << "|" << endl;

    gotoxy(coordX, coordY + 5);
    cout << "------------" << endl;

    gotoxy(coordX, coordY + 6);
    cout << "|" << liste->next << setw(2) << " |" << endl;

    gotoxy(coordX, coordY + 7);
    cout << "------------" << endl;
}

int YoneticiListesi::Count() const
{
    return size;
}

YoneticiListesi::~YoneticiListesi()
{
    clear();
}