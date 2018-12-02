#include "IntegerSetWithIterator.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


namespace ece309{
int main() {
	IntegerSetHT set;
    set.insert(5);
    set.insert(99);
    set.insert(0);
    
    IntegerSetHT::iterator sit = set.begin();
    while(!sit.end()){
        printf("%d\n", sit.getInt());
        sit.increment();
    }
    return 0;
    }
}