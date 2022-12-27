/**
* @file ReadAndAdd.cpp
* @description Dosyadan sayilari okur ve satir listesine aktarir.
* @course 1. Ogretim A Grubu
* @assignment 1.Odev
* @date 19.11.2022
* @author Korhan Temiz	/ korhan.temiz@ogr.sakarya.edu.tr
*/
#include "ReadAndAdd.hpp"

ReadAndAdd::ReadAndAdd(string filename)
{
    this->filename = filename;
    int numlines = countLines();
    this->lines = new SatirListesi *[numlines];
    for (int i = 0; i < numlines; i++)
    {
        this->lines[i] = new SatirListesi();
    }
    readLine();
}

int ReadAndAdd::countLines()
{
    int count = 0;
    ifstream file(this->filename);
    string lines;
    while (getline(file, lines))
        ++count;

    file.close();
    return count;
}

void ReadAndAdd::readLine()
{
    string split;
    ifstream file(this->filename);
    string line;
    int index = 0;
    while (getline(file, split))
    {
        istringstream ss(split);

        while (getline(ss, line, ' '))
        {
            this->lines[index]->add(stoi(line));
        }
        index++;
    }

    file.close();
}

SatirListesi **ReadAndAdd::getLine()
{
    int numlines = countLines();
    for (int i = 0; i < numlines; i++)
    {
        //lines[i]->calAverage();
    }
    return lines;
}

SatirListesi **ReadAndAdd::sortFile()
{
    int numlines = countLines();
    SatirListesi *tmp;
    for (int i = 0; i < numlines; i++)
    {
        lines[i]->calAverage();
    }

    for (int i = 0; i < numlines - 1; i++)
    {

        for (int j = 0; j < numlines - 1 - i; j++)
        {

            if (lines[j]->listAverage > lines[j + 1]->listAverage)
            {
                tmp = lines[j];
                lines[j] = lines[j + 1];
                lines[j + 1] = tmp;
            }
        }
    }

    return lines;
}

ReadAndAdd::~ReadAndAdd()
{
    if (lines != 0)
    {

        int count = countLines();
        for (int i = 0; i < count; i++)
        {

            if (lines[i] != 0)

                delete lines[i];
        }
        delete[] lines;
    }
}