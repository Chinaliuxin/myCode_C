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
		new的过程中会使用new---》operator new-》malloc-》构造函数，返回ptr指针 
		那么构造函数便会调用n次
		*/
		return sum;
	}

private:
	static int sum;
	static int i;//存放在静态区
};
int subject::sum =0;
int subject::i=1;
int main()
{

	subject sub;
	std::cout<<sizeof(sub)<<std::endl;
	std::cout<<sub.sum_Solution(10)<<std::endl;

}
