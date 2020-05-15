#ifndef STUDENT2_H_
#define STUDENT2_H_


#include <iostream>
#include <string>
#include <valarray>
class Student2 :private std::string, private std::valarray<double>
{
private:
	typedef std::valarray<double> ArrayDb;
	std::ostream& arr_out(std::ostream& os) const {
		int i;
		int lim = ArrayDb::size();
		if (lim > 0)
		{
			for (i = 0; i < lim; i++)
			{
				os << ArrayDb::operator[](i) << " ";
				if (i % 5 == 4)
					os << std::endl;

			}
			if (i % 5 != 0)
				os << std::endl;

		}
		else
		{
			os << " empty array";
		}
		return os;
	}
public:
	Student2():std::string("Null Student"),ArrayDb(){}
	Student2(const std::string & s):std::string(s),ArrayDb(){}
	explicit Student2(int n):std::string("Nully"),ArrayDb(n){}
	Student2(const std::string &s,int n):std::string(s),ArrayDb(n){}
	~Student2(){}
	double Average()const;
	double& operator[](int i);
	double operator[](int i) const;
	const std::string& Name() const {
		return (const string&)*this;//该引用指向用于调用该方法的Student2对象中的继承而来的string对象
	}

	friend std::istream& operator>>(std::istream& is, Student2& stu);
	friend std::istream& getline(std::istream& is, Student2& stu);
	friend std::ostream& operator<<(std::ostream& os, const Student2& stu) {
		os << "Scores for " << (const string&)stu << ":\n";
		stu.arr_out(os);
		return os;
	}

	//Student2(const char * str,const double *pd,int n):std::string(str),
};
#endif // !STUDENT2_H_
