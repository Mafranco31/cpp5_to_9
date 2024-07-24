#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T, typename L, typename F >
void    iter(T *addr, L len, F function) {
    for (L i = 0; i < len; i++) {
        function(addr[i]);
    }
}

#endif