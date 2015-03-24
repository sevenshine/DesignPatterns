#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Observer.h"
using namespace std;

//�������ӿ�
class Subject
{
public:
	virtual void RegisterObserver(Observer *ob)=0;
	virtual void RemoveObserver(Observer *ob) = 0;		//ɾ���۲���
	virtual void NotifyObserver() = 0;			//������״̬�ı�ʱ��֪ͨ���й۲���
};

//WeatherData�����࣬�̳������������
class WeatherData:public Subject
{
public:
	WeatherData(){}
	~WeatherData();

	void RegisterObserver(Observer *ob);

	void RemoveObserver(Observer *ob);

	void NotifyObserver();
	void MessurementsChanged();

	//��������վ�۲�ֵ,���ڲ���
	void SetMessurements(float temperature,float humility,float pressure);

private:
	vector<Observer *> m_vecObservers;
	float m_fTemperature;
	float m_fHumility;//ʪ��
	float m_fPressure;
};