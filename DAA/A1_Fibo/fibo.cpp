#include <bits/stdc++.h>
using namespace std;

void disp(const vector<int> &fibo) {
    cout<<"Fibonacci sequence is : ";
    for(const int &term: fibo) {
        cout<<term<<" ";
    }
    cout<<"\n";
}

void nonrec(int n) {
    if(n <=0 ){
        cout<<"Enter valid positive number\n";
        return;
    }

    vector<int> fibo(n);
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i=2; i<n; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    disp(fibo);
}

int fib(int n) {
    if(n <= 1) {
        return n;
    }
    return fib(n-1) + fib(n-2);
}

void rec(int n) {
    if(n <=0 ){
        cout<<"Enter valid positive number\n";
        return;
    }
    vector<int> fibo(n);
    for(int i=0; i<n; i++) {
        fibo[i] = fib(i);
    }
    disp(fibo);
}


int main() {
    int n, option;

    do {
        cout<<"- - - - - - MENU - - - - - -\n";
        cout<<"1. Using Non recursive approach.\n";
        cout<<"2. Using recursive approach.\n";
        cout<<"3. Exit.\n";
        cout<<"Enter the option : ";

        while(true) {
            if(!(cin>>option) || (option<1 || option>3)) {
                cout<<"Invalid Option!!\nEnter valid option (1-3) : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }

        if(option != 3) {
            cout<<"Enter number up to which you want to print fibonacci series : ";
            while(true) {
                if(!(cin>>n) || (n<=0)) {
                    cout<<"Invalid Input!!\nEnter valid positive number :";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    break;
                }
            }
        }

        switch(option) {
            case 1:
                nonrec(n);
                break;
            case 2:
                rec(n);
                break;
            case 3:
                cout<<"\nExiting...\n";
                return 0;
            case 4:
                cout<<"Invalid option";
                break;
        }
    } while(true);
    return 0;
}