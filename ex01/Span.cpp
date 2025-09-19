#include "Span.hpp"

#include <algorithm>
#include <climits>

Span::Span() : _maxSize(0), _numbers() {}

Span::Span(unsigned int N) : _maxSize(N), _numbers() {}

Span::~Span() {}

Span::Span(Span const &other)
    : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span &Span::operator=(Span const &other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

// public methods
void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw std::out_of_range("Span is full");
    }
    _numbers.push_back(number);
}

static unsigned int min(unsigned int a, unsigned int b) {
    return (a < b) ? a : b;
}

unsigned int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span");
    }

    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    std::vector<int>::reverse_iterator i, prev;
    unsigned int minSpan = UINT_MAX;
    for (i = sortedNumbers.rbegin(), prev = (i + 1);
        prev != sortedNumbers.rend(); i++, prev++) {
        minSpan =
            min(minSpan, static_cast<unsigned int>(
                             static_cast<long>(*i) - static_cast<long>(*prev)));
        if (minSpan == 0)
            return 0;
    }
    return minSpan;
}

unsigned int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span");
    }
    int minNum = *std::min_element(_numbers.begin(), _numbers.end());
    int maxNum = *std::max_element(_numbers.begin(), _numbers.end());
    return maxNum - minNum;
}

size_t Span::getSize() const { return _numbers.size(); }

size_t Span::getEmptySize() const { return _maxSize - _numbers.size(); }
