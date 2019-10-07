#include <iostream>
#include <string>
#define n  4
using namespace std;

int fastest_way(int a[2][n],int e[2], int t[2][n],int x[2]){
    int f1[n], f2[n];
    
    f1[0] = e[0]+ a[0][0];
    f2[0] = e[1]+ a[1][1];
    string s1[n]="e0,a00",s2[n]="e1, a11";
    
    
    for(int j=1;j<n;j++){
        if(f1[j-1]+a[0][j]<=f2[j-1]+t[1][j-1]+a[0][j]){
            f1[j] = f1[j-1]+a[0][j];
            s1[j]=s1[j-1]+", a0"+std::to_string(j);
        }
        else{
            f1[j] = f2[j-1]+t[1][j-1]+a[0][j];
            s1[j]=s1[j-1]+", a0"+std::to_string(j);
        }
        
        if(f2[j-1]+a[1][j]<=f1[j-1]+t[0][j-1]+a[1][j]){
            f2[j] = f2[j-1]+a[1][j];
            s2[j]=s2[j-1]+", a1"+std::to_string(j);
        }
        else{
            f2[j] = f1[j-1]+t[0][j-1]+a[1][j];
            s2[j]=s2[j-1]+", a1"+std::to_string(j);
        }
    }
    if(f1[n]+x[0]<= f2[n]+x[1]){
        s1[n]=s1[n-1]+", x0";
        cout<<"posiciones"<<endl;
        for(int i=0;i<n;i++){
            cout<<s1[i]<<" ";
        }
        cout<<endl<<"tiempo"<<endl;
        return f1[n]+x[0];
    }
    else{
        s2[n]=s2[n-1]+", x1";
        cout<<"posiciones"<<endl;
        for(int i=0;i<n;i++){
            cout<<s1[i]<<" ";
        }
        cout<<endl<<"tiempo"<<endl;
        return f2[n]+x[1];
    }
    
}

int main()
{
    int A[2][n] ={{1,2,3,4},{4,3,2,1}};
    int T[2][n] ={{5,6,7,8},{8,7,6,5}};
    int E[2] ={9,10};
    int X[2] = {10,9};
    cout<<fastest_way(A,E,T,X);

}
