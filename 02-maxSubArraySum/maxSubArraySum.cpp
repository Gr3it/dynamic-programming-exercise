#include <fstream>
using namespace std;

int main(){
    int length;
    ifstream in("input.txt");

    in >> length;

    int array[length];
    for(int i=0; i<length; i++){
        in >> array[i];
    }

    int max = 0;
    int maxHere = 0;

    for(int i=0; i<length; i++){
        maxHere += array[i];
        if(maxHere > max) max = maxHere;
        if(maxHere < 0) maxHere = 0;
    }

    ofstream out("output.txt");
    out << max;

    return 0;
}