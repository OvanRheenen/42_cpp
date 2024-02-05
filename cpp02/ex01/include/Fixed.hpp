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
	Fixed	&operator=(const Fixed &fixedPointN);
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &ostream, const Fixed &fixedPointN);

#endif