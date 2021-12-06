#include<iostream>
#include<climits>
using namespace std;

void bubbleSort(int arr[],int n){
    bool swap = false;
    for(int j=1;j<n;j++){
        if(!swap){
            for(int i = 1;i<n;i++){
                    if(arr[i]>arr[i+1]){
                        swap = true;
                        int temp = arr[i];
                        arr[i] = arr[i+1];
                        arr[i+1]= temp;
                    }
            }
        }
        else{
            break;
        }
    }
}


int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    
    bubbleSort(arr,n);

    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}