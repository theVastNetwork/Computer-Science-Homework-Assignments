#pragma once

#ifndef STATISTICIAN_H
#define STATISTICIAN_H
#include <iostream>

namespace main_savitch_2C
{
#define	DBL_MAX 1.7976931348623158e+308 // I defined these values for an easier implementation of the min and max
#define DBL_MIN 2.2250738585072014e-308

	class statistician
	{
	public:
		statistician();
		statistician(int length, double sum, double mean, double maximum, double minimum);
		void next_number(const double number);
		const void reset();
		int length();
		double sum();
		double mean();
		double maximum();
		double minimum();

		statistician operator+(statistician rhs);
		bool operator==(statistician rhs);

	private:
		int _length;
		double _sum;
		double _mean;
		double _minimum;
		double _maximum;
	};

	main_savitch_2C::statistician operator*(double n, main_savitch_2C::statistician s);
};

template <typename T> void log_hold(T data)
{
	std::cout << data << std::endl;
	getchar();
}

#endif
