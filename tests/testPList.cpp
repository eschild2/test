#include <stdio.h>
#include "PList.h"

// This is the test file for our PList.
// It demonstrates how we can add different
// types of objects to the list, and remove them

namespace ece309{
int main(){
    PList l;
    Object O0;
    Object* o1 = new StringItem("cheese");
    Object* o2 = new IntItem(6);
    Object* o3 = new DoubleItem(5.6);
    Object* o4 = new StringItem("bread");
    
    l.append(o1); // add cheese
    l.append(o2); // add 6
    l.append(o3); // add 5.6
    l.append(o4); // add bread
    l.remove(o1); // remove the head (cheese)
    
    PList::iterator it = l.begin();
    while(!it.end()){
        Object* copy = it.getObject();
        
        printf("Next thing in List: ");
        copy->print();
        it.increment();
    }
    
    return 0;
}
}