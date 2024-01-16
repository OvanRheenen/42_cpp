#include "Account.hpp"
#include <ctime>
#include <time.h>
#include <iostream>

// Initialization of static members in Account class
int Account::_nbAccounts			= 0;
int Account::_totalAmount			= 0;
int Account::_totalNbDeposits		= 0;
int Account::_totalNbWithdrawals	= 0;

Account::Account( int initial_deposit )
{
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	Account::_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";" \
				<< "amount:" << _amount << ";" \
				<< "created" \
				<< std::endl;
}

// [19920104_091532]
void	Account::_displayTimestamp( void )
{
	time_t	rawTime;
	char	buffer[19];

	std::time(&rawTime);
	std::strftime(buffer, 19, "[%Y%m%d_%H%M%S] ", std::localtime(&rawTime));
	std::cout << buffer;
}

// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout 	<< "accounts:" << _nbAccounts << ";" \
				<< "total:" << _totalAmount << ";" \
				<< "deposits:" << _totalNbDeposits << ";" \
				<< "withdrawals:" << _totalNbWithdrawals \
				<< std::endl;
}

// [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";" \
				<< "amount:" << _amount << ";" \
				<< "deposits:" << _nbDeposits << ";" \
				<< "withdrawals:" << _nbWithdrawals \
				<< std::endl;
}

// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void	Account::makeDeposit( int deposit )
{
	int	oldAmount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;

	Account::_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";" \
				<< "p_amount:" << oldAmount << ";" \
				<< "deposit:" << deposit << ";" \
				<< "amount:" << _amount << ";" \
				<< "nb_deposits:" << ++_nbDeposits \
				<< std::endl;
}

// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";" \
				<< "p_amount:" << _amount << ";" \
				<< "withdrawal:";

	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}

	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout	<< withdrawal << ";" \
				<< "amount:" << _amount << ";" \
				<< "nb_withdrawals:" << ++_nbWithdrawals \
				<< std::endl;

	return (true);
}

// [19920104_091532] index:0;amount:47;closed
Account::~Account( void )
{
	_nbAccounts--;

	Account::_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";" \
				<< "amount:" << _amount << ";" \
				<< "closed" \
				<< std::endl;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}
