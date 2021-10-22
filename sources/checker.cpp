#include "checker.hpp"
#include <ostream>
#include <iostream>
#include <fstream>
#include <cstdio>

int     main(int ac, char **av)
{
	if (ac != 2)
		return 1;

    FILE * file;
    file = fopen (av[1], "wb");
    fseek(file, 0, SEEK_END);
    if (ftell(file) == 0)
    {
		std::cout << av[1] << "\033[1;32m OK\033[0m\n";
    }
    else 
    {
		std::cout << av[1] << "\033[1;31m KO\033[0m\n";
    }
    fclose(file);
    return (0);
}