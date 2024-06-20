#include "BitcoinExchange.hpp"
#include <iostream>
#include <iomanip>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr	<< "Error: provide one argument:\n"
					<< "./btc <filepath>"
					<< std::endl;
		return (1);
	}

	BitcoinExchange exchange;
	try
	{
		const char *btcExFile = "./data.csv";
		exchange.setMap(parseData(btcExFile));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}

	// //testing
	// exchange.printBtcExMap();
	// //testing

	try
	{
		parseInput(exchange, argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}
