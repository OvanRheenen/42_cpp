#include "BitcoinExchange.hpp"
#include <iostream>
#include <iomanip>

//--Con/destructors-----------------------------------------------------------//

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::map< std::string, float > &btcExMap)
 : _btcExMap(btcExMap) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->_btcExMap = other._btcExMap;

	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

//--Member functions----------------------------------------------------------//

void BitcoinExchange::calculate(const char *exRateFile) const
{
	std::ifstream file(exRateFile);
	if (!file.is_open())
		throw std::runtime_error("Error: unable to open file");

	std::string line;
	if (std::getline(file, line) != "date | value")
		throw std::runtime_error("Error: file format is incorrect");
	
	while (std::getline(file, line))
	{
		//parse line
	}
}

// for testing
void BitcoinExchange::printBtcExMap() const
{
	for (const auto& pair : _btcExMap)
		std::cout << pair.first << " => " << std::setprecision(7) << pair.second << std::endl;

}


//--Other functions-----------------------------------------------------------//

#include <fstream>

static void parseDataLine(const std::string &line, std::map< std::string, float > &map)
{
	std::istringstream iss(line);
	std::string date;
	std::string value;

	while (std::getline(iss, date, ',') && std::getline(iss, value, '\n'))
	{
		float exchangeRate = std::stof(value);
		map.insert(std::make_pair(date, exchangeRate));
	}
}

const std::map< std::string, float > parseData(const char *dataFile)
{
	std::ifstream file(dataFile);
	// if (!file.is_open())
	// 	throw std::runtime_error("Error: failed to open file");

	std::string line;
	std::getline(file, line); // skip over first 'date,exchange_rate' line
	std::map< std::string, float > map;
	while (std::getline(file, line))
	{
		parseDataLine(line, map);
	}
	file.close();

	return (map);
}

// static void parseInLine(const std::string &line, std::map< std::string, float > &map)
// {
// 	std::istringstream iss(line);
// 	std::string date;
// 	char separator;
// 	float value;

// 	if (iss >> date >> separator && separator == '|' && iss >> value && value >= 0 && value <= 1000)
// 	{
// 		std::tm tm = {};
// 		std::istringstream ss(date);
// 		ss >> std::get_time(&tm, "%Y-%m-%d");
//         if (ss.fail())
// 		{
// 			std::cerr << "Error: date is not valid" << std::endl;	
// 		}
//         map.insert(std::make_pair(date, value));
// 	}
// }

