#include <iostream>
#include <cmath>
using namespace std;
/*double rate() 
  double Area(double a, double b, double c) 
*/

double rate(); //���ڼ�����Ϣ

int bubble_sort();//ð������

void triangle_Area();//�������������

void factorial();//����n�Ľ׳�

class robot
{
	char name[20];//����������
	char type[20];//�������ͺ�
	bool flag = 0;
public:
	robot();//���캯��
	~robot();//��������
	void translate(int n);
	void cinnum();
private:
	void tran_int(int a);
	void out(int n);
};