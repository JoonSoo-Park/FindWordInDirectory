/*
 * represent one file in current directory
 * keeps body of file
 */

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class File {
		typedef std::vector<std::string>::size_type content_sz;
	public:
		explicit File(std::string n); // current directory 
		explicit File(std::string dir, std::string n); // read source file. also includes directory(full path)

		std::string get_name() const { return name; }	
		int read(); // reads the file 
		int find_in_file(std::string&) const;

		void print() const;
		void print_in_format(std::vector<content_sz>&, std::string&) const;
	private:
		std::ifstream in_file;
		std::string dir;
		std::string name;
		std::vector<std::string> content;

};
