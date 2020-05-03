#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<string.h>
#include<assert.h>

class String
{
public:

	typedef const char* const_iterator;
	typedef char* iterator;

	const iterator begin()const
	{
		return _str;
	}
	iterator begin()
	{
		return _str;
	}
	iterator end()
	{
		return _str + _size;
	}

	/*String() :_str(new char[1])
	{
	*_str = '\0';
	}*/

	String(const char* str = "") :_str(new char[strlen(str) + 1])
	{
		//ÒÑ¾­¿½±´'\0'
		strcpy(_str, str);	//while (*dest++ = *src++);
		_size = strlen(str);
		_capacity = _size;
	}

	~String()
	{
		delete[]_str;
		_str = nullptr;
		_size = _capacity = 0;
	}

	//Éî¿½±´
	//String copy1(s1)
	String(const String& s) :_str(new char[s._size + 1]), _size(s._size), _capacity(s._size)
	{
		strcpy(_str, s._str);
	}

	//s1 = s2;
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			delete[]_str;
			_str = new char[s._size + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}
		return *this;
	}

	const char* c_str()
	{
		return _str;
	}

	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}
	const char& operator[](size_t pos)const
	{
		assert(pos < _size);
		return _str[pos];
	}

	size_t size()
	{
		return _size;
	}

	size_t capacity()
	{
		return _capacity;
	}

	//Ô¤Áô
	void reserve(size_t n)		//reverse:ÄæÖÃ
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[]_str;
			_str = tmp;
			_capacity = n;
		}
	}

	void push_back(char ch)
	{
		//if (_size == _capacity)
		//{
		//	//À©ÈÝ
		//	reserve(_capacity * 2);
		//}
		//_str[_size] = ch;
		//++_size;
		//_str[_size] = '\0';
		insert(_size, ch);
	}

	//s1.append("11111");
	void append(const char* str)
	{
		//size_t len = strlen(str);
		//if (_size + len > _capacity)
		//{
		//	//À©ÈÝ
		//	reserve(_size + len);
		//}
		//strcpy(_str + _size, str);
		//_size += len;
		insert(_size, str);
	}

	const String& operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}
	const String& operator+=(const char* str)
	{
		append(str);
		return *this;
	}
	const String& operator+=(const String& s)
	{
		append(s._str);
		return *this;
	}

	void insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		if (_size == _capacity)
		{
			if (_capacity == 0)
			{
				reserve(8);
			}
			else
			{
				reserve(_capacity * 2);
			}
		}
		/*int end = _size;
		while (end >= (int)pos)
		{
		_str[end + 1] = _str[end];
		--end;
		}*/
		size_t end = _size + 1;
		while (end >= pos + 1)
		{
			_str[end] = _str[end - 1];
			--end;
		}
		_str[pos] = ch;
		++_size;
	}
	void insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		/*int end = _size;
		while (end >= (int)pos)
		{
		_str[end + len] = _str[end];
		--end;
		}*/
		size_t end = _size + len;
		while (end >= pos + len)
		{
			_str[end] = _str[end - len];
			--end;
		}
		while (*str)
		{
			_str[pos++] = *str++;
		}
		_size += len;
	}

	bool operator>(const String& s)const
	{
		const char* str1 = _str;
		const char* str2 = s._str;
		while (*str1 && *str2)
		{
			if (*str1 > *str2)
			{
				return true;
			}
			else if (*str1 < *str2)
			{
				return false;
			}
			else
			{
				str1++;
				str2++;
			}
		}
		if (*str1) return true;
		if (*str2) return false;
		return false;
	}
	bool operator==(const String& s)const
	{
		const char* str1 = _str;
		const char* str2 = s._str;
		while (*str1 && *str2)
		{
			if (*str1 != *str2)
			{
				return false;
			}
			str1++;
			str2++;
		}
		if (*str1 || *str2)
		{
			return false;
		}
		return true;
	}
	bool operator>=(const String& s)const
	{
		return *this > s || *this == s;
	}
	bool operator<(const String& s)const
	{
		return !(*this > s || *this == s);
	}

	/*size_t find(char ch)
	{
		for (size_t i = 0; i < _size; ++i)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}
		return String::npos;
	}*/
	//size_t find(const char* str)	//strstr ->kmp bm
	//{
	//	const char* pos = strstr(_str, str);
	//	if (pos == nullptr)
	//	{
	//		return npos;
	//	}
	//	else
	//	{
	//		return pos - _str;
	//	}
	//}

	//size_t find(const char* str)	//strstr ->kmp bm
	//{
	//	const char* src = _str;
	//	const char* dst = str;
	//	size_t srclen = _size;
	//	size_t dstlen = strlen(dst);
	//	size_t srcindex = 0;
	//	while (srcindex < srclen)
	//	{
	//		size_t i = srcindex;
	//		size_t j = 0;
	//		while (j < dstlen && src[i] == dst[j])
	//		{
	//			++i;
	//			++j;
	//		}
	//		if (j == dstlen)
	//		{
	//			return srcindex;
	//		}
	//		srcindex++;
	//	}
	//	return npos;
	//}

	//operator+

	//ostream& operator<<(ostream& out, const String& s)
	//{
	//	//out<<s.c_str();
	//	for (size_t i = 0; i < s.size(); ++i)
	//	{
	//		out << s[i];
	//	}
	//	return out;
	//}

	//istream& operator>>(istream& in, String& s)
	//{
	//	char ch = in.get();
	//	while (ch != ' ' && ch != '\n')
	//	{
	//		s += ch;
	//		ch = in.get();
	//	}
	//	return in;
	//}

	//getline

private:
	char* _str;
	size_t _size;
	size_t _capacity;
};