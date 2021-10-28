#include "Header.h"
#include <iostream>

void userGuess()
{
	std::cout << "Nhap so dau tien: ";
	int number1{};
	std::cin >> number1;

	std::cout << "Nhap so thu hai: ";
	int number2{};
	std::cin >> number2;

	std::cout << "So can doan se nam trong khoang [" << number1 << ";" << number2 << "]\n";
	int count = static_cast<int>(log2((number2 - number1) + 1)) + 1;
	/* std::ceil Dung de lam tron len, vi du 3.3 --> 4. Version 2.0 minh dung std::ceil, version 3.0 khong dung nua roi.
	std::floor Dung de lam tron xuong, vi du 3.3 --> 3
	std::round Dung de lam tron theo quy tac thong thuong
	minh phai dung int count = ... vi VS2019 bao khong cho phep conversion tu Double --> Int khi dung {}
	*/

	std::cout << "So lan doan toi da cho phep: " << count << '\n';

	int random{ randomNumber(number1, number2) };
	guessTheNumber(random, count);
}

void machineGuess()
{
	std::cout << "Moi ban nhap vao khoang gia tri [x;y] cach nhau boi dau cach: ";
	int canDuoi{};
	int canTren{};
	std::cin >> canDuoi >> canTren;
	int number{};
	std::cout << "So can doan se nam trong khoang [" << canDuoi << ";" << canTren << "]\n";
	int count = static_cast<int>(log2((canTren - canDuoi) + 1)) + 1;
	std::cout << "So lan doan toi da cho phep: " << count << '\n';
	while (true)
	{
		std::cout << "Moi ban chon so de may tinh doan: ";
		std::cin >> number;
		if (number < canDuoi || number > canTren || canDuoi >= canTren)
		{
			std::cout << "Invalid input, please try again\n";
		}
		else break;
	}
	int machineNumber{ static_cast<int>((canDuoi + canTren) / 2) };
	while (true)
	{
		bool isFirst{ true };
		if (isFirst)
		{
			std::cout << "May tinh doan so: " << machineNumber << '\n';
			isFirst = false;
		}

		if (machineNumber == number)
		{
			std::cout << "May tinh da thang\n";
			std::cout << "So luot con lai la: " << count - 1;
			break;
		}
		else
		{
			--count;
			if (count <= 0)
			{
				std::cout << "So luot con lai la: " << count << ", may tinh da thua : ))\n";
				return;
			}

			std::cout << "So luot con lai: " << count << ", nguoi dung nhap h / l: ";
			char comment{};
			std::cin >> comment;
			if (comment == 'h')
			{
				canTren = machineNumber - 1;
				machineNumber = static_cast<int>((canDuoi + canTren) / 2);
			}
			else if (comment == 'l')
			{
				canDuoi = machineNumber + 1;
				machineNumber = static_cast<int>((canDuoi + canTren) / 2);
			}
		}
	}
}