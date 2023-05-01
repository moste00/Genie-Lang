#include "parser-invoker/bison-invoker/Genie-BisonInvoker.h"
#include <iostream>

int main(int argc,char* argv[]) {
    if (argc < 2) {
        std::cout<<"No file given, please call genie with a file path";
        exit(-1);
    }
    genie::BisonInvoker invoker;
    invoker.add_file(argv[1]);
}