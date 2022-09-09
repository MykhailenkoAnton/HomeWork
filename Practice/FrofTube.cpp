#include <iostream>

int atoii(char* str);
bool isDigit(char ch);
int Convert(char ch);

int main()
{
	char* str = "1331";

	std::cout << str << std::endl;

	int result = atoii(str);

	std::cout << result << std::endl;
	return 0;
}

int atoii(char* str)
{
	if (str == nullptr)
	{
		return 0;
	}

	int multipl = 10;
	int number = 0;

	for (char * elem = &str[0]; *elem != '\0'; elem++)
	{
		int digit = Convert(*elem);
		number = number * multipl + digit;
	}

	return number;
}
bool isDigit(char ch)
{
	return ch >= 48 && ch <= 57;
}

int Convert(char ch)
{
	int result = ch - '0';
	return result;
}