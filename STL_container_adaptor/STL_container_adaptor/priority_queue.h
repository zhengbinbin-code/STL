#pragma once
#include<vector>

template<class T>
class my_less
{
public:
	bool operator()(const T& l, const T& r)
	{
		return l < r;
	}
};

template<class T>
class my_greater
{
public:
	bool operator()(const T& l, const T& r)
	{
		return l > r;
	}
};

//Ä¬ÈÏ´ó¶Ñ
template<class T, class Container = vector<T>, class compare = my_less<T>>
class Priority_queue
{
public:
	void adjust_up(int child)
	{
		compare com;
		int parent = (child - 1) / 2;
		while (child > 0)
		{
			//if (_con[parent] < _con[child])
			if (com(_con[parent], _con[child]))
			{
				swap(_con[child], _con[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}

	void adjust_down(int root)
	{
		int parent = root;
		int child = parent * 2 + 1;
		compare com;
		while (child < _con.size())
		{
			//if (child + 1 < _con.size() && _con[child] < _con[child + 1])
			if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
			{
				++child;
			}
			//if (_con[parent] < _con[child])
			if (com(_con[parent], _con[child]))
			{
				swap(_con[parent], _con[child]);
				parent = child;
				child = parent * 2 - 1;
			}
			else
			{
				break;
			}
		}
	}

	void push(const T& x)
	{
		_con.push_back(x);
		adjust_up(_con.size() - 1);
	}

	void pop()
	{
		swap(_con[0], _con[_con.size() - 1]);
		_con.pop_back();
		adjust_down(0);
	}

	T& top()
	{
		return _con[0];
	}

	size_t size()
	{
		return _con.size();
	}

	bool empty()
	{
		return _con.empty();
	}
private:
	Container _con;
};