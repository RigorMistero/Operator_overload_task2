#include <iostream>
#include <string>

class Fraction
{
private:
    int numerator_;
    int denominator_;


    void reduce() 
    {
        int gcd = calcGCD(numerator_, denominator_);
        numerator_ /= gcd;
        denominator_ /= gcd;

        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
    }

    // NOD
    int calcGCD(int a, int b) const {
        a = std::abs(a);
        b = std::abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    Fraction(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {
        if (denominator_ == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        reduce();
    }

    
    void print() const {
        std::cout << numerator_ << "/" << denominator_;
    }

   
    Fraction operator+(const Fraction& other) const {
        int new_numerator = numerator_ * other.denominator_ + other.numerator_ * denominator_;
        int new_denominator = denominator_ * other.denominator_;
        return Fraction(new_numerator, new_denominator);
    }

    Fraction operator-(const Fraction& other) const {
        int new_numerator = numerator_ * other.denominator_ - other.numerator_ * denominator_;
        int new_denominator = denominator_ * other.denominator_;
        return Fraction(new_numerator, new_denominator);
    }

    Fraction operator*(const Fraction& other) const {
        int new_numerator = numerator_ * other.numerator_;
        int new_denominator = denominator_ * other.denominator_;
        return Fraction(new_numerator, new_denominator);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator_ == 0) {
            throw std::invalid_argument("Division by zero");
        }
        int new_numerator = numerator_ * other.denominator_;
        int new_denominator = denominator_ * other.numerator_;
        return Fraction(new_numerator, new_denominator);
    }

    // unar minus
    Fraction operator-() const {
        return Fraction(-numerator_, denominator_);
    }

    // prefix increment
    Fraction& operator++() {
        numerator_ += denominator_; 
        reduce();
        return *this;
    }

    // postfix increment
    Fraction operator++(int) {
        Fraction temp = *this;
        numerator_ += denominator_;
        reduce();
        return temp;
    }

    // prefix decrement
    Fraction& operator--() {
        numerator_ -= denominator_; 
        reduce();
        return *this;
    }

    // postfix decrement 
    Fraction operator--(int) {
        Fraction temp = *this;
        numerator_ -= denominator_;
        reduce();
        return temp;
    }

    
    bool operator==(const Fraction& other) const {
        return numerator_ * other.denominator_ == other.numerator_ * denominator_;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }
};

int main(int argc, char** argv)
{
    try {
        int num1, den1, num2, den2;

        std::cout << "Enter fraction 1 numerator: ";
        std::cin >> num1;
        std::cout << "Enter fraction 1 denominator: ";
        std::cin >> den1;

        std::cout << "Enter fraction 2 numerator: ";
        std::cin >> num2;
        std::cout << "Enter fraction 1 denominator:";
        std::cin >> den2;

        Fraction f1(num1, den1);
        Fraction f2(num2, den2);

        Fraction sum = f1 + f2;
        f1.print();
        std::cout << " + ";
        f2.print();
        std::cout << " = ";
        sum.print();
        std::cout << std::endl;

        Fraction diff = f1 - f2;
        f1.print();
        std::cout << " - ";
        f2.print();
        std::cout << " = ";
        diff.print();
        std::cout << std::endl;

        Fraction multiply = f1 * f2;
        f1.print();
        std::cout << " * ";
        f2.print();
        std::cout << " = ";
        multiply.print();
        std::cout << std::endl;

        
        Fraction division = f1 / f2;
        f1.print();
        std::cout << " / ";
        f2.print();
        std::cout << " = ";
        division.print();
        std::cout << std::endl;

        //  ++3 / 4 * 4 / 5 = 7 / 5
        //    Значение дроби 1 = 7 / 4
        //    7 / 4-- * 4 / 5 = 7 / 5
        //    Значени дроби 1 = 3 / 4

        std::cout << "++"; 
        f1.print();
        ++f1;
        std::cout << " * ";
        f2.print();
        Fraction multnew1 = f1 * f2;
        std::cout << " = ";
        multnew1.print();
        std::cout << std::endl;
        std::cout << "Fraction 1 new meaning = ";
        f1.print();
        std::cout << std::endl;
   
        
        f1.print();
        std::cout << "--";
        f1--;
        std::cout << " * ";
        f2.print();
        Fraction multnew2 = f1 * f2;
        std::cout << " = ";
        multnew2.print();
        std::cout << std::endl;
        std::cout << "Fraction 1 new meaning = ";
        f1.print();
        std::cout << std::endl;
    
    
    
    }
    catch (const std::exception& e) {
        std::cout << "ERROR: " << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}