/*
 * since C++17
 * -lstdc++fs
 */
#include <iostream>
#include <string>
#include <experimental/filesystem>

using namespace std;
namespace fs = std::experimental::filesystem;

int main()
{
	string path = fs::current_path();
	cout << "Current directory is " << path << endl;
}
