#include <cassert>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

#include "Span.hpp"
int main()
{
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

        Span sp3(sp2); // Copy constructor
        assert(sp3.getSize() == 3);
        assert(sp3.getEmptySize() == 7);
        assert(sp3.shortestSpan() == 52);
        assert(sp3.longestSpan() == 110);

        Span sp4 = sp2; // Copy assignment operator
        assert(sp4.getSize() == 3);
        assert(sp4.getEmptySize() == 7);
        assert(sp4.shortestSpan() == 52);
        assert(sp4.longestSpan() == 110);
    }

    Span sp = Span(12);
    assert(sp.getSize() == 0);

    sp.addNumber(17);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.addNumber(42);
    sp.addNumber(100);
    sp.addNumber(-10);
    sp.addNumber(11);
    sp.addNumber(-39);
    sp.addNumber(0);
    sp.addNumber(5);
    assert(sp.getSize() == 12);

    // Test adding number to a full Span
    try
    {
        sp.addNumber(42);
        assert(false); // Should not reach here
    }
    catch (const std::out_of_range &e)
    {
        assert(std::string(e.what()) == "Span is full");
    }

    // Test shortestSpan and longestSpan
    int shortest = sp.shortestSpan();
    int longest = sp.longestSpan();
    assert(shortest == 0);  // 11 - 11
    assert(longest == 139); // -39 - 100
    std::cout << "Shortest span: " << shortest
              << std::endl; // Expected: 0 (11 - 11)
    std::cout << "Longest span: " << longest
              << std::endl; // Expected: 139 (-39 - 100)

    // Test maximum span
    Span sp1 = Span(3);
    sp1.addNumber(INT_MIN);
    sp1.addNumber(INT_MAX);
    assert(sp1.shortestSpan() == UINT_MAX);
    assert(sp1.longestSpan() == UINT_MAX);

    sp1.addNumber(INT_MIN + 1);
    assert(sp1.shortestSpan() == 1);
    assert(sp1.longestSpan() == UINT_MAX);

    // Test with insufficient numbers
    Span sp2 = Span(5);
    try
    {
        sp2.shortestSpan();
        assert(false); // Should not reach here
    }
    catch (const std::logic_error &e)
    {
        assert(std::string(e.what()) == "Not enough numbers to find a span");
    }
    try
    {
        sp2.longestSpan();
        assert(false); // Should not reach here
    }
    catch (const std::logic_error &e)
    {
        assert(std::string(e.what()) == "Not enough numbers to find a span");
    }
    sp2.addNumber(42);
    try
    {
        sp2.shortestSpan();
        assert(false); // Should not reach here
    }
    catch (const std::logic_error &e)
    {
        assert(std::string(e.what()) == "Not enough numbers to find a span");
    }
    try
    {
        sp2.longestSpan();
        assert(false); // Should not reach here
    }
    catch (const std::logic_error &e)
    {
        assert(std::string(e.what()) == "Not enough numbers to find a span");
    }

    // Test adding a range of numbers
    Span sp3 = Span(10);
    std::vector<int> nums;
    for (int i = 0; i < 20; ++i)
    {
        nums.push_back(i * 5); // 0, 5, 10, ..., 95
    }
    try
    {
        sp3.addNumbers(nums.begin(), nums.end());
        assert(false); // Should not reach here
    }
    catch (const std::out_of_range &e)
    {
        assert(std::string(e.what()) == "Span is full");
    }
    assert(sp3.getSize() == 10);
    assert(sp3.shortestSpan() == 5);
    assert(sp3.longestSpan() == 45);

    // Test adding a range of numbers exceeding capacity
    std::cout << "start large test" << std::endl;
    unsigned int largeSize = 100000;
    Span sp4 = Span(largeSize);
    std::vector<int> largeNums;
    srand(time(NULL));
    for (unsigned int i = 0; i < largeSize; i++)
    {
        // largeNums.push_back(rand());
        largeNums.push_back(i);
    }
    std::cout << "registered large numbers"
              << std::endl;
    sp4.addNumbers(largeNums.begin(), largeNums.end());
    try
    {
        sp4.addNumber(42);
        assert(false); // Should not reach here
    }
    catch (const std::out_of_range &e)
    {
        assert(std::string(e.what()) == "Span is full");
    }
    assert(sp4.getSize() == largeSize);
    std::cout << "start large span calc" << std::endl;
    int testShortest = sp4.shortestSpan();
    assert(testShortest == 1);
    std::cout << "testShortest: " << testShortest << std::endl;
    std::cout << "calculated short span" << std::endl;
    std::cout << "start long span calc" << std::endl;
    int testLongest = sp4.longestSpan();
    assert(testLongest == 99999);
    std::cout << "testLongest: " << testLongest << std::endl;
    std::cout << "calculated long span" << std::endl;

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
