#ifndef FIXED_H
# define FIXED_H

class	Fixed
{
private:

	int					_value;
	static const int	_binPoint = 8;

public:

	//constructor
	Fixed();

	//copy constructor
	Fixed(const Fixed &fixedPointN);

	//copy assignment operator overload
	Fixed &operator=(const Fixed &fixedPointN);

	// destructor
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif