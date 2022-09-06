#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/nim-game/solution/
 * 
 You can always win a Nim game if the number of stones nn in the pile is not divisible by 44.

Reasoning

Let us think of the small cases. It is clear that if there are only one, two, or three stones in the pile, 
and it is your turn, you can win the game by taking all of them. Like the problem description says, if there
 are exactly four stones in the pile, you will lose. Because no matter how many you take, you will leave some
  stones behind for your opponent to take and win the game. So in order to win, you have to ensure that you
   never reach the situation where there are exactly four stones on the pile on your turn.

Similarly, if there are five, six, or seven stones you can win by taking just enough to leave four stones 
for your opponent so that they lose. But if there are eight stones on the pile, you will inevitably lose, 
because regardless whether you pick one, two or three stones from the pile, your opponent can pick three, 
two or one stone to ensure that, again, four stones will be left to you on your turn.

It is obvious that the same pattern repeats itself for n=4,8,12,16,\dotsn=4,8,12,16,…, basically all multiples of 44.

Basically if N%4 != 0, u can keep repeating the situation for the last 4 stones, the second player
is with 4 stones remaining and will remain just 3 stones for the first player
 */ 

class Solution {
public:
    bool canWinNim(int n) {
        return (n % 4 != 0);
    }
};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}