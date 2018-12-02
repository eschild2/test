#include "PList.h"
// PList.cpp
// I would like to note that this file is not very long
// because most of my member functions in my classes
// are only a line of code long and I left them in the
// header file PList.h

// This is the source code file for PList.h. It defines
// some of the functions that were too long to define in
// PList.h. PList is a class that describes a singly linked
// list that can hold strings, integers, and doubles

namespace ece309{
PList::PList()
{
  // start with an empty list
  head = NULL;
  tail = NULL;
}
// adds an item to the end of the list
void PList::append(Object *a){
  PListNode *node = new PListNode(a);
  if (head == NULL)
    {
      // list is empty
      head = node;
      tail = node;
    }
  else
    {
      tail->setNext(node);
      tail = node;
    }
}

// removes the head of the list
bool PList::remove(Object* copy)
{
  if (!empty()) // if list is not empty
    {
      copy = head->getObject(); // return copy
      PListNode *tmp = head->getNext();
      delete head; // delete the node
      head = tmp;  // update the head
      if (tmp==NULL) // removed last element
	  tail = NULL;
      return true;
    }
  return false; // nothing in list
}

}