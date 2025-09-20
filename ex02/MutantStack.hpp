#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

// std::stack is a container adaptor, it uses another container (by default
// std::deque) to store the elements. The underlying container is accessible as
// a protected member named 'c'. This allows us to define iterators for
// MutantStack by using the iterators of the underlying container.
template <typename T>
class MutantStack : public std::stack<T> {
   private:
    typedef typename std::stack<T>::container_type _ContainerType;

   public:
    MutantStack() : std::stack<T>() {};
    virtual ~MutantStack() {};
    MutantStack(MutantStack const &other) : std::stack<T>(other) {}
    MutantStack &operator=(MutantStack const &other) {
        if (this != &other) {
            std::stack<T>::operator=(other);
        }
        return *this;
    }

    typedef typename _ContainerType::value_type value_type;
    typedef typename _ContainerType::size_type size_type;
    typedef typename _ContainerType::difference_type difference_type;
    typedef typename _ContainerType::reference reference;
    typedef typename _ContainerType::const_reference const_reference;
    typedef typename _ContainerType::iterator iterator;
    typedef typename _ContainerType::const_iterator const_iterator;
    typedef typename _ContainerType::reverse_iterator reverse_iterator;
    typedef
        typename _ContainerType::const_reverse_iterator const_reverse_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }
    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif /* MUTANTSTACK_HPP */
