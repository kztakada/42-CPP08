#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <stdexcept>
#include <vector>

class Span {
   public:
    Span();
    Span(unsigned int N);
    ~Span();
    Span(Span const &other);
    Span &operator=(Span const &other);

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

    size_t getSize() const;
    size_t getEmptySize() const;

    template <typename InputIterator>
    void addNumbers(InputIterator begin, InputIterator end) {
        for (InputIterator it = begin; it != end; ++it) {
            addNumber(*it);
        }
    }

   private:
    unsigned int _maxSize;
    std::vector<int> _numbers;
};

#endif /* SPAN_HPP */
