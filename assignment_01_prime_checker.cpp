#include <iostream>
using namespace std;
int main () {
    cout<<"ENTER A NUMBER"<<endl;
    int n;
    cin>>n;
    if(n==2 || n==3 || n==5 || n==7 || n==11) {
        cout<<"the number is prime"<<endl;
    } else {
        cout<<"the number is not prime"<<endl;
    }
    return 0;

}
