
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;


int max(int a, int b) { return (a > b) ? a : b; } 

int knapSack_classic(int W, const vector<int> &weights, const vector<int> &val, int n) 
{ 
	int i, w; 
	vector<vector<int> > K(n + 1, vector<int>(W + 1)); 

	for (i = 0; i <= n; i++) { 
		for (w = 0; w <= W; w++) { 
			if (i == 0 || w == 0) 
				K[i][w] = 0; 
			else if (weights[i - 1] <= w) 
				K[i][w] = max(val[i - 1] 
								+ K[i - 1][w - weights[i - 1]], 
							K[i - 1][w]); 
			else
				K[i][w] = K[i - 1][w]; 
		} 
	} 
	return K[n][W]; 
} 
int knapSack_naive(int W, const vector<int> &weights, const vector<int> &val, int n) 
{ 
  
 
    if (n == 0 || W == 0) 
        return 0; 
  
    if (weights[n - 1] > W) 
        return knapSack_naive(W, weights, val, n - 1); 

    else
        return max(val[n - 1] + knapSack_naive(W - weights[n - 1], weights, val, n - 1), 
        knapSack_naive(W, weights, val, n - 1)); 
} 


int check_results() {
    cout<<"Введите 0 для проверки наивного решения и 1 для проверки динамического решения:"<<endl;
    int mode;
    cin>>mode;
    ifstream f("knapsack_tests.txt");
    if (!f) {
        cerr << "Ошибка открытия файла на загрузку " << endl;
        return 1;
    }

    string line1,line2;
    int n;
    int W;
    while (f>>n) {
        f>>ws;
        vector<int> profit;
        vector<int> weight;
        getline(f, line1);
        istringstream isss(line1);
        int num;
        while (isss >> num) {
            weight.push_back(num);
        }
        getline(f, line2);
        istringstream iss(line2);
        
        while (iss >> num) {
            profit.push_back(num);
        }
        f>>W;
        f>>ws;
        cout<<endl;
        cout<<"weights: "<<line1<<endl;
        cout<<"values:  "<<line2<<endl;
        cout<<"max_weight:"<<W<<endl;
        if (mode){
        cout<<"Backpack max value by dinamic method:"<<knapSack_classic(W, weight, profit, n)<<endl;
        }
        else{
            cout<<"Backpack max value by naive method:"<<knapSack_naive(W, weight, profit, n)<<endl;
        }
    }

    return 0;
}



