// module file

export module fraction;

import <cmath>;
import <iostream>;

export class Fraction
{
private:
	int numerator_;
	int denominator_;

	// ��������� ����� 
	void simplify();

	// �������� ������� �� 0
	void check() const;

	// ���������� ����� ��������
	unsigned int greatest_common_divisor(unsigned int, unsigned int);

	// ���������� ����� �������
	unsigned int least_common_multiple(unsigned int a, unsigned int b);

public:

	// --

	int toInt() const;

	double toReal() const;

	Fraction getInverse() const;

	void print() const;

	// �������
	int get_num() const;
	int get_denum() const;

	friend std::ostream& operator<<(std::ostream&, const Fraction&);

	// ������������� ���������

	bool operator==(Fraction);
	bool operator!=(Fraction);
	bool operator>(Fraction);
	bool operator<(Fraction);
	bool operator>=(Fraction);
	bool operator<=(Fraction);

	// ������ ������������� ���������

	/*
��������;
���������;
���������;
�������;
������� �����;
��������� ����������� � ����������;
��������� ����������� � ����������.
	*/

	Fraction operator+(Fraction);
	Fraction operator-(Fraction);
	Fraction operator*(Fraction);
	Fraction operator/(Fraction);
	Fraction operator--();
	Fraction operator--(int);
	Fraction operator++();
	Fraction operator++(int);
	Fraction operator-() const;

	// �����������
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
};

// ��� �������

// �������
int Fraction::get_num() const
{
	return this->numerator_;
}

int Fraction::get_denum() const
{
	return this->denominator_;
}

void Fraction::print() const
{
	std::cout << this->numerator_ << "\\" << this->denominator_;
}

export std::ostream& operator<<(std::ostream& stream, const Fraction& other) 
{
	stream << other.get_num() << "\\" << other.get_denum();
	return stream;
}

// ���������� ����� ��������
unsigned int Fraction::greatest_common_divisor(unsigned int a, unsigned int b) 
{
	if (a % b == 0)
		return b;
	if (b % a == 0)
		return a;
	if (a > b)
		return greatest_common_divisor(a % b, b);
	return greatest_common_divisor(a, b % a);
}

// ���������� ����� �������
unsigned int Fraction::least_common_multiple(unsigned int a, unsigned int b)
{
	return (a * b) / greatest_common_divisor(a, b);
}

// ��������� ����� 
void Fraction::simplify()
{
	int gcd = greatest_common_divisor(std::abs(this->numerator_), std::abs(this->denominator_));
	this->numerator_ /= gcd;
	this->denominator_ /= gcd;
	if (this->denominator_ < 0)
	{
		this->denominator_ *= -1;
		this->numerator_ *= -1;
	}
}

// �������� ������� �� 0
void Fraction::check() const
{
	if (this->denominator_ == 0) 
	{
		throw std::overflow_error("�������� ����� ����!");
	}
}

int Fraction::toInt() const 
{
	return this->numerator_ / this->denominator_;
}

double Fraction::toReal() const 
{
	return double(this->numerator_) / this->denominator_;
}

Fraction Fraction::getInverse() const 
{
	return Fraction(this->denominator_, this->numerator_);
}

Fraction Fraction::operator-() const 
{
	return Fraction(-this->numerator_, this->denominator_);
}

// ���������� ����������

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

// ���������� �������������� ����������

Fraction Fraction::operator+(Fraction other)
{
	int a = this->numerator_,
		b = this->denominator_,
		c = other.numerator_,
		d = other.denominator_;

	Fraction result(a * d + b * c, b * d);

	return result;
}

Fraction Fraction::operator-(Fraction other)
{
	return *this + (-other);
}

Fraction Fraction::operator*(Fraction other)
{
	int a = this->numerator_, 
		b = this->denominator_,
		c = other.numerator_, 
		d = other.denominator_;

	Fraction result(a * c, b * d);

	result.simplify();

	return result;
}

Fraction Fraction::operator/(Fraction other)
{
	int a = this->numerator_,
		b = this->denominator_,
		c = other.numerator_,
		d = other.denominator_;

	Fraction result(a * d, b * c);
	return result;
}

Fraction Fraction::operator--()
{
	this->numerator_ -= this->denominator_;
	check();
	simplify();
	return *this;
}

Fraction Fraction::operator--(int)
{
	Fraction old_value(*this);
	--* this;
	return old_value;
}

Fraction Fraction::operator++()
{
	this->numerator_ += this->denominator_;
	check();
	simplify();
	return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction old_value(*this);
	++ *this;
	return old_value;
}