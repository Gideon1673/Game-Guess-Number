#include <iostream>
#include <random>
#include <cmath>

void guessTheNumber(int, int);
int randomNumber(int, int);
void cheatCode(int random);

int main()
{
	std::cout << "Nhap so dau tien: ";
	int number1{};
	std::cin >> number1;

	std::cout << "Nhap so thu hai: ";
	int number2 {};
	std::cin >> number2;

	std::cout << "So can doan se nam trong khoang [" << number1 << ";" << number2 <<"]\n";
	int count = std::ceil(log2((number2 - number1) + 1)) ;
/* std::ceil Dung de lam tron len, vi du 3.3 --> 4
std::floor Dung de lam tron xuong, vi du 3.3 --> 3
std::round Dung de lam tron theo quy tac thong thuong
minh phai dung int count = ... vi VS2019 bao khong cho phep conversion tu Double --> Int khi dung {}
*/
	
	std::cout << "So lan doan toi da cho phep: " << count << '\n';

	int random{ randomNumber(number1, number2) };
	guessTheNumber(random, count);
	return 0;
}

void guessTheNumber(int random, int count)
{
	while (count > 0)
	{
		std::cout << "Please guess your number: ";
			int x {};
			std::cin >> x;
			if (x == random)
			{
				std::cout << "Chuc mung ban da thang, dap an la: " << random << '\n';
				return;
			}
			if (x > random)
				std::cout << "So cua ban qua cao, moi nhap lai\n";
			if (x < random)
				std::cout << "So cua ban qua thap, moi nhap lai\n";
			if (x == -123456789) // Cheat code hien luon dap an
				cheatCode(random);
		--count;
		std::cout << "So lan con lai la: " << count << '\n' << '\n';
	}
	std::cout << "Da qua so lan toi da cho phep, ban da thua\n";
	return;
}

int randomNumber(int number1, int number2)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(number1, number2);
	return distr(gen);
}
/* Mot cach tao random number trong C++ kha kho hieu, minh cung chua hieu sao lai nhu nay. Lien quan
den distribution (phan phoi) nen minh chiu. 
*/

void cheatCode(int random)
{
	std::cout << "Dap an la: " << random << '\n';
}