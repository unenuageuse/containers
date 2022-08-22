#include <iostream>
#include <string>
#include <deque>
#include <stdlib.h>

// ? Here for the std
// // #include <map>
// // #include <stack>
// #include <vector>
// namespace ft = std;

// ? Here for the ft (my own)
// #include "../include/map.hpp"
// #include "../include/stack.hpp"
#include "../include/vector.hpp"

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

int main(int argc, char** argv) {
	std::cout << "* Vector *" << std::endl;
  ft::vector<int> vec;
  std::cout << "Empty : " << vec.empty() << std::endl;
  std::cout << "Push back : ";
  for (int i = 0; i < 5; i++)
    vec.push_back(i * 10);
  for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;
  std::cout << "Reverse iterator : ";
  for (ft::vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); rit++)
    std::cout << *rit << " ";
  std::cout << std::endl;
  std::cout << "Size : ";
  std::cout << vec.size() << std::endl;
  std::cout << "Resize : ";
  vec.resize(10, 42);
  for (size_t i = 0; i < vec.size(); i++)
    std::cout << vec[i] << " ";
  std::cout << std::endl;
  std::cout << "Pop back : ";
  vec.pop_back();
  for (size_t i = 0; i < vec.size(); i++)
    std::cout << vec.at(i) << " ";
  std::cout << std::endl;
  vec.reserve(20);
  std::cout << "Capacity : " << vec.capacity() << std::endl;
  std::cout << "Front : " << vec.front() << std::endl;
  std::cout << "Back : " << vec.back() << std::endl;
  std::cout << "Insert : ";
  vec.insert(vec.begin() + 1, 3, 999);
  for (size_t i = 0; i < vec.size(); i++)
    std::cout << vec[i] << " ";
  std::cout << std::endl;
  std::cout << "Erase : ";
  vec.erase(vec.end() - 5);
  for (size_t i = 0; i < vec.size(); i++)
    std::cout << vec[i] << " ";
  std::cout << std::endl;
  std::cout << "Assign : ";
  vec.assign(5, 10);
  for (size_t i = 0; i < vec.size(); i++)
    std::cout << vec[i] << " ";
  std::cout << std::endl;
  std::cout << "Copy vec : ";
  ft::vector<int> copy_vec = vec;
  for (size_t i = 0; i < copy_vec.size(); i++)
    std::cout << copy_vec[i] << " ";
  std::cout << std::endl;

	// ! delete this
	(void)argv;
	(void)argc;
	// ! 

	// if (argc != 2)
	// {
	// 	std::cerr << "Usage: ./test seed" << std::endl;
	// 	std::cerr << "Provide a seed please" << std::endl;
	// 	std::cerr << "Count value:" << COUNT << std::endl;
	// 	return 1;
	// }
	// const int seed = atoi(argv[1]);
	// srand(seed);

	// ft::vector<std::string> vector_str;
	// ft::vector<int> vector_int;
	// ft::stack<int> stack_int;
	// ft::vector<Buffer> vector_buffer;
	// ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	// ft::map<int, int> map_int;

	// for (int i = 0; i < COUNT; i++)
	// {
	// 	vector_buffer.push_back(Buffer());
	// }

	// for (int i = 0; i < COUNT; i++)
	// {
	// 	const int idx = rand() % COUNT;
	// 	vector_buffer[idx].idx = 5;
	// }
	// ft::vector<Buffer>().swap(vector_buffer);

	// try
	// {
	// 	for (int i = 0; i < COUNT; i++)
	// 	{
	// 		const int idx = rand() % COUNT;
	// 		vector_buffer.at(idx);
	// 		std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
	// 	}
	// }
	// catch(const std::exception& e)
	// {
	// 	//NORMAL ! :P
	// }
	
	// for (int i = 0; i < COUNT; ++i)
	// {
	// 	map_int.insert(ft::make_pair(rand(), rand()));
	// }

	// int sum = 0;
	// for (int i = 0; i < 10000; i++)
	// {
	// 	int access = rand();
	// 	sum += map_int[access];
	// }
	// std::cout << "should be constant with the same seed: " << sum << std::endl;

	// {
	// 	ft::map<int, int> copy = map_int;
	// }
	// MutantStack<char> iterable_stack;
	// for (char letter = 'a'; letter <= 'z'; letter++)
	// 	iterable_stack.push(letter);
	// for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	// {
	// 	std::cout << *it;
	// }
	// std::cout << std::endl;
	return (0);
}
