#include <vector>
#include <sstream>


using std::vector;
using std::string;

namespace Potato{
	struct Pair{
		int x;
		int y;
	};

	class Debug{
	public:
		static void PrintVector(vector<string>* output, char div='\n');
	};

	class Strings{
	public:
		static vector<string>* Split(string data, string tokens=" \t\n\r", bool sensitive=false);
		static string ReadFile(string filename);
		static vector<string>* GetLines(string filename);
	};
}