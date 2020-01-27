#ifndef LIST_H
#define LIST_H
/*
 * Read files name from current Dir
 */

#include "./File.h"

class List {
	public:
		explicit List(std::istream& is);

		int Initialize();
		std::istream& read(std::istream&);
		int read_file();

		void print() const;

		std::string get_current_dir() const { return current_dir; }
	private:
		std::string current_dir;
		std::vector<std::string> files_name;
		std::vector<File> files;
		int dir_select;

		typedef std::vector<File>::size_type file_size;
		typedef std::vector<std::string>::size_type svec_sz;
};

#endif
