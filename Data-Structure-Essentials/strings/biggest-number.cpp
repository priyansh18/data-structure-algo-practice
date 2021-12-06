#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  string str = "3894584";
  // int x = stoi(str);
  // cout<<x;
  sort(str.begin(),str.end(),greater<int>());

  cout<<str;
}