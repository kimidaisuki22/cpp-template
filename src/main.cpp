#include <main/main.h>
#include <format>
#include <iostream>
#include <stacktrace>

int main(){
	std::cout << std::format("Hello {}\n", __cplusplus);
	
//    std::cout << std::stacktrace::current() << '\n';
  return 0;
}
