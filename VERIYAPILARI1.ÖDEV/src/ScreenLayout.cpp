/**
 * @file ScreenLayout.cpp
 * @description Konsolda istenilen formatta cikti alabilmemiz icin gerekli islemleri yapar.
 * @course 1. Ogretim A Grubu
 * @assignment 1.Odev
 * @date 13.11.2022
 * @author Korhan Temiz / korhan.temiz@ogr.sakarya.edu.tr
 */
#include "ScreenLayout.hpp"

ScreenLayout::ScreenLayout(YoneticiListesi *Yoneticilistesi)
{
    this->Yoneticilistesi = Yoneticilistesi;
    if (this->Yoneticilistesi->Count() < 8)
    {
        this->finishPosition = this->Yoneticilistesi->Count();
    }
    else
    {
        this->finishPosition = 8;
    }
    this->startposition = 0;
    this->selectedNode = 0;
}

void ScreenLayout::gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ScreenLayout::Layout()
{
    int PageNum = selectedNode / 8;

    this->startposition = 8 * PageNum;
    this->finishPosition = 8 * (PageNum + 1);
    if (this->finishPosition >= this->Yoneticilistesi->Count())
    {
        this->finishPosition = this->Yoneticilistesi->Count();
    }
}

void ScreenLayout::PageItr(int current)
{
    if (current == 0)
    {
        for (int i = 0; i < 8; ++i)
        {
            this->NodeItr(0);
        }
    }
    else if (current == 1)
    {
        for (int i = 0; i < 8; ++i)
        {
            this->NodeItr(1);
        }
    }
}

void ScreenLayout::NodeItr(int current)
{
    if (current == 0)
    {
        if (selectedNode >= this->Yoneticilistesi->Count() - 1)
        {
            return;
        }

        selectedNode++;
        Layout();
    }
    else if (current == 1)
    {
        if (selectedNode <= 0)
        {
            return;
        }
        selectedNode--;
        Layout();
    }
    else if (current == 2)
    {
        Layout();
    }
}

void ScreenLayout::printList()
{
    int count = Yoneticilistesi->Count();

    system("cls");

    if (count == 0)
    {
        cout << "Liste bitti"<<endl;
        exit(1);
        return;
    }
    gotoxy(0, 0);

    if (this->startposition == 0)
    {
        cout << "ilk";
    }
    else
    {
        cout << "<---";
    }

    int currentNodeNumber = this->finishPosition - this->startposition;
    currentNodeNumber = currentNodeNumber * 14 + 1;

    gotoxy(currentNodeNumber, 0);

    if (this->finishPosition == Yoneticilistesi->Count())
    {

        cout << "son";
    }
    else
    {
        cout << "--->";
    }
    for (int i = this->startposition; i < this->finishPosition; i++)
    {
        int remainder = i % 8;
        this->Yoneticilistesi->PrintNode(i, 15 * remainder, 2);
    }

    this->currentNode((this->selectedNode % 8) * 15, 10);
}

void ScreenLayout::RemoveList()
{
    this->Yoneticilistesi->removeAt(this->selectedNode);
    this->NodeItr(2);

    if (this->selectedNode == this->finishPosition)
    {
        this->selectedNode--;
    }
    this->NodeItr(2);
}

void ScreenLayout::currentNode(int x, int y)
{
    this->Yoneticilistesi->elementAt(this->selectedNode)->print(x, y);
}

int ScreenLayout::printRandomNode()
{
    int random = this->Yoneticilistesi->randomIndex(this->selectedNode);
    int xPosition = ((this->selectedNode % 8) + 1) * 16;
    int yPosition = (random)*6;
    yPosition += 12;
    gotoxy(xPosition, yPosition);
    cout << "<--silinecek secili";
    yPosition = this->Yoneticilistesi->elementAt(this->selectedNode)->Count() * 6 + 12;

    gotoxy(0, yPosition - 1);

    return random;
}

void ScreenLayout::RemoveRandom(int number)
{
    if (this->Yoneticilistesi->elementAt(this->selectedNode)->Count() == 1)
    {
        this->RemoveList();
        return;
    }
    this->Yoneticilistesi->removeRandomNode(this->selectedNode, number);
}