#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Observer.h"
using namespace std;

//主题抽象接口
class Subject
{
public:
	virtual void RegisterObserver(Observer *ob)=0;
	virtual void RemoveObserver(Observer *ob) = 0;		//删除观察者
	virtual void NotifyObserver() = 0;			//当主题状态改变时，通知所有观察者
};

//WeatherData具体类，继承自主题抽象类
class WeatherData:public Subject
{
public:
	WeatherData(){}
	~WeatherData();

	void RegisterObserver(Observer *ob);

	void RemoveObserver(Observer *ob);

	void NotifyObserver();
	void MessurementsChanged();

	//设置气象站观测值,用于测试
	void SetMessurements(float temperature,float humility,float pressure);

private:
	vector<Observer *> m_vecObservers;
	float m_fTemperature;
	float m_fHumility;//湿度
	float m_fPressure;
};