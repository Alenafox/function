#include <iostream>

#include <fstream>

#include <cstdlib>

#include <cstring>

#include <cmath>


using namespace std;

// Абстрактный класс
class Function

{
protected:
	double x; //значение
private:
	int n; //показатель функции, ее определяет
	double A;
	double B;
	double C;
public:
	Function();
	double setFuncion(int n);
	// виртуальные функции
	virtual double Dfdx(double x);
	virtual double D2fdx2(double x);
	virtual double NewtonMax(double start, bool isMax); //максимум
	virtual double NewtonMin(double start, bool isMax); //минимум

	

};

//Конструктор без параметров

Function::Function()
{
	x = 0;
}
double Function::setFuncion(int n)
{
	if (n = 2)
	{
		cout << "Введите коэффициенты:" << endl;
		cout << "a = ";
		cin >> A;
		cout << "b = ";
		cin >> B;
		cout << "c = ";
		cin >> C;
		cout << "Введите значение x:";
		cin >> x;
		Parabola::Par(A, B, C);
		Parabola::Count(x);
	}
	if (n = 1)
	{
		cout << "Введите коэффициент:" << endl;
		cout << "a = ";
		cin >> A;
		cout << "Введите значение x:";
		cin >> x;
		Hiperbola::Hyperbola(A);
		Hiperbola::Count(x);
	}
	if (n = 0)
	{
		cout << "Введите значение x:";
		cin >> x;
		Exponenta::Count(x);
	}
}
double Function::Dfdx(double x) //производная первого порядка
{
	return -1 * sin(x) + cos(x);
}
double Function::D2fdx2(double x) //производная второго порядка
{
	return -1 * (cos(x) + sin(x));
}
double Function::NewtonMax(double start, bool isMax)
{
	double x1, dx, eps = 2.7;
	double x0 = start;
	do
	{
		x1 = x0 - Dfdx(x0) / D2fdx2(x0);
		dx = abs(x1 - x0);
		x0 = x1;
	} while (dx < eps);
	if (D2fdx2(x1) < 0)
	{
		return x1;
	}

}
double Function::NewtonMin(double start, bool isMin)
{
	double x1, dx, eps = 2.7;
	double x0 = start;
	do
	{
		x1 = x0 - Dfdx(x0) / D2fdx2(x0);
		dx = abs(x1 - x0);
		x0 = x1;
	} while (dx < eps);
	if (D2fdx2(x1) > 0)
	{
		return x1;
	}

}
class Hiperbola : public Function
{
private:
	double A;
public:
	double Hyperbola(double a);
	double Count(double x);
};
double  Hiperbola:: Hyperbola(double a)
{
	A = a;
}
double Hiperbola:: Count(double x)
{
	return A / x;
}
class Parabola : public Function
{
private:
	double A;
	double B;
	double C;
public:
	double Par(double a, double b, double c);
	double Count(double x);
};
double Parabola:: Par(double a, double b, double c)
{
	A = a;
	B = b;
	C = c;
	return 0;
}
double Parabola:: Count(double x)
{
	return A * x * x + B * x + C;
}
class Exponenta : public Function
{
private:
	double e = 2.7;
public:
	double Count(double x);
};
double Exponenta:: Count(double x)
{
	return pow(e, x);
}
class Polinom : public Function
{
private:
	unsigned int deg; //степень полинома
	double *koef; //указатель на массив коэффициентов полинома
public:
	void vvod();    //функция ввода полинома
	void print();   //функция вывода полинома;

};
void Polinom::print() {

	if (koef[deg] == 1)
		cout << "X^" << deg;
	else if (koef[deg] == -1)
		cout << "-X^" << deg;
	else
		cout << koef[deg] << "X^" << deg;

	for (int i = deg - 1; i > 0; i--) {
		if (koef[i] > 0) {
			if (koef[i] == 1)
				cout << " + " << "X^" << i;
			else
				cout << " + " << koef[i] << "X^" << i;
		}
		else if (koef[i] < 0)
			if (koef[i] == -1)
				cout << " - " << "X^" << i;
			else
				cout << " - " << (-1)*koef[i] << "X^" << i;
	}

	if (koef[0] > 0)
		cout << " + " << koef[0] << "\n";
	else if (koef[0] < 0)
		cout << " - " << (-1)*koef[0] << "\n";
}
void Polinom::vvod() {

	cout << "Введите степень полинома: ";
	cin >> deg;
	delete[] koef;
	koef = new double[deg + 1];
	for (int i = 0; i < deg; i++) {
		cout << "K" << i << " = ";
		cin >> koef[i];
	}
	do {
		cout << "K" << deg << " = ";
		cin >> koef[deg];
		if (koef[deg] == 0)
			cout << "K" << deg << " не может быть нулем!\n";
	} while (!koef[deg]);
}

int main(void) {
	setlocale(LC_ALL, "Russian");
	int n;
	Function function;
	Function *FunctionX = &function;
	Hiperbola hiperbola;
	Parabola parabola;
	Parabola *ParabolaX = &parabola;
	Exponenta exponenta;
	Polinom polinom;
	Polinom *PolinomX = &polinom;
	cout << "Реализация класса Function" << endl;
	PolinomX->vvod();
	PolinomX->print();
	cout << "Введите 0 для функции Exponenta, 1 для функции Hiperbola, 2 для функции Parabola: ";
	cin >> n;
	FunctionX->setFuncion(n);
	cout << "Минимум функции: ";
	//FunctionX->NewtonMin();
	cout << "Максимум функции: ";
	//FunctionX->NewtonMax();
	return 0;
}