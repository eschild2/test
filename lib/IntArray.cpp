#include <string.h>
#include "IntArray.h"
#include <stdio.h>

namespace ece309{
  IntArray::IntArray(const char* str){
      int i = 0;
      while(str[i] != '\0'){
          i++;
      }
      length = i;
      ourArray = new int[length];
      for(i = 0; i < length; i++){
         ourArray[i] = str[i];
      }
  }
  
  IntArray::IntArray(int size, int val){
       int i;
       length = size;
       ourArray = new int[size];
       for(i = 0; i<size; i++){
          ourArray[i] = val;
       }
  }
  
  int& IntArray::operator[](int index){
            return ourArray[index];
        }
        
  IntArray IntArray::operator +(const IntArray &rhs) const {
        IntArray result(length);
        int i = 0;
        for(i=0; i<length && i<rhs.length; i++){
            result.ourArray[i] = ourArray[i] + rhs.ourArray[i];
        }
        for(; i<length; i++){
            result.ourArray[i] = ourArray[i];
            
        }
          return result;  
  }
        
  IntArray& IntArray::operator+=(const IntArray &rhs){
         int i = 0;
         for(i = 0; i<length && i< rhs.length; i++){
             ourArray[i] = ourArray[i] + rhs.ourArray[i];
         }
         return *this;
  }
        IntArray IntArray::operator-(const IntArray &rhs) const {
             IntArray result(length);
             int i = 0;
             for(i=0; i<length && i<rhs.length; i++){
             result.ourArray[i] = ourArray[i] - rhs.ourArray[i];
         }
             for(; i<length; i++){
             result.ourArray[i] = ourArray[i];
            
        }
          return result;  
        }
        
        IntArray IntArray::operator*(int x) const {
            int i = 0;
            IntArray result(length);
            for(i = 0; i <length; i++){
                result.ourArray[i] = ourArray[i]*x;
            }
            return result;
        }
        IntArray IntArray::operator/(int x) const {
            IntArray result(length);
            int i =0 ;
            for(i = 0; i <length; i++){
                result.ourArray[i] = ourArray[i]/( x);
            }
            return result;
        }
        IntArray IntArray::operator<<(int count) const {
            IntArray result(length);
            int i = 0;
            int j = 0;
            for(i = 0; i < count; i++){
                for(j = 0; j < length; j++){
                   if(j==0){
                       result.ourArray[0] = ourArray[length-1];
                    }
                   else{
                       result.ourArray[j] = ourArray[j-1];
                    }
                    
                }
            }
           return result;
        }
        IntArray::operator char*() const{
            char* ourString = new char[length];
            int i;
            for(i = 0; i < length; i++){
                if((ourArray[i] < 0) || (ourArray[i] > 255)){
                    ourString[i] = 32;
                }
                else{
                    ourString[i] = ourArray[i];
                }
            }
            return ourString;
        }
        IntArray::operator int() const{
            int i ;
            int sum = 0;
            for(i = 0; i < length; i ++){
                sum += ourArray[i];
                
            }
            return sum/length;
        }
}