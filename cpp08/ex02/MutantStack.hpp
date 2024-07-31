#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack> 
# include <iostream>
# include <iterator>
# include <deque>

//  The class template of std::stack ask for a type T and a container
//  to addapt to. (deque by default)
template <typename T, class container=std::deque<T> >
class MutantStack: public std::stack<T> {
    public:
        MutantStack () {};
        ~MutantStack () {};
        MutantStack ( const MutantStack & copy ) : std::stack<T> (copy) {};
        MutantStack &operator=( const MutantStack & other ) {
            if (this != &other)
                std::stack<T>::operator=(other);
            return *this;
        };

        typedef typename container::iterator iterator;

    //  'c' is the name of the container in std::stack
        iterator begin() { return this->c.begin(); };
        iterator end() { return this->c.end(); };
};

#endif