#include <iostream>
#include <string>
#include <conio.h>
#include <math.h>
using namespace std;

int Quadractic()
{
float a, b, c, x1, x2, discriminant, realPart, imaginaryPart;
cout << "Enter coefficients a, b and c: ";
cin >> a >> b >> c;
discriminant = b*b - 4*a*c;
if (discriminant > 0)
{
x1 = (-b + sqrt(discriminant)) / (2*a);
x2 = (-b - sqrt(discriminant)) / (2*a);
cout << "Roots are real and different." << endl;
cout << "x1 = " << x1 << endl;
cout << "x2 = " << x2 << endl;
}
else if (discriminant == 0)
{
cout << "Roots are real and same." << endl;
x1 = -b/(2*a);
cout << "x1 = x2 =" << x1 << endl;
}
else

{
realPart = -b/(2*a);
imaginaryPart =sqrt(-discriminant)/(2*a);
cout << "Roots are complex and different."<< endl;
cout << "x1 = " << realPart << "+"<< imaginaryPart << "i" <<
endl;
cout << "x2 = " << realPart << "-" << imaginaryPart << "i" <<
endl;
}
return 0;
}

int determinant( int matrix[10][10], int n)
{
int det = 0;
int submatrix[10][10];
if (n == 2)
return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] *
matrix[0][1]));
else

{
for (int x = 0; x < n; x++) {
int subi = 0;
for (int i = 1; i < n; i++) {
int subj = 0;

for (int j = 0; j < n; j++) {
if (j == x)
continue;
submatrix[subi][subj] = matrix[i][j];
subj++;
}
subi++;
}
det = det + (pow(-1, x) * matrix[0][x] * determinant(
submatrix, n - 1 ));
}
}
return det;
}

int determinantmain() {
int n, i, j;
int matrix[10][10];
cout << "Enter the size of the matrix:\n";
cin >> n;
cout << "Enter the elements of the matrix:\n";
for (i = 0; i < n; i++)
for (j = 0; j < n; j++)
cin >> matrix[i][j];
cout<<"The entered matrix is:"<<endl;
for (i = 0; i < n; i++)
{
for (j = 0; j < n; j++)
cout << matrix[i][j] <<" ";
cout<<endl;
}
cout<<"Determinant of the matrix is "<< determinant(matrix, n);

return 0;
}

int INVERSE()
{
int mat[3][3], i, j;
float determinant = 0;
cout<<"Enter elements of matrix row wise:\n";
for(i = 0; i < 3; i++)
for(j = 0; j < 3; j++)

cin>>mat[i][j];
printf("\nGiven matrix is:");
for(i = 0; i < 3; i++){
cout<<"\n";
for(j = 0; j < 3; j++)
cout<<mat[i][j]<<"\t";

}
//finding determinant
for(i = 0; i < 3; i++)
determinant = determinant + (mat[0][i] *

(mat[1][(i+1)%3] * mat[2][(i+2)%3] - mat[1][(i+2)%3] *
mat[2][(i+1)%3]));
cout<<"\n\ndeterminant: "<<determinant;
cout<<"\n\nInverse of matrix is: \n";
for(i = 0; i < 3; i++){
for(j = 0; j < 3; j++)
cout<<((mat[(j+1)%3][(i+1)%3] *
mat[(j+2)%3][(i+2)%3]) - (mat[(j+1)%3][(i+2)%3] *
mat[(j+2)%3][(i+1)%3]))/ determinant<<"\t";

cout<<"\n";
}
return 0;
}

int Simultaneously()
{
float a1, b1, c1, a2, b2, c2;

cout << "Enter 3 values for coefficients of first equation : ";
cin >> a1 >> b1 >> c1;
cout << "Enter 3 values for coefficients of second equation : ";
cin >> a2 >> b2 >> c2;
float x = (c1*b2 - c2*b1) /(a1*b2 - b1*a2);
float y = (c1*a2 - c2*a1) /(b1*a2 - b2*a1);
cout << "x = " << x << endl;
cout << "y = " << y << endl;
}

int main()
{
int ProfessorHulk;

cout<<"Welcome to ProfessorHulk's' Scientific Calculator
"<<endl;
cout<<"Press '1' for Quadractic Equation: "<<endl;
cout<<"Press '2' for Determinant of Matrix: "<<endl;
cout<<"Press '3' for Inverse of Matrix: "<<endl;
cout<<"Press '4' for Simultaneous Equation: "<<endl;
cin>>ProfessorHulk;
switch(ProfessorHulk)
{
case 1: //Quadractic Equation
Quadractic();
break;
case 2: //Determinant of Matrix

determinantmain();
break;
case 3: //Inverse of Matrix

INVERSE();
break;
case 4: //Simultaneously Equation
Simultaneously();
break;
default:
cout<<"Wrong Input"<<endl;

}
getch();
}
