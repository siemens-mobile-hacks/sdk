#include <swilib.h>
#include <vector>
#include <string>
#include <cstdio>
#include <map>

#include <fcntl.h>

static void init_stdio(void) {
	__setup_stdout_fd(open("0:\\Misc\\stdout.txt", O_CREAT | O_TRUNC | O_WRONLY));
	__setup_stderr_fd(open("0:\\Misc\\stderr.txt", O_CREAT | O_TRUNC | O_WRONLY));
}

void print_map(std::string comment, const std::map<std::string, int>& m) {
	printf("%s\n", comment.c_str());
	for (const auto& n : m)
		printf("%s = %d\n", n.first.c_str(), n.second);
	printf("\n");
}

void test_map() {
	// Create a map of three (string, int) pairs
	std::map<std::string, int> m{{"CPU", 10}, {"GPU", 15}, {"RAM", 20}};
	
	print_map("1) Initial map: ", m);
 
	m["CPU"] = 25; // update an existing value
	m["SSD"] = 30; // insert a new value
	print_map("2) Updated map: ", m);
	
	// Using operator[] with non-existent key always performs an insert
	printf("3) m[UPS] = %d\n", m["UPS"]);
	print_map("4) Updated map: ", m);
	
	m.erase("GPU");
	print_map("5) After erase: ", m);
	
	printf("6) m.size() = %d\n", m.size());
	
	m.clear();
	printf("7) Map is empty: %s\n", m.empty() ? "true" : "false");
}

void test_vector() {
	// Create a vector containing integers
	std::vector<int> v = {8, 4, 5, 9};
	
	// Add two more integers to vector
	v.push_back(6);
	v.push_back(9);
	
	// Overwrite element at position 2
	v[2] = -1;
	
	for (int n : v)
		printf("%d\n", n);
}

void test_string() {
	std::string str = "freeCodeCamp";
	
	// Inserting a single character into `str`
	str.push_back('s');
	printf("%s\n", str.c_str()); // `str` is now `freeCodeCamps`
	
	// Deleting the last character from `str`
	str.pop_back();
	printf("%s\n", str.c_str()); // `str` is now `freeCodeCamp`
	
	// Resizing a string
	str.resize(13);
	printf("%s\n", str.c_str());
	
	// Decreasing excess capacity of the string
	str.shrink_to_fit();
	printf("%s\n", str.c_str());
}

int main() {
	init_stdio();
	test_vector();
	test_string();
	test_map();
	ShowMSG(0, (int) "OK");
	
	fflush(stdout);
	fflush(stderr);
	fclose(stdout);
	fclose(stderr);
	
	kill_elf();
	return 0;
}
