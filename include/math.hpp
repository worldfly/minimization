#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cassert>

// Объявление типов:
typedef long double ld;
typedef std::vector<ld> Vector;
typedef std::vector<Vector> Matrix;
typedef ld(*Function)(const Vector & x);
typedef std::pair<Vector, int>(*Method)(Function, Vector, int);

// Точность сравнения вещественных чисел:
const ld COMPARE_EPS = 0.0000000000000001L;

// Математические константы (M_E, M_PI, M_PI_2) в файле реализации

// Операторы вывода в поток:
std::ostream& operator<<(std::ostream& os, const Vector& v);
std::ostream& operator<<(std::ostream& os, const Matrix& m);

// Операция умножения вектора на число и различные ее вариации:
Vector& operator*=(Vector& v, const ld value);
Vector operator*(const ld value, Vector v);
Vector operator*(Vector v, const ld value);

// Унарный минус для вектора:
Vector operator-(Vector v);

// Сложение и вычитание векторов:
Vector& operator+=(Vector & v1, const Vector& v2);
Vector& operator-=(Vector & v1, const Vector& v2);
Vector operator+(Vector v1, const Vector& v2);
Vector operator-(Vector v1, const Vector& v2);

// Скалярное произведение векторов:
ld dot(const Vector& v1, const Vector& v2);

// Норма вектора:
ld norm(const Vector& v);

// Умножение матрицы на вектор:
Vector operator*(const Matrix& m, const Vector& v);

// Проверка равенства вектора нулю
bool is_zero(const Vector& v);

// Базисный вектор в пространстве R^n:
// на i-ом месте 1, на всех остальных нули
Vector id_vect(int size, int i);

// Явное взятие градиента от функции:
Vector grad(Function f, const Vector& point, const ld h = 1e-4);

// Явное вычисление матрицы Гессе (слишком затратно, годится только для проверки результатов)
// в точке x с шагом h и погрешностью O(h)
Matrix hess(Function f, const Vector& x, const ld h = 1e-4);