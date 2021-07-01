#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#include "../Vector3D/Vector3D.h"

using namespace std;

int main(int argc, char** argv) {

    if(argc != 3) {
        cerr << "Usage: ./a.out" << " " << "[Driver File]" << " " << "[Output File]" << '\n';
        return 1;
    }
    
    return 0;
}
