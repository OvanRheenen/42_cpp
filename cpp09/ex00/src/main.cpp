#include "BitcoinExchange.hpp"
#include <iostream>
#include <iomanip>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr	<< "Error: provide only one argument:\n"
					<< "./btc <filepath>"
					<< std::endl;
		return (1);
	}

	try
	{
		const std::string btcExFile("./data.csv");
		BitcoinExchange exchange(parseData(btcExFile));

		exchange.parseAndCalculate(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}
