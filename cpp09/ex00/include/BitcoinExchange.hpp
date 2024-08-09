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

	void parseAndCalculate(const char *exchangeRateFile) const;
	void calculate(const std::pair< std::string, float > &dateValue) const;

	// for testing
	void printBtcExMap() const;
};

const std::map< std::string, float > parseData(const std::string &dataFile);
