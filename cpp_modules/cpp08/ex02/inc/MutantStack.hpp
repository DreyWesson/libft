#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template< typename T, class Container = std::deque< T > > 
class MutantStack : public std::stack< T, Container >
{
public:

    MutantStack( void ) {};
    ~MutantStack( void ) {};

    MutantStack( const MutantStack& cpy ) { *this = cpy; }
    MutantStack&    operator=( const MutantStack& obj ) {
        std::stack< T, Container >::operator=( obj );
        return *this;
    }

    typedef typename Container::iterator    iterator;

    iterator    begin() { return this->c.begin(); }
    iterator    end() { return this->c.end(); }
};


#endif