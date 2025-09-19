#include <cassert>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

#include "Span.hpp"
int main() {
    // test from Subject
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    std::cout << "---------------------" << std::endl;
    // The Orthodox Canonical Form Test
    {
        Span sp;
        assert(sp.getSize() == 0);
        assert(sp.getEmptySize() == 0);

        Span sp2(10);
        assert(sp2.getSize() == 0);
        assert(sp2.getEmptySize() == 10);
        sp2.addNumber(42);
        assert(sp2.getSize() == 1);
        assert(sp2.getEmptySize() == 9);
        sp2.addNumber(100);
        assert(sp2.getSize() == 2);
        assert(sp2.getEmptySize() == 8);
        sp2.addNumber(-10);
        assert(sp2.getSize() == 3);
        assert(sp2.getEmptySize() == 7);
        assert(sp2.shortestSpan() == 52);
        assert(sp2.longestSpan() == 110);

        Span sp3(sp2);  // Copy constructor
        assert(sp3.getSize() == 3);
        assert(sp3.getEmptySize() == 7);
        assert(sp3.shortestSpan() == 52);
        assert(sp3.longestSpan() == 110);

        Span sp4 = sp2;  // Copy assignment operator
        assert(sp4.getSize() == 3);
        assert(sp4.getEmptySize() == 7);
        assert(sp4.shortestSpan() == 52);
        assert(sp4.longestSpan() == 110);
    }

    Span sp = Span(5);
    assert(sp.getSize() == 0);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    assert(sp.getSize() == 5);

    // Test adding number to a full Span
    try {
        sp.addNumber(42);
        assert(false);  // Should not reach here
    } catch (const std::out_of_range &e) {
        assert(std::string(e.what()) == "Span is full");
    }

    // Test shortestSpan and longestSpan
    int shortest = sp.shortestSpan();
    int longest = sp.longestSpan();
    assert(shortest == 2);
    assert(longest == 14);
    std::cout << "Shortest span: " << shortest
              << std::endl;  // Expected: 2 (9 - 11 or 11 - 9)
    std::cout << "Longest span: " << longest
              << std::endl;  // Expected: 14 (3 - 17)

    // Test with insufficient numbers
    Span sp2 = Span(5);
    try {
        sp2.shortestSpan();
        assert(false);  // Should not reach here
    } catch (const std::logic_error &e) {
        assert(std::string(e.what()) == "Not enough numbers to find a span");
    }
    try {
        sp2.longestSpan();
        assert(false);  // Should not reach here
    } catch (const std::logic_error &e) {
        assert(std::string(e.what()) == "Not enough numbers to find a span");
    }
    sp2.addNumber(42);
    try {
        sp2.shortestSpan();
        assert(false);  // Should not reach here
    } catch (const std::logic_error &e) {
        assert(std::string(e.what()) == "Not enough numbers to find a span");
    }
    try {
        sp2.longestSpan();
        assert(false);  // Should not reach here
    } catch (const std::logic_error &e) {
        assert(std::string(e.what()) == "Not enough numbers to find a span");
    }

    // Test adding a range of numbers
    Span sp3 = Span(10);
    std::vector<int> nums;
    for (int i = 0; i < 20; ++i) {
        nums.push_back(i * 5);  // 0, 5, 10, ..., 95
    }
    try {
        sp3.addNumbers(nums.begin(), nums.end());
        assert(false);  // Should not reach here
    } catch (const std::out_of_range &e) {
        assert(std::string(e.what()) == "Span is full");
    }
    assert(sp3.getSize() == 10);
    assert(sp3.shortestSpan() == 5);
    assert(sp3.longestSpan() == 45);

    time_t start, rap;
    time(&start);
    // Test adding a range of numbers exceeding capacity
    std::cout << "start large test :" << start - start << "s" << std::endl;
    unsigned int largeSize = 1000000;
    Span sp4 = Span(largeSize);
    std::vector<int> largeNums;
    srand(time(NULL));
    for (unsigned int i = 0; i < largeSize; i++) {
        // largeNums.push_back(rand());
        largeNums.push_back(i);
    }
    time(&rap);
    std::cout << "registered large numbers :" << rap - start << "s"
              << std::endl;
    sp4.addNumbers(largeNums.begin(), largeNums.end());
    try {
        sp4.addNumber(42);
        assert(false);  // Should not reach here
    } catch (const std::out_of_range &e) {
        assert(std::string(e.what()) == "Span is full");
    }
    assert(sp4.getSize() == largeSize);
    time(&start);
    std::cout << "start large span calc :" << start - start << "s" << std::endl;
    int testShortest = sp4.shortestSpan();
    assert(testShortest == 1);
    std::cout << "testShortest: " << testShortest << std::endl;
    time(&rap);
    std::cout << "calculated short span :" << rap - start << "s" << std::endl;
    time(&start);
    std::cout << "start long span calc :" << start - start << "s" << std::endl;
    int testLongest = sp4.longestSpan();
    assert(testLongest == 999999);
    std::cout << "testLongest: " << testLongest << std::endl;
    time(&rap);
    std::cout << "calculated long span :" << rap - start << "s" << std::endl;

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
