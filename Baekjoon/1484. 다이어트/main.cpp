#include <iostream>
#include <math.h>

using namespace std;
int G;
int curWeight=2;
int memWeight=1;

long long getG(){
    return pow(curWeight,2) - pow(memWeight,2);
}
int main() {
    cin>>G;
    
    bool checkPrint=false;
    while(memWeight<curWeight){
        if(getG()>G){
            memWeight++;
        }
        else if(getG()<G){
            curWeight++;
        }else{
            cout<<curWeight<<endl;
            checkPrint = true;
            curWeight++;
        }
    }
    if(!checkPrint)
        cout<<-1<<endl;
    return 0;
}
