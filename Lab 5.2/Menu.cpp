#pragma once
#include "libraries.h"

void chooseinstr()
{
	std::cout << "Введите 1 чтобы изменить элемент в массиве" << std::endl;
	std::cout << "Введите 2 чтобы отсортировать массив" << std::endl;
	std::cout << "Введите 3 чтобы вывести массив на экран" << std::endl;
	std::cout << "Введите 4 чтобы перемешать массив" << std::endl;
	std::cout << "Введите 5 чтобы найти в массиве" << std::endl;
	std::cout << "Введите 6 чтобы реверснуть массив" << std::endl;
	std::cout << "Введите любое другое число чтобы выйти" << std::endl;
}

//Проверка на ввод
int getintValue()
{
	int value = 0;

	while (true)
	{
		std::cin >> value;
		if (std::cin.peek() != '\n')
		{

			std::cin.clear();
			std::cin.ignore(32767, '\n');
			system("CLS");
			std::cout << "Введено неверное значение, поврторите ввод" << std::endl;
		}
		else
		{
			return value;
		}
	}
}

//Add element
void add_to_array(std::array<Human, ARRAY_SIZE>& arr)
{
	for (auto &x : arr)
	{
		std::string temp;
		int temp_int;
		std::cout << "Введите имя:" << std::endl;
		std::cin >> temp;
		x.set_name(temp);
		std::cout << "Введите фамилию:" << std::endl;
		std::cin >> temp;
		x.set_pathranomic(temp);
		std::cout << "Введите возраст:" << std::endl;
		temp_int = getintValue();
		x.set_age(temp_int);
		x.set_id(addId(arr));
	}
}
int addId(const std::array<Human, ARRAY_SIZE> arr)
{
	srand(time(0));
	bool bad_rand = true;
	int id = 0;
	while (bad_rand == true)
	{
		bad_rand = false;
		id = rand();
		for (auto x : arr)
		{
			if (x.get_id() == id)
			{
				bad_rand = true;
				break;
			}
		}
	}
	return id;
}

//Edit element 
void chagne_element(std::array<Human, ARRAY_SIZE>& arr)
{
	std::cout << "Введите номер элемента который хотите изменить" << std::endl;
	int choose = getintValue();
	std::string temp;
	int temp_int;
	std::cout << "Введите имя:" << std::endl;
	std::cin >> temp;
	arr[choose-1].set_name(temp);
	std::cout << "Введите фамилию:" << std::endl;
	std::cin >> temp;
	arr[choose - 1].set_pathranomic(temp);
	std::cout << "Введите возраст:" << std::endl;
	temp_int = getintValue();
	arr[choose - 1].set_age(temp_int);
}

//Show array
void show_arr(const std::array<Human, ARRAY_SIZE> arr)
{
	for (auto x : arr)
		std::cout << x << std::endl;
}

//Sorting 
int sort_by_choose()
{
	std::cout << "Введите 1 чтобы отсортировать по имени" << std::endl;
	std::cout << "Введите 2 чтобы отсортировать по фамилии" << std::endl;
	std::cout << "Введите 3 чтобы отсортировать по возрасту" << std::endl;
	return getintValue();
}
int sort_type_choose()
{
	std::cout << "Введите 1 чтобы отсортировать по возрастанию" << std::endl;
	std::cout << "Введите 2 чтобы отсортировать по убыванию" << std::endl;
	return getintValue();
}
void sortArray(std::array<Human, ARRAY_SIZE>& arr, bool(*comparator)(Human, Human))
{
	std::sort(arr.begin(), arr.end(), comparator);
}
void sort_by_name(std::array<Human, ARRAY_SIZE>& arr)
{
	int sort_type = sort_type_choose();
	if (sort_type == 1)
	{
		sortArray(arr, [](Human a, Human b)
			{
				return a.get_name() > b.get_name();
			});
	}
	else if (sort_type == 2)
	{
		sortArray(arr, [](Human a, Human b)
			{
				return a.get_name() < b.get_name();
			});
	}
	else
		std::cout << "Такого варианта нет" << std::endl;
}
void sort_by_surname(std::array<Human, ARRAY_SIZE>& arr)
{
	int sort_type = sort_type_choose();
	if (sort_type == 1)
	{
		sortArray(arr, [](Human a, Human b)
			{
				return a.get_pathranomic() > b.get_pathranomic();
			});
	}
	else if (sort_type == 2)
	{
		sortArray(arr, [](Human a, Human b)
			{
				return a.get_pathranomic() < b.get_pathranomic();
			});
	}
	else
		std::cout << "Такого варианта нет" << std::endl;
}
void sort_by_age(std::array<Human, ARRAY_SIZE>& arr)
{
	int sort_type = sort_type_choose();
	if (sort_type == 1)
	{
		sortArray(arr, [](Human a, Human b)
			{
				return a.get_age() > b.get_age();
			});
	}
	else if (sort_type == 2)
	{
		sortArray(arr, [](Human a, Human b)
			{
				return a.get_age() < b.get_age();
			});
	}
	else
		std::cout << "Такого варианта нет" << std::endl;
}
void sort_arr_menu(std::array<Human, ARRAY_SIZE>& arr)
{
	int sort_by = sort_by_choose();
	switch (sort_by)
	{
	case 1:
		system("CLS");
		sort_by_name(arr);
		system("CLS");
		std::cout << "Успешно отсортировано" << std::endl;
		break;
	case 2:
		system("CLS");
		sort_by_surname(arr);
		system("CLS");
		std::cout << "Успешно отсортировано" << std::endl;
		break;
	case 3:
		system("CLS");
		sort_by_age(arr);
		system("CLS");
		std::cout << "Успешно отсортировано" << std::endl;
		break;
	default:
		std::cout << "Такого варианта нет" << std::endl;
		break;
	}
} 

