#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack> 
# include <iostream>
# include <iterator>
# include <deque>

template <typename T, class container=std::deque<T> >
class MutantStack: public std::stack<T> {
    public:
        MutantStack ();
        ~MutantStack ();
        MutantStack ( const MutantStack & copy ) ;
        MutantStack &operator=( const MutantStack & other );

        typedef typename container::iterator iterator;
        iterator begin() { return this->c.begin(); };
        iterator end() { return this->c.end(); };
};

#endif

template <typename T, class container> MutantStack<T, container>::MutantStack() {}
template <typename T, class container> MutantStack<T, container>::~MutantStack() {}

template <typename T, class container> MutantStack<T, container>::MutantStack(const MutantStack &copy) : std::stack<T> (copy) {}

template <typename T, class container> MutantStack<T, container> &MutantStack<T, container>::operator=(const MutantStack &other) {
    if (this != &other)
        std::stack<T>::operator=(other);
    return *this;
}