#ifndef HANDLE_H
#define HANDLE_H

#include "./List.h"
#include <istream>
#include <string>

class Handle {
	public:
		Handle(std::istream& is) : list(new List(is)), isRunning(true) { }

		int get_word(std::istream&);
		bool IsRunning() const { return isRunning; }
	private:
		List* list;
		bool isRunning;
};

#endif
