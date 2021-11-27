#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <memory>
#include <exception>
#include "MyPtr.h"
#include "MyPtr_ref.h"

// template <typename T>
// class MyPtr
// {
//      T *ptr;

// public:
//      MyPtr() noexcept
//      {
//           ptr = new T;
//      };

//      MyPtr(T input)
//      {
//           ptr = new T;
//           *ptr = input;
//      };

//      ~MyPtr()
//      {
//           delete ptr;
//      }

//      MyPtr(const MyPtr &) = delete; // No copy constructor! Unique_ptr.

//      MyPtr &operator=(const MyPtr &x) = delete; // No copy assignment! Unique Ptr

//      MyPtr &operator=(MyPtr &&x)
//      {
//           if (&x != this)
//           {
//                delete ptr;
//                ptr = x.ptr;
//                x.ptr = nullptr;
//           }
//           return *this;
//      }

//      void operator=(T input)
//      {
//           *ptr = input;
//      }

//      T operator*()
//      {
//           return *ptr;
//      }

//      bool operator==(MyPtr<T> &input)
//      {
//           bool out = false;
//           if (*ptr == *input.ptr)
//           {
//                out = true;
//           }

//           return out;
//      }

//      bool operator!=(MyPtr<T> &input)
//      {
//           bool out = true;
//           if (*ptr == *input.ptr)
//           {
//                out = false;
//           }

//           return out;
//      }

//      bool operator<(MyPtr<T> &input)
//      {
//           bool out = false;
//           if (*ptr < *input.ptr)
//           {
//                out = true;
//           }

//           return out;
//      }

//      bool operator>(MyPtr<T> &input)
//      {
//           bool out = false;
//           if (*ptr > *input.ptr)
//           {
//                out = true;
//           }

//           return out;
//      }

//      bool operator<=(MyPtr<T> &input)
//      {
//           bool out = false;
//           if (*ptr <= *input.ptr)
//           {
//                out = true;
//           }

//           return out;
//      }

//      bool operator>=(MyPtr<T> &input)
//      {
//           bool out = false;
//           if (*ptr >= *input.ptr)
//           {
//                out = true;
//           }

//           return out;
//      }

//      T &get() const
//      {

//           return *ptr;
//      }

//      const T *getAdress()
//      {
//           return ptr;
//      }
// };

// template <typename T1>
// void swap(MyPtr<T1> &x1, MyPtr<T1> &x2)
// {
//      MyPtr<T1> temp;
//      temp = std::move(x1);
//      x1 = std::move(x2);
//      x2 = std::move(temp);
// }

// template <typename T>
// class MyPtr_ref
// {
//      int *ref_num;
//      T *ptr;

// public:
//      MyPtr_ref() noexcept
//      {
//           ptr = new T;
//           ref_num = new int;
//           *ref_num = 0;
//      };

//      MyPtr_ref(T input)
//      {
//           ptr = new T;
//           *ptr = input;
//           ref_num = new int;
//           *ref_num = 1;
//      };

//      ~MyPtr_ref()
//      {
//           if (*ref_num < 1)
//           {
//                delete ptr;
//           }
//           (*ref_num)--;
//      }

//      MyPtr_ref(MyPtr_ref &x)
//      {
//           ptr = x.ptr;
//           ref_num = x.ref_num;
//           (*ref_num)++;
//      }

//      MyPtr_ref &operator=(MyPtr_ref &x)
//      {
//           ptr = x.ptr;
//           ref_num = x.ref_num;
//           (*ref_num)++;
//           return *this;
//      }

//      // MyPtr_ref &operator=(MyPtr_ref &&x)
//      // {
//      //      if (&x != this)
//      //      {
//      //           delete ptr;
//      //           ptr = x.ptr;
//      //           x.ptr = nullptr;
//      //      }
//      //      return *this;
//      // }

//      void operator=(T input)
//      {
//           *ptr = input;
//      }

//      T operator*()
//      {
//           return *ptr;
//      }

//      bool operator==(MyPtr_ref<T> &input)
//      {
//           bool out = false;
//           if (*ptr == *input.ptr)
//           {
//                out = true;
//           }

//           return out;
//      }

