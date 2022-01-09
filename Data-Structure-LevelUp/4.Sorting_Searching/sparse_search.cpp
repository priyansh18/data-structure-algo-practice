#include <cstring>
#include <iostream>
using namespace std;

int sparse_search(string arr[], int n, string str) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        int mid_left = mid - 1;
        int mid_right = mid + 1;
        if (arr[mid] == "") {
            while (1) {
                if (mid_left < start and mid_right > end) {
                    return -1;
                } else if (mid_right <= end and arr[mid_right] != "") {
                    mid = mid_right;
                    break;
                } else if (mid_left >= start and arr[mid_left] != "") {
                    mid = mid_left;
                    break;
                }
                mid_left--;
                mid_right++;
            }
        }else if(arr[mid]==str){
          return mid;
        } else if (arr[mid] > str) {
            end = mid - 1;
        } else if (arr[mid] < str) {
            start = mid + 1;
        }
    }
    return -1;
}

int main() {
    string arr[] = {"ai",  "",    "", "bat", "",    "",
                    "car", "cat", "", "",    "dog", "e"};
    int n = 12;
    string str = "bat";
    cout << sparse_search(arr, n, str) << endl;
}