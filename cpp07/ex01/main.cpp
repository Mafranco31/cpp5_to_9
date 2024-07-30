#include "iter.hpp"
#include <iostream>
#include <string>

void    ft_capitalize(char &c) {
    if (c > 96 && c < 123)
        c -= 32;
}


template <typename T>
void    ft_increment(T &n) {
    int p = 1;
    T pp = static_cast<T>(p);

    n += pp;
}

int main( void ) {
    std::string str = "Hello World ! az";
    void    (*ptr_cap)(char &) = &ft_capitalize;

    iter(const_cast<char *>(str.c_str()), 16, ptr_cap);
    std::cout << str << std::endl;
    std::cout << std::endl;

    int     i[] = {1, 2, 3, 4, 5};
    double  d[] = {0.123456, 2., 3.};
    float   f[] = {0.123456, 42.};
    void    (*ptr_incr_int)(int &) = &ft_increment<int>;
    void    (*ptr_incr_dbl)(double &) = &ft_increment<double>;
    void    (*ptr_incr_float)(float &) = &ft_increment<float>;

    iter(i, 5, ptr_incr_int);
    iter(d, 3, ptr_incr_dbl);
    iter(f, 2, ptr_incr_float);
    std::cout << "i: ";
    for (int k = 0; k < 5; k++) { std::cout << i[k] << ", "; }
    std::cout << std::endl << "d: ";
    for (int k = 0; k < 3; k++) { std::cout << d[k] << ", "; }
    std::cout << std::endl << "f: ";
    for (int k = 0; k < 2; k++) { std::cout << f[k] << ", "; }
    return (0);
}