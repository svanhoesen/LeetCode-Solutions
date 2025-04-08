/*
* Author: Steffan Van Hoesen
* Date: April 8th, 2025
* Name: twoSum
* Purpose: Solve the twoSum problem with optimal time and space complexity.
* Description: Given an array of integers nums and an integer target, determine which method to use then return indices of the two numbers such that they add up to target.
* Given Assumptions:  1) You may assume that each input would have exactly one solution, and you may not use the same element twice.
*                     2) You can return the answer in any order.
* Return: Return indices of the two numbers such that they add up to target or returns an empty vector.
*/

#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        if(nums.size()>100)
        {
            return twoSumL(nums, target);
        }
        else
        {
            return twoSumS(nums, target);
        }
        return {};
    }
    /*
    * Author: Steffan Van Hoesen
    * Date: April 8th, 2025
    * Name: twoSumL
    * Purpose: A variation of twoSum for large data sets.
    * Description: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
    * Return: returns the indices of the two numbers that add up to the target or returns an empty vector.
    */
    vector<int> twoSumL(vector<int>& nums, int target)
    {
        std::unordered_map<int, int> map;
        for(int i=0;i<nums.size();i++)
        {
            int complement = target - nums[i];
            if(map.contains(complement))
            {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
    /*
    * Author: Steffan Van Hoesen
    * Date: April 8th, 2025
    * Name: twoSumS
    * Purpose: A variation of twoSum for small data sets.
    * Description: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
    * Return: returns the indices of the two numbers that add up to the target or returns an empty vector.
    */
    vector<int> twoSumS(vector<int>& nums, int target)
    {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]] = i;
        }
        for(int i=0;i<nums.size();i++)
        {
            int complement = target - nums[i];
            if(map.contains(complement) && map[complement] != i)
            {
                return {map[complement], i};
            }
        }
        return {};
    }
};
