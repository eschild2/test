#include "IntInf.h"
#include <stdio.h>
#include <string.h>

using namespace ece309;
int main(){
    
    /*Test Case 1
     * Demonstrates that the user can set an IntInf using
     * a string, an integer, or another IntInf */
     
    printf("\n------Testing operator=------\n");
    bool a;
    bool b;
    bool c;
    bool d;
    bool e;
    bool f;
    IntInf q;
    IntInf s;
    IntInf t;
    IntInf u;
    IntInf v;
    IntInf w;
    IntInf x;
    IntInf y;
    IntInf z;
    w = "-infinity";
    x = 5;
    y = x;
    z = "+infinity";
    printf("Given the following code in main:\nx = 5;\n");
    printf("y = x;\nz = \"+infinity\";\nw = \"-infinity\"\n");
    
    if(x.k == 5 && y.k == 5 && z.pos_inf == 1 && w.neg_inf ==1){
        printf("Test Case 1 passes\n");
    }
    else{
        printf("Test Case 1 does not pass\n");
    }
    
    /* Test Case 2
     * Demonstrates that the user can create new IntInfs
     * by adding preexisting IntInfs, integers, or strings
     * Note: I assumed inf + -inf = +inf
     */
     
     u = 10;
     v = 4;
     t = u + v;
     y = y + z;
     x = w + "+infinity";
     
     printf("\n------Testing operator+------\n");
     printf("Given the following code in main:\nu = 10;\nv = 4;\ny = 5;\n");
     printf("z = \"+infinity\";\nw = \"-infinity\";\n");
     printf("t = u + v;\ny = y + z;\nx = w + \"+infinity\";\n");
     printf("t = %d\n", t.k);
     
     printf("Solutions:\n");
     if(y.pos_inf == 1){
         printf("y = +infinity\n");
     }
     
     if(x.pos_inf == 1){
         printf("x = +infinity\n");
     }
     
     if(t.k == 14 && y.pos_inf == 1 && x.pos_inf == 1 && t.pos_inf == 0 && x.neg_inf == 0){
         printf("Test Case 2 passes\n");
     }
     else{
         printf("Test Case 2 does not pass\n");
     }
    
    /*Test Case 3
     * Demonstrates that the user can multiply an IntInf by another
     * IntInf, by an int, or by a string
     */
     x = -3;
     y = 8;
     z = "+infinity";
     w = "-infinity";
     v = 0; 
     u = x*y;
     t = v*z;
     s = z*"-infinity";
     q = w*w;
     
     
     printf("\n-----Testing operator*------\n");
     printf("Given the following code in main:\nx = -3;\ny = 8;\nz = \"+infinity\";\n");
     printf("w = \"-infinity\";\nv = 0;\nu = x * y;\nt = v * z;\ns = z * \"-infinity\";\n");
     printf("q = w * w;\nSolutions:\nu = %d\nt = %d\n", u.k, t.k);
     if(s.neg_inf == 1){
         printf("s = -infinity\n");
     }
     if(q.pos_inf == 1){
         printf("q = +infinity\n");
     }
     
     //Check for the values of u, t, s, and q; also check that their other constants are 0
     if(u.k == -24 && t.k == 0 && t.zero == 1 && s.neg_inf == 1 && q.neg_inf == 0 && u.pos_inf == 0 && u.zero == 0 && s.zero == 0){
         printf("Test Case 3 passes.\n");
     }
     else{
         printf("Test Case 3 does not pass.\n");
     }
     
     /*Test Case 4
     * Demonstrates that the user can compare an IntInf to another
     * IntInf, to an int, or to a string
     */
     
     printf("\n-------Testing operator==-------\n");
     printf("Given the following code in main:\ns = 0;\nt = \"-infinity\";\n");
     printf("u = 5;\nv = 5;\nx = 0;\ny = \"+infinity\";\na = s == x;\nb = t == u;\n");
     printf("c = t == \"+infinity\";\nd = u == v;\ne = v == x;\n");
     s = 0;
     t= "-infinity";
     u= 5;
     v= 5;
     x = 0;
     
     a = s==x;
     b = t==u;
     c = t=="+infinity";
     d = u==v;
     e = v==x;
     
     printf("Solutions:\na = %d\nb = %d\nc = %d\nd = %d\ne = %d\n", a, b, c, d, e);
     
     if(a == 1 && b == 0 && c == 0 && d == 1 && e == 0){
         printf("Test Case 4 passes\n");
     }
     else{
         printf("Test Case 4 fails");
     }
     
     /*Test Case 5
      * Demonstates that the user can compare their IntInf to other IntInfs, 
      * integers, or strings
      */
      
      x = 0;
      y = 500;
      z = -26;
      u = "+infinity";
      
      a = x > y;
      b = z > "-infinity";
      c = y > "+infinity";
      d = x > x;
      e = u > "-infinity";
      f = y > 89;
      
      /*Test Case 6
      * Demonstates that the user can compare their IntInf to other IntInfs, 
      * integers, or strings
      */
      
      printf("\n-------Testing operator>-------\n");
      printf("Given the following code in main:\nx = 0;\ny = 500;\nz= -26;\nu = \"+infinity\";\n");
      printf("a = x > y;\nb = z > \"-infinity\";\nc = y > \"+infinity\";\nd= x > x;\n");
      printf("e = u > \"-infinity\";\nf = y > 89;\n");
      
      printf("Solutions:\na = %d\nb = %d\nc = %d\nd = %d\ne = %d\nf = %d\n", a, b, c, d, e, f);
      
      if(a == 0 && b == 1 && c == 0 && d == 0 && e == 1 && f == 1){
          printf("Test Case 5 passes\n");
      }
      else{
          printf("Test Case 5 fails\n");
      }
      
      /*Test Case 7
       * Demonstrates that the user can compare their IntInf to other IntInfs,
       * integers, or strings
       */
    
      printf("\n---------Testing operator<---------\n");
      printf("Given the following code in main:\nx = 0;\ny = 500;\nz= -26;\nu = \"+infinity\";\n");
      printf("a = x < y;\nb = z < \"-infinity\";\nc = y < \"+infinity\";\nd= x < x;\n");
      printf("e = u < \"-infinity\";\nf = y < 89;\n");
    
      a = x < y;
      b = z < "-infinity";
      c = y < "+infinity";
      d = x < x;
      e = u < "-infinity";
      f = y < 89;
      
      printf("Solutions:\na = %d\nb = %d\nc = %d\nd = %d\ne = %d\nf = %d\n", a, b, c, d, e, f);
      if(a == 1 && b == 0 && c == 1 && d == 0 && e == 0 && f == 0 ){
          printf("Test Case 7 Passes\n");
      }
      else{
          printf("Test Case 7 fails\n");
      }
      
      /*Test Case 8
       *Demonstrates that the user can subtract IntInfs, integers, 
       *and strings
       * Note: I assumed int - (-inf) = +inf
       *       I assumed +inf - (-inf) = +inf
       */
      
      printf("\n------------Testing operator- -------------\n");
      printf("Given the following code in main:\nq = 7;\ns = 28;\nt = s - q;\n");
      printf("u = q - \"-infinity\";\nm = q - 7;\nw = s - \"+infinity\";\ny = \"+infinity\";\n");
      printf("z = y - \"-infinity\";\nSolutions:\n");
      
      IntInf m;
      q = 7;
      s = 28;
      t = s - q;
      u = q - "-infinity";
      m = q - 7;
      w = s - "+infinity";
      y = "+infinity";
      z = y - "-infinity";
      
       printf("t = %d\n", t.k);
      
      if(u.pos_inf == 1){
          printf("u = +infinity\n");
      }
      if(m.zero == 1){
          printf("m = 0\n");
      }
      
      if(w.neg_inf == 1){
          printf("w = -infinity\n");
      }
      if (z.pos_inf == 1){
          printf("z = +infinity\n");
      }
      
      if(u.pos_inf == 1 && m.zero == 1 && w.neg_inf == 1 && z.pos_inf == 1 && t.k == 21){
          printf("Test Case 8 passes\n");
      }
      else{
          printf("Test Case 8 fails\n");
      }
      
      /*Test Case 9 demonstrates how we can divide 
       *IntInfs, integers, and strings 
       *Note: I assumed int/inf = 0 or int/-inf = 0
       *      I assumed +inf/+inf = +inf, -inf/+inf = -inf
       *      I assumed -inf/-inf = +inf
       *If the user attempts to divide by 0, an error message is
       * printed.
       */
      printf("\n-------------Testing operator / --------------\n");
      printf("Given the following code in main:\ny = \"+infinity\";\nq = 7;\ns = 28;\n");
      printf("w = s / \"-infinity\";\nz = s / q;\nt = y / \"-infinity\";\nm = w/0;\nSolutions:\n");
      
      y = "+infinity";
      q = 7;
      s = 28;
      w = s/"-infinity";
      z = s/q;
      t = y/"-infinity";
      m = w/0;
      
      if(w.zero == 1){
          printf("w = 0\n");
          
      }
      if(z.k == 4){
          printf("z = 4\n");
      }
      if(t.neg_inf == 1){
          printf("t = -infinity\n");
      }
      
      if(w.zero == 1 && z.k == 4 && t.neg_inf == 1){
          printf("Test Case 9 passes\n");
          
      }
      else{
          printf("Test Case 9 fails\n");
      }
 
    return 0;
}
