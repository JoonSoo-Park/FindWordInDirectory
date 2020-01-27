#ifndef LIST_H
#define LIST_H
/*
 * Read files name from current Dir
 */

#include "./File.h"

class List {
		friend class Handle;

		typedef std::vector<std::string>::size_type svec_sz;
		typedef std::vector<File>::size_type files_sz;
	public:
		explicit List(std::istream& is);

		std::string get_current_dir() const { return current_dir; }
		int find_file(std::istream&);
		void print() const;
	private:
		std::string current_dir;
		std::vector<std::string> files_name;
		std::vector<File> files;
		int dir_select;

		std::istream& read(std::istream&);
		int Initialize();
		int read_file();
};

#endif
