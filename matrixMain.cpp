#include "matrix.h"
int main()
{
	Matrix m1(3,3);
	for (int i=0;i<3;i++)
		{
			for (int j=0;j<3;j++)
			{
				m1.set(i,j,2);
			}
		}
	cout<<"Displaying matrix m1: \n"<<m1;

	Matrix m2(m1);
	cout<<"Displaying matrix m2: \n"<<m2;

	Matrix result;
	result=m1+m2;
	cout<<"Displaying sum of matrix m1 and m2: \n"<<result;

	Matrix result1;
	result1=m1-m2;
	cout<<"Displaying difference of matrix m1 and m2: \n"<<result1;

	Matrix result2;
	result2=m1*m2;
	cout<<"Displaying multiplication of two matrices m1 and m2: \n"<<result2;

	result2++;
	cout<<"Displaying result2 after post increment: \n"<<result2;

	m1+=m2;
	cout<<"Displaying m1 after incrementing m2 in it: \n"<<m1;

	m1-=m2;
	cout<<"Displaying m1 after decrementing m2 in it: \n"<<m1; //back to original values




	Matrix m3(4,4);
	cin>>m3;
	cout<<"Displaying matrix m3 after taking input: \n"<<m3;

	m3=m2;
	cout<<"Displaying matrix m3 after assigning m2 to it: \n"<<m3;

}
