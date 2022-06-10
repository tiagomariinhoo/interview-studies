#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/reverse-integer/submissions/
 * 
 * Given a string, just reverse it
 * 
 * Both solutions run in O(|N|) where N is the number of digits
 * The second solution is naive but the first one
 * u just need to get the last digit by using %10 and for each iteration
 * check if the current number is greater than > INT_MAX/10 or < INT_MIN
 * 
 * Basically if the rev number is > INT_MAX/10, this means that
 * when add one more digit for the rev number, will also be greater than INT_MAX
 * and will cause Overflow. The same for INT_MIN.
 */

// int reverse(int x) {  
//   int rev = 0;
//   while(x != 0) {
//     int pop = x%10;
//     x /= 10;

//     /**
//      * This means that:
//      * if INT_MAX = 1010, for example
//      * and rev = 102
//      * 
//      * if 1010/10 (101) is > rev, this means that the next digit will be greater as well
//      * and this comparation won't cause overflow
//      */
//     if(rev > INT_MAX/10 || (rev == INT_MAX && pop > 7)) return 0;
//     if(rev < INT_MIN/10 || (rev == INT_MIN && pop < -8)) return 0;

//     rev = (rev * 10 + pop);
//   }

//   return rev;
// }


// Solution using Strings
// int reverse(int x) {
//   string s = to_string(x);

//   if(s[0] == '-') {
//     reverse(s.begin() + 1, s.end());
//     string min_com = to_string(INT_MIN);

//     if(min_com.size() > s.size()) {
//       return stoi(s);
//     } 

//     bool at = false;
//     for(int i=1;i<s.size();i++) {
//       if(s[i] < min_com[i]) at = true;
//       else if(s[i] > min_com[i]) {
//         if(!at) {
//           return 0;
//         }
//       }
//     }
//   } else {
//     reverse(s.begin(), s.end());
//     string max_com = to_string(INT_MAX);
//     bool at = false;

//     if(max_com.size() > s.size()) {
//       return stoi(s);
//     }

//     for(int i=0;i<s.size();i++) {
//       if(s[i] < max_com[i]) at = true;
//       else if(s[i] > max_com[i]) {
//         if(!at) {
//           return 0;
//         }
//       }
//     }
//   }


//   return stoi(s);
// }

int main(){
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  
  cout << reverse(-123) << endl;

  return 0;
}