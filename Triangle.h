#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Triangle
{
public:

	class Angle
	{
		double grades, minutes;
		static int counter;
	public:
		void SetGrades(double grades);
		void SetMinutes(double minutes);

		double GetGrades() const;
		double GetMinutes() const;

		Angle();
		Angle(double, double);
		Angle(const Angle&);

		Angle& operator = (const Angle&);
		friend ostream& operator << (ostream&, const Angle&);
		friend istream& operator >> (istream&, Angle&);
		operator string() const;

		Angle& operator ++ ();
		Angle& operator -- ();
		Angle operator ++ (int);
		Angle operator -- (int);

		double to360() const;
		double toRadian() const;

		friend Angle operator + (const Angle, const Angle);
		friend Angle operator - (const Angle, const Angle);
		friend Angle operator / (const Angle, const double);

		void Increase(Angle X, Angle& A, Angle& B, Angle& C, int tmp);
		void Decrease(Angle X, Angle& A, Angle& B, Angle& C, int tmp);

		double getSin() const;

		friend bool operator > (const Angle, const Angle);
		friend bool operator < (const Angle, const Angle);
		friend bool operator == (const Angle, const Angle);

		void Comparison(Angle A, Angle B);

		static int getCounter();
	};

	void SetA(Angle A);
	void SetB(Angle B);
	void SetC(Angle C);

	void Set_a(double value);
	void Set_b(double value);
	void Set_c(double value);

	Angle& GetA();
	Angle& GetB();
	Angle& GetC();

	double Get_a() const;
	double Get_b() const;
	double Get_c() const;

	Triangle();
	Triangle(Angle, Angle, Angle, double, double, double);

	friend ostream& operator << (ostream&, const Triangle&);
	friend istream& operator >> (istream&, Triangle&);
	operator string() const;

	double Square() const;
	double Perimeter() const;
	double Altitude(int tmp) const;
	void TypeOFTriangle();
	void Equalizetriangle(int tmp);

	static int getCounter();
private:
	Angle A, B, C;
	double a, b, c;
	static int counter;
};

