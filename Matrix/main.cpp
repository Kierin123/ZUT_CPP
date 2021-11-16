#include <iostream>
#include <string>
#include <cstring>
#include <vector>

template <int N = 1, int M = 1, typename T = int>
class Matrix
{
     std::vector<std::vector<T>> Mat;

public:
     Matrix()
     {
          Mat.resize(N);
          std::vector<T> temp_vect(M, 0);

          for (auto i = Mat.begin(); i < Mat.end(); i++)
          {
               *i = temp_vect;
          }
     };

     template <int N1, int M1, typename T1>
     Matrix(const Matrix<N1, M1, T1> &cpMat)
     {
          Matrix<N1, M1, T1> temp = cpMat;
          for (int i = 0; i < N1; i++)
          {
               for (int j = 0; j < M1; j++)
               {
                    Mat[i][j] = static_cast<T>(temp[i][j]);
               }
          }
     }

     void fillBy(T val)
     {
          std::vector<T> temp_vect(M, val);

          for (auto i = Mat.begin(); i < Mat.end(); i++)
          {
               *i = temp_vect;
          }
     }

     std::vector<T> operator[](int index)
     {
          return Mat.at(index);
     }

     

     template <int N1, int M1, typename T1>
     Matrix<N, M, T> operator+(const Matrix<N1, M1, T1> input)
     {
          if ((N1 >= N) && (M1 >= M))
          {
               Matrix<N1, M1, T1> temp = input;
               for (int i = 0; i < N1; i++)
               {
                    for (int j = 0; j < M1; j++)
                    {
                         Mat[i][j] = Mat[i][j] + temp[i][j];
                    }
               }
          }
          else
               printf("Cannot add, wrong size\n");

          return *this;
     }

     Matrix<N, M, T> operator+(int val)
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
};

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
std::ostream &operator<<(std::ostream &os, Matrix<N, M, T> input)
{
     for (int i = 0; i < N; i++)
     {
          for (int j = 0; j < M; j++)
          {
               os << input[i][j] << " ";
          }
          os << std::endl;
     }
     return os;
}

int main(void)
{
     Matrix<10, 5, int> b;

     Matrix<10, 5, int> m;

     m.fillBy(2);

     Matrix<10, 5, int> n = m;

     std::cout << "M: \n"
               << m;
     std::cout << std::endl;

     std::cout << "N: \n"
               << n;
     n = n + 2;
     std::cout << "n: \n"
               << n;
     std::cout << std::endl;
     b = m + n;
     std::cout << "B: \n"
               << b;

     // std::cout << m;

     return 0;
}