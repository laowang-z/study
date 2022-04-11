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
//// copy(内容起始迭代器，内容结束迭代器，目标迭代器)将v1中的元素复制到v中，v需要开辟内存空间
//
//replace(v.begin(), v.end(), x, y);
////将v[begin, end)内的x替换成y
//
//replace_if(v.begin(), v.end(), Bigger30(), 30);
////将v[begin, end)内大于30的元素替换为30
//
//swap(v, v1);
////将v和v1的元素互换，v和v1应该是相同的数据类型
//
//accumulate(v.begin(), v.end(), x);
////计算v[begin, end)的总和 + x
//
//fill(v.begin(), v.end(), x);
////将v[begin, end)区间用x填充
//
//set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
////将v1和v2的交集复制到v中，v需要开辟内存空间
//
//set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
////将v1和v2的并集复制到v中，v需要开辟内存空间
//
//set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
////将v1和v2的差集复制到v中，v需要开辟内存空间，算法会返回一个迭代器，这个迭代器指向复制到v中的最后一个元素的下一个位置
	string s = "aaaaa";
	cout << s[0] << endl;

}