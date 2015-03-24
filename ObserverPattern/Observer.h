#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Observer.h"

using namespace std;

static int g_SetConditionTimes = 0;//��¼���õ��ܴ���

//�۲��ߣ�����壩����ӿ�
class Observer
{
public:
	virtual void Update(float temp,float humidity,float pressure) = 0;
};

//�������ӿ�
class Subject
{
public:
	virtual void RegisterObserver(Observer *ob)=0;
	virtual void RemoveObserver(Observer *ob) = 0;		//ɾ���۲���
	virtual void NotifyObserver() = 0;			//������״̬�ı�ʱ��֪ͨ���й۲���
};

//�������ʾ
class DisplayElement
{
public:
	virtual void Display()=0;
};

//WeatherData�����࣬�̳������������
class WeatherData:public Subject
{
public:
	WeatherData(){}
	~WeatherData()
	{
		//??
		vector<Observer *>::iterator pos=m_vecObservers.begin();
		if (pos != m_vecObservers.end())
		{
			delete(*pos);
			++pos;
		}
	}

	void RegisterObserver(Observer *ob)
	{
		m_vecObservers.push_back(ob);
	}

	void RemoveObserver(Observer *ob)
	{
		vector<Observer *>::iterator pos=find(m_vecObservers.begin(),
			m_vecObservers.end(),ob);
		if (pos != m_vecObservers.end())
			m_vecObservers.erase(pos);
	}

	void NotifyObserver()
	{
		vector<Observer *>::iterator pos=m_vecObservers.begin();
		while (pos != m_vecObservers.end())
		{
			(*pos)->Update(m_fTemperature,m_fHumility,m_fPressure);
			++pos;
		}
	}

	void MessurementsChanged()
	{
		NotifyObserver();
	}

	//��������վ�۲�ֵ,���ڲ���
	void SetMessurements(float temperature,float humility,float pressure)
	{
		++g_SetConditionTimes;
		m_fTemperature=temperature;
		m_fHumility=humility;
		m_fPressure=pressure;
		MessurementsChanged();
	}

private:
	vector<Observer *> m_vecObservers;
	float m_fTemperature;
	float m_fHumility;//ʪ��
	float m_fPressure;
};

//���������ࣺĿǰ״��
class CurrentConditionDisplay:public Observer,public DisplayElement
{
public:
	//��ʼ������ע��
	CurrentConditionDisplay(Subject *weatherData)
	{
		m_WeatherData = weatherData;
		weatherData->RegisterObserver(this);
	}
	~CurrentConditionDisplay(){}

	//update���ã����桢��ʾ
	void Update(float temp,float humi,float pressure)
	{
		m_fTemperature=temp;
		m_fHumility=humi;

		Display();
	}

	void Display(){
		cout << "Current conditions: " << m_fTemperature << "F degrees and " <<
			m_fHumility << "% humility" << endl;
	}

private:
	float m_fTemperature;
	float m_fHumility;

	Subject *m_WeatherData;
};
