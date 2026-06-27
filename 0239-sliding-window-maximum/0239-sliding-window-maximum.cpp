class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // code here
    vector<int> res;
    // create deque to store maximum val
    deque<int> dq(k);
    // Process first k (or first window) elements of array
    for (int i = 0; i < k; ++i) {
        while (!dq.empty() && nums[i] >= nums[dq.back()])
         {
            dq.pop_back();
        }

        dq.push_back(i);
    }
    for (int i = k; i < nums.size(); ++i) 
    {
        res.push_back(nums[dq.front()]);
        while (!dq.empty() && dq.front() <= i - k) 
        {
          
            dq.pop_front();
        }

        while (!dq.empty() && nums[i] >= nums[dq.back()]) 
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    res.push_back(nums[dq.front()]);

    return res;
        
    }
};