#include "stdafx.h"
#include "PotatoLibrary.h"
#include <stdio.h>
#include <iostream>

namespace Potato{
	Debug::Debug(void)
		/* Default constructor */
	{
		file = &std::cout;
	}

	Debug::Debug(string fileName)
		/* Log file constructor */
	{
		std::ofstream fileStream(fileName);
		file = &fileStream;
	}

	Debug::~Debug(void)
		/* Deconstructor */
	{
	}

	void Debug::PrintVector(vector<string>* output, char div)
		/* This function print a vectors contents out with a seperator in between */
	{
		string message("");
		for (auto i : *output)
		{
			message += i;
			message += div;
		}
		LogMessage(message);
	}

	void Debug::LogMessage(string message)
		/* Log a message to the file stream, only 1 stream may be written at a time */
	{
		padlock.lock();
		*file << message.c_str() << std::endl;
		padlock.unlock();
	}

	void Debug::LogMessage(int value)
		/* Logs a numerical value */
	{
		string number="";
		number += value;
		LogMessage(number);
	}

	Debug& Debug::operator=(const Debug &other)
		/* Assignment definition */
	{
		file = other.file;
		return *this;
	}
}