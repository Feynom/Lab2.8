#include "Triangle.h"

//Class Triangle

int Triangle::counter = 0;
int Triangle::getCounter()
{
	return counter;
}
Triangle::Triangle(Angle A, Angle B, Angle C,
	double a = 0, double b = 0, double c = 0)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->A.SetGrades(A.GetGrades()); this->A.SetMinutes(A.GetMinutes());
	this->B.SetGrades(B.GetGrades()); this->B.SetMinutes(B.GetMinutes());
	this->C.SetGrades(C.GetGrades()); this->C.SetMinutes(C.GetMinutes());
	counter++;
}
Triangle::Triangle()
{
	this->GetA().SetGrades(0); this->GetA().SetMinutes(0);
	this->GetB().SetGrades(0); this->GetB().SetMinutes(0);
	this->GetC().SetGrades(0); this->GetC().SetMinutes(0);
	a = 0, b = 0, c = 0;
	counter++;
}

void Triangle::SetA(Angle A)
{
	this->A.Angle::SetGrades(A.GetGrades());
	this->A.Angle::SetMinutes(A.GetMinutes());
}
void Triangle::SetB(Angle B)
{
	this->B.Angle::SetGrades(B.GetGrades());
	this->B.Angle::SetMinutes(B.GetMinutes());
}
void Triangle::SetC(Angle C)
{
	this->C.Angle::SetGrades(C.GetGrades());
	this->C.Angle::SetMinutes(C.GetMinutes());
}

void Triangle::Set_a(double value) { a = value; }
void Triangle::Set_b(double value) { b = value; }
void Triangle::Set_c(double value) { c = value; }

Triangle::Angle& Triangle::GetA() { return A; }
Triangle::Angle& Triangle::GetB() { return B; }
Triangle::Angle& Triangle::GetC() { return C; }

double Triangle::Get_a() const { return a; }
double Triangle::Get_b() const { return b; }
double Triangle::Get_c() const { return c; }

ostream& operator << (ostream& out, const Triangle& A)
{
	out << string(A);
	return out;
}
istream& operator >> (istream& in, Triangle& X)
{
	cout << "Angle A: " << endl;
	in >> X.A;
	cout << "Angle B: " << endl;
	in >> X.B;
	cout << "Angle C: " << endl;
	in >> X.C;

	cout << "\nEnter a side 'a' : "; in >> X.a;
	cout << "Enter a side 'b' : "; in >> X.b;
	cout << "Enter a side 'c' : "; in >> X.c;

	return in;
}
Triangle::operator string() const
{
	stringstream ss;
	ss << "Angle A Grades is equal to " << A.GetGrades() << endl;
	ss << "Angle A minutes is equal to " << A.GetMinutes() << endl;

	ss << "Angle B Grades is equal to " << B.GetGrades() << endl;
	ss << "Angle B Minutes is equal to " << B.GetMinutes() << endl;

	ss << "Angle C Grades is equal to " << C.GetGrades() << endl;
	ss << "Angle C Minutes is equal to " << C.GetMinutes() << endl;

	ss << "\nSide a is equal to " << a << endl;
	ss << "Side b is equal to " << b << endl;
	ss << "Side c is equal to " << c << endl;

	return ss.str();
}

double Triangle::Square() const
{
	double p = Perimeter() / 2.;
	return sqrt(p * (p - Get_a()) * (p - Get_b()) * (p - Get_c()));
}
double Triangle::Perimeter() const { return Get_a() + Get_b() + Get_c(); }
double Triangle::Altitude(int tmp) const
{
	switch (tmp)
	{
	case 1:
		return (2 * Square()) / (Get_a() * 1.);
	case 2:
		return (2 * Square()) / (Get_b() * 1.);
	case 3:
		return (2 * Square()) / (Get_c() * 1.);
	}
}
void Triangle::TypeOFTriangle()
{
	if ((Get_a() == Get_b()) && (Get_b() == Get_c()))
		cout << "Equilateral triangle" << endl; //рівносторонній
	else if ((Get_a() == Get_b() && Get_a() != Get_c()) ||
		(Get_a() == Get_c() && Get_a() != Get_b()) ||
		(Get_c() == Get_b() && Get_c() != Get_a()))
		cout << "Isosceles triangle" << endl;//рівнобедрений
	else if (A.to360() == 90 || B.to360() == 90 || C.to360() == 90)
		cout << "Rectangular triangle" << endl;//прямокутний
	else if (A.to360() > 90 || B.to360() > 90 || C.to360() > 90)
		cout << "Obtuse triangle" << endl;// тупокутний 
	else if (A.to360() < 90 && B.to360() < 90 && C.to360() < 90)
		cout << "Oxygon" << endl;// гострокутний
}
void Triangle::Equalizetriangle(int tmp)
{
	switch (tmp)
	{
	case 1:
		Set_b((Get_a() * B.getSin()) / (A.getSin() * 1.));
		Set_c((Get_a() * C.getSin()) / (A.getSin() * 1.));
		break;
	case 2:
		Set_a((Get_b() * A.getSin()) / (B.getSin() * 1.));
		Set_c((Get_b() * C.getSin()) / (B.getSin() * 1.));
		break;
	case 3:
		Set_a((Get_c() * A.getSin()) / (C.getSin() * 1.));
		Set_b((Get_c() * B.getSin()) / (C.getSin() * 1.));
		break;
	}
}

