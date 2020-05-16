#ifndef MYCOLLECTION_H
#define MYCOLLECTION_H
#include <string>
#include <vector>
#include <iostream>
template <typename Object>
class Collection {
public:
	Collection() = default;
	Collection(Object obj):obj{obj}{}
	Object getObj() { return obj; }
	bool isEmpty() { return obj.size() ? false : true; }
	Collection<Object>& operator=(Collection<Object>& a) {
		return *this = a;
	}
	~Collection() {}
	template <typename T>
	Object insert(T apl) {
		Object temp;
		temp.resize(obj.size() + 1);
		for (size_t i = 0; i < obj.size(); i++)
		{
			temp[i] = obj[i];
		}
		temp[temp.size() - 1] = apl;
		obj = temp;
		return obj;
	}
	template <typename T>
	bool contains(T in) {
		if (obj.size() == 0) { return false; }
		for (auto ob : obj) {
			if (in == ob)
				return true;
		}
		return false;
	}
	template <typename T>
	void remove(T oup) {
		if (obj.size() == 0) { return; }
		int count = 0;
		for (size_t i = 0; i < obj.size(); i++) {
			if (oup == obj[i]) {
				obj[i] = NULL;
				count++;
			}
		}
		Object temp;
		temp.resize(obj.size() - 1);
		int i = 0;
		for (auto ob : obj) {
			if (ob != NULL)
			{
				temp[i] = ob;
				i++;
			}
		}
		obj = temp;
	}
	void print() { for (auto each : obj) std::cout << each << " "; std::cout << std:: endl; }
private:
	Object obj;
};
//²âÊÔ´úÂë
//vector<int> a = { 1,2,3,4,5 };
//vector<int>  b;
//Collection<vector<int>>  c(a);
//Collection<string> stc;
//cout << c.getObj().at(1) << endl;
//c.insert<int>(6);
//cout << "C after inserted :  " << c.getObj()[5] << endl;
//c.remove(3);
//cout << "c.constains(3) true or false: " << c.contains(4) << endl;
//c.print();
//c.~Collection();
//cout << "c.isEmpty() true or false: " << c.isEmpty() << endl;
#endif // !MYCOLLECTION_H
