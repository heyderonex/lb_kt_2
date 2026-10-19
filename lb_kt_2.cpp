#include <iostream>
#include <limits>
#include <windows.h>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int N, i;
const int W1 = 6, W2 = 12, W3 = 12, W4 = 12;
double A, B, h, x_i;

double F(double x);
double G(double x);
string repeat(int n);    



int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "Введите A и B:" << endl;
    cin >> A >> B;
    cout << "A = " << A << ", B = " << B << endl;
    if (A > B) {
        cout << "Вы ввели некорректные значения"; // проверка корректности ввода
        return 1;
    }
    if (A == B)  {
        cout << F(A) << endl; // вариант при равенстве
        return 2;
    }
    cout << "Введите N:" << endl; // стандартный вариант
    cin >> N;
    cout << "Вы ввели N = " << N << endl;
    h = (B - A)/N; // шаг икса

    // шапка таблицы
    cout << "┌" << repeat(W1) << "┬" << repeat(W2) << "┬" << repeat(W3) << "┬" << repeat(W4) << "┐" << endl;
    cout << "│" << setw(W1) << "i" << "│" << setw(W2) << "x" << "│" << setw(W3) << "F(x)" << "│" << setw(W4) << "G(x)" << "│" << endl;
    cout << "├" << repeat(W1) << "┼" << repeat(W2) << "┼" << repeat(W3) << "┼" << repeat(W4) << "┤" << endl;

    // строки таблицы
    cout << fixed << setprecision(4);
    for (i = 0; i <= N; i++) {
        x_i = A + i * h;
        cout << "│" << setw(W1) << i << "│" << setw(W2) << x_i << "│" << setw(W3) << F(x_i) << "│" << setw(W4) << G(x_i) << "│" << endl;
    }

    // низ таблицы
    cout << "└" << repeat(W1) << "┴" << repeat(W2) << "┴" << repeat(W3) << "┴" << repeat(W4) << "┘" << endl;
    return 0;
}

double F(double x) {
    return pow((x*x + 4), 0.5);
}

double G(double x) {
    return 4 * exp(abs(x)) - 1;
}

string repeat(int n) {
    string s = "";
    for (int k = 0; k < n; k++){
        s = s + "─";
    }
    return s;
}