#include "./Handle.h"
#include <iostream>

using namespace std;

int main()
{
	Handle handle(cin);

	while (handle.IsRunning())
		handle.get_word(cin);
}
