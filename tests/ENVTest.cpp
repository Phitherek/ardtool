#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    system("ARDTOOL_ENVTEST_VAR=Works echo $ARDTOOL_ENVTEST_VAR");
    return EXIT_SUCCESS;
}
