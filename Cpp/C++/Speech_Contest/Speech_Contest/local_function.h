#pragma once
#include<iostream>
using namespace std;
#include<algorithm>
#include<string>
#include<vector>
#include<ctime>
#include"Person.h"

class LocalFunction
{
public:
	LocalFunction();
	void show_header();
	float show_get_scorelab(const Person& p);
	char referees[1024];
};