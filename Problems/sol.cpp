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

ListNode *reverseList(ListNode* head) {
  ListNode *prevNode = NULL;
  while(head != NULL) {
    ListNode *nextNode = head->next;
    head->next = prevNode;
    prevNode = head;
    head = nextNode;
  }
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode *ans = new ListNode();
  l1 = reverseList(l1);
  l2 = reverseList(l2);

  int sum = 0;

  while(l2 != NULL || l1 != NULL) {
    if(l2 != NULL && l1 != NULL) {
      ans->val = 
      sum = (l2->val + l1-> val)/10;
      
    } else if(l2 != NULL) {
      
    } else {

    }
  }

  return reverseList(ans);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}