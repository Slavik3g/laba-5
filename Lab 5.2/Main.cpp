#pragma once
#include "libraries.h"

int main()
{
	setlocale(0, "");
	std::array<Human, ARRAY_SIZE> arr;
	add_to_array(arr);
	perfomance(arr);
}