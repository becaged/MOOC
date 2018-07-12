#include <iostream>
#include <cmath>
using namespace std;
/*double rate() 
  double Area(double a, double b, double c) 
*/

double rate(); //用于计算利息

int bubble_sort();//冒泡排序

void triangle_Area();//计算三角形面积

void factorial();//计算n的阶乘

class robot
{
	char name[20];//机器人姓名
	char type[20];//机器人型号
	bool flag = 0;
public:
	robot();//构造函数
	~robot();//析构函数
	void translate(int n);
	void cinnum();
private:
	void tran_int(int a);
	void out(int n);
};