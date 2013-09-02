#include "stdafx.h"
#include "PotatoLibrary.h"

namespace Potato{
	vector<string>* Strings::Split(string data, string tokens, bool sensitive)
		/* This function takes a string data and splits it into a vector from a string of optional tokens */
	{
		string temp="";
		bool found;
		vector<string>* buffer = new vector<string>;
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

	vector<string>* Strings::GetLines(string filename)
		/* This function returns a vector of strings of all lines in a file */
	{
		string data;
		data = ReadFile(filename);
		return Split(data, "\n");
	}
	
	string Strings::ReadFile(string filename)
		/* This function returns a string copy of a files contents */
	{
		std::ifstream file;
		string data;
		std::stringstream buffer;

		file.open(filename);
		buffer << file.rdbuf();
		data = buffer.str();
		file.close();
		return data;
	}
}