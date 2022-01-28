#include <iostream>
#include "two_player.h"
using namespace std;

int main()
{
    cout<<"Hello:  This is a simple two player card game."<<endl;
    base_card * ac1 = new action_card("ac1");
    base_card * dc2 = new defense_card("dc2");
    base_card * sc1 = new spell_card("sc1");

    board b;
    b.discard_to_board(ac1);
    b.discard_to_board(dc2);
    b.discard_to_board(sc1);
  //  b.display_board();

    ac1->display();
    dc2->display();
    sc1->display();

    base_card * p = b.get_random_card();
    base_card * q = b.get_random_card();
    base_card * r = b.get_random_card();
    p->display();
    q->display();
    r->display();
/*


    //b.display_board();
    //game_controller gc(13);
    //gc.generate_deck();
    /*
    base_card * ac1 = new action_card("test1");
    base_card * ac2 = new action_card("test2");
    base_card * sc1 = new spell_card("spell 1");

    deck * a_deck;
    a_deck = new deck;
    a_deck->add_card(ac1);
    a_deck->add_card(ac2);
    a_deck->add_card(sc1);
    //a_deck->display();
    int x;
    if(a_deck->hascard())
    {
        base_card * &t = a_deck->get_card();
        x = t->which_card();
        cout<<"card type: "<<x<<endl;

    }
    base_card * &u = a_deck->get_card();
    x = u->which_card();
    cout<<"card type: "<<x<<endl;
    base_card * &v = a_deck->get_card();
    x = v->which_card();
    cout<<"card type: "<<x<<endl;
    if(a_deck->hascard())
    {

    base_card * &w = a_deck->get_card();
    x = w->which_card();
    cout<<"card type: "<<x<<endl;
    }
    */
    return 0;
}
