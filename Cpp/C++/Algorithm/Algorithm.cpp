#include<iostream>
using namespace std;
#include<string>

class Solution
{
public:
	bool rotateString(string s, string goal);
};

bool Solution::rotateString(string s, string goal)
{
	int rotate_time = 0;
	int s_length = s.size();
	int goal_length = goal.size();
	if (s_length != goal_length)
		return false;
	while (rotate_time < s_length)
	{
		int x_index = s.find(goal[0]);
		if (x_index == -1)
			return false;
		rotate_time += x_index;
		s = s.substr(x_index, s_length) + s.substr(0, x_index);
		if (s == goal)
			return true;
	}
	return false;
}

