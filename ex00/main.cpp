#include <cassert>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

template <typename Iterator>
void printFindResult(Iterator result_itr, Iterator end_itr) {
    if (result_itr != end_itr) {
        std::cout << "Found: " << *result_itr << std::endl;
    } else {
        std::cout << "Not Found" << std::endl;
    }
}

int main() {
    // Test with std::vector
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i * 10);
    }
    if (!vec.empty()) {
        assert(vec.size() == 10);
        assert(*vec.begin() == 0);
        assert(*(vec.end() - 1) == 90);
        assert(*vec.rbegin() == 90);
        assert(*(vec.rend() - 1) == 0);
    }

    // case 1: value exists
    std::vector<int>::iterator result_vec_itr = easyfind(vec, 50);
    assert(*result_vec_itr == 50);
    printFindResult(result_vec_itr, vec.end());

    // case 1.1: value exists (const container)
    const std::vector<int> constVec(vec);
    std::vector<int>::const_iterator result_const_vec_itr =
        easyfind(constVec, 50);
    assert(*result_const_vec_itr == 50);
    printFindResult(result_const_vec_itr, constVec.end());

    // case 2: value does not exist
    std::vector<int>::iterator result_vec_itr2 = easyfind(vec, 100);
    assert(result_vec_itr2 == vec.end());
    printFindResult(result_vec_itr2, vec.end());

    // case 2.1: value does not exist (const container)
    const std::vector<int> constVec2(vec);
    std::vector<int>::const_iterator result_const_vec_itr2 =
        easyfind(constVec2, 100);
    assert(result_const_vec_itr2 == constVec2.end());
    printFindResult(result_const_vec_itr2, constVec2.end());

    std::cout << "---------------------" << std::endl;
    // Test with std::list
    std::list<int> lst;
    for (int i = 0; i < 5; ++i) {
        lst.push_back(i * 20);
    }
    if (!lst.empty()) {
        assert(lst.size() == 5);
        assert(*lst.begin() == 0);
        std::list<int>::iterator lastElement = lst.end();
        --lastElement;
        assert(*lastElement == 80);
        assert(*lst.rbegin() == 80);
        std::list<int>::reverse_iterator firstElementReverse = lst.rend();
        --firstElementReverse;
        assert(*firstElementReverse == 0);
    }

    // case 1: value exists
    std::list<int>::iterator result_lst_itr = easyfind(lst, 60);
    assert(*result_lst_itr == 60);
    printFindResult(result_lst_itr, lst.end());

    // case 1.1: value exists (const container)
    const std::list<int> constLst(lst);
    std::list<int>::const_iterator result_const_lst_itr =
        easyfind(constLst, 60);
    assert(*result_const_lst_itr == 60);
    printFindResult(result_const_lst_itr, constLst.end());

    // case 2: value does not exist
    std::list<int>::iterator result_lst_itr2 = easyfind(lst, 100);
    assert(result_lst_itr2 == lst.end());
    printFindResult(result_lst_itr2, lst.end());

    // case 2.1: value does not exist (const container)
    const std::list<int> constLst2(lst);
    std::list<int>::const_iterator result_const_lst_itr2 =
        easyfind(constLst2, 100);
    assert(result_const_lst_itr2 == constLst2.end());
    printFindResult(result_const_lst_itr2, constLst2.end());

    return 0;
}
