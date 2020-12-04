#include "type.h"
#include "InterperterException.h"
#include "parser.h"
#include <iostream>

#define WELCOME "Welcome to Magshimim Python Interperter version 1.0 by "
#define YOUR_NAME "Ethan Eshed"


int main(int argc,char **argv)
{
	std::cout << WELCOME << YOUR_NAME << std::endl;

	std::string input_string;
	Type* temp = nullptr;

	// get new command from user
	std::cout << ">>> ";
	std::getline(std::cin, input_string);
	
	while (input_string != "quit()")
	{
		// prasing command
		try
		{
			temp = Parser::parseString(input_string);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

		if (temp != nullptr)
		{
			if(temp->getIsTemp()) delete temp;
		}

		// get new command from user
		std::cout << ">>> ";
		std::getline(std::cin, input_string);
	}

	return 0;
}


