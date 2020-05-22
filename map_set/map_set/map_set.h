#pragma once
#include<map>
#include<set>
#include<string>
using namespace std;

void test_map_set1()
{
	set<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(5);
	s.insert(8);
	s.insert(9);
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	set<int>::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	auto pos = s.find(5);	//传值找5所在位置的迭代器---set成员函数查找		O(logN)
	//auto pos = std::find(s.begin(), s.end(), 5);	//算法中的查找			O(N)
	if (pos != s.end())		//传迭代器删除元素，必须判断
	{
		s.erase(pos);	
	}

	s.erase(5);		//传值删除元素不用判断

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_map_set2()
{
	map<string, string> dict;
	dict.insert(pair<string,string>("insert", "插入"));
	dict.insert(pair<string, string>("left", "左边"));
	dict.insert(pair<string, string>("right", "右边"));
	dict.insert(pair<string, string>("node", "节点"));
	dict.insert(pair<string, string>("tree", "树"));
	dict["sort"] = "排序";

	/*string str;
	while (cin >> str)
	{
		auto ret = dict.find(str);
		if (ret != dict.end())
		{
			cout << str << ":" << (*ret).second << endl;
		}
		else
		{
			cout << str << ":" << "非法词汇" << endl;
		}
	}*/

	//string strs[] = { "苹果", "西瓜", "草莓", "草莓", "西瓜", "草莓" };
	//map<string, int> countMap;
	//for (auto& e : strs)
	//{
	//	//map<string, int>::iterator ret = countMap.find(e);
	//	auto ret = countMap.find(e);
	//	if (ret != countMap.end())
	//	{
	//		//(*ret).second++;
	//		ret->second++;
	//	}
	//	else
	//	{
	//		//调用构造函数创建匿名对象
	//		//countMap.insert(pair<string, int>(e, 1));

	//		/*template<class K,class V>
	//		inline pair<K,V> make_pair(const K& k, cosnt V& v)
	//		{
	//			return pair<K, V>(k, v);
	//		}*/
	//		countMap.insert(make_pair(e, 1));
	//	}
	//}

	/*V& operator[](const K& k)
	{
		pair<iterator, bool>ret = insert(make_pair(k, V()));
		return ret.first->second;
	}*/
	string strs[] = { "苹果", "西瓜", "草莓", "草莓", "西瓜", "草莓" };
	map<string, int> countMap;
	for (auto& e : strs)
	{
		countMap[e]++;
	}
	countMap["香蕉"];
	countMap["香蕉"] = 5;
	
	/*string strs[] = { "苹果", "西瓜", "草莓", "草莓", "西瓜", "草莓" };
	map<string, int> countMap;
	for (auto& e : strs)
	{
		pair<map<string, int>::iterator, bool>ret = countMap.insert(make_pair(e, 1));
		if (ret.second == false)
		{
			ret.first->second++;
		}
	}*/
}

void test_map_set3()
{
	map<string, string>dict;
	dict.insert(pair<string, string>("insert", "插入"));
	dict.insert(make_pair("isnrt", "插入"));

	dict.insert(pair<string, string>("left", "左边"));
	dict.insert(make_pair("left", "剩余"));
	dict["left"] = "剩余";		//方括号的作用：查找+修改(查找时如果不存在就会插入)
	dict["string"] = "字符串";		//方括号的作用：查找+插入
}

void test_map_set4()
{
	set<int> s;
	s.insert(3);
	s.insert(2);
	s.insert(1);
	s.insert(2);
	s.insert(4);

	multiset<int> ms;
	ms.insert(3);
	ms.insert(2);
	ms.insert(1);
	ms.insert(2);
	ms.insert(4);
	
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto e : ms)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_map_set5()
{
	map<string, string> dict;
	dict.insert(pair<string, string>("insert", "插入"));
	dict.insert(pair<string, string>("left", "左边"));
	dict.insert(pair<string, string>("right", "右边"));
	dict.insert(pair<string, string>("node", "节点"));
	dict.insert(pair<string, string>("tree", "树"));

	map<string, string>::iterator dit = dict.begin();
	while (dit != dict.end())
	{
		cout << (*dit).first << "----" << (*dit).second << endl;
		cout << dit->first << "----" << dit->second << endl;
		++dit;
	}

	string strs[] = { "苹果", "西瓜", "草莓", "草莓", "西瓜", "草莓" };
	map<string, int> countMap;
	for (auto& e : strs)
	{
		map<string, int>::iterator it = countMap.find(e);
		if (it != countMap.end())
		{
			it->second++;
		}
		else
		{
			countMap.insert(pair<string, int>(e, 1));
		}
	}
}


//#include<vector>
//#include<algorithm>
//#include<queue>
//struct CountCompare
//{
//	bool operator()(const pair<string, int>& l, const pair<string, int>& r)
//	{
//		return l.second > r.second;
//	}
//};
//void GetFavoriteFruit1(const vector<string>& fruits, size_t k)
//{
//	//1.统计各种水果出现的次数
//	map<string, int> countMap;
//	for (auto& e : fruits)
//	{
//		countMap[e]++;
//	}
//	//2.找出大家最喜欢吃的水果
//	//数组、vector、deque(效率低)
//	//vector<pair<string, int>> v(countMap.begin(),countMap.end());	//构造函数支持迭代器区间构造
//	vector<pair<string, int>> v;
//	for (auto& e : countMap)
//	{
//		v.push_back(e);
//	}
//
//	//O(N*logN)
//	sort(v.begin(), v.end(), CountCompare());
//	for (size_t i = 0; i < k; ++i)
//	{
//		cout << v[i].first << ":" << v[i].second << endl;
//	}
//}
//
//void GetFavoriteFruit2(const vector<string>& fruits, size_t k)
//{
//	//1.统计各种水果出现的次数
//	map<string, int> countMap;
//	for (auto& e : fruits)
//	{
//		countMap[e]++;
//	}
//	//2.找出大家最喜欢吃的水果
//	//找最大的前k个
//	priority_queue<pair<string, int>, vector<pair<string, int>>, CountCompare> pq;
//	size_t i = 0;
//	for (auto& e : countMap)
//	{
//		if (i < k)
//		{
//			pq.push(e);
//			++i;
//		}
//		else
//		{
//			//O(logK)*N
//			if (e.second > pq.top().second)
//			{
//				pq.pop();
//				pq.push(e);
//			}
//		}
//	}
//}

















