#include <iostream>
#include <string>
#include <array>
#include <cstring>
#include <iterator>
#include <typeinfo>

template <typename T, int N>
class RingBuffer
{
     std::array<T, N> bufferPtr;
     T *headIt;
     T *tailIt;
     int bufferElements;

public:
     RingBuffer()
     {

          headIt = bufferPtr.begin();
          tailIt = bufferPtr.begin();

          bufferElements = 0;
     };

     void push(T newElement)
     {

          if (headIt == (bufferPtr.end() - 1))
          {
               *headIt = newElement;
               headIt = bufferPtr.begin();
          }
          else
          {
               *headIt = newElement;
               headIt++;
          }

          if (bufferElements >= N)
          {
               bufferElements = N;
          }
          else
          {
               bufferElements++;
          }
     }

     T get()
     {
          T output = 0;

          if ((tailIt == headIt) && (bufferElements == 0))
          {
               printf("Error! buffer empty.\n");
          }
          else if (tailIt == (bufferPtr.end() - 1))
          {
               output = *tailIt;
               *tailIt = 0;
               tailIt = bufferPtr.begin();
               bufferElements--;
          }
          else
          {
               output = *tailIt;
               *tailIt = 0;
               tailIt++;
               bufferElements--;
          }

          return output;
     }

     T show()
     {
          T output = 0;

          if ((tailIt == headIt) && (bufferElements == 0))
          {
               printf("Error! buffer empty.\n");
          }
          else if (tailIt == (bufferPtr.end() - 1))
          {
               output = *tailIt;
               tailIt = bufferPtr.begin();
          }
          else
          {
               output = *tailIt;
               tailIt++;
          }

          return output;
     }

     int size()
     {
          return bufferElements;
     }

     ~RingBuffer()
     {
     }

     T operator[](int index)
     {
          return bufferPtr.at(index);
     }

     const T *getHeadIt()
     {
          return headIt;
     }
};

template <typename T, int N>
std::ostream &operator<<(std::ostream &os, RingBuffer<T, N> &var)
{

     int bufferSize = var.size();
     for (int i = 0; i < bufferSize; i++)
     {
          os << var.show() << " ";
     }

     return os;
}

int main(void)
{
     RingBuffer<int, 10> buff;

     std::cout << buff.get() << std::endl;
     buff.push(2);
     buff.push(3);
     buff.push(4);
     buff.push(5);
     buff.push(6);
     buff.push(7);
     buff.get();
     buff.get();
     buff.push(8);
     buff.push(9);
     buff.push(10);
     buff.push(11);
     buff.push(12);
     // buff.push(13);
     // buff.push(14);

     // std::cout << buff.get() << std::endl;
     std::cout << "RingBuffer size: " << buff.size() << std::endl;
     std::cout << "RingBuffer elements: " << buff << std::endl;
     std::cout << "RingBuffer size: " << buff.size() << std::endl;
     std::cout << "RingBuffer elements: " << buff << std::endl;

     std::cout << "Buffer elem: " << buff.get() << std::endl;
     std::cout << "RingBuffer size: " << buff.size() << std::endl;

     return 0;
}