//arraytp.h -- Array Template
#ifndef ARRAYTP_H_
#define ARRAYTP_H_

#include <iostream>
#include <cstdlib>

template <typename T,int n>
class ArrayTP
{
private:
	T ar[n];
public:
	ArrayTP() {};
	explicit ArrayTP(const T& v);// explicit关键字的作用就是防止类构造函数的隐式自动转换.

	virtual T& operator[](int i);
	virtual T operator[](int i)const;
};
template <typename T,int n>
ArrayTP<T, n>::ArrayTP(const T& v)
{
	for (int i = 0; i < n; i++)
		ar[i] = v;
}
template <typename T, int n>
T& ArrayTP<T, n>::operator[](int n)
{
	if (i < 0 || i >= n)
	{
		std::cerr << "Error in array limits: " << i << " is out of range\n";
		std::exit(EXIT_FAILURE);
	}
	return ar[i];
}

template <typename T,int n>
T ArrayTP<T, n>::operator[](int i)const
{
	if (i < 0 || i >= n)
	{
		std::cerr << "Error in array limits: " << i << "is out of range\n";
		std::exit(EXIT_FAILURE);
	}
	return ar[i];
}


#endif // !ARRAYTP_H_
