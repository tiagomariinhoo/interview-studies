#include <bits/stdc++.h>

using namespace std;

/**
 * A summary about BigO
 * 
 * X! > 2ˆx > xˆ2 > x log x > x > log x 
 * 
 * Amortized Time
 * Amortized time is the way to express the time 
 * complexity when an algorithm has the very bad 
 * time complexity only once in a while besides the
 * time complexity that happens most of time. 
 * Good example would be an ArrayList which is
 * a data structure that contains an array and can be extended.
 * 
 * Recursive Runtimes
 * 
 * Some algorithms like Fibonacci runs in 2ˆn (see Pg 45)
 */


/**
 * In the functio below, the complexity is O(arrayA.size * arrayB.size)
 * O(N*M)
 * The for until 100000, is a constant, so, its not considered in the complexity 
 * calculation
 */
void function1 (vector<int> arrayA, vector<int> arrayB) {
    for (auto i : arrayA) { 
        for (auto j : arrayB) {
            for(int k = 0; k < 100000; k++) {
                cout << i << j << k << endl;
            }
        }
    }
}

/**
 * The function below will calculates n! but the complexity is
 * a just straight recursion, will take O(n)
 */
int factorial (int n) {
    if (n == 0) {
        return 1;
    } 
    return n * factorial(n - 1);
}

/**
 * The function below is a tricky one.
 * Lets suppose that we have 7 characters in the string.
 * 
 * In the first slot we have 7 options, in the next slot we have 6 options and so on.
 * 
 * Therefore we have n! options. So, executing 7 times and the line that do:
 * str.substr(0, i) ... will take O(n) as well as the For outside of it
 * So, the whole algorithm will take O (Nˆ2 * N!)
 */

//Call permutation(str, "")
void permutation (string str, string prefix) {
    if (str.size() == 0) cout << prefix << endl;
    else {
        for (int i = 0; i < str.size(); i++) {
            string rem = str.substr(0, i) + str.substr(i + 1);
            permutation(rem, prefix + str[i]);
        }
    }
}

/**
 * The following function will compute the Fibonacci Number
 * 
 * Its common use a pattern to get the complexity time for this kind of recursion:
 * 
 * O (branches ˆ depth)
 * 
 * Note: Calculating Fibonacci using Dynamic Programming will take O (N)
 */

int fib (int n) {
    if (n <= 0) return 0;
    else if(n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main () {



    return 0;
}