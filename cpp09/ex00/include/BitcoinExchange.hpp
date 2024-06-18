#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
private:
	std::multimap< std::string, float > _btcExMap;
	std::multimap< std::string, float > _multRateMap;

	BitcoinExchange();

public:
	BitcoinExchange(std::multimap< std::string, float > &btcExMap, std::multimap< std::string, float > &multRateMap);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	std::multimap< std::string, float > getBtcExMap() const;
	std::multimap< std::string, float > getMultRateMap() const;
};

void parsing(char *inputFile);