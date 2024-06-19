#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
private:
	std::map< std::string, float > _btcExMap;

	BitcoinExchange();

public:
	BitcoinExchange(const std::map< std::string, float > &btcExMap);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void calculate(const char *exRateFile) const;

	// for testing
	void printBtcExMap() const;
};

const std::map< std::string, float > parseData(const char *dataFile);