/*this is a bst program
 *Trevor Horine
 *3/15/18
 */
#include <iostream>
#include <cstring>
#include <fstream>
#include "node.h"
#include <math.h>

using namespace std;

void print(node*, int, int);
void add(node*);

//main mentod
int main(){
  node* root = new node();
  root -> setvalue(NULL);
  int input;
  cout << "enter a number between 1 and 1000 to add to the tree" << endl;
  cin >> input;
  node* temp = new node();
  temp -> setvalue(input);
  add(temp)
}
//method to add
void add(node* current){
  if(root == NULL){
    root = current;
  }
  
}
//method to print tree
void print(node* current, int d, int y){
  if(current -> getleft() != NULL){
    print(current-> getleft(), d+1, y);
  }
  int t = d;
  for(t; t>0; t--){
    cout << "\t";
  }
  cout << current -> getvalue() << endl;
  if(current -> getright() != NULL){
    print(current -> getright(), d+1, y);
  }
}
