// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <iostream>
#include <memory>

#include <coxeter/fcoxgroup.h>
#include <coxeter/interactive.h>
#include <coxeter/constants.h>


int main() {
    // Always need to run this line first.
    constants::initConstants();

    const std::unique_ptr<interactive::CoxGroup> group(interactive::coxeterGroup("A", 5));

    std::cout << group->order() << std::endl;
}
