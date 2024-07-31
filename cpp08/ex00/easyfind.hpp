#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <algorithm>

class NumNotFoundException: public std::exception {
    const char * what() const throw () {
        return "The number has not been found !";
    }
};

template <typename T>
typename T::iterator easyfind( T &cont, int ent) {
    typename T::iterator it;
    it = std::find(cont.begin(), cont.end(), ent);
    if (it == cont.end())
        throw NumNotFoundException();
    return it;
}

/*template <typename T>
void easyfind( T &cont, int ent) {
    typename T::iterator it;

    it = std::find(cont.begin(), cont.end(), ent);

    if (it == cont.end())
        throw NumNotFoundException();

    std::cout << "Number found at position: "
        << std::distance(cont.begin(), it) << std::endl;
}*/

#endif