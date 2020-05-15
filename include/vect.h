#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
namespace VECTOR
{
	const double Rad_to_deg = 57.2957795130823;
	class Vector
	{
	private:
		
		double x;
		double y;
		double mag;
		double ang;
		char mode;//'r' = rectangular,'p'= polar
	//private methods for setting values
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double n1, double n2, char form = 'r');
		void set(double n1, double n2, char form = 'r');
		~Vector();
		double xval()const { return x; }
		double yval()const { return y; }
		double magval()const { return mag; }
		double angval()const { return ang; }
		void polar_mode();
		void rect_mode();
		//operator overloading
		Vector operator+(const Vector& b)const;
		Vector operator-(const Vector& b)const;
		Vector operator-()const;
		Vector operator*(double n)const;
		//friends
		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v) {
			if (v.mode == 'r')
				os << "(x,y)=(" << v.x << "," << v.y << ")";
			else if (v.mode == 'p')
			{
				os << "(m,a)=(" << v.mag << "," << v.ang * Rad_to_deg << ")";
			}
			else
				os << "Vector object mode is valid";
			return os;
		}
	};
} //end namespace VECTOR
#endif // !VECTOR_H_
