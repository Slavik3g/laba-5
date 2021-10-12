#pragma once
#include <array>
#include <algorithm>
#include <string>
#include <random>
#include "Human.h"
#define ARRAY_SIZE 3

void chooseinstr();
int getintValue();
void perfomance(std::array<Human, ARRAY_SIZE>& arr);
int addId(std::array<Human, ARRAY_SIZE> arr);
void add_to_array(std::array<Human, ARRAY_SIZE>& arr);