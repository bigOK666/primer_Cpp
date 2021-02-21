#include<string>


class Account {
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double actualRate) { interestRate = actualRate; };
private:
	std::string owner;
	double amount;
	static double interestRate;
	static constexpr double todayRate = 0.8;
	static void initRate();


};

void Account::initRate()
{
	interestRate = todayRate;
}