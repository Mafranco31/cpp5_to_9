#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include "data.h"
# include <stdint.h>

class Serializer {

	private:
		Serializer( void );
		~Serializer();
		Serializer( const Serializer& copy);
		Serializer	&operator= ( Serializer& other );

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
		
};

#endif