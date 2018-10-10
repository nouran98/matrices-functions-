// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 1
// Program: CS213-2018-A1-T1-P1
// Purpose: Code to make operations on matrices
// Author:  Nouran Qassem & Nehal Akram
// Date:    16 September  2018
// Version: 1.0




#include <iostream>

using namespace std;


// A structure to store a matrix
struct matrix
{
    int* data;
    int row, col;
};

void createMatrix (int row, int col, int num[], matrix& mat)
{
    mat.row = row;
    mat.col = col;
    mat.data = new int [row * col];
    for (int i = 0; i < row * col; i++)
    {
        mat.data [i] = num [i];
    }
}

matrix operator+  (matrix mat1, matrix mat2)
{
    if (mat1.row == mat2.row && mat1.col == mat2.col)
    {
        matrix mat ;
        mat.row = mat1.row ;
        mat.col = mat1.col ;
        mat.data = new int [mat.row * mat.col] ;

        for (int i = 0 ; i < mat1.row * mat1.col ; i++)
        {
            mat.data[i] = mat1.data[i] + mat2.data[i] ;
        }
        return mat ;
    }
}

matrix operator-  (matrix mat1, matrix mat2)
{
    if (mat1.row == mat2.row && mat1.col == mat2.col)
    {
        matrix mat ;
        mat.row = mat1.row ;
        mat.col = mat1.col ;
        mat.data = new int [mat.row * mat.col] ;

        for (int i = 0 ; i < mat1.row * mat1.col ; i++)
        {
            mat.data[i] = mat1.data[i] - mat2.data[i] ;
        }
        return mat ;
    }
}

matrix operator*  (matrix mat1, matrix mat2)
{
    if (mat1.col == mat2.row )
    {
        matrix mat ;
        mat.row = mat1.row ;
        mat.col = mat2.col ;
        mat.data = new int [mat1.row * mat2.col] ;

        int arr[mat1.row][mat1.col] ;
        int c = 0 ;
        for (int i = 0 ; i < mat1.row ; i++)
        {
            for (int j = 0 ; j < mat1.col ; j++)
            {
                arr[i][j] = mat1.data[c] ;
                c++  ;
            }
        }

        int arr1[mat2.row][mat2.col] ;
        int c1 = 0 ;

        for (int i = 0 ; i < mat2.row ; i++)
        {
            for (int j = 0 ; j < mat2.col ; j++)
            {
                arr1[i][j] = mat2.data[c1] ;
                c1++ ;
            }
        }

        int l = 0, m=0, mult, c2=0, z=0;

        for (int i = 0 ; i < mat1.row * mat2.col; i++)
        {
            if ( c2 == mat2.col )
            {
                m++ ;
                l= 0 ;
                c2 = 0;
            }
            mult = 0 ;
            for (int j = 0 ; j < mat2.row ; j++)
            {
                mult +=  (arr[m][j] * arr1[j][l]) ;
            }
            mat.data[z] = mult ;
            l++ ;
            c2++ ;
            z++ ;
        }
        return mat ;
    }
    else { cout << " Can't be multiplied bec. two matrices aren't the same dimensions " ; }
}

matrix operator+  (matrix mat1, int scalar)
{
    matrix mat;
    mat.row = mat1.row ;
    mat.col = mat1.col ;
    mat.data = new int [mat1.row * mat1.col] ;

    for (int i=0 ; i < (mat1.row)*(mat1.col) ; i++)
    {
        mat.data[i] = mat1.data[i] + scalar ;
    }
    return mat ;
}

matrix operator-  (matrix mat1, int scalar)
{
    matrix mat;
    mat.row = mat1.row ;
    mat.col = mat1.col ;
    mat.data = new int [mat1.row * mat1.col] ;

    for (int i=0 ; i < (mat1.row)*(mat1.col) ; i++)
    {
        mat.data[i] = mat1.data[i] - scalar ;
    }
    return mat ;
}

matrix operator* (matrix mat1, int scalar)
{
    matrix mat;
    mat.row = mat1.row ;
    mat.col = mat1.col ;
    mat.data = new int [mat1.row * mat1.col] ;

    for (int i=0 ; i < (mat1.row)*(mat1.col) ; i++)
    {
        mat.data[i] = scalar * mat1.data[i] ;
    }

    return mat ;
}

