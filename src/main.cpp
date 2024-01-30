#include <main/main.h>
#include <format>
#include <iostream>
#include <stacktrace>
import foo;

int main(){
	std::cout << std::format("Hello {}\n", __cplusplus);

	
  foo f;
  f.helloworld();
	
//    std::cout << std::stacktrace::current() << '\n';
  return 0;
}
