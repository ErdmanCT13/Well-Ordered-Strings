#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>


std::string getMaxString(int);
std::string initializeString(int);
void printWellOrdered(int);
void resetString(std::string& string, int start);

int main()
{
	//std::cout << getMaxString(5) << "\n";
	//std::cout << initializeString(5) << "\n \n \n \n";
	//std::string test = "aBfdM";
	//resetString(test, 0);
	//std::cout << test << "\n \n \n \n";
	printWellOrdered(4);

	while (true)
	{
		Sleep(100);
	}
}


void printWellOrdered(int length)
{
	std::ofstream file;
	file.open("WellOrderedString.txt");
	int combos = 1;
	std::string maxString = getMaxString(length);
	std::string string = initializeString(length);
	int index = length - 1;
	file << string << "\n";
	while (string != maxString)
	{
		if (index == length - 1)
		{
			while (string.at(index) != 'z')
			{
  				string.at(index)++;
				combos++;
				file << string <<"\n";     // length 5 118 119 120 121 122
			}
			index--;
			continue; // after incrementing last value to 122, go to the next iteration of the loop
		}
		else if (index < length - 1 && string.at(index) < 122 - length + index + 1)
		{
			string.at(index)++;
			combos++;
			resetString(string, index);
			file << string << "\n";     // length 5 118 119 120 121 122
			index = length - 1;
			continue;
		}
			index--;
	}

	//check in source file folder

	file.close();
	std::cout << "DONE!" << "\n";
	std::cout << combos << " Well Ordered Combinations" << "\n";
	return;
}


std::string getMaxString(int length)
{
	std::string holder;
	for (int i = 0; i < length; i++)
	{
		holder += (122 - length + i + 1);
	}
	return holder;
}

std::string initializeString(int length)
{
	std::string holder;
	for (int i = 0; i < length; i++)
	{
		holder += (65 + i);
	}
	return holder;
}

void resetString(std::string& string, int start) // all values after start will be one greater than the previous value
{
	for (int i = start + 1; i < string.size(); i++)
	{
		string.at(i) = string.at(i - 1) + 1;
	}
}