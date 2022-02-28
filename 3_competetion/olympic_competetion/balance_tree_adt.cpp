//Name: Nustrat Jahan Ila.
//Date: 2/18/22
//Assignemnt 3 : This file contains the implimentation of the custom tree ADT.
// This file implements the custom

#include "olympic_competetion.h"

//constructor function for ski jumping athlete tree.
ski_jumping_athlete_tree :: ski_jumping_athlete_tree()
{
    t_root = new tree_node;
    t_root->color = 0;
    t_root->parent = nullptr;
    t_root->left = nullptr;
    t_root->right = nullptr;
    root = t_root;
}

//destructor
ski_jumping_athlete_tree :: ~ski_jumping_athlete_tree()

{
    delete t_root;
    delete root;
}


 //For balancing the tree after insertion
 //one letter var name used here to easy read.
//wrapper function for balancing tree after every insert.
void ski_jumping_athlete_tree :: balance_after_insert(tree_node * k)
{
    tree_node * u;
    balance_after_insert(k,u);
    root->color = 0;
}

// For balancing the tree after insertion recursive function.
void ski_jumping_athlete_tree :: balance_after_insert(tree_node *& k,tree_node * &u)
{
    if(!k->parent)
        return;
    if(k->parent->color != 1)
        return;
    if (k->parent == k->parent->parent->right)
    {
        u = k->parent->parent->left;
        if (u->color == 1)
        {
            u->color = 0;
            k->parent->color = 0;
            k->parent->parent->color = 1;
            balance_after_insert(k->parent->parent,u);      //recursive function call
        }
        else
        {
            if (k == k->parent->left)
            {
                k = k->parent;
                rightRotate(k);
            }
            k->parent->color = 0;
            k->parent->parent->color = 1;
            leftRotate(k->parent->parent);
        }
    }
    else
    {
        u = k->parent->parent->right;
        if (u->color == 1)
        {
            u->color = 0;
            k->parent->color = 0;
            k->parent->parent->color = 1;
            balance_after_insert(k->parent->parent,u);       //recursive function call
        }
        else
        {
            if (k == k->parent->right)
            {
                k = k->parent;
                leftRotate(k);
            }
            k->parent->color = 0;
            k->parent->parent->color = 1;
            rightRotate(k->parent->parent);
        }
    }
    if (k == root)
    {
        return;
    }
}

// display tree function with recursive call.
void ski_jumping_athlete_tree :: display_tree(tree_node * root, string indent, bool last)
{
    if (root != t_root) {
      cout << indent;
      if (last) {
        cout << "R----";
        indent += "   ";
      } else {
        cout << "L----";
        indent += "|  ";
      }

      string sColor = root->color ? "[R]" : "[B]";
      cout << sColor <<root->data << endl;
      display_tree(root->left, indent, false);
      display_tree(root->right, indent, true);
    }
}

ski_jumping * ski_jumping_athlete_tree :: find_athlete(char * name)
{
    if(name)
        return find_athlete(name,root);
    else
        return nullptr;
}

ski_jumping * ski_jumping_athlete_tree :: find_athlete(char * name,tree_node * x)
{
    ski_jumping * t_sj=nullptr;
    if(x==nullptr)
        return nullptr;
    int x_hash = x->data.get_hash();
    int y_hash = HashCode(name);
    if(x->data.check_name(name))
        return &(x->data);
    if(y_hash<x_hash)
    {
        t_sj = find_athlete(name,x->left);
    }
    else
    {
        t_sj = find_athlete(name,x->right);
    }
    return t_sj;
}


void ski_jumping_athlete_tree :: delete_all()
{
    if(root)
        delete_all(root);
}

int ski_jumping_athlete_tree :: remove_athlete(char * t_name)
{
    // Not implemented as not required as part of this project for balance tree.
    cout<<"delete item from the tree is not implemented "<<endl;


}
//recursive fuction for deleting all items from the tree
void ski_jumping_athlete_tree :: delete_all(tree_node* &x)
{
    if (x == nullptr)
        return;
    if(x->left)
        delete_all(x->left);
    if(x->right)
        delete_all(x->right);
    if(!x->left && !x->right)
    {
        delete x;
        x=nullptr;

    }
}

// wrapper funciont for display the tree.
void ski_jumping_athlete_tree :: display_tree() {
    if (root) {
      display_tree(this->root, "", true);
    }
  }
// this function is to rotate the root left direction.
// This is a helper function for red black tree.
void ski_jumping_athlete_tree :: leftRotate(tree_node * x) {
    tree_node * y = x->right;
    x->right = y->left;
    if (y->left != t_root) {
      y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
      this->root = y;
    } else if (x == x->parent->left) {
      x->parent->left = y;
    } else {
      x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
  }


// this function is to rotate the root right direction.
// This is a helper function for red black tree.
void ski_jumping_athlete_tree :: rightRotate(tree_node * x) {
    tree_node * y = x->left;
    x->left = y->right;
    if (y->right != t_root) {
      y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
      this->root = y;
    } else if (x == x->parent->right) {
      x->parent->right = y;
    } else {
      x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
  }



//recursive function to add an athelete.
void ski_jumping_athlete_tree :: add_athlete(tree_node *& x , tree_node *&y , tree_node *& node)
{
    if(x==t_root)
    {
        node->parent = y;
        if (y == nullptr) {
          root = node;
        } else if (node->data < y->data) {
          y->left = node;
        } else {
          y->right = node;
        }
        return;
    }
    else
    {
        y = x;
        if(node->data<x->data)
            add_athlete(x->left,y,node);
        else
            add_athlete(x->right,y,node);
    }


}



// Inserting a ski jumping athlete.
void ski_jumping_athlete_tree :: add_athlete(ski_jumping athlete) {
    tree_node * node = new tree_node;
    node->parent = nullptr;
    node->data = athlete;
    node->left = t_root;
    node->right = t_root;
    node->color = 1;

    tree_node * y = nullptr;
    tree_node * x = this->root;
    add_athlete(x,y,node);
    if (node->parent == nullptr) {
      node->color = 0;
      return;
    }

    if (node->parent->parent == nullptr) {
      return;
    }

    balance_after_insert(node);
  }





