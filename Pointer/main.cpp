#include <iostream>
#include <string>
#include <cstring>
#include <vector>

template <typename T>
class MyPtr
{
     T *ptr;

public:
     MyPtr()
     {
          ptr = new T;
     };

     MyPtr(T input)
     {
          ptr = new T;
          *ptr = input;
     };

     ~MyPtr()
     {
          delete ptr;
     }

     MyPtr(const MyPtr &oldPtr)
     {
          ptr = new T;
          *ptr = oldPtr.get();
     }

     MyPtr(MyPtr &&inPtr)
     {
          ptr = inPtr.ptr;
          inPtr.ptr = nullptr;
     }

     MyPtr &operator=(const MyPtr &x)
     {
          if (&x != this)
          {
               delete ptr; 
               ptr = new T(x.get());
          }
          return *this;
     }

     void operator=(T input)
     {
          *ptr = input;
     }

     T &get() const
     {
          return *ptr;
     }

     T *getAdress()
     {
          return ptr;
     }
};

template <typename T1>
void swap(MyPtr<T1> &x1, MyPtr<T1> &x2)
{
     MyPtr<T1> temp = x2;
     x2 = x1;
     x1 = temp;
}

int main(void)
{
     MyPtr<int> p = 5;
     MyPtr<int> p1(10);
     MyPtr<int> p2 = MyPtr<int>(15);
     MyPtr<int> p3(p1);

     std::cout << "ptr val: " << p.get() << " address: " << (p.getAdress()) << std::endl;
     std::cout << "ptr1 val: " << p1.get() << " address: " << (p1.getAdress()) << std::endl;
     std::cout << "ptr2 val: " << p2.get() << " address: " << (p2.getAdress()) << std::endl;
     std::cout << "ptr3 val: " << p3.get() << " address: " << (p3.getAdress()) << std::endl;

     swap(p, p1);

     std::cout << "ptr val: " << p.get() << " address: " << (p.getAdress()) << std::endl;
     std::cout << "ptr1 val: " << p1.get() << " address: " << (p1.getAdress()) << std::endl;

     return 0;
}