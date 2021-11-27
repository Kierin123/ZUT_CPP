template <typename T>
class MyPtr_ref
{
     int *ref_num;
     T *ptr;

public:
     MyPtr_ref() noexcept
     {
          ptr = new T;
          ref_num = new int;
          *ref_num = 0;
     };

     MyPtr_ref(T input)
     {
          ptr = new T;
          *ptr = input;
          ref_num = new int;
          *ref_num = 1;
     };

     ~MyPtr_ref()
     {
          if (*ref_num < 1)
          {
               delete ptr;
          }
          (*ref_num)--;
     }

     MyPtr_ref(MyPtr_ref &x)
     {
          ptr = x.ptr;
          ref_num = x.ref_num;
          (*ref_num)++;
     }

     MyPtr_ref &operator=(MyPtr_ref &x)
     {
          ptr = x.ptr;
          ref_num = x.ref_num;
          (*ref_num)++;
          return *this;
     }

     // MyPtr_ref &operator=(MyPtr_ref &&x)
     // {
     //      if (&x != this)
     //      {
     //           delete ptr;
     //           ptr = x.ptr;
     //           x.ptr = nullptr;
     //      }
     //      return *this;
     // }

     void operator=(T input)
     {
          *ptr = input;
     }

     T operator*()
     {
          return *ptr;
     }

     bool operator==(MyPtr_ref<T> &input)
     {
          bool out = false;
          if (*ptr == *input.ptr)
          {
               out = true;
          }

          return out;
     }

     bool operator!=(MyPtr_ref<T> &input)
     {
          bool out = true;
          if (*ptr == *input.ptr)
          {
               out = false;
          }

          return out;
     }

     bool operator<(MyPtr_ref<T> &input)
     {
          bool out = false;
          if (*ptr < *input.ptr)
          {
               out = true;
          }

          return out;
     }

     bool operator>(MyPtr_ref<T> &input)
     {
          bool out = false;
          if (*ptr > *input.ptr)
          {
               out = true;
          }

          return out;
     }

     bool operator<=(MyPtr_ref<T> &input)
     {
          bool out = false;
          if (*ptr <= *input.ptr)
          {
               out = true;
          }

          return out;
     }

     bool operator>=(MyPtr_ref<T> &input)
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

     int get_count()
     {
          int output = *ref_num;
          return output;
     }
};