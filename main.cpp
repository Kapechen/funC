// learnC++.cpp: 定义应用程序的入口点。
//

#include "main.h"

#include <string>
#include <vector>
#include <iostream>
//#include <cctype>
//#include <string>
using namespace std;
void swap(vector<string>& x, vector<string>& y) {
	vector<string> tmp = std::move(x);
	x = std::move(y);
	y = std::move(tmp);
}


//泛型findMax，用到一个函数对象，c++风格
//前提:a.size()>0
template <typename Object,typename Comparator>
const Object& findMax(const vector<Object>& arr, Comparator isLessThan)
{
	int maxIndex = 0;
	for (int i = 1; i < arr.size(); ++i)
		if (isLessThan(arr[maxIndex], arr[i]))
			maxIndex = i;
	return arr[maxIndex];
}
//泛型findMax，使用默认的排序
#include <functional>
template <typename Object>
const Object& findMax(const vector<Object>& arr)
{
	return findMax(arr, less<Object>{});
}
class CaseInsensitiveCompare
{
public:
	bool operator()(const string& lhs, const string& rhs)const
	{
		return stricmp(lhs.c_str(), rhs.c_str()) < 0;
	}
};

int main()
{
	vector<string> arr = { "ZEBRA","alligator","crocodile" };
	cout << findMax(arr, CaseInsensitiveCompare{}) << endl;
	cout << findMax(arr) << endl;
return 0;
}
