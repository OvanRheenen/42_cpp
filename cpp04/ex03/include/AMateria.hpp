#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

typedef enum {
    AVAILABLE,
    EQUIPPED,
    ON_THE_FLOOR
} Status;

class ICharacter;

class AMateria
{
protected:
	AMateria();
	AMateria(const AMateria &other);

	std::string	type;
	Status		status;

public:
	AMateria(std::string const & type);
	AMateria &operator=(const AMateria &other);
	virtual ~AMateria();

	std::string const & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

	Status	getStatus();
	void	setStatus(Status status);
};

#endif
