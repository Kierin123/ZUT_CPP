template <typename T>
class MyPtr
{
     T *ptr;

public:
     MyPtr() noexcept
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

     MyPtr(const MyPtr &) = delete; // No copy constructor! Unique_ptr.

     MyPtr &operator=(const MyPtr &x) = delete; // No copy assignment! Unique Ptr

     MyPtr &operator=(MyPtr &&x)
     {
          if (&x != this)
          {
               delete ptr;
               ptr = x.ptr;
               x.ptr = nullptr;
          }
          return *this;
     }

     void operator=(T input)
     {
          *ptr = input;
     }

     T operator*()
     {
          return *ptr;
     }

     bool operator==(MyPtr<T> &input)
     {
          bool out = false;
          if (*ptr == *input.ptr)
          {
               out = true;
          }

          return out;
     }

     bool operator!=(MyPtr<T> &input)
     {
          bool out = true;
          if (*ptr == *input.ptr)
          {
               out = false;
          }

          return out;
     }

     bool operator<(MyPtr<T> &input)
     {
          bool out = false;
          if (*ptr < *input.ptr)
          {
               out = true;
          }

          return out;
     }

     bool operator>(MyPtr<T> &input)
     {
          bool out = false;
          if (*ptr > *input.ptr)
          {
               out = true;
          }

          return out;
     }

     bool operator<=(MyPtr<T> &input)
     {
          bool out = false;
          if (*ptr <= *input.ptr)
          {
               out = true;
          }

          return out;
     }

     bool operator>=(MyPtr<T> &input)
     {
          bool out = false;
          if (*ptr >= *input.ptr)
          {
               out = true;
          }

          return out;
     }

     T &get() const
     {

          return *ptr;
     }

     const T *getAdress()
     {
          return ptr;
     }
};

template <typename T1>
void swap(MyPtr<T1> &x1, MyPtr<T1> &x2)
{
     MyPtr<T1> temp;
     temp = std::move(x1);
     x1 = std::move(x2);
     x2 = std::move(temp);
}