#include<iostream>
#include<string>
#include<vector>
#include<fstream>


std::vector<std::string> wrongTries;

void printWrongTries(std::vector<std::string> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << i + 1 << "." << vector[i] << "\n";
	}
}

void changePassword()
{
	std::string input;
	std::vector<std::string> something;
	std::ofstream passwordFile("password.txt");
	std::cout << "Type new password: \n";
	std::cin >> input;
	something.push_back(input);

	for (std::string something : something)
	{
		passwordFile << something;
	}
	std::cout << "New password saved.\n";
}

void guessPassword()
{
	std::string answer;
	std::ifstream passwordFile("password.txt");
	getline(passwordFile, answer);
	std::string userGuess;
	int chances = 5;
	if (passwordFile.is_open())
	{
		std::cout << "\nEnter your password: \n";
		for (int i = 0; i < chances + 1; i++)
		{
			std::cin >> userGuess;
			if (userGuess == answer)
			{
				std::cout << "Correct answer! \n";
				exit(0);
			}
			else
			{
				std::cout << "Wrong answer.\n";
				wrongTries.push_back(userGuess);
				if (i >= chances - 1)
				{
					std::cout << "\n\nWrong Tries: \n";
					printWrongTries(wrongTries);
					exit(0);
				}
			}
		}
	}
	else
	{
		std::cout << "No password saved.Please key in a new password.\n";
		changePassword();
	}
	
}

int main()
{
	int userChoice;
	std::cout << "------------System Terminal------------ \n" << "1.Guess password\n" << "2.Change password\n" << "3.Exit\n" << "---------------------------------------\n";
	std::cout << "Your choice: ";
	std::cin >> userChoice;
	if (userChoice == 1)
	{
		guessPassword();
	}
	else if (userChoice == 2)
	{
		changePassword();
	}
	else if (userChoice == 3)
	{
		std::cout << "\nOk,bye bye.\n";
		exit(0);
	}
	else
	{
		std::cout << "\nChoice not recognised.Exiting...\n";
		exit(1);
	}
}
