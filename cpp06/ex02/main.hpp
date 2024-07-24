#ifndef MAIN_HPP
# define MAIN_HPP

# include "Base.hpp"
# include <iostream>
# include <string>
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

void identify(Base* p);

void identify(Base& p);

Base * generate(void);

#endif