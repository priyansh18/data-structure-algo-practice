#include<iostream>
#include<climits>
using namespace std;

void allSubarrayPrint(int arr[],int n){
  for(int i = 0;i<n;i++){
    cout<<"------------------"<<endl;
    for(int j = 0;j<n;j++){
      for(int k = i;k<=j;k++){
        cout<<arr[k]<<" ";
      }
      cout<<endl;
    }
    cout<<endl;
  }
}

// Print All Subarray Sum O(n^3)

void allSubarraySumPrint(int arr[],int n){
  for(int i = 0;i<n;i++){
    cout<<"------------------"<<endl;
    for(int j = 0;j<n;j++){
      int sum = 0;
      for(int k = i;k<=j;k++){
        sum = sum + arr[k];
        cout<<sum<<" ";      
      }
      cout<<endl;
    }
    cout<<endl;
  }
}

// Print All Subarray Sum O(n^2 + n)

void allSubarrayPrintOptimized(int arr[],int n){
  int prefixSum[n];
  prefixSum[0] = arr[0];
  for (int i = 1; i < n; i++){
    prefixSum[i] = prefixSum[i-1] + arr[i];
  }
  
  for(int i = 0;i<n;i++){
    if(i == 0){
      for (int i = 0; i < n; i++)
      {
          cout<<prefixSum[i]<<endl;
      }
      continue;
    }
    for(int j = i;j<n;j++){
      cout<< prefixSum[j] - prefixSum[i-1]<<" ";
    }
  }
}
int main(){
 int n;
 cin>>n;
 int arr[n];
 for(int i = 0;i<n;i++){
   cin>>arr[i];
 }

 allSubarrayPrint(arr,n); 


 allSubarraySumPrint(arr,n);


 allSubarrayPrintOptimized(arr,n);
}

 