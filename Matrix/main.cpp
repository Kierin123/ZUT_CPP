#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <int N = 1, int M = 1, typename T = int>
class Matrix
{
     vector<vector<T>> Mat;

public:
     //################################
     //        Constructors
     //################################
     Matrix()
     {
          Mat.resize(N);
          vector<T> temp_vect(M, 0);
          for (auto i = Mat.begin(); i < Mat.end(); i++)
          {
               *i = temp_vect;
          }
     };

     Matrix(int val)
     {
          Mat.resize(N);
          vector<T> temp_vect(M, val);
          for (auto i = Mat.begin(); i < Mat.end(); i++)
          {
               *i = temp_vect;
          }
     };

     Matrix(const Matrix<N, M, T> &cpMat)
     {
          Mat.resize(N);

          cout << "    Copy Ctor\n";
          for (auto i = 0; i < N; i++)
          {
               Mat[i] = cpMat[i];
          }
     }

     template <int N1, int M1, typename T1>
     Matrix(const Matrix<N1, M1, T1> &cpMat)
     {
          Mat.resize(N1);

          cout << "    Copy Ctor T1!!!\n";
          for (auto i = 0; i < N1; i++)
          {
               Mat[i] = cpMat[i];
          }
     }

     //################################
     //        methods
     //################################

     void fillBy(T val)
     {
          vector<T> temp_vect(M, val);
          for (auto i = Mat.begin(); i < Mat.end(); i++)
          {
               *i = temp_vect;
          }
     }

     //################################
     //        OPERATORS
     //################################

     template <int N1, int M1, typename T1>
     Matrix<N, M, T> &operator=(const Matrix<N1, M1, T1> &input)
     {
          for (auto i = 0; i < N; i++)
          {
               Mat[i] = input[i];
          }
          return *this;
     }

     Matrix<N, M, T> &operator=(const Matrix<N, M, T> &input)
     {
          for (auto i = 0; i < N; i++)
          {
               Mat[i] = input[i];
          }
          return *this;
     }

     template <int N1, int M1, typename T1>
     Matrix<N, M, T> &operator+(const Matrix<N1, M1, T1> &input)
     {

          if ((N1 >= N) && (M1 >= M))
          {

               for (int i = 0; i < N1; i++)
               {
                    for (int j = 0; j < M1; j++)
                    {
                         Mat[i][j] = Mat[i][j] + input[i][j];
                    }
               }
          }
          else
               printf("Cannot add, wrong size\n");

          return *this;
     }

     Matrix<N, M, T> &operator+(const Matrix<N, M, T> &input)
     {

          for (int i = 0; i < N; i++)
          {
               for (int j = 0; j < M; j++)
               {
                    Mat[i][j] = Mat[i][j] + input[i][j];
               }
          }

          return *this;
     }

     Matrix<N, M, T> &operator+(int val)
     {

          for (int i = 0; i < N; i++)
          {
               for (int j = 0; j < M; j++)
               {
                    Mat[i][j] = Mat[i][j] + val;
               }
          }

          return *this;
     }

     vector<T> operator[](int index) const
     {
          return (Mat.at(index));
     }
};

//#####################################
//        Specialization
//#####################################

template <typename T>
class Matrix<0, 0, T>
{
public:
     Matrix()
     {
          printf("Cannot create the object! \n");
     }
};

template <int N, int M>
class Matrix<N, M, bool>
{
public:
     Matrix()
     {
          printf("Cannot create the object! Type bool! \n");
     }
};

template <int N, int M, typename T>
std::ostream &operator<<(std::ostream &os, Matrix<N, M, T> &input)
{
     for (int i = 0; i < N; i++)
     {
          for (int j = 0; j < M; j++)
          {
               os << input[i][j] << " ";
          }
          os << endl;
     }
     return os;
}

//################################
//        MAIN
//################################

int main(void)
{
     Matrix<3, 5, int> M1;
     Matrix<3, 2, int> M2;
     M2.fillBy(3);

     Matrix<3, 5, int> M3 = M2;
     Matrix<3, 5, int> M4(10);

     cout << "new M1: " << endl
          << M1;
     cout << "new M2: " << endl
          << M2;
     cout << "new M3: " << endl
          << M3;
     cout << "new M4: " << endl
          << M4;


     M2 = M2 + 2;

     cout << "M2: " << endl
          << M2;
     M1 = M2 + M3;
     cout << "M1: \n"
          << M1;
     M1 = M2 + 9;
     cout << "M1: \n"
          << M1;

     return 0;
}