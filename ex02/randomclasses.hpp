#ifndef ABC_HPP
# define ABC_HPP

#include "Base.hpp"
#include <cstdlib>
#include <iostream>


class A : public Base {};

class B : public Base {};

class C : public Base {};

Base *generate(void);

#endif