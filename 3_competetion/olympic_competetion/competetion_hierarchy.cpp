//Name: Nustrat Jahan Ila.
//Date: 2/18/22
//Assignemnt 3 : Creating a competition heirarchy of class using Operator overloading and using exception handling
// the file contains only the base class and the three derived hierarchy class.

#include "olympic_competetion.h"


// All the base class implementation goes here which is a class for athlete.
athlete::athlete()  //constructor without argument
{
    name = nullptr;
}

athlete::athlete(const athlete & source) //copy constructor
{
    name = nullptr;
    if(source.name)
        name = new char [strlen(source.name)+1];
    strcpy(name,source.name);
    no_of_wins = source.no_of_wins;
    top_score = source.top_score;
}

//assignment operator overloaded.
athlete & athlete::operator=(const athlete & source)     // = operator overload and this comparison will ignore the name for comparison purpse.
{
    if(!name)
        delete[] name;
    if(source.name)
        name = new char [strlen(source.name)+1];
    strcpy(name,source.name);
    no_of_wins = source.no_of_wins;
    top_score = source.top_score;
    return *this;
}

//constructor with all the argument.
athlete::athlete(char * ath_name, int score, int wins)
{
    if(ath_name)
    {
        name = new char [strlen(ath_name)+1];
        strcpy(name,ath_name);
    }
    no_of_wins = wins;
    top_score = score;
}


athlete::~athlete() ////destructor
{
    if(name)
        delete[] name;
}




//setter for top_score.
void athlete::set_score(int points)
{
    top_score = points;
    return;
}
//getter for top_score.
int athlete::get_score()
{
    return top_score;
}
//return no_of wins.
int athlete::get_wins()
{
    return no_of_wins;
}
void athlete::set_name(char *t_name)
{
    if(name)
       delete [] name;
    name = new char[strlen(t_name) - 1];
    strcpy(name,t_name);
}

// check for the name if the parameter passed is matched with the name.
bool athlete::check_name(char * t_name)
{
    return !strcmp(t_name,name);
}

int athlete :: get_hash()
{
    return HashCode(name);
}

// this will inchrease the number of wins for a athlete.
int athlete::increase_wins(int wins)
{
    no_of_wins += wins;
    return no_of_wins;
}







//derived classes:
//Declaration of ice_dancing class
ice_dancing::ice_dancing(char * name , int score , int wins, string st,char performance):athlete(name,score,wins)
{
    perf_quality=performance;
    style = st;
}

ice_dancing::ice_dancing()  //constructor
{

}
ice_dancing::~ice_dancing() //destructor
{

}
/*
ice_dancing & ice_dancing::operator=(const ice_dancing & obj2) //operator overloading of = operator
{
    if(this==&obj2)
        return *this;
    if(obj2)
        delete [] style;
    style = new char[strlen(obj2.style)+1];
    strcpy(style,obj2.style);

}
*/

void ice_dancing::display()
{
    cout<< "[icedance] Name: "<<name<< " TopScore: "<<top_score<<" Total win: "<<no_of_wins<<" Style: "<<style<<" Performance Q: "<<perf_quality<<endl;
}

// for == operator name is not taken under consideration.
// for comparing name and style is ignored by design.
bool ice_dancing::operator==(const ice_dancing & obj2) const // == operator overloading.
{
    bool res = true;
    if(obj2.top_score!=top_score)
        res = false;
    if(obj2.no_of_wins!=no_of_wins)
        res = false;
    if(obj2.perf_quality!=perf_quality)
        res = false;
    return res;
}

// for != operator name is not taken under consideration.
bool ice_dancing::operator!=(const ice_dancing & obj2) const
{
    bool res = true;
    if(obj2.top_score!=top_score)
        res = false;
    if(obj2.no_of_wins!=no_of_wins)
        res = false;
    if(obj2.perf_quality!=perf_quality)
        res = false;
        /*
    if(strcmp(obj2.style,style))
        res = false;
        */
    return !res;

}


void hockey::display()
{
    cout<< "[hockey] Name: "<<name<< " TopScore: "<<top_score<<" Total win: "<<no_of_wins<<" No of fouls: "<<no_of_foul<<" Shot on Target: "<<shot_on_target<<endl;
}

