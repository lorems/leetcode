// Source : https://leetcode.com/problems/two-sum/
// Author : Laurent Beauregard
// Date   : 2019-02-10

// 1. Two Sum
// Easy
//
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// 
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// 
// Example:
// 
// Given nums = [2, 7, 11, 15], target = 9,
// 
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return[0, 1].

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Runtime: 12 ms, faster than 97.31% of C++ online submissions for Two Sum.
// Memory Usage : 6.8 MB, less than 0.99% of C++ online submissions for Two Sum.
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> result;
		unordered_map<int, int> m;

		for (int i = 0; i < nums.size(); i++)
		{
			if (m.count(target - nums[i]) == 1)
			{
				result.push_back(m[target - nums[i]]);
				result.push_back(i);
				break;
			}
			if (m.count(nums[i]) == 0)
				m[nums[i]] = i;
		}
		return result;
	}
};

int main()
{
	Solution s;

	vector<int> v = { 2, 7, 11, 15 };
	vector<int> vec = s.twoSum(v, 9);

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << "- " << *it << std::endl;

	cout << "Hello, World!";
	int vv;
	cin >> vv;
	return 0;
}