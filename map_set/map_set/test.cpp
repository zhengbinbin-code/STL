#include<iostream>
using namespace std;

#include"BinarySearchTree.h"
#include"map_set.h"
#include"AVLTree.h"

//#include<vector>		//随机迭代器
//#include<list>			//双向迭代器
//#include<forward_list>	//单向迭代器
//#include<algorithm>
//void test1()
//{
//	vector<int> v = { 1, 4, 3, 2 };
//	forward_list<int> fl = { 1, 4, 3, 2 };
//	list<int> l = { 1, 4, 3, 2 };
//
//	find(v.begin(), v.end(), 2);
//	find(fl.begin(), fl.end(), 2);
//	find(l.begin(), l.end(), 2);
//
//	sort(v.begin(), v.end());
//	//sort(fl.begin(), fl.end());	//不支持
//	//sort(l.begin(), l.end());		//不支持
//}

int main()
{
	//test_map_set1();
	//test_map_set2();
	//test_map_set3();
	//test_map_set4();
	//test_map_set5();

	//test1();

	testAVLTree();



	//TestBSTreeKV1();
	system("pause");
	return 0;
}