#include "BitcoinExchange.hpp"

//--Con/destructors-----------------------------------------------------------//

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::multimap< std::string, float > &btcExMap, std::multimap< std::string, float > &multRateMap)
 : _btcExMap(btcExMap), _multRateMap(multRateMap) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->_btcExMap = other._btcExMap;
		this->_multRateMap = other._multRateMap;
	}

	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

//--Member functions----------------------------------------------------------//

std::multimap< std::string, float > BitcoinExchange::getBtcExMap() const
{
	return (_btcExMap);
}

std::multimap< std::string, float > BitcoinExchange::getMultRateMap() const
{
	return (_multRateMap);
}

//--Other functions-----------------------------------------------------------//

void parsing(char *inputFile)
{

}
