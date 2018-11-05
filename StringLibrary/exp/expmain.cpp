// expmain.cpp
//
// Do whatever you'd like here.  This is intended to allow you to experiment
// with the code in the "app" directory or with any additional libraries
// that are part of the project, outside of the context of the main
// application or Google Test.
#include <iostream>

int len(const char * src)
{
	int counter = 0;
	for (int i = 0; src[i] != '\0'; i++)
	{
		++counter;
	}
	return counter;
}

char * copy(const char * src, char * dest)
{
	int i;
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return dest;
}

int main()
{
	const char * src = "Minsung";
	char dest[8];
	//std::cout << len(name) << std::endl;
	std::cout << copy(src, dest) << std::endl;
    return 0;
}

