## Strategy Pattern

The strategy pattern, aka policy pattern, is a software design pattern that enables an algorithm’s behavior
to be selected at runtime. The strategy pattern

- defines a family of algorithms,
- encapsulates each algorithm, and
- makes the algorithms interchangeable within that family

```c++
//Simple Example in C++
#include <iostream>
#include <string>
 
template <typename OutputPolicy, typename LanguagePolicy>
class HelloWorld : private OutputPolicy, private LanguagePolicy
{
    using OutputPolicy::print;
    using LanguagePolicy::message;
 
public:
    // Behaviour method
    void run() const
    {
        // Two policy methods
        print(message());
    }
};
 
class OutputPolicyWriteToCout
{
protected:
    template<typename MessageType>
    void print(MessageType&& message) const
    {
        std::cout << message << std::endl;
    }
};

class LanguagePolicyEnglish
{
protected:
    std::string message() const
    {
        return "Hello, World!";
    }
};
 
class LanguagePolicyGerman
{
protected:
    std::string message() const
    {
        return "Hallo Welt!";
    }
};
 
int main()
{
    /* Example 1 */
    typedef HelloWorld<OutputPolicyWriteToCout, LanguagePolicyEnglish> HelloWorldEnglish;
 
    HelloWorldEnglish hello_world;
    hello_world.run(); // prints "Hello, World!"
 
    /* Example 2 
     * Does the same, but uses another language policy */
    typedef HelloWorld<OutputPolicyWriteToCout, LanguagePolicyGerman> HelloWorldGerman;
 
    HelloWorldGerman hello_world2;
    hello_world2.run(); // prints "Hallo Welt!"
}
```