istream & operator>>(istream& is,  ice_dancing& athlt)  // cin overload
{
    //char * name , int score , int wins,int h, int d):athlt(name,score,wins)
        char* data = new char[101];
        char* t_name = new char[101];
        int t_score;
        int t_wins;
        int res;
        string t_style;
        char t_perf;
        is.getline(t_name,100,' ');
        is.getline(data,100,' ');
        res =sscanf(data, "%d", &t_score);
        if(res!=1)
        {
            is.ignore(100,'\n');
            throw invalid_argument("Top Score is invalid.[not an integer or extra space]");
        }
        is.getline(data,100,' ');
        res =sscanf(data, "%d", &t_wins);
        if(res!=1)
        {
            is.ignore(100,'\n');
            throw invalid_argument("No of Wins is invalid.[not an integer or extra space]");
        }
        is.getline(data,100,' ');
        t_style = data;
        is.getline(data,100,'\n');
        res =sscanf(data, "%c", &t_perf);
        t_perf = toupper(t_perf);
        if(strlen(data)>1)
        {
            throw invalid_argument("perf grade is single letter");
        }
        else if(t_perf<65||t_perf>68)
        {
            throw invalid_argument("perf grade is not valid[A-D]");
        }
        athlt = ice_dancing(t_name,t_score,t_wins,t_style,t_perf);
        delete[] t_name;
        delete[] data;
        return is;
}
ostream & operator<<(ostream& os, ice_dancing& athlt)  // cout overload
{
   os<< "[hockey] Name: "<<athlt.name<< " TopScore: "<<athlt.top_score<<" Total win: "<<athlt.no_of_wins<<" Style: "<<athlt.style<<" Performance Grade: "<<athlt.perf_quality<<endl;
    return os;
}





//implementation of hockey class(derived class)
hockey::hockey()   //constructor
{

}
hockey::~hockey()  //destructor
{

}
hockey::hockey(char * name , int score , int wins,int foul_count, int shot_target):athlete(name,score,wins)
{
    no_of_foul = foul_count;
    shot_on_target = shot_target;
}

int hockey :: add_foul(int x)
{
    no_of_foul += x;
    return no_of_foul;
}

int hockey :: add_shot(int x)
{
    shot_on_target += x;
    return shot_on_target;
}

istream & operator>>(istream& is,  hockey& athlete)  // cin overload
{
    //char * name , int score , int wins,int h, int d):athlete(name,score,wins)
        char* data = new char[101];
        char* t_name = new char[101];
        int t_score;
        int t_wins;
        int t_foul;
        int t_shot;
        int res;
        is.getline(t_name,100,' ');
        is.getline(data,100,' ');
        res =sscanf(data, "%d", &t_score);
        if(res!=1)
        {
            is.ignore(100,'\n');
            throw invalid_argument("Top Score is invalid.[not an integer or extra space]");
        }
        is.getline(data,100,' ');
        res =sscanf(data, "%d", &t_wins);
        if(res!=1)
        {
            is.ignore(100,'\n');
            throw invalid_argument("No of wins is invalid.[not an integer or extra space]");
        }
        is.getline(data,100,' ');
        res =sscanf(data, "%d", &t_foul);
        if(res!=1)
        {
            is.ignore(100,'\n');
            throw invalid_argument("No of Foul is invalid.[not an integer or extra space]");
        }
        is.getline(data,100,'\n');
        res =sscanf(data, "%d", &t_shot);
        if(res!=1)
        {

            throw invalid_argument("shot on target is invalid.[not an integer or extra space]");
        }
        athlete.set_name(t_name);
        athlete.top_score = t_score;
        athlete.no_of_wins = t_wins;
        athlete.no_of_foul = t_foul;
        athlete.shot_on_target = t_shot;
        delete[] data;
        delete [] t_name;
        return is;
}
ostream & operator<<(ostream& os, hockey& athlete)  // cout overload
{
   os<< "[Hockey] Name: "<<athlete.name<< " TopScore: "<<athlete.top_score<<" Total win: "<<athlete.no_of_wins<<" No of fouls: "<<athlete.no_of_foul<<" Shot on Target: "<<athlete.shot_on_target<<endl;
    return os;
}




