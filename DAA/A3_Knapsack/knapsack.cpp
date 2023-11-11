#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { 
    return (a > b) ? a : b; 
}

int knapsack(int W, int wt[], int val[], int n) {
    vector<vector<int>> K(n+1, vector<int>(W+1));
    
    for(int i=0; i<=n; i++) {
        for(int w=0; w<=W; w++) {
            if(i == 0 || w == 0) {
                K[i][w] = 0;
            }
            else if(wt[i-1] <= w) {
                K[i][w] = max(val[i-1] + K[i-1][w - wt[i-1]], K[i-1][w]);
            }
            else {
                K[i][w] = K[i-1][w];
            }
        }
    }

    return K[n][W];
}

int main() {
    int n;
    cout<<"Enter number of items : ";
    while(!(cin>>n) || n<=0) {
        cout<<"Enter valid positive number here : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int weight[n], profit[n];

    for(int i=0; i<n; i++) {
        string input;
        int itemWeight, itemProfit;
        cout<<"Enter weight for item "<<i+1<<" : ";
        while(true) {
            cin>>input;
            if(isdigit(input[0])) {
                itemWeight = stoi(input);
                weight[i] = itemWeight;
                break;
            } else {
                cout<<"Enter valid input ";
            }
        }

        cout<<"Enter profit for item "<<i+1<<" : ";
        while(true) {
            cin>>input;
            if(isdigit(input[0])) {
                itemProfit = stoi(input);
                profit[i] = itemProfit;
                break;
            } else {
                cout<<"Enter valid input";
            }
        }
    }

    int W;
    cout<<"Enter the knapsack weight : ";
    while(!(cin>>W) || W<=0) {
        cout<<"Enter valid number ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout<<"Maximum profit earned is : "<<knapsack(W, weight, profit, n);
    return 0;
}