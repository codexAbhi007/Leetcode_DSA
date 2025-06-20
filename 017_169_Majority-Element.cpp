//https://leetcode.com/problems/majority-element/


#include <bits/stdc++.h>
using namespace std;


//* Using HashMap 
//* TC-> O(n) / O(logn) + O(n)
//* SC-> O(n)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hashMap;
        int n = nums.size();
        int i;
        for(i = 0; i< n; ++i){
            hashMap[nums[i]]++;
        }
        int major = n/2;
        int element = 0;
        for(auto it:hashMap){
            if(it.second > major){
                element = it.first;
                break;
            }
        }

        return element;
    }
};

//* Moore Voting Algorithm

//* 1) Apply Algo 2) Verify 

// If the array contains a majority element, its occurrence must be greater than the floor(N/2). Now, we can say that the count of minority elements and majority elements is equal up to a certain point in the array. So when we traverse through the array we try to keep track of the count of elements and the element itself for which we are tracking the count. 

// After traversing the whole array, we will check the element stored in the variable. If the question states that the array must contain a majority element, the stored element will be that one but if the question does not state so, then we need to check if the stored element is the majority element or not. If not, then the array does not contain any majority element.

// Approach: 
// Initialize 2 variables:
// Count –  for tracking the count of element
// Element – for which element we are counting
// Traverse through the given array.
// If Count is 0 then store the current element of the array as Element.
// If the current element and Element are the same increase the Count by 1.
// If they are different decrease the Count by 1.
// The integer present in Element should be the result we are expecting 

//Verification not Needed (see Coding Ninja for the other type)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int count = 0;
       int el;
       int i;
       for(i = 0; i< nums.size(); ++i){
        if(count == 0){
            el = nums[i];
            ++count;
        }
        else if(nums[i] != el){
            --count;
        }
        else{
            ++count;
        }
       }

       return el;
    }
};