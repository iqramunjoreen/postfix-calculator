#include <string>
using namespace std;

class RuntimeException
{
private:
	string errorMsg;
public:
	RuntimeException(const string& err)
	{
		errorMsg = err;
	}
	string getMessage()
	{
		return errorMsg;
	}
};

class StackEmpty: public RuntimeException
{
public:
	StackEmpty(const string& err): RuntimeException(err)
	{}
};

class StackFull: public RuntimeException
{
public:
	StackFull(const string& err): RuntimeException(err)
	{}
};