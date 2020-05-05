#pragma once

//ÊÊÅäÆ÷Ä£Ê½  ×ª»»
template<class T, class Container = deque<T>>
class Stack
{
public:
	void push(const T& x)
	{
		_con.push_back(x);
	}

	void pop()
	{
		_con.pop_back();
	}

	T& top()
	{
		return _con.back();
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