#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
private:
	std::map< std::string, float > _btcExMap;

public:
	BitcoinExchange();
	BitcoinExchange(const std::map< std::string, float > &btcExMap);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void setMap(const std::map< std::string, float > &map);

	void calculate(const std::pair< std::string, float > &dateValue) const;

	// for testing
	void printBtcExMap() const;
};

const std::map< std::string, float > parseData(const char *dataFile);
void parseInput(const BitcoinExchange &btcEx, const char *exRateFile);