matrix operator+= (matrix& mat1, matrix mat2)
{
    for (int i = 0 ; i < mat1.row * mat1.col ; i++)
    {
        mat1.data[i] += mat2.data[i] ;
    }
    return mat1 ;
}

matrix operator-= (matrix& mat1, matrix mat2)
{
    for (int i = 0 ; i < mat1.row * mat1.col ; i++)
    {
        mat1.data[i] -= mat2.data[i] ;
    }
    return mat1 ;
}

matrix operator+= (matrix& mat, int scalar)
{
    for (int i = 0 ; i < mat.row * mat.col ; i++)
    {
        mat.data[i] += scalar ;
    }
    return mat ;

}

matrix operator-= (matrix& mat, int scalar)
{
    for (int i = 0 ; i < mat.row * mat.col ; i++)
    {
        mat.data[i] -= scalar ;
    }
    return mat ;
}

void operator++ (matrix& mat)
{
    for (int i = 0 ; i < mat.row * mat.col ; i++)
    {
        mat.data[i] += 1 ;
    }
}

void operator-- (matrix& mat)
{
    for (int i = 0 ; i < mat.row * mat.col ; i++)
    {
        mat.data[i] -= 1 ;
    }
}

istream& operator>> (istream& in, matrix& mat)
{
    cout << " Row = " ;
    in >> mat.row ;
    cout << " Column = ";
    in >> mat.col ;

    mat.data = new int [mat.row * mat.col] ;

    for (int i = 0 ; i < mat.row * mat.col ; i++)
    {
        in >> mat.data[i] ;
    }
    return in ;

}

ostream& operator<< (ostream& out, matrix mat)
{
    int l=0, k, c1 ;
    c1 = mat.col ;
    for (int i = 0 ; i < mat.row ; i++ )
    {
        for ( k = l ; k < mat.col ; k++)
        {
            out << mat.data[k] << " " ;
        }
        cout << endl ;
        l += c1 ;
        mat.col += c1 ;
    }
    return out ;
}

bool   operator== (matrix mat1, matrix mat2)
{
    if (mat1.row != mat2.row || mat1.col != mat2.col )
    {
        return false ;
    }
    if (mat1.row == mat2.row && mat1.col == mat2.col)
    {
        for (int i = 0 ; i < mat1.row * mat1.col ; i++ )
        {
            if (mat1.data[i] != mat2.data[i])
            {
                return false ;
            }
        }
    }
    return true ;
}

bool   operator!= (matrix mat1, matrix mat2)
{
    if (mat1.row == mat2.row && mat1.col == mat2.col )
    {
        for (int i = 0 ; i < mat1.row * mat1.col ; i++ )
        {
            if (mat1.data[i] != mat2.data[i])
            {
                return true ;
            }
        }
        return false ;
    }
    return true ;
}

bool   isSquare   (matrix mat)
{
    if (mat.row == mat.col )
    {
        return true ;
    }
    return false ;
}

bool   isSymetric (matrix mat)
{
    if (mat.row == mat.col )
    {
        int arr[mat.row][mat.col] ;
        int k = 0 ;
        for (int i = 0 ; i < mat.row ; i++)
        {
            for (int j = 0 ; j < mat.col ; j++)
            {
                arr[i][j] = mat.data[k] ;
                k++  ;
            }
        }
        for (int m = 0 ; m < mat.row ; m++)
        {
            for (int n = 0 ; n < mat.col ; n++)
            {
                if (arr[m][n] == arr[n][m])
                {
                    continue ;
                }
                else
                {
                    return false ;
                }
            }
        }
        return true ;
    }
    return false ;
}

bool   isIdentity (matrix mat)
{
    int l=1, r = mat.row ;
    if ( mat.row == mat.col )
    {
        for (int i=0 ; i < mat.row * mat.col ; i+=(mat.row +1))
        {
            for (int j=l ; j < mat.row ; j++ )
            {
                if (mat.data[i] !=1 && mat.data[j]!=0)
                {
                    return false;
                }
            }
            l+=1 ;
            mat.row += r ;

        }
        return true ;
    }
    return false ;
}

