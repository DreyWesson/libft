#include "./inc/Span.hpp"

int testSubject()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}

void testConsecutiveNumbers()
{
    Span span(5);
    span.fillConsecutiveNumbers();
    span.printElements();
    std::cout << "Shortest Span: " << span.shortestSpan() << "\n";
    std::cout << "Longest Span: " << span.longestSpan() << "\n";
}

void testRandomNumbers()
{
    Span span(7);
    span.fillRandomNumbers();
    span.printElements();
    std::cout << "Shortest Span: " << span.shortestSpan() << "\n";
    std::cout << "Longest Span: " << span.longestSpan() << "\n";
}

void testExceptions()
{
    try
    {
        Span emptySpan(0);
        emptySpan.shortestSpan(); // Should throw NoSpanException
    }
    catch (const Span::NoSpanException &e)
    {
        std::cerr << "NoSpanException: " << e.what() << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    try
    {
        Span span(3);
        span.addNumber(1);
        span.addNumber(2);
        span.addNumber(3);
        span.addNumber(4); // Should throw MaxSizeException
    }
    catch (const Span::MaxSizeException &e)
    {
        std::cerr << "MaxSizeException: " << e.what() << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}

int main()
{
    testSubject();
    testConsecutiveNumbers();
    testRandomNumbers();
    testExceptions();
    return 0;
}
