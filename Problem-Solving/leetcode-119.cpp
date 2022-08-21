
 // Pascal Triangle II

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n=rowIndex;
       vector<int> res;
       res.push_back(1);
        for(int i=1;i<=n;i++)
        {
           int x= (int) ( ((long long)res.back()*(n-i+1) ) /i);
           res.push_back(x);
        }
        return res;
    }
};