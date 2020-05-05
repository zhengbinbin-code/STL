#pragma once

using namespace std;
template<class T, class Container = deque<T>>
class Queue
{
public:
	void push(const T& x)
	{
		_con.push_back(x);
	}

	void pop()
	{
		_con.pop_front();
	}

	T& back()
	{
		return _con.back();
	}

	T& front()
	{
		return _con.front();
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