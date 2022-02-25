#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    int n = nums.size();

    int i = 0;
    while (i < n - 1) {
        if (nums[i] < nums[i + 1]) {
            i++;
        } else {
            break;
        }
    }
    
    vector<int> li;

    int j = i + 1;
    while (j < n) {
        li.push_back(nums[j]);
        j++;
    }

    int k = 0;
    while (k <= i) {
        li.push_back(nums[k]);
        k++;
    }

    i = 0;
    for (; i < li.size() - 1; i++) {
        if (li[i] > li[i + 1]) {
            cout << "false" << endl;
            break;
        }
    }
    if (i == li.size()-1) {
        cout << "true";
    }
}