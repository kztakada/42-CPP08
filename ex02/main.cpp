#include <cassert>
#include <iostream>
#include <list>
#include <typeinfo>
#include <vector>

#include "MutantStack.hpp"

int main() {
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    std::cout << "---------------------" << std::endl;
    {
        std::list<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << mstack.size() << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        //[...]
        mstack.push_back(0);
        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int> s(mstack);
    }
    std::cout << "---------------------" << std::endl;
    {
        std::vector<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << mstack.size() << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        //[...]
        mstack.push_back(0);
        std::vector<int>::iterator it = mstack.begin();
        std::vector<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        std::vector<int> s(mstack);
    }
    std::cout << "---------------------" << std::endl;
    // Type definitions test <int>
    assert(typeid(MutantStack<int>::value_type) == typeid(int));
    assert(typeid(MutantStack<int>::size_type) == typeid(std::size_t));
    assert(typeid(MutantStack<int>::difference_type) == typeid(std::ptrdiff_t));
    assert(typeid(MutantStack<int>::reference) == typeid(int&));
    assert(typeid(MutantStack<int>::const_reference) == typeid(const int&));
    assert(typeid(MutantStack<int>::container_type) == typeid(std::deque<int>));
    assert(typeid(MutantStack<int>::iterator) ==
           typeid(std::deque<int>::iterator));
    assert(typeid(MutantStack<int>::const_iterator) ==
           typeid(std::deque<int>::const_iterator));
    assert(typeid(MutantStack<int>::reverse_iterator) ==
           typeid(std::deque<int>::reverse_iterator));
    assert(typeid(MutantStack<int>::const_reverse_iterator) ==
           typeid(std::deque<int>::const_reverse_iterator));
    // Type definitions test <std::string>
    assert(typeid(MutantStack<std::string>::value_type) == typeid(std::string));
    assert(typeid(MutantStack<std::string>::size_type) == typeid(std::size_t));
    assert(typeid(MutantStack<std::string>::difference_type) ==
           typeid(std::ptrdiff_t));
    assert(typeid(MutantStack<std::string>::reference) == typeid(std::string&));
    assert(typeid(MutantStack<std::string>::const_reference) ==
           typeid(const std::string&));
    assert(typeid(MutantStack<std::string>::container_type) ==
           typeid(std::deque<std::string>));
    assert(typeid(MutantStack<std::string>::iterator) ==
           typeid(std::deque<std::string>::iterator));
    assert(typeid(MutantStack<std::string>::const_iterator) ==
           typeid(std::deque<std::string>::const_iterator));
    assert(typeid(MutantStack<std::string>::reverse_iterator) ==
           typeid(std::deque<std::string>::reverse_iterator));
    assert(typeid(MutantStack<std::string>::const_reverse_iterator) ==
           typeid(std::deque<std::string>::const_reverse_iterator));
    // Type definitions test vector
    assert(typeid(MutantStack<std::vector<int> >::value_type) ==
           typeid(std::vector<int>));
    assert(typeid(MutantStack<std::vector<int> >::size_type) ==
           typeid(std::size_t));
    assert(typeid(MutantStack<std::vector<int> >::difference_type) ==
           typeid(std::ptrdiff_t));
    assert(typeid(MutantStack<std::vector<int> >::reference) ==
           typeid(std::vector<int>&));
    assert(typeid(MutantStack<std::vector<int> >::const_reference) ==
           typeid(const std::vector<int>&));
    assert(typeid(MutantStack<std::vector<int> >::container_type) ==
           typeid(std::deque<std::vector<int> >));
    assert(typeid(MutantStack<std::vector<int> >::iterator) ==
           typeid(std::deque<std::vector<int> >::iterator));
    assert(typeid(MutantStack<std::vector<int> >::const_iterator) ==
           typeid(std::deque<std::vector<int> >::const_iterator));
    assert(typeid(MutantStack<std::vector<int> >::reverse_iterator) ==
           typeid(std::deque<std::vector<int> >::reverse_iterator));
    assert(typeid(MutantStack<std::vector<int> >::const_reverse_iterator) ==
           typeid(std::deque<std::vector<int> >::const_reverse_iterator));

    // The Orthodox Canonical form test
    {
        MutantStack<int> mstack;  // default constructor
        assert(mstack.empty());
        assert(mstack.size() == 0);

        for (int i = 0; i < 10; i++) {
            mstack.push(i);
        }
        assert(!mstack.empty());
        assert(mstack.size() == 10);
        assert(mstack.top() == 9);

        MutantStack<int> copyStack(mstack);  // copy constructor
        assert(copyStack.size() == 10);
        assert(copyStack.top() == 9);

        MutantStack<int> assignStack;
        assert(assignStack.empty());
        assert(assignStack.size() == 0);
        assignStack = mstack;  // assignment operator
        assert(!assignStack.empty());
        assert(assignStack.top() == 9);
        assert(assignStack.size() == 10);

        for (int i = 0; i < 10; i++) {
            assert(mstack.top() == assignStack.top());
            assert(mstack.size() == assignStack.size());
            assert(mstack.top() == copyStack.top());
            assert(mstack.size() == copyStack.size());
            mstack.pop();
            assignStack.pop();
            copyStack.pop();
        }
        assert(mstack.empty());
        assert(assignStack.empty());
        assert(copyStack.empty());
    }

    // Iterator functionality test
    {
        MutantStack<int> mstack;
        for (int i = 0; i < 10; i++) {
            mstack.push(i);
        }
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        int value = 0;
        while (it != ite) {
            assert(*it == value);
            ++it;
            value++;
        }
        assert(value == 10);
        it = mstack.begin();
        value = 0;
        while (it != ite) {
            assert(*it == value);
            ++it;
            value++;
        }
        assert(value == 10);
    }

    // Const iterator functionality test
    {
        MutantStack<int> mstack;
        for (int i = 0; i < 10; i++) {
            mstack.push(i);
        }
        MutantStack<int>::const_iterator it = mstack.begin();
        MutantStack<int>::const_iterator ite = mstack.end();
        int value = 0;
        while (it != ite) {
            assert(*it == value);
            ++it;
            value++;
        }
        assert(value == 10);
        it = mstack.begin();
        value = 0;
        while (it != ite) {
            assert(*it == value);
            ++it;
            value++;
        }
        assert(value == 10);
    }

    // Reverse iterator functionality test
    {
        MutantStack<int> mstack;
        for (int i = 0; i < 10; i++) {
            mstack.push(i);
        }
        MutantStack<int>::reverse_iterator rit = mstack.rbegin();
        MutantStack<int>::reverse_iterator rite = mstack.rend();
        int value = 9;
        while (rit != rite) {
            assert(*rit == value);
            ++rit;
            value--;
        }
        assert(value == -1);
        rit = mstack.rbegin();
        value = 9;
        while (rit != rite) {
            assert(*rit == value);
            ++rit;
            value--;
        }
        assert(value == -1);
    }
    // Const reverse iterator functionality test
    {
        MutantStack<int> mstack;
        for (int i = 0; i < 10; i++) {
            mstack.push(i);
        }
        MutantStack<int>::const_reverse_iterator rit = mstack.rbegin();
        MutantStack<int>::const_reverse_iterator rite = mstack.rend();
        int value = 9;
        while (rit != rite) {
            assert(*rit == value);
            ++rit;
            value--;
        }
        assert(value == -1);
        rit = mstack.rbegin();
        value = 9;
        while (rit != rite) {
            assert(*rit == value);
            ++rit;
            value--;
        }
        assert(value == -1);
    }

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
