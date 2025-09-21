#include "Span.hpp"

#include <algorithm>
#include <climits>

Span::Span() : _maxSize(0), _numbers(), _sortedNumbers() {}

Span::Span(unsigned int N) : _maxSize(N), _numbers(), _sortedNumbers() {}

Span::~Span() {}

Span::Span(Span const &other)
    : _maxSize(other._maxSize),
      _numbers(other._numbers),
      _sortedNumbers(other._sortedNumbers) {}

Span &Span::operator=(Span const &other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
        _sortedNumbers = other._sortedNumbers;
    }
    return *this;
}

// public methods
void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
    {
        throw std::out_of_range("Span is full");
    }
    _numbers.push_back(number);
    _sortedNumbers.insert(number);
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
    {
        throw std::logic_error("Not enough numbers to find a span");
    }

    std::multiset<int>::const_iterator current = _sortedNumbers.begin();
    std::multiset<int>::const_iterator next = current;
    ++next;

    unsigned int minSpan = UINT_MAX;
    while (next != _sortedNumbers.end())
    {
        unsigned int span = static_cast<unsigned int>(static_cast<long>(*next) - static_cast<long>(*current));
        if (span < minSpan)
        {
            minSpan = span;
        }
        if (minSpan == 0)
        {
            return 0;
        }
        ++current;
        ++next;
    }
    return minSpan;
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() < 2)
    {
        throw std::logic_error("Not enough numbers to find a span");
    }
    int minNum = *std::min_element(_numbers.begin(), _numbers.end());
    int maxNum = *std::max_element(_numbers.begin(), _numbers.end());
    return static_cast<unsigned int>(static_cast<long>(maxNum) - static_cast<long>(minNum));
}

size_t Span::getSize() const { return _numbers.size(); }

size_t Span::getEmptySize() const { return _maxSize - _numbers.size(); }
