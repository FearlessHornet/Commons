// Split.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


std::vector<std::string>* Split(std::string data, std::string tokens=" \t\n\r", bool sensitive=false)
{
	std::string temp="";
	bool found=false;
	std::vector<std::string>* buffer = new std::vector<std::string>;
	for (auto i : data)
	{

		found = false;
		for (auto token : tokens)
		{
			if (!sensitive)
			{
				found = (tolower(i) == tolower(token));
			}
			else
			{
				found = (i == token);
			}

			if (found)
			{
				if (temp.length() > 0)
				{
					buffer->push_back(temp);
					temp = "";
				}
				break;
			}
		}

		if (!found)
		{
			temp += i;
		}
		
	}
	if (!found)
	{
		buffer->push_back(temp);
	}

	return buffer;
}

std::string StrVector(std::vector<std::string> output)
{
	std::string buffer;
	for (auto i : output)
	{
		buffer.append(i+"\n");
	}
	return buffer;
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<std::string>* result;
	std::string result1;
	std::string result2;
	std::string result3;
	std::string data;
	data = "This is a test piece of data. Its sole purpose is testing...\nSo no further a due\tTEST!";
	std::printf("TESTING SPLIT...\nTEST DATA: %s\n",data.c_str());
	result = Split(data);
	result1 = StrVector(*result);
	result = Split(data, ",. \t");
	result2 = StrVector(*result);
	result = Split(data, "T", true);
	result3 = StrVector(*result);
	std::printf("TEST 1; DEFAULTS:\n%sTEST 2; TOKENS = \",. \\t\":\n%sTEST 3; CASE SENSITIVE, TOKENS = \"T\":\n%sPRESS ENTER TO CONTINUE",result1.c_str(),result2.c_str(),result3.c_str());
	std::getchar();
	return 0;
}

