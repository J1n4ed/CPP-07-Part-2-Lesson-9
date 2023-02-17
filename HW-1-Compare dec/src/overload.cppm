// module file

export module fraction;

export class Fraction
{
private:
	int numerator_;
	int denominator_;

public:

	// Перегруженные операторы

	bool operator==(Fraction);
	bool operator!=(Fraction);
	bool operator>(Fraction);
	bool operator<(Fraction);
	bool operator>=(Fraction);
	bool operator<=(Fraction);

	// Конструктор
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
};

// Реализации функций класса

bool Fraction::operator==(Fraction other)
{
	bool result = false;

	double num1 = static_cast<double>(this->numerator_) / static_cast<double>(this->denominator_);
	double num2 = static_cast<double>(other.numerator_) / static_cast<double>(other.denominator_);

	if (num1 == num2)
	{
		result = true;
	}

	return result;
}

bool Fraction::operator!=(Fraction other)
{
	return !(*this == other);
}

bool Fraction::operator>(Fraction other)
{
	bool result = false;

	double num1 = static_cast<double>(this->numerator_) / static_cast<double>(this->denominator_);
	double num2 = static_cast<double>(other.numerator_) / static_cast<double>(other.denominator_);

	if (num1 > num2)
	{
		result = true;
	}

	return result;
}

bool Fraction::operator<(Fraction other)
{
	return !(*this > other);
}

bool Fraction::operator>=(Fraction other)
{
	return ( (*this == other) || (*this > other) );
}

bool Fraction::operator<=(Fraction other)
{
	return ( (*this == other) || !(*this > other) );
}