//class Angle
int Triangle::Angle::counter = 0;
int Triangle::Angle::getCounter()
{
	return counter;
}

void Triangle::Angle::SetGrades(double grades) { this->grades = grades; }
void Triangle::Angle::SetMinutes(double minutes) { this->minutes = minutes; }

double Triangle::Angle::GetGrades() const { return grades; }
double Triangle::Angle::GetMinutes() const { return minutes; }

Triangle::Angle::Angle()
{
	grades = 0; minutes = 0;
	counter++;
}
Triangle::Angle::Angle(double grades = 0, double minutes = 0)
{
	this->grades = grades;
	this->minutes = minutes;
	counter++;
}
Triangle::Angle::Angle(const Triangle::Angle& A)
{
	grades = A.GetGrades();
	minutes = A.GetMinutes();
	counter++;
}

Triangle::Angle& Triangle::Angle::operator = (const Triangle::Angle& A)
{
	grades = A.grades;
	minutes = A.minutes;

	return *this;
}
ostream& operator << (ostream& out, const Triangle::Angle& A)
{
	out << string(A);
	return out;
}
istream& operator >> (istream& in, Triangle::Angle& A)
{
	cout << "Enter a grades of angle: "; in >> A.grades;
	cout << "Enter a minutes of angle "; in >> A.minutes;
	return in;
}
Triangle::Angle::operator string() const
{
	stringstream ss;
	ss << "Grades of angle is equal to " << grades << endl;
	ss << "Minutes of pair is equal to " << minutes << endl;
	return ss.str();
}

Triangle::Angle& Triangle::Angle::operator ++ ()
{
	grades++;
	return *this;
}
Triangle::Angle& Triangle::Angle::operator -- ()
{
	grades--;
	return *this;
}
Triangle::Angle Triangle::Angle::operator ++ (int)
{
	Angle t(*this);
	minutes++;
	return t;
}
Triangle::Angle Triangle::Angle::operator -- (int)
{
	Angle t(*this);
	minutes--;
	return t;
}

double Triangle::Angle::to360() const { return GetGrades() + GetMinutes() / 60.; }
double Triangle::Angle::toRadian()const { return (to360() * 3.141592) / 180.; }

Triangle::Angle operator + (const Triangle::Angle A, const Triangle::Angle B)
{
	Triangle::Angle t(A.GetGrades() + B.GetGrades(),
		A.GetMinutes() + B.GetMinutes());
	return t;
}
Triangle::Angle operator - (const Triangle::Angle A, const Triangle::Angle B)
{
	Triangle::Angle t(A.GetGrades() - B.GetGrades(),
		A.GetMinutes() - B.GetMinutes());
	return t;
}
Triangle::Angle operator / (const Triangle::Angle A, const double value)
{
	Triangle::Angle t(A.GetGrades() / 2., A.GetMinutes() / 2.);
	return t;
}

void Triangle::Angle::Increase(Triangle::Angle X, Triangle::Angle& A, Triangle::Angle& B, Triangle::Angle& C, int tmp)
{
	switch (tmp)
	{
	case 1:
		A = A + X;
		B = B - X / 2.;
		C = C - X / 2.;
		break;
	case 2:
		B = B + X;
		A = A - X / 2.;
		C = C - X / 2.;
		break;
	case 3:
		C = C + X;
		A = A - X / 2.;
		B = B - X / 2.;
		break;
	}
}
void Triangle::Angle::Decrease(Triangle::Angle X, Triangle::Angle& A, Triangle::Angle& B, Triangle::Angle& C, int tmp)
{
	Angle minus(-1 * X.GetGrades(), -1 * X.GetMinutes());
	minus.Increase(minus, A, B, C, tmp);
}

double Triangle::Angle::getSin() const { return sin(toRadian() * 1.); }

bool operator > (const Triangle::Angle A, const Triangle::Angle B)
{
	if (A.to360() > B.to360())
		return 1;
	else
		return 0;
}
bool operator < (const Triangle::Angle A, const Triangle::Angle B)
{
	if (A.to360() < B.to360())
		return 1;
	else
		return 0;
}
bool operator == (const Triangle::Angle A, const Triangle::Angle B)
{
	if (A.to360() == B.to360())
		return 1;
	else
		return 0;
}

void Triangle::Angle::Comparison(Triangle::Angle A, Angle B)
{
	if (A > B)
		cout << "First angle > Second angle" << endl;
	if (A < B)
		cout << "First angle < Second angle" << endl;
	if (A == B)
		cout << "First angle = Second angle" << endl;
}
