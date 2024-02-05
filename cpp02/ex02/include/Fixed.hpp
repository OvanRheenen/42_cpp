#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class	Fixed
{
private:

	int					_value;
	static const int	_binPoint = 8;

public:

	Fixed();
	Fixed(const int n);
	Fixed(const float f);
	Fixed(const Fixed &fixedPointN);
	~Fixed();

	Fixed	&operator=(const Fixed &fixedPointN);

	bool	operator>(const Fixed &fixedPointN) const;
	bool	operator<(const Fixed &fixedPointN) const;
	bool	operator>=(const Fixed &fixedPointN) const;
	bool	operator<=(const Fixed &fixedPointN) const;
	bool	operator==(const Fixed &fixedPointN) const;
	bool	operator!=(const Fixed &fixedPointN) const;

	float	operator+(const Fixed &fixedPointN) const;
	float	operator-(const Fixed &fixedPointN) const;
	float	operator*(const Fixed &fixedPointN) const;
	float	operator/(const Fixed &fixedPointN) const;

	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	operator--(int);

	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &ostream, const Fixed &fixedPointN);

#endif