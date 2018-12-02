#include "IntegerSetArray.h"
namespace ece309{
       IntegerSetArray::IntegerSetArray(int s):IntegerSet(s) {
            size = s;
            currentIndex = 0;
            a = new int[size];
            for(int i = 0; i<size; i++){
                a[i] = -1;
            }
}
        bool IntegerSetArray::insert(int x){
            if(a[currentIndex] == -1){
                a[currentIndex] = x;
                currentIndex++;
                return true;
            }
            return false;
       }        
        
        bool IntegerSetArray::search(int x) const {
            for(int i = 0 ; i < size; i++){
                if(a[i] == x){
                    return true;
                }
            }
            return false;
        }
        
        void IntegerSetArray::remove(int x){
            for(int i = 0 ; i < size; i++){
                if(a[i] == x){
                    a[i] = -1;
                }
            }
        }



}
