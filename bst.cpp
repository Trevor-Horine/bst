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

void print(node*, int);
void add(node*, node*);
void remove(node*, node*);
node* min(node*);

//main mentod
int main(){
  node* root = new node();
  root -> setvalue(NULL);
  int input;
  char in[10];
  bool w = true;
  while(w == true){
    cout << "do you want to add, remove, or quit?" << endl;
    for (int i = 0; i < 10; i++){
      in[i] = NULL;
    }
    cin >> in;
    for (int i = 0; i < 10; i++){
      in[i] = toupper(in[i]);
    }
    if(strcmp(in, "ADD") == 0){
      cout << "enter a number between 1 and 1000 to add to the tree" << endl;
      input = NULL;
      cin >> input;
      node* temp = new node();
      temp -> setvalue(input);
      add(temp, root);
      print(root, 0);
    }
    else if(strcmp(in, "REMOVE") == 0){
      cout << "enter a number you would like to remove from the tree" << endl;
      input = NULL;
      cin >> input;
      node* temp = new node();
      temp -> setvalue(input);
      if (root -> getvalue() != NULL){
	remove(temp, root);
	if(root -> getvalue() == 0){
	  root = NULL;
	}
	if (root != NULL){
	  print(root, 0);
	}
      }
      else{
	cout << "that is not in the tree" << endl;
      }
    }
    else if(strcmp(in, "QUIT") == 0){
      w = false;
    }
  }
}

//method to add nodes to tree
void add(node* current, node* tcurrent){
  if(tcurrent -> getvalue() == NULL){
    tcurrent -> setvalue(current -> getvalue());
  }
  else if(tcurrent -> getvalue() > current -> getvalue()){
    if(tcurrent -> getleft() == NULL){
      node* temp = new node();
      temp -> setprev(tcurrent);
      tcurrent -> setleft(temp);
    }
    tcurrent = tcurrent -> getleft();
    add(current, tcurrent);
  }
  else if(tcurrent -> getvalue() < current -> getvalue()){
    if(tcurrent -> getright() == NULL){
      node* temp = new node();
      temp -> setprev(tcurrent);
      tcurrent -> setright(temp);
    }
    tcurrent = tcurrent -> getright();
    add(current, tcurrent);
  }
}

//method to remove nodes from tree
void remove(node* re, node* tcurrent){
  if(re -> getvalue() == tcurrent -> getvalue()){
    if(tcurrent -> getprev() == NULL){
      tcurrent -> setvalue(NULL);
    }
    else if(tcurrent -> getleft() == NULL){
      tcurrent -> getprev() -> setright(tcurrent -> getright());
    }
    else if(tcurrent -> getright() == NULL){
      tcurrent -> getprev() -> setleft(tcurrent -> getleft());
    }
    else if(tcurrent -> getright() != NULL && tcurrent -> getleft() != NULL){
      tcurrent -> setvalue(min(tcurrent)-> getvalue());
      min(tcurrent) -> getprev() -> setleft(NULL); 
    }
  }
  else if(re-> getvalue() > tcurrent -> getvalue()){
    tcurrent = tcurrent -> getright();
    remove(re, tcurrent);
  }
  else if(re -> getvalue() < tcurrent -> getvalue()){
    tcurrent = tcurrent -> getleft();
    remove(re, tcurrent);
  }
}

//method to print tree
void print(node* current, int d){
  cout << "TREE" << endl;
  if(current -> getleft() != NULL){
    print(current-> getleft(), d+1);
  }
  int t = d;
  for(t; t>0; t--){
    cout << "\t";
  }
  cout << current -> getvalue() << endl;
  if(current -> getright() != NULL){
    print(current -> getright(), d+1);
  }
}

//method to find smalles node is right sub tree
node* min (node* current){
  if(current-> getleft() != NULL){
    return min(current -> getleft());
  }
  return current;
}
