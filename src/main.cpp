#include <iostream>
#include <unistd.h>
#include <chrono>

#define WIDTH 80
#define HEIGHT 24

using std::cout, std::endl, std::cin;

#include "screen.cpp"

auto time_now = []{return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();};
auto sleep_ms = [](int ms){usleep(ms*1000);};

int main(){
	
	Screen screen{};

	return 0;
}


/*
	cout << "\x1B[5;5H at place \x1B[m";
	
	cout << "\x1B[m  empty \x1B[m" << endl;
	cout << "\x1B[31;107m   dfs  \x1B[m" << endl;
	cout << "\x1B[64m  HELLO! \x1B[m" << endl;

	for(int i=0;i<108;i++){
		cout << "\x1B[" << i << "m" << "Text " << i << "\x1B[m" << endl;
	}
*/