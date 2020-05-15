#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include <valarray>
class Student
{
private:
	typedef std::valarray<double> ArrayDb;
	std::string name;
	ArrayDb scores;
	std::ostream& arr_out(std::ostream& os)const {
		int i;
		int lim = scores.size();
		if (lim > 0)
		{
			for (i = 0; i < lim; i++)
			{
				os << scores[i] << " ";
				if (i % 5 == 4)
					os << std::endl;
			}
			if (i % 5 != 0)
			{
				os << std::endl;
			}
		}
		else {
			os << " empty array";
		}
		return os;
	}
public:
	//由于初始化的是成员对象 而不是继承的对象，所以初始化列表中使用的是成员名，而不是类名！
	Student():name("Null Student"),scores(){}
	Student(const std::string& s):name(s),scores(){}
	explicit Student(int n):name("Nully"),scores(n){
	//避免没有意义的隐式转换
	}
	Student(const std::string& s,int n):name(s),scores(n){}
	Student(const std::string& s,const ArrayDb& a):name(s),scores(a){}
	Student(const char* str,const double *pd,int n):name(str),scores(pd,n){}
	~Student(){}
	double Average()const;
	const std::string& Name()const;
	double& operator[](int i);
	double operator[](int i)const;
//friends
	//input
	friend std::istream& operator>>(std::istream& is, Student& stu) {
		is >> stu.name;
		return is;
	}//1 word
	friend std::istream& getline(std::istream& is, Student& stu) {
		getline(is,stu.name);
		return is;
	}//1 line
	//output
	friend std::ostream& operator<<(std::ostream& os, const Student& stu) {
		os << "Scores for " << stu.Name() << ":\n";
		stu.arr_out(os);
		return os;
	}
};
#endif // !STUDENT_H_
