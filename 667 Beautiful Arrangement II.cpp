class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        int small = 1, large = n;
        while(small <= large)
        {
            if(k > 1)
            {
                res.push_back((k%2==0)?small++:large--);
                k--;
            }
            else
            {
                res.push_back(large--);
            }
        }
        
        return res;
    }
};