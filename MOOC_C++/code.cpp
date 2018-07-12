#include "stdafx.h"
#include "code.h"
using namespace std;

double rate()
{
	double money, years, rate, sum;
	std::cout << "�����뱾�𡢴����ݡ������ʣ��Կո���������س�����" << std::endl;
	std::cin >> money >> years >> rate;
	while (money > 0)
	{
		sum = money * pow((1 + rate), years);
		std::cout << "��Ϣ��" << sum << std::endl;
		std::cout << "�����뱾�𡢴����ݡ������ʣ��Կո���������س�����\7" << std::endl;
		std::cin >> money >> years >> rate;
	}
	return money;
}

/*bubble sort ,return the number of elements <100 ð������ 100���� ��������Ԫ�ظ��� */
int bubble_sort()
{
	std::cout << "****ð������****" << std::endl << std::endl;
	double arr[100];
	int N = 0;
	while (N < 1 || N > 100 )
	{
		std::cout <<"�����������Ԫ������(1-100)"<< std::endl;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "����ֵ�Ƿ�" << std::endl;
		}
		std::cin >> N;
	}
 	for ( int i = 0; i < N; i++)
	{
		while ( std::cin.fail() )
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "����ֵ�Ƿ�" << std::endl;
		}
		std::cout << "�����" << i + 1 << "��Ԫ�أ���" << N << "��" << std::endl;
		std::cin >> arr[i];
	}
	std::cout << "�������" << std::endl;
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
	std::cout << "������������£�" << std::endl;
	for (int i = 0; i < N ; i++)
	{
		std::cout << arr[i] << " ";
		if ( !( (i+1) % 16) )
			std::cout << std::endl;
	}
	std::cout << std::endl;
	return N;
}

/* �������������*/
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

/*ʹ�����ñ�����������ֵ�����ú��ı䴫��ֵ*/
void swap(int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
	return ;
}

/*�ݹ麯�� ����n!*/
unsigned long int factorial_n(int n)
{
	return  (n > 0) ? (n*factorial_n(n - 1)) : 1;//?:���㣬��� n>0������������n=0��ݹ����
}
void factorial()
{
	int n;
	cout << "Input n" << endl;
	cin >> n;
	cout << factorial_n(n)<< endl;
}

#pragma region class robot
const static char *num1[] ={
	"","one","two","three","four","five","six","seven","eight","nine","ten",
	"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"
};
const static char *num2[] ={
	"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"
};
robot::robot()//���캯��
{
	strcpy_s(name, "robot");
	strcpy_s(type, "V1.0");
}
robot::~robot(){};//��������
void robot::translate(int n)
{
	if (n > 2999999999 || n < 0)
	{
		cout << "Input illegal" << endl;
	}
	else
	{
		out(n);
		flag = 0;
	}
	cout << endl;
}
void robot::cinnum()
{
	int num;
	cin >> num;
	translate(num);
}
void robot::tran_int(int a)
{
	if (!a)
	{
		cout << "zero";
	}
	int units, tens, hundreds;
	hundreds = a / 100;
	tens = (a - hundreds * 100) / 10;
	units = a % 10;
	if (hundreds > 0)
	{
		cout << num1[hundreds] << " " << "hundred ";
	}
	if ((hundreds > 0 || flag) && (tens > 0 || units > 0))
	{
		cout << "and ";
	}
	if (tens > 1)
	{
		cout << num2[tens];
		if (units > 0)
			cout << "-" << num1[units] << " ";
		else
			cout << " ";
	}
	else
	{
		cout << num1[units + tens * 10] << " ";
	}
}
void robot::out(int n)
{
	if (n > 1000000000)
	{
		tran_int(n / 1000000000);
		cout << "billion ";
		flag = 1;
		out(n % 1000000000);
	}
	else
	{
		if (n > 1000000)
		{
			tran_int(n / 1000000);
			cout << "million ";
			flag = 1;
			out(n % 1000000);
		}
		else
		{
			if (n > 1000)
			{
				tran_int(n / 1000);
				cout << "thousand ";
				flag = 1;
				out(n % 1000);
			}
			else
				tran_int(n);
		}
	}
}
#pragma endregion
