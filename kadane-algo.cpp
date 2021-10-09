#include<iostream>
#include<climits>
using namespace std;

void kadaneAlgo(int arr[],int n){
  int maxCumSum = INT_MIN;
  int currentSum = 0;
  for(int i = 0;i<n;i++){
    currentSum =  currentSum + arr[i];
    if(currentSum < 0){
      currentSum = 0;
    }
    maxCumSum = max(maxCumSum,currentSum);
  }

  cout<<maxCumSum;
  
}



int main(){
  int n;
  cin>>n;
  int arr[n];

  for(int i = 0;i<n;i++){
    cin>>arr[i];
  }

  kadaneAlgo(arr,n);
}