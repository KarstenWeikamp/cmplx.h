#pragma once
class cmplx
{
private:
	
	double re;
	double im;
	double amnt;
	double arg;
	double defabs(double re, double im) {
		return sqrt((re * re) + (im * im));
	}
	double defarg(double re, double im) {
		const double PI = 3.1415926;
		double alpha;
		if (im != 0) {
			alpha = atan2(re, im);
		}
		else {
			if (re < 0) alpha = -180;
			if (re >= 0) alpha = 0;
		}
		if (re >= 0) {
			if (im < 0)alpha = (-1 * alpha);
			if (im > 0)alpha = alpha;
		}
		if (re < 0) {
			if (im < 0)alpha = (PI - alpha);
			if (im > 0)alpha = (PI + alpha);
		}
		return alpha;
	}
public:
	cmplx(double re, double im){
		cmplx::re = re;
		cmplx::im = im;
		cmplx::arg = defarg(re, im);
		cmplx::amnt = defabs(re, im);
	}
	cmplx(int re, int im) {
		cmplx::re = re;
		cmplx::im = im;
		cmplx::arg = defarg(re, im);
		cmplx::amnt = defabs(re, im);
	}
	cmplx() {
		re = 0.0;
		im = 0.0;
		arg = 0.0;
		amnt = 0.0;
	}
	cmplx(double cmplxVec[2]) {
		re = cmplxVec[0];
		im = cmplxVec[1];
		arg = defarg(re, im);
		amnt = defabs(re, im);
	}
	cmplx(int cmplxVec[2]) {
		re = cmplxVec[0];
		im = cmplxVec[1];
		cmplx::arg = defarg(re, im);
		cmplx::amnt = defabs(re, im);
	}
	void polar(double, double);
	double getRe();
	double getIm();
	double getArg();
	double getAbs();
	void cmplxconj();
	void print();
	void printpolar();
	cmplx operator+(cmplx);
	cmplx operator-(cmplx);
	cmplx operator*(cmplx);
	cmplx operator/(cmplx);
};

