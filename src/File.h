/*
 * represent one file in current directory
 * keeps body of file
 */

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class File {
	public:
		explicit File(std::string n); // current directory 
		explicit File(std::string dir, std::string n); // read source file. also includes directory(full path)

		std::string get_name() const { return name; }	
		int read(); // reads the file 

		void print() const;
	private:
		std::ifstream in_file;
		std::string dir;
		std::string name;
		std::vector<std::string> content;
};
