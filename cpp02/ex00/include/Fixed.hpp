#ifndef FIXED_H
# define FIXED_H

class	Fixed
{
private:

	int					_value;
	static const int	_binPoint = 8;

public:

	Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif