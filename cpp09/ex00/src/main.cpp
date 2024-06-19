#include "BitcoinExchange.hpp"
#include <iostream>
#include <iomanip>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Please provide one file as argument" << std::endl;
		return (1);
	}

	const char *btcExFile = "./data.csv";
	BitcoinExchange exchange(parseData(btcExFile));
	
	exchange.printBtcExMap();
	try {
		exchange.calculate(argv[1]);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}

/**
 * I can also skip parsing the input file and only do that while
 * performing the calculations, so I can still execute the rightly 
 * formatted lines and give an error per line instead of the whole thing
 * OR
 * exit program if input file isn't according to date | value
 * with value >= 0 && <= 1000
 * or give error codes to these pairs in the map and still execute the rest
 * and give an error line by line (more like subject):
 * - Not a positive number
 * - Too large number
 * - Wrong date format
 * - Wrong line format (not date | value)
 */