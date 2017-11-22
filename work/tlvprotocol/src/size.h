#ifndef SIZE_H
#define SIZE_H

#include <string>

template<typename T>
size_t size(const T &value)
{
	return sizeof(T);
}

template<>
size_t size(const std::string &s)
{
	return s.length();
}

#endif
