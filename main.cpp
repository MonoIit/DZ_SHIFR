#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include "LCS.h"
#include "homework.h"
#include "Roshchektaev_AA-22-08_DZ.h"
#include "rusin.h"
#include "max_code.h"


using namespace std;

void Max(vector<int> matrixSizes)
{
    if (matrixSizes.size() < 2)
    {
        cerr << "Недостаточно данных для умножения матриц" << endl;
        return;
    }

    // Создаем таблицы для хранения промежуточных результатов
    int n = matrixSizes.size() - 1;
    vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));

    matrixChainOrder(matrixSizes, m, s);
    cout << "Minimum number of multiplications: " << m[1][n] << endl;

    cout << "Naive method: " << simpleMatrixChainMultiplication(matrixSizes) << endl;
}

void start(int W, const vector<int> &wt, const vector<int> &val, int n)
{
    int ans2;
    auto start_rec2 = chrono::high_resolution_clock::now();
    ans2 = knapSack_classic(W, wt, val, n);
    auto end_rec2 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_rec2 = end_rec2 - start_rec2;
    cout << "Time duration (DP): " << elapsed_rec2.count() << endl;
    cout << "Answer: " << ans2 << endl;

    int ans1;
    auto start_rec1 = chrono::high_resolution_clock::now();
    ans1 = knapSack_naive(W, wt, val, n);
    auto end_rec1 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_rec1 = end_rec1 - start_rec1;
    cout << "Time duration (recursive): " << elapsed_rec1.count() << endl;
    cout << "Answer: " << ans1 << endl;
}

void Danya()
{
    ifstream f("knapsack_tests.txt");
    if (!f)
    {
        cerr << "Ошибка открытия файла на загрузку " << endl;
        return;
    }
    string line1, line2;
    int n;
    int W;
    cout << "BackPack" << endl;
    while (f >> n)
    {
        f >> ws;
        vector<int> profit;
        vector<int> weight;
        getline(f, line1);
        istringstream isss(line1);
        int num;
        while (isss >> num)
        {
            weight.push_back(num);
        }
        getline(f, line2);
        istringstream iss(line2);

        while (iss >> num)
        {
            profit.push_back(num);
        }
        f >> W;
        f >> ws;
        start(W, weight, profit, n);
    }
    f.close();
    
}



void Sanya(int &N)
{
    cout << "Fibonacci" << endl;
    int ans2;
    auto start_rec2 = chrono::high_resolution_clock::now();
    ans2 = dinamic_prog(N);
    auto end_rec2 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_rec2 = end_rec2 - start_rec2;
    cout << "Time duration (DP): " << elapsed_rec2.count() << endl;
    cout << "Answer: " << ans2 << endl;

    int ans1;
    auto start_rec1 = chrono::high_resolution_clock::now();
    ans1 = rekursia(N);
    auto end_rec1 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_rec1 = end_rec1 - start_rec1;
    cout << "Time duration (recursive): " << elapsed_rec1.count() << endl;
    cout << "Answer: " << ans1 << endl;
}

void Katya(const int& N)
{
    cout << "Grasshopper" << endl;
    int ans2;
    auto start_rec2 = chrono::high_resolution_clock::now();
    ans2 = countWays(N);
    auto end_rec2 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_rec2 = end_rec2 - start_rec2;
    cout << "Time duration (DP): " << elapsed_rec2.count() << endl;
    cout << "Answer: " << ans2 << endl;

    int ans1;
    auto start_rec1 = chrono::high_resolution_clock::now();
    ans1 = countWaysRecursive(N);
    auto end_rec1 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_rec1 = end_rec1 - start_rec1;
    cout << "Time duration (recursive): " << elapsed_rec1.count() << endl;
    cout << "Answer: " << ans1 << endl;
}

void Kep(string& s1, string& s2)
{
    string ans1;
    cout << "LCS:" << endl;
    auto start_rec1 = chrono::high_resolution_clock::now();
    ans1 = lcs(s1, s2);
    auto end_rec1 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_rec1 = end_rec1 - start_rec1;
    cout << "Time duration: " << elapsed_rec1.count() << endl;
    cout << "Answer: " << ans1 << endl;
    string ans2;
    cout << "Naive LCS:" << endl;
    auto start_rec2 = chrono::high_resolution_clock::now();
    ans2 = naive(s1, s2);
    auto end_rec2 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_rec2 = end_rec2 - start_rec2;
    cout << "Time duration: " << elapsed_rec2.count() << endl;
    cout << "Answer: " << ans2 << endl;
}

