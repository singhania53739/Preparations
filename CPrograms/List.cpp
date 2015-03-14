#include <iostream>
#include "Node.cpp"
using namespace std;
int main ()
{
  Node<char> *p,*q,*r;
  // Link the nodes with each other
  q = new Node<char>('B'); // here nxtptr is passed by a nullptr by default
  p = new Node<char>('A',q);
  r = new Node<char>('C');

  // modify the list
  q->InsertAfter(r);
  /*
  Call the InsertAfter method that belongs to the object pointed by q, as
  paramater, pass to it the address contained in r.
  */

  cout << "p:" << p->data << endl;                 // "A" will be printed out
  cout << "p_next:" << p->NextNode()->data << endl;  // "B" will be printed out
  cout << "q:" << q->data << endl;                 // "B" will be printed out
  cout << "q_next:" << q->NextNode()->data << endl;  // "C" will be printed out
  cout << "r:" << r->data << endl;        
 delete q;
  delete p;
  delete r;
return 0;
}
