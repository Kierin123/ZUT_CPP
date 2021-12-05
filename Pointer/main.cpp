#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <memory>
#include <exception>
#include "MyPtr.h"
#include "MyPtr_ref.h"

int main(void)
{
     std::cout << "Unique Pointers" << std::endl;
     MyPtr<int> p{10};
     MyPtr<int> p1{10};

     std::cout << "ptr val: " << *p << " address: " << (p.getAdress()) << std::endl;
     std::cout << "ptr1 val: " << *p1 << " address: " << (p1.getAdress()) << std::endl;

     std::cout << (p < p1) << std::endl;

     p = std::move(p1);
     p1 = std::move(MyPtr<int>(15));

     std::cout << "ptr val: " << p.get() << " address: " << (p.getAdress()) << std::endl;
     std::cout << "ptr1 val: " << static_cast<bool>(*p1) << " address: " << (p1.getAdress()) << std::endl;

     try
     {
          swap(p, p1);
     }
     catch (const std::exception &e)
     {
          std::cerr << e.what() << '\n';
     }

     std::cout << "ptr val: " << p.get() << " address: " << (p.getAdress()) << std::endl;
     std::cout << "ptr1 val: " << p1.get() << " address: " << (p1.getAdress()) << std::endl;

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