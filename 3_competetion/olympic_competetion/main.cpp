//Name: Nustrat Jahan Ila.
//Date: 2/18/22
//Assignemnt 3 : Creating a competition heirarchy using Operator overloading and using exception handling

//The purpose of this header file is to declare all the prototype of the function, creating OOP by providing derivation list
//and making dynamic binding


#include "olympic_competetion.h"
using namespace std;

int HashCode (const string &str) {
    int h = 0;
    for (size_t i = 0; i < str.size(); ++i)
        h = h * 31 + static_cast<int>(str[i]);
    return h;
}


int main()
{
    user_class client;
    client.main_menu();
    return 0;
}
