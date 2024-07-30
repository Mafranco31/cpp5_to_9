#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <stdexcept>

template <typename T> class Array {
    private:
        T*		data;
        size_t	s;

    public:
        Array( void ) : s(0) { this->data = new T; }
        Array( unsigned int n ) : s(n) { this->data = new T[s]; };
		~Array() { delete[] data; }

		Array( const Array &copy ) : s(copy.s) {
			data = new T[s];
			for (size_t i = 0; i < s; i++) {
				data[i] = copy.data[i];
			}
		}

		Array<T>& operator=( const Array &other) {
			if (this == &other) { return *this; }
			delete[] data;
			s = other.s;
			data = new T[s];
			for (size_t i = 0; i < s; i++) {
				data[i] = other.data[i];
			}
			return *this;
		}

		size_t size( void ) const { return s;}

		T& operator[](size_t index) {
			if (index >= s)
				throw OutOfIndexException();
			return (data[index]);
		}

		const T& operator[](size_t index) const {
			if (index >= s)
				throw OutOfIndexException();
			return (data[index]);
		}

		class OutOfIndexException: public std::exception {
			const char	*what() const throw() {
				return "Index is out of bounds !";
			}
		};
};

#endif