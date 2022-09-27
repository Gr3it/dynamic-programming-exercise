#include <fstream>
#include <iostream>
using namespace std;

int main(){
    int N;
    ifstream in("input.txt");

    in >> N;

    char input[N];
    int output[N];
    bool canBeLeftEdge[(N+1)/2];
    bool canBeRightEdge[(N+1)/2];
    int count = 0;

    for(int i=0; i<N; i++){
        in >> input[i];
    }

    int supL = -1;
    int supR = -1;
    for(int i=1; i<(N+1)/2; i++){
        if(supR != -1){
            canBeLeftEdge[i] = true;
            continue;
        }
        if(input[i*2-1] == 's'){
            supL = i;
            canBeLeftEdge[i] = true;
        }else {
            canBeLeftEdge[i] = false;
        }
        if(supL != -1 && input[i*2] == 'd'){
            bool toRemove = false;
            bool exit = false;
            for(int j=supL+1; j<(i-supL)/2 && !exit; j+=2){
                if(toRemove){
                    if(input[j]=='s' && input[j+1]=='s') toRemove = false;
                    if(input[j]=='d' && input[j+1]=='s') toRemove = false;
                } else{
                    if(input[j]=='s' && input[j+1]=='d') toRemove = true;
                    if(input[j]=='d') exit = true;
                }
            }
            if(!toRemove) supR = i;
        }
    }
    canBeLeftEdge[0] = true;

    supL = -1;
    supR = -1;
    for(int i=((N+1)/2)-1; i>=0; i--){        
        if(supR != -1){
            canBeRightEdge[i] = true;
            continue;
        }
        if(input[i*2+1] == 'd'){
            supL = i;
            canBeRightEdge[i] = true;
        }else {
            canBeRightEdge[i] = false;
        }
        if(supL != -1 && input[i*2] == 's'){
            bool toRemove = false;
            bool exit = false;
            for(int j=i+1; j<(supL-1)/2; j+=2){
                if(toRemove){
                    if(input[j]=='s' && input[j+1]=='s') toRemove = false;
                    if(input[j]=='d' && input[j+1]=='s') toRemove = false;
                } else{
                    if(input[j]=='s' && input[j+1]=='d') toRemove = true;
                    if(input[j]=='d') exit = true;
                }
            }
            if(!toRemove) supR = i;
        }
    }
    canBeRightEdge[(N-1)/2] = true;

    for(int i=0; i<(N+1)/2; i++){
        if(canBeRightEdge[i] == 1 && canBeLeftEdge[i] == 1) output[count++] = i*2;
    }

    ofstream out("output.txt");
    out << count << "\n";
    for(int i=0; i<count; i++){
        out << output[i] << " ";
    }


    return 0;
}