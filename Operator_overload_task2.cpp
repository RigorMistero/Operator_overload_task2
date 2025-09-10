#include <iostream>

//сложение;
//вычитание;
//умножение;
//деление;
//унарный минус;
//инкремент постфиксный и префиксный;
//декремент постфиксный и префиксный.

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	int get_numerator_()  { return numerator_; }
	int get_denominator_() { return denominator_; }
	void SetDen(int value) { this->denominator_ = value; }

	void  print_fraction()const
	{
		//if ((numerator_ == denominator_)) std::cout << "1";
		std::cout << numerator_ << "/" << denominator_;

	}
	bool check1() const
	{
		if (numerator_ == denominator_) return true;
	}

	int NOD(int numerator_, int denominator_)
	{
		numerator_ = abs(numerator_);
		denominator_ = abs(denominator_);

		if (denominator_ == 0) return numerator_;
		else return NOD(numerator_, numerator_ % denominator_);
	}

	void Reduce(int &numerator_, int &denominator_) 
	{
		int tmp = NOD(numerator_, denominator_);
		numerator_ = numerator_ / tmp;
		denominator_ = denominator_ / tmp;
	}

	Fraction operator+ (const Fraction& frac) 
	{
		int num_{};
		int denom_{};
		if (denominator_ == frac.denominator_)
		{
			num_ = numerator_ + frac.numerator_;
			denom_ = denominator_;
		}
		else
		{
			num_ = numerator_ * frac.denominator_ + frac.numerator_ * denominator_;
			denom_ = denominator_ * frac.denominator_;
		}

		//Reduce(num_,denom_);
		return Fraction(num_, denom_);
	}
	
	Fraction operator- (const Fraction& frac) 
	{
		int cd = denominator_ * frac.denominator_; // Общий знаменатель  
		int ns = numerator_ * frac.denominator_ + frac.numerator_ * denominator_; // Числитель разности  
		Fraction subtr(ns, cd); // subtr — разность дробей  
		return subtr;
	}

	Fraction operator* (const Fraction& frac) // Умножение дробей
	{
		int num = numerator_ * frac.numerator_; // числитель 
		int den = denominator_ * frac.denominator_; // знаменатель
		Fraction mult(num, den); 
		return mult;
	}

	Fraction operator/ (const Fraction& frac) // Деление дробей
	{
		int num = numerator_ * frac.denominator_; // числитель 
		int den = frac.numerator_ * denominator_; // знаменатель
		Fraction div(num, den); 
		return div;
	}

	Fraction operator- () // Унарный минус
	{
		return Fraction(-numerator_, denominator_);
	}

	Fraction operator++(int) //постфиксный инкремент
	{
		numerator_++;
		denominator_++;
		return *this;
	}

	Fraction operator--(int) //постфиксный декремент
	{
		numerator_--;
		denominator_--;
		return *this;
	}
};

int main()
{
	int num1{};
	int num2{};
	int den1{};
	int den2{};

	std::cout << "Enter fraction 1 numerator: "; std::cin >> num1;
	std::cout << "Enter fraction 1 denominator: "; std::cin >> den1;
	
	std::cout << "Enter fraction 2 numerator: "; std::cin >> num2;
	std::cout << "Enter fraction 2 denominator: "; std::cin >> den2;

	Fraction fraction1(num1, den1);
	Fraction fraction2(num2, den2);

	Fraction fraction3 = fraction1 + fraction2;

	//fraction3.Reduce(fraction3.get_numerator_(), fraction3.get_denominator_());

	fraction1.print_fraction();
	std::cout << " + ";
	fraction2.print_fraction();
	std::cout << std::endl;
	
	//std::cout << "Fraction 1 + fraction 2 numerator: " << fraction3.get_numerator_() << std::endl;
	//std::cout << "Fraction 1 + fraction 2 numerator:"  << fraction3.get_denominator_() << std::endl;
	
	//std::cout << std::endl;
	
	//std::cout << " = "; fraction3.Reduce();
	
	fraction3.print_fraction();


	return 0;
}