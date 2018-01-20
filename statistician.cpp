#include "statistician.h"

main_savitch_2C::statistician::statistician()
:	_length( 0 ),
	_minimum( DBL_MAX),
	_maximum( DBL_MIN ),
	_sum( 0.0f ),
	_mean( 0.0f )
{}

main_savitch_2C::statistician::statistician(int length, double sum, double mean, double maximum, double minimum)
:	_length( length ),
	_minimum( minimum ),
	_maximum( maximum ),
	_sum( sum ),
	_mean( mean )
{}

void main_savitch_2C::statistician::next_number(const double number)
{
	_length++;
	_sum += number;
	_mean = (_sum / (double)_length);

	if (number < _minimum)
	{
		_minimum = number;
	}

	if (number > _maximum)
	{
		_maximum = number;
	}
}

const void main_savitch_2C::statistician::reset()
{
	_length = 0;
	_minimum = 0;
	_maximum = 0;
	_sum = 0;
	_mean = 0;
}

int main_savitch_2C::statistician::length()
{
	return _length;
}

double main_savitch_2C::statistician::mean()
{
	return _mean;
}

double main_savitch_2C::statistician::sum()
{
	return _sum;
}

double main_savitch_2C::statistician::maximum()
{
	return _maximum;
}

double main_savitch_2C::statistician::minimum()
{
	return _minimum;
}

main_savitch_2C::statistician main_savitch_2C::statistician::operator+(main_savitch_2C::statistician rhs)
{
	statistician newStat;
	newStat._length = this->_length + rhs._length;

	log_hold<int>(newStat.length());

	newStat._sum = this->_sum + rhs._sum;

	log_hold<double>(newStat.sum());

	newStat._mean = (this->_mean + rhs._mean) / 2.0f;

	log_hold<double>(newStat.mean());

	double min, max;
	if (this->minimum() <= rhs.minimum())
	{
		min = this->minimum();
	}
	else
	{
		min = rhs.minimum();
	}

	

	if (this->maximum() >= rhs.maximum())
	{
		max = this->maximum();
	}
	else
	{
		max = rhs.maximum();
	}

	

	newStat._minimum = min;
	log_hold<double>(newStat.minimum());
	newStat._maximum = max;
	log_hold<double>(newStat.maximum());
	return newStat;
}

bool main_savitch_2C::statistician::operator==(main_savitch_2C::statistician rhs)
{
	return
		(
			rhs.length() == this->length() &&
			rhs.maximum() == this->maximum() &&
			rhs.minimum() == this->minimum() &&
			rhs.mean() == this->mean() &&
			rhs.sum() == this->sum()
		);
}

main_savitch_2C::statistician main_savitch_2C::operator*(double n, main_savitch_2C::statistician rhs)
{
	main_savitch_2C::statistician newStat(rhs.length() * (int)n, rhs.sum() * n,
										  rhs.mean() * n, rhs.maximum() * n, rhs.minimum() * n);
	return newStat;
}