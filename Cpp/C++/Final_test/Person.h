#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<string>


class Person
{
public:
	Person(string name, int number);
	pair<int, int> GetPrInf();
	void GiveScore(float score, string round);
	void ShowInf();
	string m_name;
	int m_number;
	float first_score = -1;
	float final_score = -1;
private:
	int m_higth = -1;
	int m_age = -1;
};

string local_placeholder = "--";