//Shuffle
void shuffle_array(std::array<Human, ARRAY_SIZE>& arr)
{
	std::mt19937 rd;
	std::shuffle(arr.begin(), arr.end(), std::default_random_engine(rd));
}


//Find
int find_choose()
{
	std::cout << "Введите 1 чтобы найти по имени" << std::endl;
	std::cout << "Введите 2 чтобы найти по фамилии" << std::endl;
	std::cout << "Введите 3 чтобы найти по возрасту" << std::endl;
	std::cout << "Введите 4 чтобы найти по id" << std::endl;
	return getintValue();
}
void find_by_name(const std::array<Human, ARRAY_SIZE> arr)
{
	std::cout << "Введите имя по которому хотите найти:" << std::endl;
	std::string name;
	std::cin >> name;
	auto start = arr.begin();
	while (start != arr.end())
	{
		auto result = std::find_if(start, arr.end(), [=](Human hum)
			{
				return hum.get_name() == name;
			});
		if (result == arr.end())
		{
			std::cout << "Такого имени не найдено" << std::endl;
			return;
		}
		else
		{
			std::cout << *result << std::endl;
			start = ++result;
		}
	}
}
void find_by_surname(const std::array<Human, ARRAY_SIZE> arr)
{
	std::cout << "Введите фамилию по которой хотите найти:" << std::endl;
	std::string name;
	std::cin >> name;
	auto start = arr.begin();
	while (start != arr.end())
	{
		auto result = std::find_if(start, arr.end(), [=](Human hum)
			{
				return hum.get_name() == name;
			});
		if (result == arr.end())
		{
			std::cout << "Такой фамилии не найдено" << std::endl;
			return;
		}
		else
		{
			std::cout << *result << std::endl;
			start = ++result;
		}
	}
}
void find_by_age(const std::array<Human, ARRAY_SIZE> arr)
{
	std::cout << "Введите возраст по которому хотите найти:" << std::endl;
	std::string name;
	std::cin >> name;
	auto start = arr.begin();
	while (start != arr.end())
	{
		auto result = std::find_if(start, arr.end(), [=](Human hum)
			{
				return hum.get_name() == name;
			});
		if (result == arr.end())
		{
			std::cout << "Такого возраста не найдено" << std::endl;
			return;
		}
		else
		{
			std::cout << *result << std::endl;
			start = ++result;
		}
	}
}
void find_by_id(const std::array<Human, ARRAY_SIZE> arr)
{
	std::cout << "Введите id по которому хотите найти:" << std::endl;
	std::string name;
	std::cin >> name;
	auto start = arr.begin();
	while (start != arr.end())
	{
		auto result = std::find_if(start, arr.end(), [=](Human hum)
			{
				return hum.get_name() == name;
			});
		if (result == arr.end())
		{
			std::cout << "Такого id не найдено" << std::endl;
			return;
		}
		else
		{
			std::cout << *result << std::endl;
			start = ++result;
		}
	}
}
void find_in_array(const std::array<Human, ARRAY_SIZE> arr)
{
	int choose = find_choose();
	switch (choose)
	{
	case 1:
		system("CLS");
		find_by_name(arr);
		break;
	case 2:
		system("CLS");
		find_by_surname(arr);
		break;
	case 3:
		system("CLS");
		find_by_age(arr);
		break;
	case 4:
		system("CLS");
		find_by_id(arr);
		break;
	default:
		system("CLS");
		std::cout << "Такого варианта нет" << std::endl;
		break;
	}
}

//Reverse
void reverse_array(std::array<Human, ARRAY_SIZE> &arr)
{
	std::reverse(arr.begin(), arr.end());
}

void perfomance(std::array<Human, ARRAY_SIZE> &arr)
{
	while (true)
	{
		chooseinstr();
		int choose = getintValue();
		switch (choose)
		{
		case 1:
			system("CLS");
			chagne_element(arr);
			break;
		case 2:
			system("CLS");
			sort_arr_menu(arr);
			break;
		case 3:
			system("CLS");
			show_arr(arr);
			break;
		case 4:
			system("CLS");
			shuffle_array(arr);
			break;
		case 5:
			system("CLS");
			find_in_array(arr);
			break;
		case 6:
			system("CLS");
			reverse_array(arr);
			break;
		default:
			return;
			break;
		}
	}
}
