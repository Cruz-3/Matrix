#include <iostream>
#include <iomanip>

using namespace std;
struct Matrix{
    double a1 = 0;
    double a2 = 0;
    double b1 = 0;
    double b2 = 0;

    string mname;
};

void menu() {
  cout << "Press 1 to Matrix Addition\n";
  cout << "Press 2 to Matrix Subtraction\n";
  cout << "Press 3 to Scalar multiplication\n";
  cout << "Press 4 to Matrix multiplication\n";
  cout << "Press 5 to Inverse of matrix\n";
  cout << "Press 6 to exit\n";
}


void getmatrix(Matrix &matrix){
  cout << "Enter Matrix Name: ";
  cin >> matrix.mname;
  cout << "Enter value for cell a1: ";
  cin >> matrix.a1;
  cout << "Enter value for cell b1: ";
  cin >> matrix.b1;
  cout << "Enter value for cell a2: ";
  cin >> matrix.a2; 
  cout << "Enter value for cell b2: ";
  cin >> matrix.b2;
  cout << endl;
}

double getscalar(){
  int scalar;
  cout << "Enter scalar for matrix multiplication: ";
  cin >> scalar;
  cout << endl;

  return scalar;
}

void displaymatrix(Matrix &matrix){
  cout << right;
  cout << setw(8) << matrix.a1 << setw(8) << matrix.b1 << endl << endl;
  cout << setw(8) << matrix.a2 << setw(8) << matrix.b2 << endl << endl;
}

void calculatesum(){
  Matrix m1;
  Matrix m2;
  
  getmatrix(m1);
  getmatrix(m2);
  
  Matrix sum;
  sum.a1 = m1.a1 + m2.a1;
  sum.a2 = m1.a2 + m2.a2;
  sum.b1 = m1.b1 + m2.b1;
  sum.b2 = m1.b2 + m2.b2;

  sum.mname = "Sum";

  displaymatrix(sum);
}

void calculatediff(){
  Matrix m1;
  Matrix m2;
  
  getmatrix(m1);
  getmatrix(m2);
  
  Matrix diff;
  diff.a1 = m1.a1 - m2.a1;
  diff.a2 = m1.a2 - m2.a2;
  diff.b1 = m1.b1 - m2.b1;
  diff.b2 = m1.b2 - m2.b2;

  diff.mname = "Difference";

  displaymatrix(diff);
}

void matrixmultiply(){
  Matrix m1;
  Matrix m2;
  
  getmatrix(m1);
  getmatrix(m2);
  
  Matrix product;
  product.a1 = ((m1.a1 * m2.a1) + (m1.a2 * m2.b1));
  product.a2 = ((m1.a1 * m2.a2) + (m1.a2 * m2.b2));
  product.b1 = ((m1.b1 * m2.a1) + (m1.b2 * m2.b1));
  product.b2 = ((m1.b1 * m2.a2) + (m1.b2 * m2.b2));

  displaymatrix(product);
}

void matrixscalarmulti(){
  Matrix matrix;
  int scalar_x;
  
  scalar_x = getscalar();
  
  Matrix s_product;
  
  s_product.a1 = scalar_x * matrix.a1;
  s_product.a2 = scalar_x * matrix.a2;
  s_product.b1 = scalar_x * matrix.b1;
  s_product.b2 = scalar_x * matrix.b2;

  displaymatrix(s_product);  
}
 

void calculateinverse(){
  Matrix matrix;
  
  getmatrix(matrix);
  
  Matrix inverse;
  
  double detA = ((matrix.a1 * matrix.b2) - (matrix.a2 * matrix.b1));
  inverse.a1 = matrix.b2 / detA;
  inverse.a2 = ((-1)*(matrix.a2))/ detA;
  inverse.b1 = ((-1)*(matrix.b1))/ detA;
  inverse.b2 = matrix.a1 / detA;
    
  displaymatrix(inverse);
};

void cases(int choice){
  switch (choice){
        case 1: 
          {
            calculatesum();
            break;
          }
        case 2:
          {
            calculatediff();
            break;
          }
        case 3:
          {
            matrixscalarmulti();
            break;
          }
        case 4:
          {
            matrixmultiply();
            break;
          }
        case 5:
          {
            calculateinverse();
          }
        case 6:
          {
            cout << "Thank You!\n";
            break; 
          }
        Default:{}
          break; 
      }
    continue_(choice);
}

void continue_(int choice){
  char option;
  cout << "Would you like to continue? Y/N: ";
  cin >> option;
  
    if((option == 'Y') || (option == 'y')) 
    {
      int choice;
      menu();
      cout << "Enter your choice: ";
      cin >> choice;
      cases(choice);
    }
    
 
}


int main() {
  char option;
  int choice;

  cout << "Will you like to begin Y or N: ";
  cin >> option;
  do
  {
   menu();
    cout << "Enter your choice: ";
    cin >> choice;
    cases(choice);
    cout << endl;
  }
  while((option == 'Y') || (option == 'y'));
 
}