
vector<int> maxOfSubarray(vector<int> nums, int n, int k) {
    // Write your code here
    vector<int> result;
    if (k > n) {
        result.push_back(*max_element(nums.begin(), nums.end()));
        return result;
    }
    int i = 0;
    int j = 0;
    deque<int> q;
    while (j < n) {
        // Removing all smaller element than current
        while (!q.empty() and q.back() < nums[j]) {
            q.pop_back();
        }
        q.push_back(nums[j]);
        if (j - i + 1 < k) {
            j++;
        } else {
            result.push_back(q.front());
            if (q.front() == nums[i]) {
                q.pop_front();
            }
            i++;
            j++;
        }
    }

    return result;
}

int main() {
    vector<int> nums = {10, 7, 8, 11};
    int n = 4;
    int k = 2;
    vector<int> result = maxOfSubarray(nums, n, k);
    for (auto x : result) cout << x << ",";
}