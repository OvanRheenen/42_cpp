#ifndef DATA_H
# define DATA_H

class Data
{
private:
	int	_someAmount;
public:
	Data();
	Data(const Data &other);
	Data &operator=(const Data &other);
	~Data();
};

#endif