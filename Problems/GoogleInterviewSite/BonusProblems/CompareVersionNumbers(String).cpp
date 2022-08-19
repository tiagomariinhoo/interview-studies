#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/compare-version-numbers/
 * 
 * It's a simple problem but with a lot of corner cases
 * 
 * Since the statement says that the numbers between the dots
 * can be stored in 32-bit integer, we can just get each interval
 * and transform into integer to compare them.
 * 
 * Another thing that we need to deal is that the numbers can
 * have different number of dots, like:
 * 
 * 1.0 and 1.0.0 (but they have the same value)
 * 
 * Then we need to make the size equal filling with zeros:
 * 1.0 -> 1.0.0
 */ 

class Solution {
public:
    
    pair<string, string> putEqualSize(string version1, string version2) {
        int dotNumber = 0;
        int dotNumber2 = 0;
        
        for(int i = 0; i < version1.size(); i++) {
            if(version1[i] == '.') dotNumber++;
        }
        
        for(int i = 0; i < version2.size(); i++) {
            if(version2[i] == '.') dotNumber2++;
        }
        
        if(dotNumber < dotNumber2) {
            while(dotNumber != dotNumber2) {
                version1 += ".0";
                dotNumber++;
            }
        } else if(dotNumber > dotNumber2) {
            while(dotNumber != dotNumber2) {
                version2 += ".0";
                dotNumber--;
            }
        }
        
        return {version1, version2};
    }
    
    int compareVersion(string version1, string version2) {
        pair<string, string> aux = putEqualSize(version1, version2);
        
        version1 = aux.first;
        version2 = aux.second;
        
        int i = 0, j = 0;
        int ans = 0;
        
        while(i < version1.size() || j < version2.size()) {
            string aux = "";
            string aux2 = "";
            
            if(i < version1.size() && version1[i] == '.') i++;
            
            while(i < version1.size() && version1[i] != '.') {
                aux += version1[i];
                i++;
            }
            
            if(j < version2.size() && version2[j] == '.') j++;
            
            while(j < version2.size() && version2[j] != '.') {
                aux2 += version2[j];
                j++;
            }
            
            if(aux.size() && aux2.size()) {
                int aa = stoi(aux);
                int bb = stoi(aux2);
                if(aa > bb) {
                    ans = 1;
                    break;
                } else if(aa < bb) {
                    ans = -1;
                    break;
                }
            } else if(aux.size() > 0) {
                ans = 1;
                break;
            } else if(aux2.size() > 0) {
                ans = -1;
                break;
            }
        }
        
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}