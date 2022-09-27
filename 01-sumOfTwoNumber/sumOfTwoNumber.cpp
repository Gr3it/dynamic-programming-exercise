#include <fstream>
using namespace std;

int main(){
    int x,y;
    ifstream in("input.txt");

    in >> x >> y;

    ofstream out("output.txt");
    out << x + y << "\n";

    return 0;
}