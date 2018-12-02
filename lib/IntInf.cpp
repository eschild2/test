/* Below, I have provided the code for the IntInf class. I would
 * like to note that the code is very long because I think that
 * I did more than the instructions wanted. My IntInf class can 
 * handle each operator given an int, an IntInf, or a string on 
 * the rhs. The string must either be "+infinity" or "-infinity"
 *  to work. 

 * Emily Childers
 
 */


#include "IntInf.h"
#include <stdio.h>
#include <string.h>
namespace ece309{
IntInf& IntInf::operator=(const IntInf &rhs){
    if(&rhs == this){
        return *this;
    }
    if(rhs.k != 0){
        k = rhs.k;
        pos_inf = 0;
        neg_inf = 0;
        zero = 0;
    }
    else if(rhs.zero == 1){
        k = 0;
        pos_inf = 0;
        neg_inf = 0;
        zero = 1;
    }
    else if(rhs.pos_inf > 0){
        pos_inf = 1;
        k = 0;
        neg_inf = 0;
        zero = 0;
    }
    else if (rhs.neg_inf > 0){
        neg_inf = 1;
        pos_inf = 0;
        k = 0;
        zero = 0;
    }
    return *this;
}

IntInf& IntInf::operator=(const int x){
    k = x;
    pos_inf = 0;
    neg_inf = 0;
    if(x == 0){
        zero = 1;
    }
    else{
        zero = 0;
    }
    return *this;
}

IntInf& IntInf::operator=(const char* str){
    if(strcmp(INF,str) == 0){
        pos_inf = 1;
        neg_inf = 0;
        k = 0;
        zero = 0;
    }
    else if(strcmp(NINF, str) == 0){
        pos_inf = 0;
        neg_inf = 1;
        k = 0;
        zero = 0;
    }
    else{
        printf("You did not give a valid value.\n");
    }
    
    return *this;
}

//I assumed that for operator+, we were creating new IntInfs
//rather than changing the lhs value
IntInf IntInf::operator+(const IntInf &rhs){
    IntInf result;
    //if rhs is +inf, then answer will always be +inf
    if(rhs.pos_inf == 1){
         result.pos_inf = 1;
         result.neg_inf = 0;
         result.k = 0;
         return result;
    }
    else if(rhs.neg_inf == 1){
        //if lhs is +inf, then answer will be +inf
        if(pos_inf == 1){
            result.pos_inf = 1;
            result.neg_inf = 0;
            result.k = 0;
            return result;
        }
        //otherwise, answer will always be -inf
        else{
            result.pos_inf = 0;
            result.neg_inf = 1;
            result.k = 0; 
            return result;
        }
        
    }
    else{
        if(pos_inf == 1){
            result.pos_inf = 1;
            result.neg_inf = 0;
            result.k = 0;
            return result;
        }
        else if(neg_inf == 1){
            result.pos_inf = 0;
            result.neg_inf = 1;
            result.k = 0;
            return result;
        }
        else{
             result.pos_inf = 0;
             result.neg_inf = 0;
             result.k = k+rhs.k;
             return result;
        }
    }
            
}

IntInf IntInf::operator+(const char* str){
    IntInf result;
    //if rhs is +inf, then answer will always be +inf
    if(strcmp(INF,str) == 0){
        result.pos_inf = 1;
        result.neg_inf = 0;
        result.k = 0;
        return result;
    }
    
    else if(strcmp(NINF, str) == 0){
        //if lhs is +inf, then answer will +inf
        if(pos_inf == 1){
            result.pos_inf = 1;
            result.neg_inf = 0;
            result.k = 0;
            return result;
        }
        //otherwise the answer is -inf
        else{
            result.pos_inf = 0;
            result.neg_inf = 1;
            result.k=0;
            return result;
        }
    }
    else{
        printf("You did not enter a valid expression\n");
        return result;
    }
}

IntInf IntInf::operator+(int rhs){
    IntInf result;
    if(pos_inf == 1){
        result.pos_inf = 1;
        result.neg_inf = 0;
        result.k = 0;
    }
    else if(neg_inf == 1){
        result.pos_inf = 0;
        result.neg_inf =1;
        result.k =0;
    }
    else{
        result.k = result.k+rhs;
        result.pos_inf = 0;
        result.neg_inf = 0;
        if(result.k == 0){
            result.zero = 1;
        }
    }
    return result;
}

//For operator- I assumed that -inf-(-inf) = -inf
IntInf IntInf::operator-(const IntInf &rhs){
    IntInf result;
    //when rhs = +inf
    if(rhs.pos_inf == 1){
        if(pos_inf == 1){
            result.k = 0;
            result.pos_inf = 1;
            result.neg_inf = 0;
            result.zero = 0;
        }
        else{
            result.k = 0;
            result.pos_inf = 0;
            result.neg_inf = 1;
            result.zero = 0;
        }
    }
    else if(rhs.neg_inf == 1){
        if(neg_inf == 1){
            result.k = 0;
            result.pos_inf=0;
            result.neg_inf = 1;
            result.zero =0;
        }
        else{
            result.k = 0;
            result.pos_inf =1;
            result.neg_inf = 0;
            result.zero = 0;
        }  
    }
    else if(rhs.neg_inf == 0 && rhs.pos_inf == 0){
        if(pos_inf == 1){
            result.k = 0;
            result.pos_inf =1;
            result.neg_inf = 0;
            result.zero = 0;
        } else if(neg_inf == 1){
            result.k = 0;
            result.pos_inf=0;
            result.neg_inf = 1;
            result.zero =0;
        } else{
            result.k = k - rhs.k;
            if(result.k == 0){
                result.zero = 1;
            }
        }
    }
    return result;
}

IntInf IntInf::operator-(const char* str){
    IntInf result;
    if(strcmp(INF,str) == 0){
        if(pos_inf == 1){
            result.k = 0;
            result.pos_inf =1;
            result.neg_inf = 0;
            result.zero = 0;
        }
        else{
            result.k = 0;
            result.pos_inf=0;
            result.neg_inf = 1;
            result.zero =0;
        }
    } else if(strcmp(NINF, str) == 0){
        if(neg_inf==1){
            result.k = 0;
            result.pos_inf=0;
            result.neg_inf = 1;
            result.zero =0;
        }
        else{
            result.k = 0;
            result.pos_inf =1;
            result.neg_inf = 0;
            result.zero = 0;
        }
    }
    else{
        printf("You entered an invalid expression");
    }
    return result;
}

IntInf IntInf::operator-(const int rhs){
    IntInf result;
    if(pos_inf == 1){
        result.k = 0;
        result.pos_inf =1;
        result.neg_inf = 0;
        result.zero = 0;
    } else if(neg_inf == 1){
        result.k = 0;
        result.pos_inf=0;
        result.neg_inf = 1;
        result.zero =0;
    } else{
        result.k = k - rhs;
        if(result.k == 0 ){
            result.zero = 1;
        }
        result.pos_inf=0;
        result.neg_inf = 0;
    }
    return result;
}

IntInf IntInf::operator*(const IntInf &rhs){
    IntInf result;
    //Case where rhs = 0 or lhs = 0
    if(rhs.zero == 1 || zero == 1){
        result.zero = 1;
        result.pos_inf = 0;
        result.neg_inf = 0;
        result.k = 0;
        return result;
    }
    //Case where rhs = +inf
    else if(rhs.pos_inf == 1){
        //Case where lhs = +inf or lhs = int
        if(pos_inf == 1 || k != 0){
            result.pos_inf = 1;
            result.neg_inf = 0;
            result.k = 0;
            result.zero = 0;
        }
        //Case where lhs = -inf
        else if(neg_inf == 1){
            result.neg_inf = 1;
            result.pos_inf = 0;
            result.k = 0;
            result.zero = 0;
        }
    }
    //Case where rhs = -inf
    else if(rhs.neg_inf == 1){
        //Case where lhs = +inf or lhs = int
        if(pos_inf == 1 || k != 0){
            result.pos_inf = 0;
            result.neg_inf = 1;
            result.k = 0;
            result.zero = 0;
        }
        //Case where lhs = -inf
        else if(neg_inf == 1){
            result.pos_inf = 1;
            result.neg_inf = 0;
            result.k = 0;
            result.zero = 0;
        }
    }
    
    //Case where rhs = int
    else if(rhs.k != 0){
        if(pos_inf == 1){
            result.pos_inf = 1;
            result.neg_inf = 0;
            result.k = 0;
            result.zero = 0;
        }
        else if(neg_inf == 1){
            result.pos_inf = 0;
            result.neg_inf = 1;
            result.k = 0;
            result.zero = 0;
        }
        else if(k != 0){
            result.pos_inf = 0;
            result.neg_inf = 0;
            result.k = k * rhs.k;
            result.zero = 0;
        }
    }
    
    return result;
    }
    
IntInf IntInf::operator*(const char* str){
    IntInf result;
    if(zero == 1){
        result.pos_inf = 0;
        result.neg_inf = 0;
        result.k = 0;
        result.zero = 1;
        return result;
    }
    //if rhs = +inf
    else if(strcmp(INF,str) == 0){
        if(pos_inf == 1 || k != 0){
            result.pos_inf = 1;
            result.neg_inf = 0;
            result.k = 0;
            result.zero = 0;
            return result;
        }
        else if(neg_inf == 1){
            result.pos_inf = 0;
            result.neg_inf = 1;
            result.k = 0;
            result.zero = 0;
            return result;
        }
    }
    //if rhs = -inf
    else if(strcmp(NINF, str) == 0){
        if(pos_inf == 1 || k != 0){
            result.pos_inf = 0;
            result.neg_inf = 1;
            result.k = 0;
            result.zero = 0;
            return result;
        }
        else if(neg_inf == 1){
            result.pos_inf = 1;
            result.neg_inf = 0;
            result.k = 0;
            result.zero = 0;
            return result;
        }
    }
    else{
        printf("You did not provide a valid expression");
    }
    return result;
}

IntInf IntInf::operator*(const int rhs){
    IntInf result;
    if(rhs == 0 || zero == 1){
        result.zero = 1;
        result.pos_inf = 0;
        result.neg_inf = 0;
        result.k = 0;
        return result;
    }
    else if(pos_inf == 1){
        result.pos_inf = 1;
        result.neg_inf = 0;
        result.k = 0;
        result.zero = 0;
        return result;
    }
    else if(neg_inf == 1){
        result.pos_inf = 0;
        result.neg_inf = 1;
        result.k = 0;
        result.zero = 0;
        return result;
    }
    else{
        result.pos_inf = 0;
        result.neg_inf = 0;
        result.k = rhs * k;
        result.zero = 0;
        return result;
    }
}


IntInf IntInf::operator/(const IntInf &rhs){
    IntInf result;
    if(pos_inf == 1){
        // +inf / +inf = +inf
        if(rhs.pos_inf == 1){
            result.pos_inf = 1;
            result.neg_inf = 0;
            result.zero = 0;
            result.k = 0;
        }
        // +inf /-inf = -inf
        else if(rhs.neg_inf == 1){
            result.pos_inf = 0;
            result.neg_inf = 1;
            result.zero = 0 ;
            result.k = 0;
        }
        
        else if(rhs.zero == 1){
            //dividing by 0 is undefined
            printf("Dividing by 0 is undefined.\n");
        }
        //case when k != 0
        else if(rhs.k != 0){
           
            result.pos_inf = 1;
            result.neg_inf = 0;
            result.k = 0;
            result.zero = 0;
            
        }
    }
    else if(neg_inf == 1){
        // -inf / +inf = -inf
        if(rhs.pos_inf == 1){
            result.pos_inf = 0;
            result.neg_inf = 1;
            result.zero = 0 ;
            result.k = 0;
        }
        // -inf /-inf = +inf
        else if(rhs.neg_inf == 1){
            result.pos_inf = 1;
            result.neg_inf = 0;
            result.zero = 0 ;
            result.k = 0;
        }
        
        else if(rhs.zero == 1){
            //dividing by 0 is undefined
            printf("Dividing by 0 is undefined.\n");
        }
        //case when k != 0
        else if(rhs.k != 0){
            result.neg_inf = 1;
            result.pos_inf = 0;
            result.k = 0;
            result.zero = 0;
        }
    }
    else if(zero == 1){
        if(rhs.zero == 1){
            //dividing by 0 is undefined
            printf("Dividing by 0 is undefined.\n");
        }
        else{
            result.pos_inf = 0;
            result.neg_inf = 0;
            result.k = 0;
            result.zero = 1;
        }
    }
    else if (k != 0){
        if(rhs.pos_inf == 1 || rhs.neg_inf == 1){
            result.pos_inf = 0;
            result.neg_inf = 0;
            result.k = 0;
            result.zero = 1;
        }
        else if(rhs.zero == 1){
            //dividing by 0 is undefined
            printf("Dividing by 0 is undefined.\n");
        }
        else if(rhs.k != 0){
            result.pos_inf = 0;
            result.neg_inf = 0;
            result.k = k/rhs.k;
            result.zero = 0;
        }
    }
    return result;
}

/*If the user is dividing lhs by a char*, they 
 * will always be dividing by +/- inf 
 * 
 */
IntInf IntInf::operator/(const char* str){
    IntInf result;
    if(pos_inf == 1){
        //+inf / +inf = +inf
        if(strcmp(INF, str) == 0){
        result.pos_inf = 1;
        result.neg_inf = 0;
        result.k = 0;
        result.zero = 0;
        }
        //+inf / -inf =-inf
        else{
            result.pos_inf = 0;
            result.neg_inf = 1;
            result.k = 0;
            result.zero = 0;
        }
    }
    else if(neg_inf == 1){
        // -inf/ +inf = -inf
        if(strcmp(INF, str) == 0){
        result.pos_inf = 0;
        result.neg_inf = 1;
        result.k = 0;
        result.zero = 0;
        }
        // -inf/-inf = +inf
        else{
        result.pos_inf = 1;
        result.neg_inf = 0;
        result.k = 0;
        result.zero = 0;
        }
    }
    else{
    result.pos_inf = 0;
    result.neg_inf = 0;
    result.k = 0;
    result.zero = 1;
    }

return result;
}

IntInf IntInf::operator/(const int rhs){
    IntInf result;
    if(pos_inf == 1){
        result.pos_inf = 1;
        result.neg_inf = 0;
        result.k = 0;
        result.zero = 0;
    }
    else if(neg_inf == 1){
        result.pos_inf = 0;
        result.neg_inf = 1;
        result.k = 0;
        result.zero = 0;
    }
    else if(zero == 1){
        result.pos_inf = 0;
        result.neg_inf = 0;
        result.k = 0;
        result.zero = 1;
    }
    else{
        result.pos_inf = 0;
        result.neg_inf = 0;
        result.k = k/rhs;
        result.zero = 0;
    }
    return result;
}



bool IntInf::operator==(const IntInf &rhs){
    // infinity can never equal infinity
    if(rhs.pos_inf == 1 || pos_inf == 1 || rhs.neg_inf == 1 || neg_inf == 1){
        return false;
    }
    //both values equal 0
    else if(rhs.zero == 1 && zero == 1){
        return true;
    }
    else if(rhs.k != 0 && k != 0){
        if(rhs.k == k){
            return true;
        }
    }
    return false;
}

/*If the user is comparing lhs to char*, they
 *will always be comparing it to +/-infinity so
 * the answer will always be false!
 */
bool IntInf::operator==(const char* str){
    return false;
}

bool IntInf::operator==(const int rhs){
    if(zero == 1 && rhs == 0){
        return true;
    }
    else if(k != 0 && rhs != 0){
        if(k == rhs){
            return true;
        }
    }
    return false;
}

bool IntInf::operator>(const IntInf &rhs){
    if(pos_inf == 1){
        // +inf cannot be greater than +inf
        if(rhs.pos_inf == 1){
            return false;
        }
        //otherwise +inf > all else
        else{
            return true;
        }
    }
    //-inf cannot be larger than anything
    else if(neg_inf == 1){
        return false;
    }
    else if(zero == 1){
        // 0 cannot be > 0
        if(rhs.zero == 1){
            return false;
        }
        //0 is not greater than +inf
        else if(rhs.pos_inf == 1){
            return false;
        }
        //0 is greater than -inf
        else if(rhs.neg_inf == 1){
            return true;
        }
        else{
            if(0 > rhs.k){
                return true;
            }
            else{
                return false;
            }
        }
    }
    else if(k != 0){
        if(rhs.pos_inf == 1){
            return false;  
        }
        else if(rhs.neg_inf == 1){
            return true;
        }
        else if(k > rhs.k && rhs.k != 0){
            return true;
        }
       
    }
    return false;
    }
    

bool IntInf::operator>(const char* str){
    //nothing is larger than infinity
    if(strcmp(INF, str) == 0){
        return false;
    }
    else if(strcmp(NINF, str)==0){
        if(neg_inf == 0){
            return true;
        }
        //-inf is not > -inf
        return false;
    }
    else{
        printf("You gave an invalid expression.\n");
    }    
    return false;
}

bool IntInf::operator>(int rhs){
    if(pos_inf == 1){
        return true;
    }
    else if(neg_inf == 1){
        return false;
    }
    else if(zero == 1){
        if(rhs == 0){
            return false;
        }
        else{
            if(rhs < 0){
                return true;
            }
            else{
                return false;
            }
        }
    }
    else{
        if(k != 0 && k > rhs){
            return true;
        }
        return false;
    }
}

bool IntInf::operator<(const IntInf &rhs){
    //-inf is greater than nothing
    if(rhs.neg_inf == 1){
       return false;
        }
    
    else if(rhs.zero == 1){
        // 0 cannot be greater than 0
        if(zero == 1){
            return false;
        }
        else if(neg_inf == 1 || (k != 0 && k <0)){
            return true;
        }
        else{
            return true;
        }
    }
    else if(rhs.pos_inf == 1){
        //+inf cannot be greater than +inf
        if(pos_inf == 1){
            return false;
        }
        else{
            return true;
        }
    } else if(rhs.k != 0){
        if(rhs.k > k){
            return true;
        }
        else return false;
    }
    return false;
}

bool IntInf::operator<(const char* str){
    //-inf is greater than nothing
    if(strcmp(NINF, str) == 0){
        return false;
    }
    else if(strcmp(INF, str) == 0){
        if(pos_inf == 1){
            return false;
        }
        else return true;
    }
    else{
        printf("You entered an invalid expression.\n");
    }
    return false;
}

bool IntInf::operator<(const int rhs){
    if(neg_inf == 1){
        return true;
    }
    else if(pos_inf == 1){
        return false;
    }
    else if(zero == 1){
        if(rhs == 0){
            return false;
        }
        else{
            if(rhs > 0){
                return true;
            }
        return false;
        }
    }
    else{
        if(k != 0 && k < rhs){
            return true;
        }
        return false;
    }
}

}