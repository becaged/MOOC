// MOOC_C++.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "code.h"
using namespace std;

robot number1;
int main()
{
	char stop = 'N';
	do
	{
		//rate();
		//bubble_sort();
		//triangle_Area();//计算三角形面积
		//factorial();
		robot number1;
		number1.cinnum();
		//循环退出命令输入  loop stop condition
		cout << "Input 'y'or'Y' to exit ";
		cin >> stop;
	} while (stop != 'y' && stop != 'Y');//输入y或Y退出
	cout << "Exit" << endl;
	system("pause");
	return 0;
}

