#include "./File.h"
#include <experimental/filesystem>
#include <algorithm>

using std::string;
using std::vector;
using std::getline;
using std::cerr;
using std::endl;
using std::cout;
using std::search;

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

int File::find_in_file(string& str) const
{
	vector<content_sz> res;
	typedef string::const_iterator iter;

	for (content_sz i = 0; i != content.size(); ++i) {
		iter s, e;	
		s = content[i].begin();
		e = content[i].end();

		s = search(s, e, str.begin(), str.end());
		if (s != e) {
			res.push_back(i + 1);
		}
	}

	if (res.empty()) return -1;

	print_in_format(res, str);
	return 1;
}

void File::print_in_format(vector<content_sz>& res, string& str) const {
	cout << "In file < " << name << " >" << endl;
	for (content_sz i = 0; i != res.size(); ++i)
		cout << "On line " << res[i] << endl;
}

void File::print() const 
{
	cout << "File Printing\n";
	for (vector<string>::size_type i = 0; i != content.size(); ++i)
		cout << content[i] << endl;
}
