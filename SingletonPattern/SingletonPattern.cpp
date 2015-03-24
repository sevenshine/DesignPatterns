#include <iostream>
using namespace std;

class Singleton
{
public:
	//实例化对象
	static Singleton* GetInstance()
	{
		if (UniqueInstance==NULL)
			UniqueInstance=new Singleton();
		return UniqueInstance;
	}
private:
	static Singleton *UniqueInstance;//利用一个静态变量来记录Singleton的唯一实例  
	static int No;
	Singleton(){};  
};

//static成员初始化
Singleton* Singleton::UniqueInstance=new Singleton();
int Singleton::No=100;

int main()
{
	//静态函数的调用
	Singleton *SingletonObj = Singleton::GetInstance();  

	delete SingletonObj;  
	return 0;  
}

