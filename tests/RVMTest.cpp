#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

int main() {
    chdir("../ardtool-testproject");
    system("bundle exec ruby test.rb");
    return EXIT_SUCCESS;
}
