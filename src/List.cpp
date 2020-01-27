#include "./List.h"
#include "./extension.h"
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

using std::string;
using std::istream;
using std::cout;
using std::cin;
using std::endl;

List::List(std::istream& is)
{
	read(is);
	Initialize();
	read_file();
}

int List::Initialize()
{
	typedef string::const_iterator iter;

	if (current_dir.empty())
		current_dir = fs::current_path();

	// get files name
	for (auto& dir : fs::directory_iterator(current_dir)) {
		// TODO: check if 확장자 is possible to load
		string fname, temp = dir.path();
		iter e = temp.end();
		while (*e != '/') --e;
		fname = temp.substr(e - temp.begin() + 1, temp.end() - e);
		if (check_extension(fname))
			files_name.push_back(fname);
	}
}

istream& List::read(istream& is)
{
	cout << "1: current directory" << endl;
	cout << "2: other directory" << endl;
	is >> dir_select;

	if (dir_select == 2) {
		cout << "Enter directory path: ";
		is >> current_dir;
	}

	return is;	
}

int List::read_file()
{
	svec_sz i;
	for (i = 0; i != files_name.size(); ++i) {
		if (dir_select == 2) // if other directory is selected
			files.push_back(File(current_dir, files_name[i]));
		else // current directory
			files.push_back(File(files_name[i]));
	}
}

void List::print() const 
{
	for (auto& a : files_name)
		cout << a << endl;

	/*
	cout << "\n\n";

	for (auto& a : files)
		a.print();
	*/
}
