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
    try
    {
        dynamic_cast<A &>(p);
        std::cout << "p is of type A" << std::endl;
    }
    catch (const std::exception &e)
    {
        try
        {
            dynamic_cast<B &>(p);
            std::cout << "p is of type B" << std::endl;
        }
        catch (const std::exception &e)
        {
            try
            {
                dynamic_cast<C &>(p);
                std::cout << "p is of type C" << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
}

int main()
{
    Base *b;
    A a;
    B B;
    C C;

    b = generate();
    identify(b);
    identify(C);
}