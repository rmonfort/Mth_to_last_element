#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::vector;

int convert_char_to_int(const char& character)
{
	return character - '0';
}

void erase_last_2_char_from_string(string& a_string)
{
	a_string.erase(a_string.size() - 2, 2);
}

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	string line;
	while (getline(ifs, line))
	{
		// Get the last element of the string and convert it to an int
		char temp = line.back();
		int mth_to_last_element = convert_char_to_int(temp);

		// If the mth to last element is equal to zero, ignore it
		if (mth_to_last_element == 0)
		{
			cout << endl;
			continue;
		}

		erase_last_2_char_from_string(line);

		vector<char> elements;
		for (const auto &letter : line)
		{
			if (!isblank(letter))
			{
				elements.push_back(letter);
			}
		}

		// If the mth to last element is greater than the number of elements, ignore it
		if (mth_to_last_element > elements.size())
		{
			continue;
		}

		cout << elements[elements.size() - mth_to_last_element] << endl;
	}

	return 0;
}