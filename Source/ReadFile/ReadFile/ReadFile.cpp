// ReadFile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <sstream>
#include <string>
using std::string;


int _tmain(int argc, _TCHAR* argv[])
{
	std::ifstream file;
	std::string data;
	std::stringstream buffer;

	file.open("testfile.txt");
	buffer << file.rdbuf();
	data = buffer.str();
	file.close();
	std::puts(data.c_str());
	std::getchar();
	return 0;
}

