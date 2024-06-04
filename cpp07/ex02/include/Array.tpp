#pragma once

//--Con/destructors-----------------------------------------------------------//

template <typename T>
Array<T>::Array() : _data(new T()), _size(0) {}
	
template <typename T>
Array<T>::Array(const unsigned int n) : _data(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array &other) : _data(new T[other._size]), _size(other._size) {
	for (unsigned int i = 0; i < other._size; i++)
		this->_data[i] = other._data[i];
}

template <typename T>
template <typename... Args>
Array<T>::Array(Args... args) : _size(sizeof...(args)) {
	_data = new T[_size];
	T temp[] = {args...};
	for (unsigned int i = 0; i < _size; i++) {
		_data[i] = temp[i];
	}
}

template <typename T>
const Array<T> &Array<T>::operator=(const Array &other) {
	if (this != &other) {
		this->_size = other._size;
		
		delete [] this->_data;
		this->_data = new T[other._size];
		for (unsigned int i = 0; i < other._size; i++)
			this->_data[i] = other._data[i];
	}

	return (*this);
}

template <typename T>
Array<T>::~Array() {
	delete [] _data;
}

//--Member functions----------------------------------------------------------//

template <typename T>
const T &Array<T>::operator[](const unsigned int index) const {
	if (index >= _size)
		throw(OutOfBoundsException());
	
	return (_data[index]);
}

template <typename T>
T &Array<T>::operator[](const unsigned int index) {
	if (index >= _size)
		throw(OutOfBoundsException());
	
	return (_data[index]);
}

template <typename T>
unsigned int Array<T>::size() const {
	return (_size);
}

template <typename T>
T *Array<T>::getData() const {
	return (_data);
}

template <typename T>
void Array<T>::print() const {
	for (unsigned int i = 0; i < this->size(); i++) {
		try {
			std::cout << "Index " << i << ": " << this->_data[i] << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

//--Exceptions----------------------------------------------------------------//

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const noexcept {
	return ("Index is out of bounds");
}
