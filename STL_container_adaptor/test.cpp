#include"string.h"
#include"vector.h"
#include"list.h"
#include<iostream>
using namespace std;

void String_test1()
{
	String s1("hello");
	s1[0] = 'x';
	cout << s1.c_str() << endl;

	String copy1(s1);
	cout << copy1.c_str() << endl;

	copy1[0] = 'h';
	cout << s1.c_str() << endl;
	cout << copy1.c_str() << endl;

	String s2 = "world";
	s1 = s2;
	cout << s1.c_str() << endl;

	String::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void String_test2()
{
	String s1("hello");
	cout << s1.capacity() << endl;
	s1 += "world";
	cout << s1.capacity() << endl;
	s1 += '!';
	cout << s1.capacity() << endl;
	cout << s1.c_str() << endl;

	String s2("helloworld");
	s2.insert(5, ' ');
	cout << s2.c_str() << endl;
	s2.insert(0, '$');
	cout << s2.c_str() << endl;
}

//#include<vector>
//void test_vector1()
//{
//	vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//
//	for (size_t i = 0; i < v1.size(); ++i)
//	{
//		cout << v1[i] << " ";
//	}
//	cout << endl;
//
//	vector<int>::iterator it1 = v1.begin();
//	while (it1 != v1.end())
//	{
//		cout << *it1 << " ";
//		++it1;
//	}
//	cout << endl;
//
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	vector<int> v2(10, int());
//	vector<int> v3(10, 5);
//
//	vector<int> v4(v1.begin(), v1.end());
//	vector<int> v5(++v1.begin(), --v1.end());
//}

void vector_test1()
{
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	//v.pop_back();
	//v.pop_back();
	auto it = v.begin();
	v.insert(it, 0);
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	it = v.begin();
	v.erase(it);

	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void vector_test2()
{
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	
	Vector<int> v2(v);
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;
}

//#include<list>
//#include<algorithm>
//void test_list1()
//{
//	list<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_back(3);
//	l.push_back(3);
//	l.push_back(3);
//	l.push_back(3);
//	l.push_back(3);
//	l.push_back(4);
//	l.push_back(2);
//	l.push_back(0);
//	//l.sort();//升序排序
//	l.unique();//去重(有序的才去)
//
//	list<int>::iterator it = l.begin();
//	while (it != l.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//
//void test_list2()
//{
//	list<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_back(4);
//
//	list<int>::iterator pos = find(l.begin(), l.end(), 3);
//	l.insert(pos, 30);
//
//	*pos = 300;
//	cout << *pos << endl;
//
//	for (auto e : l)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}

void print_list(const List<int>& l)
{
	List<int>::const_iterator it = l.begin();
	while (it != l.end())
	{
		//*it = 10;//it.operator*()=10;//const迭代器只能读无法写
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void list_test1()
{
	List<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	print_list(l);

	List<int>::iterator it = l.begin();
	while (it != l.end())
	{
		*it *= 10;//it.operator*()=10;//既能读也能写
		++it;
	}
	cout << endl;

	print_list(l);
}

void list_test2()
{
	List<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	print_list(l);

	List<int> copy = l;
	l.push_back(5);
	print_list(copy);
}

//#include<stack>
//#include<queue>
//
//void test_stack1()
//{
//	stack<int> s;
//	s.push(1);
//	s.push(2);
//	s.push(3);
//	s.push(4);
//
//	while (!s.empty())
//	{
//		cout << s.top() << endl;
//		s.pop();
//	}
//}
//
//void test_queue1()
//{
//	queue<int> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//
//	while (!q.empty())
//	{
//		cout << q.front() << endl;
//		q.pop();
//	}
//}

int main()
{


	//test_queue1();
	//test_stack1();
	
	//list_test1();
	//list_test2();

	//test_list2();
	//test_list1();

	//vector_test1();
	//vector_test2();

	//test_vector1();
	//cout << int() << endl;

	//String_test1();
	//String_test2();

	system("pause");
	return 0;
}