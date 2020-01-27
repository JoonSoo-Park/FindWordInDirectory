#include "./Handle.h"

using std::string;
using std::istream;

int Handle::get_word(istream& is)
{
	if (!list->find_file(is)) {
		isRunning = false;
		return 0;
	}
	return 1;
}

