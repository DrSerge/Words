#include "functions.h"
#include <cstring>
#include <iostream>
using namespace std;

char* MedianaFind(vector <char*> accumulator)
{
    int size=accumulator.size();
    int mediana=size/2;
    return accumulator[mediana];

}

char* thirtiethPerz(vector <char*> accumulator)
{
    int size=accumulator.size();
    int perz=(size*30)/100;
    return accumulator[perz];

}
char* seventiethPerz(vector <char*> accumulator)
{
    int size=accumulator.size();
    int perz=(size*70)/100;
    return accumulator[perz];

}
