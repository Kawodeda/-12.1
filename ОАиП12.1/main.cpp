
#include <iostream>
#include <fstream>

void ErrorFileMessage(const char* filename)
{
	std::cerr << "Cannot open the file " << filename << std::endl;
}

int main()
{
	const char* file1Name = "file1.txt";
	const char* file2Name = "file2.txt";

	std::ofstream file1Write(file1Name);
	if (file1Write.is_open() == false)
	{
		ErrorFileMessage(file1Name);
		return -1;
	}

	std::cout << "Enter natural numbers(to end the sequence enter 0):" << std::endl;
	while (true)
	{
		int n = 0;
		std::cin >> n;
		if (n == 0)
		{
			break;
		}
		if (n < 0)
		{
			std::cerr << "Received non-natural number";
			return -1;
		}

		file1Write << n << std::endl;
	}
	file1Write.close();

	int k = 0;
	std::cout << "\nK = ";
	std::cin >> k;

	std::ifstream file1Read(file1Name);
	if (file1Read.is_open() == false)
	{
		ErrorFileMessage(file1Name);
		return -1;
	}

	std::fstream file2(file2Name, file2.trunc | file2.in | file2.out);
	if (file2.is_open() == false)
	{
		ErrorFileMessage(file2Name);
		return -1;
	}

	int num = 0;
	while (file1Read >> num)
	{
		if (num % k == 0)
		{
			file2 << num << std::endl;
		}
	}
	file1Read.close();

	std::cout << "\nThe multiples of K:" << std::endl;

	file2.seekp(0);
	while (file2 >> num)
	{
		std::cout << num << std::endl;
	}
	file2.close();

	return 0;
}
