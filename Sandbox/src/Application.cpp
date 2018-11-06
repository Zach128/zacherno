
namespace Zacherno {

	__declspec(dllimport) void Print(); //Basic dll import statement using the 'Print' functions method signature

}

void main()
{
	Zacherno::Print(); //Hello World print statement using dll
}