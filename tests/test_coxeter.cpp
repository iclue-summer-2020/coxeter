// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <iostream>

#include <coxeter/fcoxgroup.h>
#include <coxeter/constants.h>

int main() {
    // Always need to run this line first.
    constants::initConstants();

    fcoxgroup::FiniteCoxGroup group("A", 5);

    std::cout << group.order() << std::endl;

    // Segfaults here for some reason?
}
