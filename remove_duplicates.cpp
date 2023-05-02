// for input and output to the respective streams
# include <iostream> 
// to use the vector class
# include <vector>
// for the std::sort() function
# include <algorithm>
// for std::numeric_limits
# include <limits>

/*
	Author: LeeTuah
	Program: Remove duplicate items from a given list
	For SuperB league event
*/

// declaring the functions
void remove_duplicates(std::vector<int> &vec);
template <typename _T>  void printVector(std::vector<_T> &vec, std::string sep);
void fix_cin();

// fixes std::cin if bad input is provided
void fix_cin(){
	if(std::cin.fail()){
		// clears std::cin and removes all the bad input from it
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
	}	
}

// function to remove the duplicate values
void remove_duplicates(std::vector<int> &vec){
	std::sort(vec.begin(), vec.end()); // sorting the list
	
	// checking if the previous index matches with the current index, then removing the duplicates
	for(int i = 0; i < (int)(vec.size()); i++){
		if(i == 0) continue; // cannot check for previous index when the iterator starts
		if(vec[i] <= vec[i - 1]){
			vec.erase(vec.begin() + i);
			i--;
		}
	}
}

// printing the vector to verify that the program is working alright
template <typename _T> void printVector(std::vector<_T> &vec, std::string sep){
	for(auto i = vec.begin(); i != vec.end(); i++){
		std::cout << *i << sep;
	}
}

// the main program starts execution from here
int main(int argc, char const* argv[]){
	// declaring variables 
	std::vector<int> list;
	int count, num;
	
	std::cout << "How many numbers to check duplicates for?: ";
	std::cin >> count;
	fix_cin();
			
	for(int i = 0; i < count; i++){
		std::cout << "Enter integer number " << i + 1 << ": ";
		std::cin >> num;
		list.push_back(num);		
	}
	
	// removing all the duplicates		
	std::cout << "List before actions:\n";
	printVector(list, " ");
	remove_duplicates(list);
	std::cout << "\nList after actions:\n";
	printVector(list, " ");	
	return 0;	
}
