//Name: Nustrat Jahan Ila.
//Date: 2/18/22
//Assignemnt 3 : Creating a competition heirarchy using Operator overloading and using exception handling

#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>

using namespace std;
class ski_jumping;
int HashCode (const string &str);           // to generate a simple hash code for string comparison.
ostream& operator<<(ostream& os, const ski_jumping& sb);    //overload cout for ski_jumping




//Declaration of athlete class(base class)
class athlete    //base class athlete.
{
    public:
        athlete();  //constructor
        ~athlete();
        athlete(const  athlete & source);
        athlete & operator=(const athlete &source);
        athlete(char * name, int score, int no_of_wins); //constructor with arguments
        int get_score();  //get the score
        void set_score(int points);  //sets the score
        int get_wins();                  // getter to get no_of_wins.
        int increase_wins(int wins);            //this will increase win by 1.
        void set_name(char * t_name);
        bool check_name(char * t_name);
        int get_hash();
        //bool check_name(string t_name);

    protected:
        int top_score;                 // whatever the competeion type is there will be sort of score scores.
        int no_of_wins;             // for comparison this will get higher precedence.
        char * name;
};


//derived classes:
//Declaration of ice_dancing class
class ice_dancing : public athlete  //exam class is derived from preparation
{
    public:
        ice_dancing();  //constructor
        ~ice_dancing(); //destructor
        ice_dancing(char * name , int score , int no_of_wins, string style,char performance);
        bool operator==(const ice_dancing & obj2) const; // == operator overloading.
        bool operator!=(const ice_dancing & obj2) const;
        friend istream &operator>>(istream& is,  ice_dancing& obj2);  // cin overload
        friend ostream & operator<<(ostream& os, ice_dancing& obj2);  // cout overload
        void display();

    protected:
        string  style; //style of ice_dancing
        char perf_quality;      // A - B - C - D for quality of jump
};



//Declaration of hockey class(derived class)
class  hockey : public athlete  //derived from preparation
{
    public:
        hockey();   //constructor
        ~hockey();  //destructor
        hockey(char * name , int score , int no_of_wins,int foul_count, int shot_target);
        int add_foul(int x);
        int add_shot(int x);
        void display();
        friend istream &operator>>(istream& is,  hockey& obj2);  // cin overload
        friend ostream & operator<<(ostream& os, hockey& obj2);  // cout overload
    protected:
        int no_of_foul; //number of foul
        int shot_on_target;
};







//Declaration of hockey class(derived class)
class ski_jumping : public athlete      //derived from preparation
{
    public:
        ski_jumping();  //constructor
        ~ski_jumping(); //destructor
        ski_jumping(char * name , int score , int no_of_wins,int h, int d);
        void update_info(int h, int d);
        void display();
        bool operator==(const ski_jumping &obj2)  const;               // == operator overload
        bool operator!=(const ski_jumping &obj2)  const;                //!= operator overload
        bool operator<(const ski_jumping & obj2)const;              // < comparison overload
        bool operator>(const ski_jumping & obj2)const;             //> comparison overload
        friend istream &operator>>(istream& is,  ski_jumping& obj2);  // cin overload
        friend ostream & operator<<(ostream& os, ski_jumping& obj2);  // cout overload
        bool nohashcollision(const ski_jumping &obj2) const;
    protected:
        int height;     //the height
        int distance;   //distance travelled


};


// this is the collection of athlete who participate in hockey and used List as data structure.
class hockey_athletes
{
public:
    hockey_athletes();
    ~hockey_athletes();
    int add_athlete(hockey ha);          // adding an athlete to the list.
    void display_all();            //display all athletes in the list.
    int delete_all();            //display all athletes in the list.
    hockey * find_athlete(char* name);
    hockey * find_athlete(char* name,list<hockey>::iterator & it);
    int remove_athlete(char * athletename);           // remote an athlete from the list.
    hockey_athletes operator+( const hockey& hockey_athlete) ;    //+ operator overload to add an athlete to the list
    hockey_athletes & operator+=( const hockey& hockey_athlete);    //+ operator overload to add an athlete to the list
protected:
    void display_all(list<hockey>::iterator & it);            //display all athletes in the list.
    //int delete_all(list<hockey>::iterator & it);            //display all athletes in the list.
    int remove_athlete(list<hockey>::iterator & it,char * athletename) ;// wrapper for removing athlete
    list<hockey> list_hockey_athletes;
    int num_athlete;
};

// this is the collection of athlete who participate in hockey and used vector as data structure.
class ice_dancing_athletes
{
public:
    ice_dancing_athletes();
    ~ice_dancing_athletes();
    ice_dancing * find_athlete(char* name);
    ice_dancing * find_athlete(char* name,vector<ice_dancing>::iterator & it);
    int add_athlete(ice_dancing id);          // adding an athlete to the list.
    void display_all();            //display all athletes in the list.
    int delete_all();           // deleting all athlete
    int get_count();                // get the number of athlete in the vector;
    int remove_athlete(char * athletename)  ;// remote an athlete from the list.
protected:
    remove_athlete(vector<ice_dancing>::iterator & it,char * athletename);           // remote an athlete from the vector.
    void display_all(vector<ice_dancing>::iterator & it)  ;
    //int delete_all(vector<ice_dancing>::iterator & it)  ;
    vector<ice_dancing> vector_hockey_athletes;
};



// this is to build the tree
// red black tree implementation   to get the tree balanced.
// this node will be used only for ski_jumping
struct tree_node {
  ski_jumping data;
  tree_node *parent;
  tree_node *left;
  tree_node *right;
  int color;
};


// this will have an tree for my athletes. Custom ADT implemenetation. this is a red black tree
// used a hash function to sort out the athlete and put into the tree and use the same to find out in the tree as well.
class ski_jumping_athlete_tree
{
public:
    ski_jumping_athlete_tree();
    ~ski_jumping_athlete_tree();
    ski_jumping_athlete_tree(const ski_jumping_athlete_tree &source);
    void add_athlete(ski_jumping data);
    ski_jumping * find_athlete(char * name);
    void display_tree();
    void delete_all();

protected:
    ski_jumping * find_athlete(char * name,tree_node *x);
    void delete_all(tree_node* x);
    tree_node * root;
    tree_node * t_root;
    void leftRotate(tree_node * x);
    void rightRotate(tree_node * x);
    void balance_after_insert(tree_node * k); //                balancing tree after inserting items
    void display_tree(tree_node * root, string indent, bool last);
    void add_athlete(tree_node *& x , tree_node *&y , tree_node *& node);
 };

//this class manage all the user interacation and all the threee data collection used in this project.
class user_class
{
public:
    // this is main menu
   void main_menu();
   void ski_jump_menu();
   void hockey_menu();
   void ice_dance_menu();

private:
    hockey_athletes  ha;                //this will contain list (STL) collection of athlets
    ice_dancing_athletes  ida;          //this will contain vector (STL) collection of athlets
    ski_jumping_athlete_tree  sja;      //this will contain custom implementation of balance tree collection of athlets
};

