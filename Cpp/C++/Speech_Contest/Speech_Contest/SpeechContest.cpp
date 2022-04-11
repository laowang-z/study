#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include"Person.h"
#include"local_function.h"


int main()
{
	vector<Person> v;
	LocalFunction lf;
	lf.show_header();
	Person p1("wjw", 000000);
	Person p2("zgdl", 000001);
	Person p3("wz", 000002);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	p1.show_inf();
	lf.show_header();
	for (vector<Person>::iterator i = v.begin(); i != v.end(); i++)
	{
		(*i).show_inf();
	}
	random_shuffle(v.begin(), v.end());
	(*v.begin()).give_score(lf.show_get_scorelab(*v.begin()));
	lf.show_header();
	for (vector<Person>::iterator i = v.begin(); i != v.end(); i++)
	{
		(*i).show_inf();
	}
}