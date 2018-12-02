#include <stdio.h>
//PList.h

namespace ece309{

class Object{
    public:
    virtual void print() {printf("Item");}
    
};

// Type of object that is a string item
class StringItem: public Object {
    public:
    const char * str;
    StringItem(const char *s= ""):str(s) {}
    void print() {printf("%s\n", str);}
};


// Type of object that is an integer item
class IntItem: public Object {
    public:
    int i;
    IntItem(int ii = 0):i(ii){}
    void print() {printf("%d\n", i); }
};


// Type of object that is a double item
class DoubleItem: public Object{
    public:
    double doub;
    DoubleItem(double dd = 0.0):doub(dd){}
    void print() {printf("Item: %lf\n", doub); }
};


// Describes one node on the PList
class PListNode{
    private:
        Object *object;
    public:
        PListNode *next;
        PListNode(Object *obj): object(obj){next = NULL;};
        PListNode* getNext(){return next;};
        Object* getObject() {return object;}
        void setNext(PListNode *n){ next = n;}
        
};

// The PList is a singly linked list that can hold strings,
// integers, and double values

class PList{
    public:
    
    // iterator can traverse through our list
    class iterator {
        private:
        PListNode *node;
        public:
        iterator(PListNode *n=NULL) { node = n; }
        Object* getObject() { return node->getObject(); }
        void increment() { node = node->next; }
        bool end() {  return node==NULL; }
        

        friend class PList;
  };
    private:
        PListNode* head;
        PListNode* tail;
    public:
        PList();
        void append(Object *o); // add an item to the end of the PList
        bool remove(Object *copy); // remove the head of the PList
        iterator begin() {return iterator(head);};
        bool empty(){return head==NULL;};
};

}