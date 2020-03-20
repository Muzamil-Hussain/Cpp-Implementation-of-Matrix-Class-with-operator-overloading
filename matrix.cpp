/*
 * matrix.cpp
 *
 *  Created on: Apr 8, 2018
 *      Author: muzamil
 */

#include "matrix.h"

Matrix::Matrix() {
	arr = NULL;
	rows = 0;
	cols = 0;
}
Matrix::Matrix(int row, int col) {
	rows = row;
	cols = col;
	arr = new double *[row];
	for (int i = 0; i < row; i++) {
		arr[i] = new double[col];
	}
}
Matrix::Matrix(const Matrix &matrix) {
	this->rows = matrix.rows;
	this->cols = matrix.cols;
	arr = new double *[rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new double[cols];
	}
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			this->arr[i][j] = matrix.arr[i][j];
		}
	}
}
int Matrix::getCols() const {
	return cols;
}

void Matrix::setCols(int cols) {
	this->cols = cols;
}

int Matrix::getRows() const {
	return rows;
}

void Matrix::setRows(int rows) {
	this->rows = rows;
}
double** Matrix::getArr() const {
	return arr;
}

void Matrix::setArr(double** arr) {
	this->arr = arr;
}
/*float & Matrix::operator()(int &i, int &j) {
	float store=0;
	if ((i >= 0 && i < rows) && (j >= 0 && j < cols)) {
		store=arr[i][j];
	}
	return store;
}
float & Matrix::operator()(int &i, int &j) const {
	float store=0;
	if ((i >= 0 && i < rows) && (j >= 0 && j < cols))
		store= arr[i][j];
	return store;
}*/
Matrix& Matrix::operator=(const Matrix & m) {
	if (&m == this) {
		return *this;
	}
	delete this->arr;

	this->rows = m.rows;
	this->cols = m.cols;
	arr = new double *[m.rows];
	for (int i = 0; i < m.rows; i++) {
		*(arr + i) = new double[m.cols];
	}

	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.cols; j++) {
			this->arr[i][j] = m.arr[i][j];
		}
	}
	return *this;
}
bool Matrix::operator==(const Matrix & m) {
	if (this->rows == m.rows && this->cols == m.cols) {
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->cols; j++) {
				if (this->arr[i][j] != m.arr[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	return false;
}
Matrix Matrix::operator+(const Matrix &matrix) {
	Matrix add(matrix.rows, matrix.cols);
	if (matrix.rows == this->rows && matrix.cols == this->cols) {
		for (int i = 0; i < add.rows; i++) {
			for (int j = 0; j < add.cols; j++) {
				add.arr[i][j] = this->arr[i][j] + matrix.arr[i][j];
			}
		}
	}
	return add;
}
Matrix Matrix::operator-(const Matrix &matrix) {
	Matrix add(matrix.rows, matrix.cols);
	if (matrix.rows == this->rows && matrix.cols == this->cols) {
		for (int i = 0; i < add.rows; i++) {
			for (int j = 0; j < add.cols; j++) {
				add.arr[i][j] = this->arr[i][j] - matrix.arr[i][j];
			}
		}
	}
	return add;
}
Matrix Matrix::operator*(const Matrix &matrix) {
	Matrix mul(this->rows, matrix.cols);
	if (this->cols == matrix.rows) {
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < matrix.cols; j++) {
				for (int k = 0; k < this->cols; k++) {
					mul.arr[i][j] = mul.arr[i][j]
							+ (this->arr[i][k] * matrix.arr[k][j]);
				}
			}
		}
	}
	return mul;
}
Matrix& Matrix::operator++(int) {
	Matrix temp(*this);
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			this->arr[i][j] = this->arr[i][j] + 1;
		}
	}
	return temp;
}
void Matrix::operator+=(const Matrix& matrix) {
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			this->arr[i][j] = this->arr[i][j] + matrix.arr[i][j];
		}
	}
}
void Matrix::operator-=(const Matrix& matrix) {
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			this->arr[i][j] = this->arr[i][j] - matrix.arr[i][j];
		}
	}
}
void Matrix::set(int i, int j, float val) {
	if ((i >= 0 && i < rows) && (j >= 0 && j < cols))
		arr[i][j] = val;}
Matrix::~Matrix() {
	
	for (int i = 0; i < this->rows; i++) {
		delete[] *(arr + i);
	}
	delete[] arr;
}
ostream& operator<<(ostream& input, const Matrix& matrix) {
	for (int i = 0; i < matrix.getRows(); i++) {
		for (int j = 0; j < matrix.getCols(); j++) {
			input << matrix.getArr()[i][j] << " ";
		}
		input << endl;
	}
	return input;
}
istream& operator>>(istream& ouput, Matrix& matrix) {
	cout << "Enter the values element wise: ";
	for (int i = 0; i < matrix.getRows(); i++) {
		cout << "Enter values for row " << i + 1;
		for (int j = 0; j < matrix.getCols(); j++) {
			ouput >> matrix.getArr()[i][j];
		}
	}
	return ouput;
}
