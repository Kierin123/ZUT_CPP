#include <iostream>
#include <string>
#include <cstring>

template <typename T>
class RingBuffer
{

     int bufferLen = 0;
     int bufferFill = 0;
     T *headPtr;
     T *tailPtr;
     T *bufferPtr;

public:
     RingBuffer(int N)
     {
          bufferLen = N;
          bufferFill = 0;
          bufferPtr = new T[N];
          headPtr = bufferPtr;
          tailPtr = bufferPtr;
     };

     ~RingBuffer()
     {
          bufferLen = 0;
          bufferFill = 0;
          headPtr = NULL;
          tailPtr = NULL;
          delete[] bufferPtr;
     }

     RingBuffer(const RingBuffer &RB)
     {
          bufferPtr = new T[RB.bufferLen];
     }

     void RingBufferWrite(T newValue)
     {
          bufferFill++;
          if (bufferFill >= bufferLen)
          {
               bufferFill = bufferLen;
          }

          if (headPtr == bufferPtr + (bufferLen - 1))
          {
               *headPtr = newValue;
               headPtr = bufferPtr;
          }
          else
          {
               *headPtr = newValue;
               headPtr++;
          }
     }

     T RingBufferRead()
     {
          if ((tailPtr == headPtr) && (bufferFill == 0))
          {
               std::cout << "Read Error - Buffer Empty" << std::endl;
               return (T)NULL;
          }

          bufferFill--;

          T readValue = *tailPtr;

          *tailPtr = (T)NULL;
          if (tailPtr == bufferPtr + (bufferLen - 1))
          {
               tailPtr = bufferPtr;
          }
          else
          {
               tailPtr++;
          }
          return readValue;
     }

     void printLog()
     {
          std::cout << "bufferPtr: " << (void *)bufferPtr << std::endl;
          std::cout << "bufferFill: " << bufferFill << std::endl;

          std::cout << "headPtr: " << *headPtr << " " << (void *)headPtr << std::endl;
          std::cout << "tailPtr: " << *tailPtr << " " << (void *)tailPtr << std::endl;
          std::cout << "ValuesPtr: ";
          for (int i = 0; i < bufferLen; i++)
          {
               std::cout << bufferPtr[i];
          }
          std::cout << std::endl
                    << std::endl;
     }
};

int main(void)
{
     RingBuffer<char> buff(4);

     buff.RingBufferWrite('a');
     buff.RingBufferWrite('b');
     buff.RingBufferWrite('c');
     buff.RingBufferWrite('d');
     buff.RingBufferWrite('e');
     buff.RingBufferWrite('f');

     buff.printLog();
     buff.RingBufferRead();
     buff.printLog();
     buff.RingBufferRead();
     buff.printLog();
     buff.RingBufferRead();
     buff.printLog();
     buff.RingBufferRead();
     buff.printLog();
     buff.RingBufferRead();


     return 0;
}