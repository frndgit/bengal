#include <iostream>
#include "parser/parser.h"

using namespace std;

int main(int argc, char *argv[])
{
    Parser parser;
    parser.setDebug(true);

    return parser.parse();
}
