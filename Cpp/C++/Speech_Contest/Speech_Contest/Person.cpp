#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Person.h"

string local_placeholder = "--.--";

Person::Person(string name, int number)
{
	this->m_name = name;
	this->m_number = number;
}

pair<int, int> Person::GetPrInf()
{
	return pair<int, int>(this->m_age, this->m_higth);
}

void Person::give_score(float score, string round)
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

void Person::show_inf()
{
	char output[1024] = "";
	string output_name = " ";
	if (this->m_name.size() > 6)
	{
		output_name += this->m_name.substr(0, 5) + ".";
	}
	else
	{
		output_name += this->m_name;
	}

	if (this->first_score == -1)
	{
		sprintf_s(output, sizeof(output), "%06d  %-6s    %4s      %4s", this->m_number, output_name.c_str(), local_placeholder.c_str(), local_placeholder.c_str());
	}
	else if (this->final_score == -1)
	{
		sprintf_s(output, sizeof(output), "%06d  %-6s    %4.2f      %4s", this->m_number, output_name.c_str(), this->first_score, local_placeholder.c_str());
	}
	else
	{
		sprintf_s(output, sizeof(output), "%06d  %-6s    %4.2f      %4.2f", this->m_number, output_name.c_str(), this->first_score, this->final_score);
	}
	cout << output << endl;
}

