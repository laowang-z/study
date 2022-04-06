#include<iostream>
#include<string>
#include<iomanip>
#include<functional>
using namespace std;
#include<algorithm>
#include<vector>
#include<deque>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<map>

void PrintVector(const vector<int>& v)
{
	for (vector<int>::const_iterator i = v.begin(); i != v.end(); i++)
	{
		cout << *i << "  ";
	}
	cout << endl;
}

class Person
{
public:
	Person(string name, int age, int hight)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Hight = hight;
	}
	string m_Name;
	int m_Age;
	int m_Hight;
};

class MyCompare
{
public:
	bool operator() (const Person& p1, const Person& p2)const;
};

bool MyCompare::operator() (const Person& p1, const Person& p2)const
{
	return p1.m_Age > p2.m_Age;
}


int main()
{
	vector<int> v;
	vector<int> v1;
	int val(10);



}