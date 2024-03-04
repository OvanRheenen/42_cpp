#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class ICharacter;

class AMateria
{
protected:
	AMateria();
	AMateria(const AMateria &other);

	std::string	type;

public:
	AMateria(std::string const & type);
	AMateria &operator=(const AMateria &other);
	virtual ~AMateria();

	std::string const & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
