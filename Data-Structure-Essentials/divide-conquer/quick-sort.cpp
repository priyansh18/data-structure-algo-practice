#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int s, int e) {
    int i = s-1;
    int pivot = arr[e];
    for (int j = s; j < e; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[e]);
    // Return index of Exact location of Pivot element
    return i+1;
}

void quick_sort(vector<int> &arr, int s, int e) {
    if (s >= e) {
        return;
    }
    int p = partition(arr, s, e);
    quick_sort(arr, s, p - 1);
    quick_sort(arr, p + 1, e);
}

int main() {
    vector<int> arr{10, 2, 5, 6, 0, 4, 7, 3};
    int s = 0;
    int e = arr.size() - 1;
    quick_sort(arr, s, e);

    for(int x:arr){
      cout<<x<<" , ";
    }
    return 0;
}