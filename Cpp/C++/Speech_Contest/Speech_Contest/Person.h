#pragma once
#include<iostream>
using namespace std;
#include<string>


class Person
{
public:
	Person(string name, int number);
	pair<int, int> GetPrInf();
	void give_score(float score, string round = "first");
	void show_inf();
	string m_name = "";
	int m_number;
	float first_score = -1;
	float final_score = -1;

private:
	int m_higth = -1;
	int m_age = -1;
};

