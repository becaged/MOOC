#include "stdafx.h"
#include "code.h"
using namespace std;

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
double Area(double a, double b, double c)
{
	double size,p;
	p = (a + b + c) / 2;
	size = sqrt(p*(p - a)*(p - b)*(p - c));
	return size;
}
void triangle_Area()
{
	double a, b, c;
	cout << "please input the triangle's three length of side to calculate its area.(separated by either commas or spaces)" << endl;;
	cin >> a >> b >> c;
	cout << "the area of this triangle is " << Area(a, b, c) << "." << endl;
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

/*递归函数 计算n!*/
unsigned long int factorial_n(int n)
{
	return  (n > 0) ? (n*factorial_n(n - 1)) : 1;//?:运算，如果 n>0则调用自身，如果n=0则递归结束
}
void factorial()
{
	int n;
	cout << "Input n" << endl;
	cin >> n;
	cout << factorial_n(n)<< endl;
}

/*robot类定义  将数字翻译为英文 */
#pragma region class robot
const static char *num1[] ={
	"zero","one","two","three","four","five","six","seven","eight","nine","ten",
	"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"
};//静态字符串指针数组，num[n]即数字0~19,n对应的字符串
const static char *num2[] ={
	"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"
};//静态字符串指针数组，num[n]即对应的几十
 /* 构造函数 */
robot::robot()
{
	strcpy_s(name, "robot");
	strcpy_s(type, "V1.0");
	ps = new char[1000];//在定义时动态申请
	memset(ps, 0, 1000);
}
robot::~robot() //析构函数
{
	delete []ps;
}
 /*键盘输入n*/
void robot::cinnum()
{
	cin >> num;
	if (cin.fail()) //cin.fail 输入不合法
	{
		cout << "输入有错!请重新输入" << endl;
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(),'\n'); //清除cin里所有内容 
		return ;
	}
	else
		translate(num);
	return;
}
/*传入整形变量n，对n进行判断，调用out()输出翻译*/
void robot::translate(int n)
{
	if (n > 2999999999 || n < 0)//整形上下限
	{
		cout << "Input illegal" << endl;
	}
	else
	{
		if (n)
		{
			flag = 0;//flag
			out(n);//如果n不等于零，调用翻译输出函数
		}
		else
			strcpy_s(ps, 6, "zero");//如果等于零，直接为“zero”
		cout << ps << endl;
	}
	return;
}
/*翻译函数*/
void robot::out(int n)
{
	char *tempint;
	if (n > 1000000000)//是否大于十亿 billion
	{
		tempint = tran_int(n / 1000000000);
		strcat_s(ps, 1000, tempint);
		delete[]tempint;//释放来自tran_int的动态申请空间
		strcat_s(ps, 1000, "billion ");
		flag = 1;		out(n % 1000000000);
	}
	else
	{
		if (n > 1000000)//是否大于百万 million
		{
			tempint = tran_int(n / 1000000);
			strcat_s(ps, 1000, tempint);
			delete[]tempint;
			strcat_s(ps, 1000, "million ");
			flag = 1;
			out(n % 1000000);
		}
		else
		{
			if (n > 1000)//是否大于千 thousand
			{
				tempint = tran_int(n / 1000);
				strcat_s(ps, 1000, tempint);
				delete[]tempint;
				strcat_s(ps, 1000, "thousand ");
				flag = 1;
				out(n % 1000);
			}
			else
			{
				tempint = tran_int(n);
				strcat_s(ps, 1000, tempint);
				delete []tempint;
			}
		}
	}
}
/*对一千以内的数进行翻译*/
char *robot::tran_int(int a)
{
	char k[1000]="";
	int units, tens, hundreds;//分别为个位、十位、百位
	hundreds = a / 100;
	tens = (a - hundreds * 100) / 10;
	units = a % 10;
	if (hundreds > 0)
	{
		strcat_s(k, 1000, num1[hundreds]);
		strcat_s(k, 1000, " hundred ");//输出百位
	}
	if ((hundreds > 0 || flag) && (tens > 0 || units > 0))
	{
		strcat_s(k, 1000, "and ");//如果前面高于百位或有百位，且个位十位有值添加and
	}
	if (tens > 1)
	{
		strcat_s(k, 1000, num2[tens]);//大于20先输出十位
		if (units > 0)
		{
			strcat_s(k, 1000, "-");
			strcat_s(k, 1000, num1[units]);
		}
		strcat_s(k, 1000, " ");
	}
	else
	{
		strcat_s(k, 1000, num1[units + tens * 10]);
		strcat_s(k, 1000, " ");//小于20直接输出
	}
	char *p = new char[strlen(k) + 1];
	strcpy_s(p, strlen(k) + 1, k);
	return p;
}
#pragma endregion
