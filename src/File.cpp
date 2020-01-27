#include "./File.h"
#include <experimental/filesystem>

using std::string;
using std::vector;
using std::getline;
using std::cerr;
using std::endl;
using std::cout;

namespace fs = std::experimental::filesystem;

File::File(string n) : name(n)
{
	dir = fs::current_path();
	
	read();
}

File::File(string dir, string n) : dir(dir), name(n)
{
	read();
}

int File::read()
{
	if (name.empty()) {
		cerr << "An empty value of name." << endl;
		return -1;
	}

	string FullName = dir + "/" + name;

	in_file.open(FullName);

	if (!in_file.is_open())	{
		cerr << FullName << " open failed." << endl;	
		return -1;
	}

	string line;
	while (!in_file.eof()) {
		getline(in_file, line);	
		content.push_back(line);
	}

	in_file.close();

	return 1;
}

void File::print() const 
{
	cout << "File Printing\n";
	for (vector<string>::size_type i = 0; i != content.size(); ++i)
		cout << content[i] << endl;
}
