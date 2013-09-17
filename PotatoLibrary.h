#include "stdafx.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <mutex>

using std::vector;
using std::string;

namespace Potato{
	struct Pair{
		int x;
		int y;

		Pair operator--(void);
		Pair operator++(void);
		Pair operator+(const Pair& other);
		Pair operator=(const Pair& other);
		Pair operator*(const Pair& other);
		Pair operator-(const Pair& other);
		Pair operator+=(const Pair& other);
		Pair operator-=(const Pair& other);
		Pair operator*=(const Pair& other);
		bool operator==(const Pair& other);
		bool operator!=(const Pair& other);
	};

	class Debug {
	public:
		std::mutex padlock;
	private:
		std::ostream *file;

	public:
		Debug(void);
		~Debug(void);
		Debug(string fileName);
		Debug& operator=(const Debug &other);

		void LogMessage(int value);
		void LogMessage(string message);
		void PrintVector(vector<string>* output, char div='\n');
	};

	class Strings{
	public:
		static string ReadFile(string filename);
		static vector<string>* GetLines(string filename);
		static vector<string>* Split(string data, string tokens=" \t\n\r", bool sensitive=false);
	};
}