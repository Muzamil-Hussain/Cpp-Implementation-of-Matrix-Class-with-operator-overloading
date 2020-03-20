/*
 * matrix.h
 *
 *  Created on: Apr 8, 2018
 *      Author: muzamil
 */

#ifndef MATRIX_H_
#define MATRIX_H_
#include <iostream>
using namespace std;
class Matrix {
private:
	double **arr;
	int rows;
	int cols;
public:
	Matrix();// a default constructor
	Matrix(int,int);// a parametrized constructor
	Matrix(const Matrix &);
	int getCols() const;
	void setCols(int cols);
	int getRows() const;
	void setRows(int rows);
	double** getArr() const;
	void setArr(double** arr);
	float &operator()(int &i, int &j);
    float &operator()(int &i, int &j)const;
    Matrix& operator=(const Matrix &);
    bool operator==(const Matrix &);
    Matrix operator+(const Matrix &);
    Matrix operator-(const Matrix &);
    Matrix operator*(const Matrix &);
    Matrix& operator++(int);
    void operator+=(const Matrix&);
    void operator-=(const Matrix&);
    void set(int i, int j, float val);
	~Matrix();

};
ostream& operator<<(ostream& input, const Matrix&);
istream& operator>>(istream& ouput, Matrix&);
#endif /* MATRIX_H_ */
