#include "randomclasses.hpp"

Base::~Base() {}

Base *generate(void)
{
    srand(time(NULL));
    int rnum = rand() % 3;
    if (rnum == 0)
        return (new A());
    if (rnum == 1)
        return (new B());
    if (rnum == 2)
        return (new C());
    return (NULL);
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "p is of type A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "p is of type B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "p is of type C" << std::endl;
    else
        std::cout << "p is of type Base" << std::endl;
}

void identify(Base &p)
{
    if (dynamic_cast<A *>(&p))
        std::cout << "Actual type is A\n";
    else if (dynamic_cast<B *>(&p))
        std::cout << "Actual type is B\n";
    else if (dynamic_cast<C *>(&p))
        std::cout << "Actual type is C\n";
    else
        std::cout << "Actual type is unknown\n";
}

int main()
{
    Base *b;
    A a;
    B B;
    C C;

    b = &B;
    identify(b);
}