//      bool operator!=(MyPtr_ref<T> &input)
//      {
//           bool out = true;
//           if (*ptr == *input.ptr)
//           {
//                out = false;
//           }

//           return out;
//      }

//      bool operator<(MyPtr_ref<T> &input)
//      {
//           bool out = false;
//           if (*ptr < *input.ptr)
//           {
//                out = true;
//           }

//           return out;
//      }

//      bool operator>(MyPtr_ref<T> &input)
//      {
//           bool out = false;
//           if (*ptr > *input.ptr)
//           {
//                out = true;
//           }

//           return out;
//      }

//      bool operator<=(MyPtr_ref<T> &input)
//      {
//           bool out = false;
//           if (*ptr <= *input.ptr)
//           {
//                out = true;
//           }

//           return out;
//      }

//      bool operator>=(MyPtr_ref<T> &input)
//      {
//           bool out = false;
//           if (*ptr >= *input.ptr)
//           {
//                out = true;
//           }

//           return out;
//      }

//      T &get() const
//      {

//           return *ptr;
//      }

//      const T *getAdress()
//      {
//           return ptr;
//      }

//      int get_count()
//      {
//           int output = *ref_num;
//           return output;
//      }
// };

int main(void)
{

     // std::cout << "Unique Pointers" << std::endl;
     // MyPtr<int> p{10};
     // MyPtr<int> p1{10};

     // std::cout << "ptr val: " << *p << " address: " << (p.getAdress()) << std::endl;
     // std::cout << "ptr1 val: " << *p1 << " address: " << (p1.getAdress()) << std::endl;

     // std::cout << (p < p1) << std::endl;

     // p = std::move(p1);
     // p1 = std::move(MyPtr<int>(15));

     // std::cout << "ptr val: " << p.get() << " address: " << (p.getAdress()) << std::endl;
     // std::cout << "ptr1 val: " << static_cast<bool>(*p1) << " address: " << (p1.getAdress()) << std::endl;

     // try
     // {
     //      swap(p, p1);
     // }
     // catch (const std::exception &e)
     // {
     //      std::cerr << e.what() << '\n';
     // }

     // std::cout << "ptr val: " << p.get() << " address: " << (p.getAdress()) << std::endl;
     // std::cout << "ptr1 val: " << p1.get() << " address: " << (p1.getAdress()) << std::endl;

     std::cout << "Shread Pointers" << std::endl;

     MyPtr_ref<int> pr{12};
     std::cout << "ptr val: " << pr.get() << " address: " << (pr.getAdress()) << " Ref number: " << pr.get_count() << std::endl;

     MyPtr_ref<int> px;

     std::cout << (px > pr) << std::endl;

     std::cout << "ptr val: " << px.get() << " address: " << (px.getAdress()) << " Ref number: " << px.get_count() << std::endl;

     MyPtr_ref<int> pr1(pr);

     std::cout << "ptr val: " << pr.get() << " address: " << (pr.getAdress()) << " Ref number: " << pr.get_count() << std::endl;
     std::cout << "ptr1 val: " << pr1.get() << " address: " << (pr1.getAdress()) << " Ref number: " << pr1.get_count() << std::endl;

     px = pr;

     std::cout << "ptr val: " << pr.get() << " address: " << (pr.getAdress()) << " Ref number: " << pr.get_count() << std::endl;
     std::cout << "ptr1 val: " << pr1.get() << " address: " << (pr1.getAdress()) << " Ref number: " << pr1.get_count() << std::endl;
     std::cout << "ptr val: " << px.get() << " address: " << (px.getAdress()) << " Ref number: " << px.get_count() << std::endl;
     std::cout << "Destructor!" << std::endl;
     pr1.~MyPtr_ref();

     std::cout << "ptr val: " << pr.get() << " address: " << (pr.getAdress()) << " Ref number: " << pr.get_count() << std::endl;
     std::cout << "ptr1 val: " << pr1.get() << " address: " << (pr1.getAdress()) << " Ref number: " << pr1.get_count() << std::endl;
     std::cout << "ptr val: " << px.get() << " address: " << (px.getAdress()) << " Ref number: " << px.get_count() << std::endl;

     return 0;
}