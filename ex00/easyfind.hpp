#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>

// requirements: T must support begin(), end(), and have a nested type
// 'iterator' This works for standard containers like std::vector, std::list,
// etc.
template <typename T>
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator result_itr =
        std::find(container.begin(), container.end(), value);
    return result_itr;
}

// const version
template <typename T>
typename T::const_iterator easyfind(const T &container, int value) {
    typename T::const_iterator result_itr =
        std::find(container.begin(), container.end(), value);
    return result_itr;
}

// note:
// If T does not meet these requirements, a compilation error will occur.
// This is a form of duck typing in C++ templates.
// Note: C++98 does not have 'concepts', so we rely on SFINAE for constraint
// checking. If you try to use easyfind with a type that does not meet the
// requirements, it will result in a compilation error.

// why need typename before T::iterator?
// In C++, when you refer to a nested type that depends on a template parameter,
// you need to use the 'typename' keyword to indicate that it is a type.
// This is necessary because the compiler cannot determine whether 'T::iterator'
// is a type or a static member until the template is instantiated with a
// specific type for T.

// ------------------------------------------------------------------
// Example to illustrate the need for 'typename':
// template <typename T>
// class Container {
// public:
//     static const int iterator = 42;  // 値として定義
// };

// template <typename U>
// void testFunction() {
//     // Container<U>::iterator は依存名で、この場合は値
//     int value = Container<U>::iterator;  // 値として使用

//     // typename Container<U>::iterator it;  // エラー！iteratorは型ではない
// }
#endif /* EASYFIND_HPP */
