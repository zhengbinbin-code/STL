using namespace std;
#include<assert.h>

template<class T>
struct __List_node
{
	__List_node<T>* _next;
	__List_node<T>* _prev;
	T _data;

	__List_node(const T& x = T()) :_data(x), _next(nullptr), _prev(nullptr)
	{ }
};

template<class T, class Ref, class Ptr>
struct __List_iterator
{
	typedef __List_node<T> node;
	typedef __List_iterator<T, Ref, Ptr> Self;
	node* _node;

	__List_iterator(node* node) :_node(node)
	{ }

	Ref operator*()//内置类型
	{
		return _node->_data;
	}

	Ptr operator->()//自定义类型
	{
		return &_node->_data;  
	}

	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}
	
	Self operator++(int)
	{
		__List_iterator<T> tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	Self operator--(int)
	{
		__List_iterator<T> tmp(*this);
		_node = _node->_prev;
		return tmp;
	}

	//it1 != it2
	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	bool operator==(const Self& it)
	{
		return _node == it._node;
	}
};

template<class T>
class List
{
	typedef __List_node<T> node;
public:
	typedef __List_iterator<T, T&, T*> iterator;
	typedef __List_iterator<T, const T&, const T*> const_iterator;

	const_iterator begin()const
	{
		return const_iterator(_head->_next);
	}
	const_iterator end()const
	{
		return const_iterator(_head);
	}

	iterator begin()
	{
		return iterator(_head->_next);
	}
	iterator end()
	{
		return iterator(_head);
	}

	List(const List<T>& l)
	{
		_head = new node(T());
		_head->_next = _head;
		_head->_prev = _head;

		//const_iterator it = l.begin();
		auto it = l.begin();
		while (it != l.end())
		{
			push_back(*it);
			++it;
		}
	}

	/*List<T>& operator=(const List<T>& l)
	{
		this->clear();
		auto it = l.begin();
		while (it != l.end())
		{
			push_back(*it);
			++it;
		}
	}*/
	List<T>& operator=(List<T> l)
	{
		swap(_head, l._head);
		return *this;
	}

	List()
	{
		_head = new node(T());
		_head->_next = _head;
		_head->_prev = _head;
	}

	~List()
	{
		clear();
		delete _head;
		_head = nullptr;
	}

	void clear()
	{
		iterator it = begin();
		while (it != end())
		{
			it = erase(it);
		}
	}
	
	void push_back(const T& x)
	{
		/*node* tail = _head->_prev;
		node* newnode = new node(x);
		tail->_next = newnode;
		newnode->_next = _head;
		newnode->_prev = tail;
		_head->_prev = newnode;*/
		insert(end(), x);
	}

	void push_front(const T& x)
	{
		insert(begin(), x);
	}

	void pop_back(const T& x)
	{
		erase(--end());
	}

	void pop_front(const T& x)
	{
		erase(begin());
	}


	void insert(iterator pos, const T& x)
	{
		node* cur = pos._node;
		node* prev = cur->_prev;

		node* newnode = new node(x);

		prev->_next = newnode;
		newnode->_next = cur;
		newnode->_prev = prev;
		cur->_prev = newnode;
	}

	iterator erase(iterator pos)
	{
		node* cur = pos._node;
		assert(cur != _head);

		node* prev = cur->_prev;
		node* next = cur->_next;

		prev->_next = next;
		next->_prev = prev;

		delete cur;
		return iterator(next);
	}

private:
	node* _head;
};

