#include "assotiativeArray.h"
#include <iostream>
#include<algorithm>

using namespace std;

//----------- функция вне класса ( для сортировки map по значению )

bool cmp(const pair< string, int > &a, const pair< string, int > &b)
{
    return a.second >b.second;
}

//-------------------- MapContainer

MapContainer::MapContainer():
   syllables(new map<string,int>)
{

}

/*MapContainer::~MapContainer()
{
    cout<<"-==============";
    syllables->clear();
}
*/
void MapContainer::addElement(string ar,int value)
{
    syllables->insert(make_pair(ar,value));
}

void MapContainer::print()
{
    if(!syllables->empty())
    {
        map <string,int>::iterator cur;
        cout<<"4astota vstea4aemosti slova v tekste: "<<endl;


        for (cur= syllables->begin();  cur!= syllables->end(); cur++)
        {
            cout<<(*cur).first;
            cout<<": "<<(*cur).second<<endl;

        }
    }
    else throw MapIsEmpty();
}

bool MapContainer::find(string ar)
{
    map <string,int>::iterator cur;
    for (cur= syllables->begin(); cur!= syllables->end(); cur++)
        if((*cur).first==ar)
        {
            ++(*cur).second;
            return true;
        }

    return false;

}

void MapContainer::oftenSeldomOccur()
{
    vector<pair< string, int > >   vec(syllables->begin(), syllables->end() );
    sort(vec.begin(), vec.end(), cmp);
    unsigned counter=1,amount=20;
    cout<<endl;
    cout<<"20 naibolee 4astovstre4aemih slov: "<<endl;
    cout<<endl;
    for (vector<pair< string, int > >::iterator it=vec.begin(); counter<=amount; ++it, ++counter)
    {
        cout <<counter<<") ";
        cout<< it->first << ": " << it->second << endl;
    }
    counter=1;
    amount=vec.size()-40;
    cout<<endl;
    cout<<"40 naibolee redkih slov: "<<endl<<endl;
    for (vec[amount]; amount<vec.size(); ++amount)
    {
        cout <<counter<<") ";
        counter++;
        cout<< vec[amount].first << ": " << vec[amount].second << endl;
    }

}

