#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int> > findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> a1, a2;
        for(const auto &i: nums1) a1.insert(i);
        for(const auto &i: nums2) a2.insert(i);
        vector<int> v1, v2;

        for(auto &i: a1){
            if(a2.find(i) == a2.end()) v1.push_back(i);
        }
        for(auto &i: a2){
            if(a1.find(i) == a1.end()) v2.push_back(i);
        }
        vector<vector<int>> ans;
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
    }
};