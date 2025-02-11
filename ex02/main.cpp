#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <cstdlib>
#include <ctime> 




void identify(Base* p)
{
    if(dynamic_cast<A*>(p))
        std::cout << "Pointer: A" << std::endl;
    if(dynamic_cast<B*>(p))
        std::cout << "Pointer: B" << std::endl;
    if(dynamic_cast<C*>(p))
        std::cout << "Pointer: C" << std::endl;
};

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        std::cout << "Reference: A" << std::endl;
        static_cast<void>(a);
    }
    catch(std::exception&) {}
    try
    {
        B &b = dynamic_cast<B&>(p);
        std::cout << "Reference: B" << std::endl;
        static_cast<void>(b);
    }
    catch(std::exception&) {}
    try
    {
        C &c = dynamic_cast<C&>(p);
        std::cout << "Reference: C" << std::endl;
        static_cast<void>(c);
    }
    catch(std::exception&){}
};

Base * generate(void)
{
    int random = std::rand() % 3 + 1;
    switch(random)
    {
        case 1:
            return new A();
        case 2:
            return new B();
        case 3:
            return new C();
    }
    return new C();
};


int main()
{
    std::srand(std::time(0));
    Base* bc = generate();
    identify(bc);
    identify(*bc);
    (void)bc;
    delete bc;

};