#include <iostream>
#include <math.h>
#include "cmplx.h"
constexpr double PI = 3.14159265358;

	void cmplx::polar(double amnt, double arg) {
		//lets a complex nuber be initialized as polar coordinates
		this->im = sin(arg) * amnt;
		this->re = cos(arg) * amnt;
		this->amnt = amnt;
		this->arg = arg;
	}
	double cmplx::getRe() {
		//Returns real part of nmbr
		return re;
	}
	double cmplx::getIm() {
		//Returns imaginary part of nmbr
		return im;
	}
	double cmplx::getAbs() {
		//returns the amount of the number in polar coordinates
		return amnt;
	}
	double cmplx::getArg() {
		//returns the argument of the polar complex number in radians
		//arctan Def.-Range is taken into account
		return arg;
	}
	void cmplx::cmplxconj() {
		double a = this->im;
		this->im = a * (-1.0);
		this->arg = defarg(this->re,this->im);
	}
	void cmplx::print() {
		//Prints a complex number as karthesic coordinates into console
		std::cout << re << "+" << im << "i\n";
	}
	void cmplx::printpolar() {
		//Prints a complex number as polar coordinates into console

		std::cout << abs(amnt) << "e^(i*" << arg << ")\n";
	}
	cmplx cmplx::operator+(cmplx B) {
		double re = this->re + B.re;
		double im = this->im + B.im;
		return cmplx(re, im);
	}
	cmplx cmplx::operator-(cmplx B) {
		double re = this->re - B.re;
		double im = this->im - B.im;
		return cmplx(re, im);
	}
	cmplx cmplx::operator*(cmplx B) {
		double amnt = this->amnt * B.amnt;
		double arg = this->arg + B.arg;
		cmplx a;
		a.polar(amnt, arg);
		return a;
	}
	cmplx cmplx::operator/(cmplx B) {
		double amnt = this->amnt * B.amnt;
		double arg = this->arg - B.arg;
		cmplx a;
		a.polar(amnt, arg);
		return a;
	}