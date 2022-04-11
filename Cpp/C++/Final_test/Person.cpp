#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include"Person.h"



Person::Person(string name, int number)
{
	this->m_name = name;
	this->m_number = number;
}

pair<int, int> Person::GetPrInf()
{
	return pair<int, int>(this->m_age, this->m_higth);
}

void Person::GiveScore(float score, string round)
{
	if (round == "Second")
	{
		this->final_score = score;
	}
	else
	{
		this->first_score = score;
	}
}

void Person::ShowInf()
{
	char output[1024];
	if (this->first_score == -1)
	{
		sprintf_s(output, sizeof(output), "%-6d  %-10s  %4s  %4s", this->m_number, this->m_name.c_str(), local_placeholder.c_str(), local_placeholder.c_str());
	}
	else if (this->final_score == -1)
	{
		sprintf_s(output, sizeof(output), "%-6d  %-10s  %4.2f  %4s", this->m_number, this->m_name.c_str(), this->first_score, local_placeholder.c_str());
	}
	else
	{
		sprintf_s(output, sizeof(output), "%-6d  %-10s  %4.2f  %4.2f", this->m_number, this->m_name.c_str(), this->first_score, this->final_score);
	}
	cout << output << endl;
}

