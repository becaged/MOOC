// MOOC_C++.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "code.h"
using namespace std;

int main()
{
	while (1)
	{
		//rate();
		//bubble_sort();

		double a, b, c;
		cout << "please input the triangle's three length of side to calculate its area.(separated by either commas or spaces)" << endl;;
		cin >> a >> b >> c;
		cout << "the area of this triangle is " << Area(a, b, c) << "." << endl;

	}
	return 0;
}

