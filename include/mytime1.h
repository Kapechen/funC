#ifndef MYTIME1_H_
#define MYTIME1_H_
#include <iostream>

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	Time operator+(const Time& t)const;
	Time operator-(const Time& t)const;
	Time operator*(double n)const;
	friend Time operator*(double m, const Time& t) {
		return t * m;//实现反转
	}// 非成员友元函数
	friend std::ostream& operator<<(std::ostream& os, const Time& t) {
		os << t.hours << " hours," << t.minutes << " minutes";
		return os;
	}
	void Show()const;
};
#endif // !MYTIME1_H_
