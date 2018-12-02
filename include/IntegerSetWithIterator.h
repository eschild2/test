//#ifndef INTEGERSET_H
//#define INTEGERSET_H

#include "List.h"

namespace ece309{

// IntegerSet abstract base class to demonstrate hash table concepts
class IntegerSet {
protected:
   int size;
   int probeDistance;
   int hash(int key) const { return (key * 997) % size; }
public:
   IntegerSet(int htsize):size(htsize) {}
   virtual bool insert(int) = 0;
   virtual bool search(int) const = 0;
   virtual void remove(int) = 0;
};

// Hash Table with Linear Probing
class IntegerSetHT : public IntegerSet {
protected:
  int *table;
  int probeDistance;
  const int empty_since_start = -2;
  const int empty_after_removal = -1;
  
public:
   IntegerSetHT(int htsize=10);
   class iterator {
      private:
        int* ourTable;
        int sizeofTable;
        int counter;
      public:
      iterator(int * t, int size){ ourTable = t; sizeofTable = size; counter =0;}
      int getInt(){
          return ourTable[counter];}
      bool end() {return (counter == sizeofTable-1);}
      void increment(){
        do{
            ++counter;
        }while(ourTable[counter] < 0 && counter!=sizeofTable-1);
      }
  };
   int failedInsertions;
   int collisions;
   int getCollisions();
   int getfailedInsertions();
   virtual bool insert(int) override;
   virtual bool search(int) const override;
   virtual void remove(int) override;
   iterator begin(){ return iterator(table, size);}
};

}
//#endif //INTEGERSET_H