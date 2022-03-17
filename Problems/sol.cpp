#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(3*1e5 + 5)
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * I think the first step is reverse the list to make the sum.
 */

ListNode* reverseList(ListNode *head) {
  ListNode *prevNode = NULL;
  while(head->next != NULL) {
    ListNode *nextNode = head->next;
    nextNode->next = head;
    head->next = prevNode;
    prevNode = head;    
  }

  return prevNode;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  l1 = reverseList(l1);
  l2 = reverseList(l2);  

  ListNode *answer = new ListNode();
  ListNode *head = answer;
  int rem = 0;

  while(l1 != NULL or l2 != NULL) {
    if(l1 != NULL && l2 != NULL) {
      int sum = l1->val + l2->val;
      answer->val = sum%10 + rem;
      rem = sum/10;

      l1 = l1->next;
      l2 = l2->next;
    } else if(l1 != NULL) {
      answer->val = l1->val + rem;
      l1 = l1->next;
    } else {
      answer->val = l2->val + rem;
      l2 = l2->val;
    }

    answer->next = new ListNode();
    answer = answer->next;
  }

  return head;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}