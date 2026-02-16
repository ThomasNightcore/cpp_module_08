
#include "Span.hpp"
#include <exception>
#include <iostream>
#include <vector>

static void shortSpanTest(void) {
    std::cout << " ==== Testing with double elements ==== " << std::endl;

    std::vector<int> tmp;
    tmp.push_back(1);
    tmp.push_back(0);
    tmp.push_back(5);
    tmp.push_back(5);
    tmp.push_back(9);
    std::vector<int>::iterator from = tmp.begin();
    std::vector<int>::iterator to = tmp.end();

    Span sp = Span(5);
    sp.assign(from, to);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

static void subjectTest(void) {
    std::cout << " ==== Testing with cases from subject ==== " << std::endl;
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

static void exceptionTests(void) {
    std::cout << " ==== Testing with cases from subject ==== " << std::endl;
    Span sp = Span(5);

    std::cout << " * getting span with insufficient elements... " << std::endl;
    try {
        std::cout << sp.longestSpan() << std::endl;
    } catch (std::exception &ex) {
        std::cout << "Caught exception " << ex.what() << std::endl;
    }
    try {
        std::cout << sp.shortestSpan() << std::endl;
    } catch (std::exception &ex) {
        std::cout << "Caught exception " << ex.what() << std::endl;
    }

    std::cout << " * adding one element..." << std::endl;
    sp.addNumber(0);
    try {
        std::cout << sp.longestSpan() << std::endl;
    } catch (std::exception &ex) {
        std::cout << "Caught exception " << ex.what() << std::endl;
    }
    try {
        std::cout << sp.shortestSpan() << std::endl;
    } catch (std::exception &ex) {
        std::cout << "Caught exception " << ex.what() << std::endl;
    }

    std::cout << " * adding one more element (should now work with 2)..."
              << std::endl;
    sp.addNumber(1);
    std::cout << sp.longestSpan() << std::endl;
    std::cout << sp.shortestSpan() << std::endl;

    std::cout << " * inserting too many elements... " << std::endl;
    try {
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);
        sp.addNumber(5);
    } catch (std::exception &ex) {
        std::cout << "Caught exception " << ex.what() << std::endl;
    }
}

static void bigSizeTest(void) {
    std::srand(static_cast<unsigned int>(time(0)));
    const int size = 10000;

    std::cout << " ==== Testing with " << size
              << " elements in Span ==== " << std::endl;

    std::vector<int> tmp;
    tmp.reserve(size);
    for (int i = 0; i < size; i++) {
        tmp.push_back(std::rand());
    }

    std::vector<int>::iterator from = tmp.begin();
    std::vector<int>::iterator to = tmp.end();
    Span sp = Span(size);
    sp.assign(from, to);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

int main(void) {
    exceptionTests();
    std::cout << std::endl;
    subjectTest();
    std::cout << std::endl;
    shortSpanTest();
    std::cout << std::endl;
    bigSizeTest();

    return 0;
}