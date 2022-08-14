#include <iostream>
#include "../include/vector.hpp"

int main(void) {
  std::cout << "* Vecotr *" << std::endl;

  ft::vector<int> vec;

  std::cout << vec.empty();

  for (int i = 0; i < 5; i++)
    vec.push_back(i * 10);

  for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    std::cout << *it << " ";
  std::cout << "\n";
  
  for (ft::vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); rit++)
    std::cout << *rit << " ";
  std::cout << "\n";

  std::cout << vec.size() << "\n";

  vec.resize(10, 42);
  std::cout << "\n";

  for (size_t i = 0; i < vec.size(); i++)
    std::cout << vec[i] << " ";
  std::cout << "\n";

  vec.pop_back();

  for (size_t i = 0; i < vec.size(); i++)
    std::cout << vec.at(i) << " ";
  std::cout << "\n";

  vec.reserve(20);
  std::cout << vec.capacity() << "\n";

  std::cout << vec.front() << "\n";
  std::cout << vec.back() << "\n";

  vec.insert(vec.begin() + 1, 3, 999);
  for (size_t i = 0; i < vec.size(); i++)
    std::cout << vec[i] << " ";
  std::cout << "\n";

  vec.erase(vec.end() - 5);
  for (size_t i = 0; i < vec.size(); i++)
    std::cout << vec[i] << " ";
  std::cout << "\n";

  vec.assign(5, 10);
  for (size_t i = 0; i < vec.size(); i++)
    std::cout << vec[i] << " ";
  std::cout << "\n";

  ft::vector<int> copy_vec = vec;
  for (size_t i = 0; i < copy_vec.size(); i++)
    std::cout << copy_vec[i] << " ";
  std::cout << "\n";

  std::cout << (vec == copy_vec) << " " << (vec != copy_vec) << "\n";
  return (0);
}
