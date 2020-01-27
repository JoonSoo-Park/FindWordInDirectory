#include "./extension.h"
#include <algorithm>
#include <cstddef>

using std::string;
using std::search;
using std::size_t;

bool check_extension(std::string& str)
{
	static const char* extensions[] = {".c", ".cc", ".cpp", ".h", ".txt", ".pdf"};

	typedef string::const_iterator iter;

	iter i = str.begin();
	iter j = str.end();
	while (*i != '.' && i != j) ++i;

	// ignore files starts with '.', return false
	if (i == str.begin())
		return false;

	string ext = str.substr(i - str.begin(), j - i);

	size_t k, e;
	e = sizeof(extensions) / sizeof(char*);
	for (k = 0; k < e; ++k) {
		if (!ext.compare(extensions[k]))
			return true;
	}

	return false;
}