//implementation of ski_jumping class(derived class)

ski_jumping::ski_jumping()  //constructor
{

}
ski_jumping::~ski_jumping() //destructor
{

}
ski_jumping::ski_jumping(char * name , int score , int wins,int h, int d):athlete(name,score,wins)
{
    height = h;
    distance =d;

}
void ski_jumping::update_info(int h , int d)
{
    height = h;
    distance = d;
}


// overload == operator but ignoring the name while comparing.
bool ski_jumping::operator==(const ski_jumping &obj2)  const               // == operator overload
{
    bool res = true;
    if(obj2.top_score!=top_score)
        res = false;
    if(obj2.no_of_wins!=no_of_wins)
        res = false;
    if(obj2.height!=height)
        res = false;
    if(obj2.distance!=distance)
        res = false;
    return res;
}
// overload != operator but ignoring the name while comparing.
bool ski_jumping::operator!=(const ski_jumping &obj2)  const                //!= operator overload
{
    bool res = true;
    if(obj2.top_score!=top_score)
        res = false;
    if(obj2.no_of_wins!=no_of_wins)
        res = false;
    if(obj2.height!=height)
        res = false;
    if(obj2.distance!=distance)
        res = false;
    return !res;
}

// this method is used for making sure if there is hash collision during insert.
bool ski_jumping::nohashcollision(const ski_jumping &obj2) const
{
    int thishash = HashCode(name);
    int obj2hash = HashCode(obj2.name);
    return (thishash!=obj2hash);
}
// this will compare two ski_jumping object for comparing and it is using hash function on name
// hash collision is not taken care here.
bool ski_jumping::operator<(const ski_jumping & obj2)const              // < comparison overload
{
    int thishash = HashCode(name);
    int obj2hash = HashCode(obj2.name);
    return (thishash<obj2hash);
}

// this will compare two ski_jumping object for comparing and it is using hash function on name
bool ski_jumping::operator>(const ski_jumping & obj2)const
{
    int thishash = HashCode(name);
    int obj2hash = HashCode(obj2.name);
    return (thishash>obj2hash);
}
void ski_jumping::display()
{
    cout<< "[skijump]Athlete Name: "<<name<< " TopScore: "<<top_score<<" Total win: "<<no_of_wins<<" Height: "<<height<<" Distance: "<<distance<<endl;
}

istream & operator>>(istream& is,  ski_jumping& sj)  // cin overload
{
    //char * name , int score , int wins,int h, int d):athlete(name,score,wins)
        char* data = new char[101];
        char* t_name = new char[101];
        int t_score;
        int t_wins;
        int t_h ;
        int t_d;
        int res;
        is.getline(t_name,100,' ');
        is.getline(data,100,' ');
        res =sscanf(data, "%d", &t_score);
        if(res!=1)
        {
            is.ignore(100,'\n');
            throw invalid_argument("Top Score is invalid.[not an integer or extra space]");
        }
        is.getline(data,100,' ');
        res =sscanf(data, "%d", &t_wins);
        if(res!=1)
        {
            is.ignore(100,'\n');
            throw invalid_argument("No of Wins is invalid.[not an integer or extra space]");
        }
        is.getline(data,100,' ');
        res =sscanf(data, "%d", &t_h);
        if(res!=1)
        {
            is.ignore(100,'\n');
            throw invalid_argument("Height is invalid.[not an integer or extra space]");
        }
        is.getline(data,100,'\n');
        res =sscanf(data, "%d", &t_d);
        if(res!=1)
        {
            throw invalid_argument("Distance is invalid.[not an integer or extra space]");
        }
        sj.set_name(t_name);
        sj.top_score = t_score;
        sj.no_of_wins = t_wins;
        sj.height = t_h;
        sj.distance = t_d;
        delete[] data;
        delete[] t_name;
        return is;
}
ostream & operator<<(ostream& os, ski_jumping& sj)  // cout overload
{
   os<< "[skijump]Athlete Name: "<<sj.name<< " TopScore: "<<sj.top_score<<" Total win: "<<sj.no_of_wins<<" Height: "<<sj.height<<" Distance: "<<sj.distance<<endl;
   return os;
}


