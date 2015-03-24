//观察者模式C++编程实现
//author：江南烟雨
//E-Mail：xiajunhust@gmail.com
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int setConditionTimes = 0;//记录设置的总次数

//观察者（布告板）抽象接口
class Observer{
public:
	virtual void update(float temp,float humidity,float pressure) = 0;
};

//主题抽象接口
class Subject{
public:
	virtual void registerObserver(Observer *o) = 0;//注册观察者
	virtual void removeObserver(Observer *o) = 0;//删除观察者
	virtual void notifyObserver() = 0;//当主题状态改变时，通知所有观察者
};

//布告板显示
class DisplayElement{
public: 
	virtual void display()= 0;
};

//WeatherData具体类，继承自主题抽象类
class WeatherData:public Subject{
private:
	vector<Observer *> observers;
	float temperature;
	float humility;//湿度
	float pressure;

public:
	WeatherData(){}

	~WeatherData(){
		vector<Observer*>::iterator pos = observers.begin();
		for (;pos != observers.end();++pos)
		{
			delete (*pos);
		}
	}

	void registerObserver(Observer *o){
		observers.push_back(o);
	}

	void removeObserver(Observer *o){
		vector<Observer*>::iterator pos = find(observers.begin(),
			observers.end(),o);
		if (pos != observers.end())
		{
			observers.erase(pos);
		}
	}

	void notifyObserver()
	{
		vector<Observer*>::iterator pos = observers.begin();
		for (;pos != observers.end();++pos)
		{
			(*pos)->update(temperature,humility,pressure);
		}
	}

	//当从气象站得到更新观测值时，通知观察者
	void messurementsChanged(){
		notifyObserver();
	}

	//设置气象站观测值
	void setMessurements(float temperature,float humility,float pressure){
		++setConditionTimes;
		this->temperature = temperature;
		this->humility = humility;
		this->pressure = pressure;
		messurementsChanged();
	}
};

//布告板具体类：目前状况
class CurrentConditionDisplay:public Observer,public DisplayElement{
private:
	float temperature;
	float humility;

	Subject *weatherData;

public: 
	//初始化对象注册
	CurrentConditionDisplay(Subject *weatherData){
		this->weatherData = weatherData;
		weatherData->registerObserver(this);
	}

	~CurrentConditionDisplay(){}

	//update调用，保存、显示
	void update(float temp,float humi,float pressure){
		this->temperature = temp;
		this->humility = humi;

		display();
	}

	void display(){
		cout << "Current conditions: " << temperature << "F degrees and " <<
			humility << "% humility" << endl;
	}
};

//布告板具体类：气象统计类
class WeatherStatisticsDisplay:public Observer,public DisplayElement{
private:
	float avgTemperatuere,maxTemperature,minTemperature;
	Subject *weatherData;

public: 
	WeatherStatisticsDisplay(Subject *weatherData){
		this->weatherData = weatherData;
		weatherData->registerObserver(this);
	}

	~WeatherStatisticsDisplay(){}

	void update(float temp,float humi,float pressure){
		if (1 == setConditionTimes)
		{
			this->avgTemperatuere = temp;
			this->maxTemperature = temp;
			this->minTemperature = temp;
		}
		else{
			this->avgTemperatuere = (this->avgTemperatuere * (setConditionTimes - 1) + temp) / setConditionTimes;
			this->maxTemperature = this->maxTemperature > temp ? this->maxTemperature : temp;
			this->minTemperature = this->minTemperature < temp ? this->minTemperature : temp;
		}

		display();
	}

	void display(){
		cout << "Avg/Max/Min: temperature  " << avgTemperatuere << "/" << 
			maxTemperature << "/" <<minTemperature << endl;
	}
};

int main()
{
	WeatherData *weatherData = new WeatherData();

	CurrentConditionDisplay *currentConditionDisplay = new CurrentConditionDisplay(weatherData);
	WeatherStatisticsDisplay *weatherStatisticsDisplay = new WeatherStatisticsDisplay(weatherData);

	weatherData->setMessurements(80,65,30.4f);
	weatherData->setMessurements(82,70,29.2f);
	weatherData->setMessurements(78,90,29.2f);

	weatherData->removeObserver(weatherStatisticsDisplay);

	cout << "after remove observer WeatherStatisticsDisplay:" << endl;
	weatherData->setMessurements(80,65,30.4f);
	weatherData->setMessurements(82,70,29.2f);
	weatherData->setMessurements(78,90,29.2f);

	return 0;
}