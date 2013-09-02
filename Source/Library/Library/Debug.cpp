#include "stdafx.h"
#include "PotatoLibrary.h"
#include <stdio.h>
#include <iostream>

namespace Potato{
	void Debug::PrintVector(vector<string>* output, char div)
		/* This function print a vectors contents out with a seperator in between */
	{
		string message("");
		for (auto i : *output)
		{
			message += i;
			message += div;
		}
	}
}