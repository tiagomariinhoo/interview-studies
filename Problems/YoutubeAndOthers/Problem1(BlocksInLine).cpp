#include <bits/stdc++.h>
using namespace std;

/**
 * https://youtu.be/rw4s4M3hFfs
 * 
 * Solution in linear time
 */ 

struct Blocks {
  bool gym;
  bool school;
  bool store;
};

vector<Blocks> vec;

void addElement(bool gym, bool school, bool store) {
  Blocks block;
  block.gym = gym;
  block.school = school;
  block.store = store;

  vec.push_back(block);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  addElement(false, true, false);
  addElement(true, false, false);
  addElement(true, true, false);
  addElement(false, true, false);
  addElement(false, true, true);

  queue<int> rightGymQueue, rightSchoolQueue, rightStoreQueue;

  for(int i = 1; i < vec.size(); i++) {
    if(vec[i].gym) {
      rightGymQueue.push(i);
    }
    if(vec[i].school) {
      rightSchoolQueue.push(i);
    }
    if(vec[i].store) {
      rightStoreQueue.push(i);
    }
  }

  int ans = 0;
  int minDistance = INT_MAX;

  int leftGym = INT_MAX;
  int leftSchool = INT_MAX;
  int leftStore = INT_MAX;

  for(int i = 0; i < vec.size(); i++) {
    if(vec[i].gym) leftGym = i;
    if(vec[i].school) leftSchool = i;
    if(vec[i].store) leftStore = i;

    int rightGym = (rightGymQueue.size() > 0 ? rightGymQueue.front() : INT_MAX);
    int rightSchool = (rightSchoolQueue.size() > 0 ? rightSchoolQueue.front() : INT_MAX);
    int rightStore = (rightStoreQueue.size() > 0 ? rightStoreQueue.front() : INT_MAX);

    if(rightGymQueue.size() > 0 && rightGymQueue.front() == i) {
      rightGymQueue.pop();
    }

    if(rightSchoolQueue.size() > 0 && rightSchoolQueue.front() == i) {
      rightSchoolQueue.pop();
    }

    if(rightStoreQueue.size() > 0 && rightStoreQueue.front() == i) {
      rightStoreQueue.pop();
    }

    int currentDistance = max({
      min({abs(leftGym - i), abs(rightGym - i)}),
      min({abs(leftSchool - i), abs(rightSchool - i)}),
      min({abs(leftStore - i), abs(rightStore - i)}),
    });

    if(currentDistance < minDistance) {
      minDistance = currentDistance;
      ans = i;
    }
  }

  cout << ans << endl;
  cout << minDistance << endl;

  return 0;
}