#include "main.h"
#include "A/index.h"
#include "B/lib.h"
#include <iostream>

int main(int argc, char *argv[]){
    call_lib_func();
    std::cout << message << std::endl;
    return 0;
}
