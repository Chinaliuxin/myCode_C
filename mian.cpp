#include <iostream>
class subject{
public :

	class Sum
	{
	public:
		Sum()
		{
			sum +=i;
			++i;
		}
	};
public :
	int sum_Solution (int const n)
	{
		Sum*p=new Sum[n];
		/*
		new�Ĺ����л�ʹ��new---��operator new-��malloc-�����캯��������ptrָ�� 
		��ô���캯��������n��
		*/
		return sum;
	}

private:
	static int sum;
	static int i;//����ھ�̬��
};
int subject::sum =0;
int subject::i=1;
int main()
{

	subject sub;
	std::cout<<sizeof(sub)<<std::endl;
	std::cout<<sub.sum_Solution(10)<<std::endl;

}
