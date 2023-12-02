#include "Serializer.hpp"

struct node
{
    int a;
};


int main()
{
    node *a = new node;
    a->a = 4;
    uintptr_t t;

    t = Serializer::serialize<node>(a);
    a = Serializer::deserialize<node>(t);
    std::cout << "t == " << t << std::endl;
    std::cout << "a == " << a << std::endl;
    std::cout << "a->a == " << a->a << std::endl;
    delete a;
}