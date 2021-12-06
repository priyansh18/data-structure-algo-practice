#include<iostream>
#include<climits>
using namespace std;

void maxTillIndex(int arr[],int n){
    int mx = INT_MIN;
    for(int i = 0;i<n;i++){
            mx = max(mx,arr[i]);
            cout<<"At index "<<i<<" maximum value "<<mx<<endl;
    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    
    maxTillIndex(arr,n);

}