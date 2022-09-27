#include <fstream>
using namespace std;

void resetArray(int vect[], int dimension){
    for(int i=0; i<dimension; i++){
        vect[i] = 0;
    }
}

int arraySum(int vect[], int dimension){
    int sum = 0;
    for(int i=0; i<dimension; i++){
        sum += vect[i];
    }
    return sum;
}

int main(){
    ifstream in("input.txt");
    int row, column;

    in >> row >> column;

    int matrix[row][column];
    int supportColumn[row];

    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            in >> matrix[i][j];
        }
    }

    resetArray(supportColumn, row);

    int max = 0;
    int maxHere = 0;

    for(int i=0; i<column; i++){
        resetArray(supportColumn, row); 
        for(int j=i; j<column; j++){
            for (int k=0; k<row; k++)
            {
                supportColumn[k]+=matrix[k][j];
            }
            maxHere = 0;
            for(int k=0; k<row; k++){
                maxHere += supportColumn[k];
                if(maxHere < 0) maxHere = 0;
                if(maxHere > max) max = maxHere; 
            }
        }   
    }

    ofstream out("output.txt");
    out << max << "\n";

    return 0;
}