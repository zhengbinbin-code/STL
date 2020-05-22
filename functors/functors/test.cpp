#include<iostream>

using namespace std;

struct Less
{
	bool operator()(int a, int b)
	{
		return a < b;
	}
};

int main()
{
	Less less;
	cout << less.operator()(1, 2) << endl;
	cout << less(1, 2) << endl;
	system("pause");
	return 0;
}