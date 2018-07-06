#include "stdafx.h"
#include "code.h"
using namespace std;

double Area(double a, double b, double c);

double rate()
{
	double money, years, rate, sum;
	std::cout << "请输入本金、存款年份、年利率，以空格隔开，按回车结束" << std::endl;
	std::cin >> money >> years >> rate;
	while (money > 0)
	{
		sum = money * pow((1 + rate), years);
		std::cout << "本息共" << sum << std::endl;
		std::cout << "请输入本金、存款年份、年利率，以空格隔开，按回车结束\7" << std::endl;
		std::cin >> money >> years >> rate;
	}
	return money;
}

/*bubble sort ,return the number of elements <100 冒泡排序 100以内 返回数组元素个数 */
int bubble_sort()
{
	std::cout << "****冒泡排序****" << std::endl << std::endl;
	double arr[100];
	int N = 0;
	while (N < 1 || N > 100 )
	{
		std::cout <<"请输入待排序元素数量(1-100)"<< std::endl;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "输入值非法" << std::endl;
		}
		std::cin >> N;
	}
 	for ( int i = 0; i < N; i++)
	{
		while ( std::cin.fail() )
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "输入值非法" << std::endl;
		}
		std::cout << "输入第" << i + 1 << "个元素，共" << N << "个" << std::endl;
		std::cin >> arr[i];
	}
	std::cout << "输入结束" << std::endl;
	for ( int i = 0 ; i < N-1; i++)
	{
		double temp;
		for ( int j = 0 ; j < N - i - 1 ; j++ )
		{
			if ( arr[j] > arr[j+1] )
				{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				}
		}
	}
	std::cout << "排序后数组如下：" << std::endl;
	for (int i = 0; i < N ; i++)
	{
		std::cout << arr[i] << " ";
		if ( !( (i+1) % 16) )
			std::cout << std::endl;
	}
	std::cout << std::endl;
	return N;
}

/* 计算三角形面积*/
void triangle_Area()
{
	double a, b, c;
	cout << "please input the triangle's three length of side to calculate its area.(separated by either commas or spaces)" << endl;;
	cin >> a >> b >> c;
	cout << "the area of this triangle is " << Area(a, b, c) << "." << endl;
}
double Area(double a, double b, double c)
{
	double size,p;
	p = (a + b + c) / 2;
	size = sqrt(p*(p - a)*(p - b)*(p - c));
	return size;
}

/*使用引用变量交换传入值，调用后会改变传入值*/
void swap(int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
	return ;
}



