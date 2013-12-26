#include "assotiativeArray.h"
#include "functions.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "smartPtr.h"
using namespace std;

typedef SmartPointer<MapContainer> MapContainerSharedPtr;

int main()
{
    MapContainerSharedPtr Words(new MapContainer());

    ifstream in;
    in.open("text.txt");
    string word;
    vector<char*> accumulator;
    while (in>>word)
    {
        for (string::iterator it = word.begin() ; it != word.end(); ++it)
            *it = tolower(*it);
        char *temp = strdup(word.c_str());
        word = strtok(temp, " ,.");

        temp = strdup(word.c_str());

        Words->addElement(word,0);
        Words->find(word);
        accumulator.push_back(temp);
    }
    try
    {
        Words->print();
    }
    catch(exception &exc)
    {
        cout << exc.what() <<endl;
    }

    Words->oftenSeldomOccur();
    cout<<"\nTekst razbit na "<<accumulator.size()<<" slov." <<endl;
    cout<<"Mediana: "<<MedianaFind(accumulator)<<endl;
    cout<<"Granica 30 percenril9: "<<thirtiethPerz(accumulator)<<endl;
    cout<<"Granica 70 percentil9: "<<seventiethPerz(accumulator)<<endl;


    return 0;
}
