#include "BitcoinExchange.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <utility>

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

void BitcoinExchange::calculate(const std::pair< std::string, float > &dateValue) const
{
	float result;
	std::map< std::string, float >::const_iterator it;
	for (it = _btcExMap.begin(); it != _btcExMap.end(); it++)
	{
		if (dateValue.first < it->first)
			break;
		result = dateValue.second * it->second;
	}

	std::cout << dateValue.first << " => " << dateValue.second << " = " << result << std::endl;
}

// for testing
void BitcoinExchange::printBtcExMap() const
{
	for (const auto& pair : _btcExMap)
		std::cout << pair.first << " => " << std::setprecision(7) << pair.second << std::endl;
}

//--Other functions-----------------------------------------------------------//

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
	if (!file.is_open())
		throw std::runtime_error("Error: failed to open file");

	std::string line;
	std::getline(file, line); // skip over first 'date,exchange_rate' line
	std::map< std::string, float > map;
	while (std::getline(file, line))
		parseDataLine(line, map);
	
	file.close();

	return (map);
}

static bool validDate(const std::string &date)
{
	// format check
	std::tm tmDate = {};
	std::istringstream ss(date);
	ss >> std::get_time(&tmDate, "%Y-%m-%d");
	if (ss.fail())
		return (false);

	// existing date check (i.e. 2009-02-30)
	std::tm tmNewDate = tmDate;
	mktime(&tmNewDate);
	if (
		tmDate.tm_year != tmNewDate.tm_year ||
        tmDate.tm_mon != tmNewDate.tm_mon   ||
        tmDate.tm_mday != tmNewDate.tm_mday
	)
		return (false);

	// date is not before 2009-01-02 check
	if (
		tmDate.tm_year + 1900 < 2009 ||
		( tmDate.tm_year + 1900 == 2009 &&
			tmDate.tm_mon + 1 == 1 && 
			tmDate.tm_mday == 1 )
	)
		return (false);
	
	// date is valid
	return (true);
} 

static const std::pair< std::string, float > parseLine(const std::string &line)
{
	std::istringstream iss(line);
	std::string date;
	float value;
	char seperator;

	if (iss >> date >> seperator && seperator == '|' && iss >> value && (iss.eof() || iss.peek() == '\n'))
	{
		if (!validDate(date))
			throw std::invalid_argument("Error: invalid date => " + date);
		else if (value < 0)
			throw std::invalid_argument("Error: not a positive number => " + std::to_string(value));
		else if (value > 1000)
			throw std::invalid_argument("Error: too large a number => " + std::to_string(value));
		else
		{
			std::pair< std::string, float > dateValuePair(date, value);
			return(dateValuePair);
		}
	}
	else
		throw std::invalid_argument("Error: bad input => " + line);
	return (std::make_pair("", 0.0f));
}

void parseAndCalculateInput(const BitcoinExchange &btcEx, const char *exRateFile)
{
	std::ifstream file(exRateFile);
	if (!file.is_open())
		throw std::runtime_error("Error: unable to open file");

	std::string line;
	std::getline(file, line);
	if (line != "date | value")
		throw std::invalid_argument("Error: incorrect file format");
	
	while (std::getline(file, line))
		btcEx.calculate(parseLine(line));
}
