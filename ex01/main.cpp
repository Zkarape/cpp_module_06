#include "Serializer.hpp"

struct data
{
    int a;
};


int main()
{
    data *a = new data;
    a->a = 4;
    uintptr_t t;

    t = Serializer::serialize<data>(a);
    a = Serializer::deserialize<data>(t);
    std::cout << "t == " << t << std::endl;
    std::cout << "a == " << a << std::endl;
    std::cout << "a->a == " << a->a << std::endl;
    delete a;
}