#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T, typename F >
void    iter(T *addr, size_t len, F function) {
    for (size_t i = 0; i < len; i++) {
        function(addr[i]);
    }
}

#endif