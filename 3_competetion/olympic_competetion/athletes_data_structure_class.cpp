//Name: Nustrat Jahan Ila.
//Date: 2/18/22
//Assignemnt 3 : This file covers 2 STL data structure implementation one is List and the other is vector.


#include "olympic_competetion.h"




// hockey_athletes - this contains all the athlets who is participating in hockey competetion.
// data structure used in this class is list from STL
hockey_athletes::hockey_athletes()
{

}


hockey_athletes::~hockey_athletes()
{

}


int hockey_athletes::add_athlete(hockey ha)          // adding an athlete to the list.
{
    list_hockey_athletes.push_front(ha);
    return 0;
}


void hockey_athletes::display_all()            //display all athletes in the list.
{
    list<hockey>::iterator it = list_hockey_athletes.begin();
    display_all(it);

}


void hockey_athletes::display_all(list<hockey>::iterator & it)            //display all athletes in the list.
{

    if(it==list_hockey_athletes.end())
        return;
    cout<<*it;
    it++;
    display_all(it);
}

int hockey_athletes::delete_all()
{
    list_hockey_athletes.erase(list_hockey_athletes.begin(),list_hockey_athletes.end());
    return 0;
}

hockey * hockey_athletes :: find_athlete(char* t_name,list<hockey>::iterator & it)
{
   if(it==list_hockey_athletes.end())
        return nullptr;
    if(it->check_name(t_name))
        return &*it;
    else
    {
        it++;
        return find_athlete(t_name,it);
    }
}

hockey * hockey_athletes :: find_athlete(char* t_name)
{
    list<hockey>::iterator it = list_hockey_athletes.begin();
    return find_athlete(t_name,it);
}


int hockey_athletes::remove_athlete(char * athletename)           // remote an athlete from the list.
{
    list<hockey>::iterator it = list_hockey_athletes.begin();
    return remove_athlete(it,athletename);
}


//removing an athlete. here using iterator first find the athlete to remove from name.
int hockey_athletes::remove_athlete(list<hockey>::iterator & it,char * athletename)           // remote an athlete from the list.
{
    int x = 0;
   if(it==list_hockey_athletes.end())
        return x;
    hockey h = *it;
    if(h.check_name(athletename))
    {
        cout<<"erasing name here"<<endl;
        it = list_hockey_athletes.erase(it);
        x = 1;
    }
    else
    {
        it++;
        x = remove_athlete(it,athletename);
    }
    return x;
}

// + overload to add an athlete to the list.
hockey_athletes & hockey_athletes::operator+=(const hockey& hockey_athlete)     //+ operator overload to add an athlete to the list
{
    add_athlete(hockey_athlete);
    //cout<<"before: "<<list_hockey_athletes.size()<<endl;
    return *this;
}


// += overload to add athlete to a list.
hockey_athletes  hockey_athletes::operator+( const hockey& hockey_athlete)    //+ operator overload to add an athlete to the list
{

    hockey_athletes t_hockey_athletes(*this);   // creating a new hockey athletes object with the same
    t_hockey_athletes.add_athlete(hockey_athlete);
    return t_hockey_athletes ;
}




// ice_dancing class that has a collection of athlets .
//data structure used in this class is vector from STL
ice_dancing_athletes::ice_dancing_athletes()
{

}
ice_dancing_athletes::~ice_dancing_athletes()
{
    delete_all();
}

int ice_dancing_athletes :: get_count()
{
    return vector_hockey_athletes.size();
}

int ice_dancing_athletes :: delete_all()
{
    vector_hockey_athletes.erase(vector_hockey_athletes.begin(),vector_hockey_athletes.end());
    return 0;
}



int ice_dancing_athletes::add_athlete(ice_dancing id)         // adding an athlete to the vector.
{
    vector_hockey_athletes.push_back(id);
    return vector_hockey_athletes.size();
}

void ice_dancing_athletes::display_all()            //display all athletes in the vector.
{
    vector<ice_dancing>::iterator it = vector_hockey_athletes.begin();
    display_all(it);
}
void ice_dancing_athletes::display_all(vector<ice_dancing>::iterator & it)            //display all athletes in the vector.
{

    if(it==vector_hockey_athletes.end())
        return;
    cout<<*it;
    it++;
    display_all(it);
}

int ice_dancing_athletes :: remove_athlete(char * athletename)           // remote an athlete from the vector.
{
    vector<ice_dancing>::iterator it = vector_hockey_athletes.begin();
    return remove_athlete(it,athletename);
}


//removing an athlete. here using iterator first find the athlete to remove from name.
int ice_dancing_athletes :: remove_athlete(vector<ice_dancing>::iterator & it,char * athletename)           // remote an athlete from the vector.
{
    int x = 0;
   if(it==vector_hockey_athletes.end())
        return x;
    ice_dancing id = *it;
    if(id.check_name(athletename))
    {
        cout<<"erasing "<<athletename<<endl;
        it = vector_hockey_athletes.erase(it);
        x = 1;
    }
    else
    {
        it++;
        x = remove_athlete(it,athletename);
    }
    return x;
}

ice_dancing * ice_dancing_athletes :: find_athlete(char* name)
{
    vector<ice_dancing>::iterator it = vector_hockey_athletes.begin();
    return find_athlete(name,it);
}
ice_dancing * ice_dancing_athletes :: find_athlete(char* t_name,vector<ice_dancing>::iterator & it)
{
   if(it==vector_hockey_athletes.end())
        return nullptr;
    if(it->check_name(t_name))
        return &*it;
    else
    {
        it++;
        return find_athlete(t_name,it);
    }
}


