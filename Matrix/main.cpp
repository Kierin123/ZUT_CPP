#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

//   N - number of raws
//   M - number of column
//   T - type of data

template <int N, int M, typename T>
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
          for (auto i = Mat.begin(); i < Mat.end(); i++)
          {
               *i = vector<T>(0);
          }
     };

     Matrix(int val)
     {
          Mat.resize(N);
          for (auto i = Mat.begin(); i < Mat.end(); i++)
          {
               *i = vector<T>(M, val);
          }
     };

     Matrix(const Matrix<N, M, T> &cpMat)
     {
          Mat.resize(N);
          for (auto i = 0; i < N; i++)
          {
               Mat[i] = cpMat.Mat[i];
          }
     }

     //################################
     //        Methods
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
          if ((N1 == N) && (M1 == M))
          {
               for (auto i = 0; i < N1; i++)
               {
                    Mat[i] = input[i];
               }
          }
          else
               printf("Cannot assign, wrong size\n");

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

     Matrix<N, M, T> &operator=(const Matrix<N, M, T> &&input)
     {
          for (auto i = 0; i < N; i++)
          {
               Mat[i] = input[i];
          }
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
          if (N == M)
          {
               for (int i = 0; i < N; i++)
               {

                    Mat[i][i] = Mat[i][i] + val;
               }
          }
          else
          {
               cout << "Cannot be done! Different raw and column size." << endl;
          }

          return *this;
     }

     template <typename T1>
     Matrix<M, N, T> operator*(const Matrix<N, M, T1> &input)
     {
          Matrix<M, N, T> temp_mat(0);
          auto it = temp_mat.Mat.begin();
          for (int k = 0; k < M; k++)
          {
               vector<T> temp_vect(N);
               for (int i = 0; i < N; i++)
               {
                    for (int j = 0; j < M; j++)
                    {
                         temp_vect[i] += Mat[k][j] * input[j][k];
                    }
               }
               *it = temp_vect;
               it++;
          }

          return temp_mat;
     }

     Matrix<N, M, T> &operator*(int val)
     {
          
          for (int i = 0; i < N; i++)
          {
               for (int j = 0; j < M; j++)
               {
                    Mat[i][j] = Mat[i][j] * val;
               }
          }

          return *this;
     }

     vector<T> operator[](int index) const
     {
          return (Mat[index]);
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
     Matrix<3, 3, int> M1(3);
     M1 = M1 + 2;
     Matrix<3, 3, int> M2(2);
     Matrix<3, 3, int> M3(0);

     cout << "new M1: " << endl
          << M1;
     cout << "new M2: " << endl
          << M2;
     cout << "new M3: " << endl
          << M3;

     try
     {
          M3 = M1 * M2;
     }
     catch (const std::exception &e)
     {
          std::cerr << e.what() << '\n';
     }

     cout << "new M1: " << endl
          << M1;
     cout << "new M2: " << endl
          << M2;
     cout << "new M3: " << endl
          << M3;

     return 0;
}