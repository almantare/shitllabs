#include <bits/stdc++.h>
#include <thread>
using namespace std;

template<typename T>
class Matrix {
private:
    int N, M;
    vector<vector<T>> matrix;
public:
    Matrix(int n, int m, vector<T> &v);
    Matrix(int n, int m, string &s);
    Matrix(int n, int m, T defaultValue = 0);
    Matrix(string &s);
    void print_matrix();
    void print_to_file(string &s);
    ~Matrix(){};
};

template<typename T>
Matrix<T>::Matrix(int n, int m, vector<T> &v) {
    if (n * m != v.size()) {
        cout << "Enter the correct params!";
        exit(-1);
    }
    N = n;
    M = m;
    for (int i = 0; i < N; i++) {
        matrix.resize(matrix.size() + 1);
        for (int j = 0; j < M; j++) {
            matrix[i].push_back(v[i * N + j]);
        }
    }
}



template<typename T>
void Matrix<T>::print_matrix() {
    for (int i = 0; i <= N - 1; i++) {
        for (int j = 0; j <= M - 1; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

template<typename t>
void Matrix<t>::print_to_file(string &s) {
    ofstream out(s);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            out << matrix[i][j] << ' ';
        }
        out << endl;
    }
}

template<typename T>
Matrix<T>::Matrix(int n, int m, string &s) {
    N = n;
    M = m;
    T tmp;
    ifstream input(s);
    for (int i = 0; i < N; i++) {
        matrix.resize(matrix.size() + 1);
        for (int j = 0; j < M; j++) {
            input >> tmp;
            cout << tmp << " ";
            matrix[i].push_back(tmp);
        }
    }
    input.close();
}

template<typename T>
Matrix<T>::Matrix(string &s) {
    ifstream input(s);
    int n, m;
    input >> n;
    input >> m;
    N = n;
    M = m;
    T tmp;
    for (int i = 0; i < N; i++) {
        matrix.resize(matrix.size() + 1);
        for (int j = 0; j < M; j++) {
            input >> tmp;
            cout << tmp << " ";
            matrix[i].push_back(tmp);
        }
    }
    input.close();

}

template<typename T>
Matrix<T>::Matrix(int n, int m, T defaultValue) {
    N = n;
    M = m;
    for (int i = 0; i < N; i++) {
        matrix.resize(matrix.size() + 1);
        for (int j = 0; j < M; j++) {
            matrix[i].push_back(defaultValue);
        }
    }
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    string input = "C://Users//almantare//CLionProjects//laba8//input.txt";
    string output = "C://Users//almantare//CLionProjects//laba8//output.txt";
    Matrix<double> test(4, 4, 5.24);
    test.print_matrix();

    return 0;
}
//void threadFunction(int i, double d, const std::string s)
//{
//    std::cout << i << ", " << d << ", " << s << std::endl;
//}
//
//int main()
//{
//    std::thread thr (threadFunction, 1, 2.34, "example");
//    thr.join();
//    return 0;
//}

/*

конструктор row col way
конструктор way
закатка data  way
конструктор с чистогана

Перегрузить операторы умножения матриц, а также матриц и скаляров
Перегрузить операторы сложения/вычитания матриц.
Перегрузить оператор логического отрицания для вычисления обратной матрицы (если обратная матрица не может быть вычислена следует запускать исключение)

Перегрузить операторы проверки на равенство для матриц.

Перегрузить операторы проверки на равенство для матриц и целых значений 0, а также 1, проверяющих что
матрица нулевая или единичная.

Перегрузить оператор присваивания.

Добавить статические методы создания нулевых и единичных матриц указанного размера.


 конструкторы:
 1. принимает два инта и вектор
 2. принимает два инта и ебашит элементами по умолчанию
 3. принимает два инта и стринг
 4. принимает из файла и размеры и дату

*/