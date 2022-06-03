#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(1e5 + 5)
#define MAXL 20
#define F first
#define S second
#define endl "\n"
#define MOD (lli)(1e9 + 9)
#define MOD2 (lli)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
#define DEBUG if (0) cout << "aqui" << endl;
#define PI 2 * acos(0.0)
typedef pair<int, lli> ii;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

/**
 * https://leetcode.com/problems/add-two-numbers/
 * 
 * Basically is just an adhoc problem. U just need
 * to simulate the two numbers sums, being careful in
 * always store the rem to use in the next sum.
 * 
 * The problem can be solved in linear time O(|n|) where
 * |n| is the size of the highest len number
 */

// vector<int> countBits(int n) {
//   vector<int> ans;

//   for(int i = 0; i <= n; i++) {
//     int j = 0;
//     int aux = 0;
//     while((1 << j) <= i) {
//       if((1 << j) & i) aux++;
//       j++;
//     }
//     ans.push_back(aux);
//   }

//   return ans;
// }

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverse(ListNode *l1) {
  ListNode *ans = NULL;
  while(l1 != NULL) {
    if(ans == NULL) {
      ans = new ListNode(l1->val);
    } else {
      ListNode *newNode = new ListNode(l1->val);
      newNode->next = ans;
      ans = newNode;
    }
    l1 = l1->next;
  }

  return ans;
}

ListNode *ans = NULL;
ListNode *tail = NULL;

void createNode(int val) {
  if(tail == NULL) {
    tail = new ListNode(val);
    ans = tail;
  } else {
    tail->next = new ListNode(val);
    tail = tail->next;
  }
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

  // l1 = reverse(l1);
  // l2 = reverse(l2);  

  int rem = 0;
  while(l1 != NULL || l2 != NULL || rem > 0) {
    if(l1 != NULL && l2 != NULL) {
      int sum = (l1->val + l2->val + rem);
      bool at = false;
      if(sum >= 10) {
        sum -= 10;
        at = true;
      }

      createNode(sum);
      if(at) {
        rem = 1;
      } else rem = 0;

      l1 = l1->next;
      l2 = l2->next;
    } else if(l1 != NULL) {
      bool at = false;
      int sum = l1->val + rem;
      if(sum >= 10) {
        sum -= 10;
        at = true;
      }

      createNode(sum);
      if(at) rem = 1;
      else rem = 0;

      l1 = l1->next;
    } else if(l2 != NULL) {
      bool at = false;
      int sum = l2->val + rem;
      if(sum >= 10) {
        sum -= 10;
        at = true;
      }
      
      createNode(sum);
      if(at) rem = 1;
      else rem = 0;

      l2 = l2->next;
    } else {
      if(rem > 0) {
        createNode(1);
      } 
      rem = 0;
    }
  }

  return ans;
}

ListNode *vectorToList(vector<int> vec) {
  ListNode *ans = NULL;
  ListNode *tail = NULL;

  for(auto i : vec) {
    if(tail == NULL) {
      tail = new ListNode(i);
      ans = tail;
    } else {
      tail->next = new ListNode(i);
      tail = tail->next;
    }
  }

  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  vector<int> vec = {9,9,9,9,9,9,9};
  vector<int> vec2 = {9,9,9,9};

  // vector<int> vec = {2,4,3};
  // vector<int> vec2 = {5,6,4};
  
  ListNode *l1 = vectorToList(vec);
  ListNode *l2 = vectorToList(vec2);

  ListNode *ans = addTwoNumbers(l1, l2);

  while(ans != NULL) {
    cout << ans->val << endl;
    ans = ans->next;
  }


  return 0;
}