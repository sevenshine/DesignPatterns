#pragma once
#include <iostream>
#include "FlyBehavior.h"
#include "QuackBehavior.h"
using namespace std;

class Duck
{
public:
	//m_pFly��ʼ��ΪNULL
	Duck():m_pFly(NULL),m_pQuack(NULL){}
	~Duck()
	{
		if (m_pFly)
		{
			delete m_pFly;
			m_pFly=NULL;
		}
		if (m_pQuack)
		{
			delete m_pQuack;
			m_pQuack=NULL;
		}
	}

	void SetFly(FlyBehavior *pFly)
	{
		if(m_pFly)
			delete m_pFly;
		m_pFly = pFly;
	}
	void SetQuack(QuackBehavior *pQuack)
	{
		if (m_pQuack)
			delete m_pQuack;
		m_pQuack = pQuack;
	}

	void PerformFly()
	{
		//if (m_fly)�ж��Ƿ�ֹʵ����fly�����ô��麯��
		if (m_pFly)
			m_pFly->Fly();
	}
	void PerformQuack()
	{
		//if (m_fly)�ж��Ƿ�ֹʵ����fly�����ô��麯��
		if (m_pQuack)
			m_pQuack->Quack();
	}
protected:
	FlyBehavior *m_pFly;
	QuackBehavior *m_pQuack;
};

//Duck�Ӷ�����
class MallardDuck:public Duck
{
public:
	MallardDuck()
	{
		cout << "I'm a Mallard duck" << endl;
		m_pFly = new FlyWithWings();
		m_pQuack = new Squeak();
	}
};

class ModelDuck:public Duck
{
public:
	ModelDuck()
	{
		cout << "I'm a Model duck" << endl;
		m_pFly = new FlyNoWay();
		m_pQuack = new MuteQuack();
	}
};

void Test()
{
	//��Խӿڱ�̣���ModelDuck���캯����m_fly = new FlyNoWay();fly��ʵ����
	Duck *duckMallard=new MallardDuck();
	duckMallard->PerformFly();
	duckMallard->PerformQuack();
	duckMallard->SetFly(new FlyRocketPowered());
	duckMallard->PerformFly();
	cout<<endl;

	Duck *duckModel=new ModelDuck();
	duckModel->PerformFly();
	duckModel->PerformQuack();
}