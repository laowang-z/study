#include<iostream>
#include<string>
#include<iomanip>
#include<functional>
#include<algorithm>
#include<numeric>
using namespace std;
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

class Bigger30
{
public:
	bool operator() (const int val);

private:

};

bool Bigger30::operator() (const int val)
{
	return val > 30;
}

int main()
{
//vector<int> v;
//vector<int> v1;
//vector<int> v2;
//int x, y;
//copy(v1.begin(), v1.end(), v.begin());
//// copy(������ʼ�����������ݽ�����������Ŀ�������)��v1�е�Ԫ�ظ��Ƶ�v�У�v��Ҫ�����ڴ�ռ�
//
//replace(v.begin(), v.end(), x, y);
////��v[begin, end)�ڵ�x�滻��y
//
//replace_if(v.begin(), v.end(), Bigger30(), 30);
////��v[begin, end)�ڴ���30��Ԫ���滻Ϊ30
//
//swap(v, v1);
////��v��v1��Ԫ�ػ�����v��v1Ӧ������ͬ����������
//
//accumulate(v.begin(), v.end(), x);
////����v[begin, end)���ܺ� + x
//
//fill(v.begin(), v.end(), x);
////��v[begin, end)������x���
//
//set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
////��v1��v2�Ľ������Ƶ�v�У�v��Ҫ�����ڴ�ռ�
//
//set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
////��v1��v2�Ĳ������Ƶ�v�У�v��Ҫ�����ڴ�ռ�
//
//set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
////��v1��v2�Ĳ���Ƶ�v�У�v��Ҫ�����ڴ�ռ䣬�㷨�᷵��һ�������������������ָ���Ƶ�v�е����һ��Ԫ�ص���һ��λ��
	string s = "aaaaa";
	cout << s[0] << endl;

}