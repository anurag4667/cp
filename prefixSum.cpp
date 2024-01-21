#include<bits/stdc++.h>
using namespace std;

class Psum{
  public:
  vector<int> N;
  Psum(vector<int> arr){
    N.resize(arr.size());
    N[0] = arr[0];
    for(int i = 1; i < arr.size(); i++) N[i] = arr[i] + N[i-1];
  }

  int getsum(int i,int j){
    if(j == 0) return N[0];
    if(i == 0) return N[j];
    return N[j] - N[i-1];
  }

};
