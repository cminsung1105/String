// String.cpp
//
// ICS 46 Spring 2018
// Project #0: Getting to Know the ICS 46 VM
//
// Implement all of your String member functions in this file.
//
// Note that the entire standard library -- both the C Standard
// Library and the C++ Standard Library -- is off-limits for this
// task, as the goal is to exercise your low-level implementation
// skills (pointers, memory management, and so on).

#include "String.hpp"
#include "OutOfBoundsException.hpp"

//CONSTRUCTORS
String::String()
{
	buf = new char[1];
	buf[0] = '\0';
}

String::String(const char * chars)
	: buf(strcpy(chars))
{
}

String::String(const String& s)
	: buf(strcpy(s.buf))
{
}

//DESTRUCTOR
String::~String() noexcept
{
	delete[] buf;
}

//PUBLIC MEMBER FUNCTIONS
String& String::operator=(const String& s)
{
	try
	{
		delete[] buf;
		buf = strcpy(s.buf);
		return *this;
	}
	catch (...)
	{
		delete[] buf;
		throw;
	}
	
}

void String::append(const String& s)
{
	
	char * temp = buf;
	int str1 = strlen(temp);
	int str2 = strlen(s.buf);
	buf = new char[str1+str2+1];
	int i;
	for (i = 0; temp[i] != '\0'; i++)
	{
		buf[i] = temp[i];
	}
	int j;
	for (j = 0; s.buf[j] != '\0'; j++)
	{
		buf[j+str1] = s.buf[j];
	}
	buf[j+str1] = '\0';
	delete[] temp;
	

}

char String::at(unsigned int index) const
{
	int len = strlen(buf);
	if (index >= len)
		throw OutOfBoundsException();
	else
		return buf[index];
}

char& String::at(unsigned int index)
{
	int len = strlen(buf);
	if (index >= len)
		throw OutOfBoundsException();
	else
		return buf[index];
}

void String::clear()
{
	try
	{
		delete[] buf;
		buf = new char[1];
		buf[0] = '\0';
	}
	catch (...)
	{
		delete[] buf;
		throw;
	}
}

int String::compareTo(const String& s) const noexcept
{
	for(int i = 0; buf[i] != '\0'; i++)
	{
		if (buf[i] - s.buf[i] != 0)
		{
			return buf[i] - s.buf[i];
		}
	}
	return 0;
}

String String::concatenate(const String& s) const
{
	String newstr;
	delete[] newstr.buf;
	int str1 = strlen(buf);
	int str2 = strlen(s.buf);
	newstr.buf = new char[str1 + str2 + 1];
	int i;
	for (i = 0; buf[i] != '\0'; i++)
	{
		newstr.buf[i] = buf[i];
	}
	int j;
	for (j = 0; s.buf[j] != '\0'; j++)
	{
		newstr.buf[j+str1] = s.buf[j];
	}
	buf[j+str1] = '\0';
	return newstr;		
}

bool String::contains(const String& substring) const noexcept
{
	char * found = strstr(buf, substring.buf);
	return found != nullptr;
}

bool String::equals(const String& s) const noexcept
{
	return strlen(buf) == strlen(s.buf) && compareTo(s) == 0;	
}

int String::find(const String& substring) const noexcept
{
	char * found = strstr(buf, substring.buf);
	if (found == nullptr)
		return -1;
	else
		return found - buf;
}

bool String::isEmpty() const noexcept
{
	return strlen(buf) == 0;
}


unsigned int String::length() const noexcept
{
	return strlen(buf);
}


String String::substring(unsigned int startIndex, unsigned int endIndex) const
{
	String substr;
	delete[] substr.buf;
	unsigned int len = endIndex - startIndex;

	int length = strlen(buf);

	if (startIndex > length || endIndex > length)
	{
		throw OutOfBoundsException();
	}

	substr.buf = new char[len+1];
	int i;
	for (i = 0; i < len; i++)
	{
		substr.buf[i] = buf[i+startIndex];
	}
	substr.buf[i] = '\0';
	return substr;		
}


const char* String::toChars() const noexcept
{
	return buf;
}


//PRIVATE MEMBER FUNCTIONS
int String::strlen(const char * src)
{
	int counter = 0;
	for (int i = 0; src[i] != '\0'; i++)
	{
		++counter;
	}
	return counter;
}

char * String::strcpy(const char * src)
{
	char * dst = new char[strlen(src)+1];
	int i;
	for (i = 0; src[i] != '\0'; i++)
	{
		dst[i] = src[i];
	}
	dst[i] = '\0';
	return dst;
}

char * String::strchr(char* str, int c)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == c)
		{
			return str + i;
		}
	}
	return nullptr;
}

int String::strncmp(const char* left, const char* right, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if(left[i] - right[i] != 0)
			return left[i] - right[i];
	}
	return 0;
}

char * String::strstr(char * str, char * substr)
{
	int len = strlen(substr);
	char * s = str;
	char * p;
	while (*s != '\0')
	{
		p = strchr(s, substr[0]);
		if (p == nullptr)
			return nullptr;
		else if (strncmp(p, substr, len) == 0)
			return p;
		else
			s = p+1;
	}
	return nullptr;
}