matrix transpose (matrix mat)
{
    matrix mat1 ;
    mat1.row = mat.row ;
    mat1.col = mat.col ;
    mat1.data = new int [mat1.row * mat1.col] ;

    int arr[mat1.row][mat1.col] ;
    int arr1[mat1.row][mat1.col] ;

    int k = 0, l=0 ;

    for (int i = 0 ; i < mat.row ; i++)
    {
        for (int j = 0 ; j < mat.col ; j++)
        {
            arr[i][j] = mat.data[k] ;
            k++  ;
        }
    }
    for (int i = 0 ; i < mat.row ; i++)
    {
        for (int j = 0 ;  j< mat.col ; j++)
        {
            arr1[i][j] = arr[j][i] ;
            mat1.data[l] = arr1[i][j] ;
            l++ ;
        }
    }


    return mat1 ;
}

int main()
{
    matrix mat1, mat2, mat3 , mat4 ;
    int x ;

    cout << "enter row and column of first array " << endl ;
    cin >> mat1.row >> mat1.col ;
    int* data1 = new int [mat1.row * mat1.col] ;

    for (int i = 0 ; i < mat1.row * mat1.col ; i++ )
    {
        cin >> data1[i] ;
    }
    createMatrix (mat1.row, mat1.col, data1, mat1);

    cout << "enter row and column of second array " << endl ;
    cin >> mat2.row >> mat2.col ;
    int* data2 = new int [mat2.row * mat2.col] ;

    for (int i = 0 ; i < mat2.row * mat2.col ; i++ )
    {
        cin >> data2[i] ;
    }
    createMatrix (mat2.row, mat2.col, data2, mat2);

    cout << "enter row and column of third array " << endl ;
    cin >> mat3.row >> mat3.col ;
    int* data3 = new int [mat3.row * mat3.col] ;

    for (int i = 0 ; i < mat3.row * mat3.col ; i++ )
    {
        cin >> data3[i] ;
    }
    createMatrix (mat3.row, mat3.col, data3, mat3);

    cout << "mat1 = " << endl << mat1 << endl ;
    cout << "mat2 = " << endl << mat2 << endl ;
    cout << "mat3 = " << endl << mat3 << endl ;
    cout << "Addition Operation = " << endl << mat1 + mat3 << endl ;
    cout << " Subtraction Operation = " << endl << mat1 - mat3 << endl ;
    cout << " Multiplication Operation = " << endl << mat1 * mat2 << endl ;
    cout << " Addition with scalar " << endl << " Enter a number " << endl ;
    cin >> x ;
    cout << mat1 + x ;
    cout << " Subtraction with scalar " << endl << " Enter a number " << endl ;
    cin >> x ;
    cout << mat1 - x ;
    cout << " Multiplication with scalar " << endl << " Enter a number " << endl ;
    cin >> x ;
    cout << mat1 * x ;
    cout << " Plus equal Operation = " << endl << ( mat1+=mat2 ) << endl ;
    cout << " Minus equal Operation = " << endl << ( mat1-=mat2 )<< endl ;
    cout << " Plus equal with scalar Operation = " << endl << " Enter a number " << endl ;
    cin >> x ;
    cout << ( mat1+=x ) ;
    cout << " Minus equal with scalar Operation = " << endl << " Enter a number " << endl ;
    cin >> x ;
    cout << ( mat1-=x ) ;
    cout << " Prefix Operation ( ++ ) = " << endl ;
    ++mat1 ;
    cout << mat1 << endl ;
    cout << " Prefix Operation ( -- ) = " << endl ;
    --mat1 ;
    cout << mat1 << endl ;
    cout << " Equal Operation " << endl ;
    if ( mat1 == mat2 )
    {
        cout << " Two matrices are equal " << endl ;
    }
    else
    {
        cout << " Two matrices are not equal " << endl ;
    }
    cout << " Not Equal Operation " << endl ;
    if ( mat1 != mat2 )
    {
        cout << " Two matrices aren't equal " << endl ;
    }
    else
    {
        cout << " Two matrices are equal " << endl ;
    }

    cout << " Is the matrix square ? " << endl << isSquare(mat3) << endl ;
    cout << " Is the matrix symmetric ? " << endl << isSymetric(mat3) << endl ;
    cout << " Is the matrix identity ? " << endl << isIdentity(mat3) << endl ;

    cout << " Transpose matrix " << endl << transpose(mat1) << endl ;

    cout << " in operator " ;
    cin >> mat4 ;
    cout << mat4 ;


    delete[] data1 ;
    delete[] data2 ;
    delete[] data3 ;

    return 0 ;

}