/*void Danya(const int& N)
{
    int ans1;
    cout << "Backpack" << endl;
    auto start_rec = chrono::high_resolution_clock::now();
    ans1 = knapSack_naive();
    auto end_rec = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_rec = end_rec - start_rec;
    cout << "Time duration (recursive): " << elapsed_rec.count() << endl;
    cout << "Answer: " << ans1 << endl;

    int ans2;
    auto start_rec = chrono::high_resolution_clock::now();
    ans2 = knapSack_classic();
    auto end_rec = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_rec = end_rec - start_rec;
    cout << "Time duration (DP): " << elapsed_rec.count() << endl;
    cout << "Answer: " << ans2 << endl;
}*/



int main()
{
    //string s1 = "eabdfeghjedfegeabdfeghjehjeabdfeghabdfeghjeabdfeghjeabdfeghjeabdfeghjabdfeghjeabdfeghjeabdfeghjeabd";
    //string s2 = "bcdjfefebcdjfefecdjfefebcdjfefebcdjfefebbcdjfefebcdjfefebcdjfefebcdjfefebcdjfefebcdjfefebcdjfefebcdjfefe";
    //string s1 = "eabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefe";
    //string s2 = "eabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefeeabdfeghjfefe";
    string s1 = "feghjfefefe";
    string s2 = "bcdfeghjfef";
    //string s1 = "eabdfeeabdfeghjfefeeabdfeghjfefeeabdfeeabdfeghjfefeea";
    //string s2 = "bcdfeghjfefeeghjfefeeabdfeghjfefeabdfeeabdfeghjfefeea";
    cout << "Kep" << endl;
    Kep(s1, s2);
    cout << endl;

    int N = 30;
    cout << "Sanya" << endl;
    Sanya(N);
    cout << endl;

    int M = 30;
    cout << "Katya" << endl;
    Katya(M);
    cout << endl;

    vector<int> sizes = {75, 83, 83, 61, 83, 82, 88, 95, 50, 75, 64, 73, 90, 92, 94, 100, 61, 100, 66, 95, 97, 92, 62, 61, 58, 53, 90, 76, 60, 63, 75, 96, 65, 100, 97, 88, 99, 75, 97, 79, 71, 68, 60, 63, 72, 77, 83, 82, 95, 64, 99, 86, 94, 56, 100, 88, 83, 94, 81, 100, 79, 54, 75, 60, 71, 99, 90, 86, 74, 97, 70, 65, 72, 51, 57, 100, 91, 92, 56, 75, 63, 97, 70, 89, 92, 78, 83, 98, 58, 85, 100, 99, 65, 84, 84, 94, 72, 63, 72, 83, 99, 92, 75, 94, 72, 71, 68, 96, 69, 56, 59, 99, 99, 72, 85, 59, 62, 63, 53, 66, 78, 68, 95, 86, 92, 53, 74, 89, 94, 66, 64, 91, 88, 79, 67, 54, 83, 72, 78, 63, 72, 93, 69, 65, 63, 50, 88, 88, 98, 58, 99, 76, 50, 53, 61, 58, 55, 56, 97, 63, 86, 62, 63, 91, 100, 72, 50, 63, 87, 94, 86, 55, 59, 56, 66, 95, 93, 51, 80, 56, 93, 55, 94, 57, 51, 52, 89, 54, 79, 51, 67, 61, 53, 91, 69, 93, 77, 56, 70, 83, 60, 62, 57, 62, 86, 73, 79, 64, 58, 83, 79, 59, 91, 53, 68, 73, 57, 87, 86, 73, 71, 88, 69, 100, 92, 62, 62, 69, 62, 90, 91, 99, 70, 96, 56, 55, 92, 73, 62, 96, 65, 98, 59, 95, 53, 66, 83, 76, 75, 78, 83, 55, 65, 87, 58, 98, 76, 73, 59, 75, 66, 95, 69, 51, 83, 85, 95, 81, 58, 81, 91, 62, 86, 61, 90, 51, 51, 58, 50, 76, 84, 50, 69, 92, 75, 83, 77, 98, 57, 67, 92, 66, 79, 73, 69, 69, 63, 96, 61, 79, 81, 57, 81, 51, 97, 91, 65, 89, 66, 63, 73, 76, 98, 74, 64, 56, 83, 88, 63, 74, 55, 57, 85, 71, 88, 52, 56, 61, 52, 50, 85, 67, 57, 75, 100, 57, 56, 61, 96, 81, 89, 56, 99, 54, 78, 64, 59, 51, 72, 82, 52, 93, 66, 83, 75, 80, 67, 64, 88, 71, 66, 61, 60, 95, 87, 79, 55, 56, 67, 66, 98, 91, 90, 82, 53, 85, 77, 73, 68, 92, 75, 66, 76, 69, 87, 75, 60, 58, 68, 79, 73, 91, 87, 92, 80, 96, 72, 97, 65, 52, 76, 63, 95, 99, 52, 61, 58, 64, 61, 84, 65, 69, 95, 62, 55, 90, 88, 57, 56, 57, 100, 51, 77, 79, 91, 92, 97, 98, 84, 96, 88, 96, 61, 100, 90, 68, 52, 57, 93, 77, 77, 73, 58, 65, 86, 50, 60, 66, 73, 59, 70, 70, 84, 95, 95, 91, 81, 81, 51, 88, 90, 50, 67, 59, 93, 69, 60, 80, 81, 85, 87, 84, 94, 78, 93, 67, 73, 93, 65, 64, 85, 91, 84, 54, 91, 89, 60, 71, 56, 86, 76, 54, 69, 62, 82, 95, 91, 75, 54, 60, 77, 61, 53, 91, 67, 65, 78, 90, 62, 70, 100, 51, 59, 53, 59, 85, 84, 57, 94, 77, 88, 92, 97, 53, 99, 71, 84, 77, 70, 68, 97, 95, 74, 69, 54, 61, 78, 69, 57, 100, 56, 59, 80, 85, 53, 53, 92, 86, 56, 56, 83, 95, 67, 71, 57, 80, 82, 51, 91, 76, 53, 79, 87, 66, 54, 64, 98, 50, 75, 66, 76, 98, 95, 77, 95, 58, 87, 62, 85, 92, 80, 90, 51, 52, 67, 99, 88, 95, 78, 94, 93, 52, 54, 90, 51, 93, 64, 62, 84, 99, 69, 75, 61, 74, 93, 71, 99, 96, 94, 51, 80, 51, 73, 58, 67, 60, 78, 53, 80, 67, 63, 67, 89, 50, 97, 81, 86, 55, 67, 64, 53, 73, 71, 100, 66, 69, 77, 94, 70, 80, 85, 88, 69, 77, 83, 87, 64, 85, 61, 99, 63, 60, 80, 98, 69, 96, 51, 79, 50, 98, 81, 97, 84, 80, 61, 85, 86, 69, 62, 63, 92, 58, 54, 60, 68, 70, 86, 80, 62, 87, 75, 93, 93, 100, 79, 72, 54, 76, 99, 75, 91, 82, 84, 88, 50, 62, 55, 75, 95, 53, 80, 81, 79, 96, 86, 59, 81, 55, 69, 65, 100, 99, 58, 61, 57, 93, 55, 54, 79, 78, 60, 83, 57, 62, 99, 76, 56, 98, 75, 85, 85, 57, 85, 92, 78, 85, 78, 91, 67, 68, 82, 68, 76, 84, 86, 91, 75, 94, 73, 82, 64, 68, 87, 83, 67, 75, 95, 87, 66, 64, 93, 69, 95, 76, 91, 89, 97, 97, 59, 58, 65, 98, 84, 93, 90, 93, 95, 66, 66, 90, 51, 83, 66, 98, 74, 61, 55, 73, 77, 50, 73, 62, 70, 51, 63, 73, 57, 58, 89, 73, 88, 54, 74, 57, 65, 77, 97, 71, 71, 85, 87, 79, 95, 83, 57, 65, 86, 100, 87, 58, 70, 94, 89, 58, 55, 98, 78, 94, 98, 88, 52, 83, 92, 58, 98, 90, 76, 52, 67, 80, 94, 53, 55, 55, 87, 82, 50, 68, 88, 68, 95, 59, 75, 68, 65, 94, 78, 87, 94, 84, 54, 85, 100, 100, 78, 84, 60, 81, 65, 92, 77, 77, 52, 75, 62, 100, 90, 66, 85, 50, 67, 97, 77, 62, 93, 50, 58, 100, 65, 95, 86, 82, 85, 91, 82, 95, 84, 90, 99, 63, 88, 89, 97, 58, 89, 69, 83, 99, 83, 99, 53, 80, 91, 94, 92, 87, 92, 78, 87, 91, 93, 53, 97, 89, 59, 61, 98, 50, 75, 85, 67, 90, 93, 54, 55, 58, 63, 100, 80, 55, 83, 58, 52, 81, 50, 58, 50, 88, 55, 92, 66, 56, 86, 83, 58, 50, 70, 78, 72, 67, 62, 82, 55, 50, 82, 82, 86, 67, 63, 92, 51, 66, 89, 96, 87, 100, 100, 90, 56, 75, 79, 69, 93, 84, 59, 58, 90, 92, 81, 70, 96, 69, 77, 71, 86, 76, 92, 91, 83, 65};
    Max(sizes);
    cout << endl;

    Danya();
}