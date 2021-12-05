#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <fstream>
#include <mutex>
#include "Prime.h"
#include "gtest/gtest.h"



using namespace std::chrono;
using std::cout;
using std::endl;
using std::thread;
using std::vector;

std::mutex time_mutex;


std::ostream &operator<<(std::ostream &os, std::vector<long long int> &input)
{
     for (auto &i : input)
     {
          os << i << " ";
     }

     return os;
}

void Thread_handler(std::vector<long long int> _vector)
{
     std::thread::id id_number = std::this_thread::get_id();
     bool output_thread;

     std::unique_lock<std::mutex> lck(time_mutex);

     std::cout << "Thread[" << id_number << "] Check if the numbers are prime." << std::endl;
     for (auto &i : _vector)
     {
          output_thread = IsPrime(i);
          std::cout << i << "-" << ((output_thread) ? "yes; " : "no; ");
     }
     std::cout << std::endl;
}

void Thread_handler_rabin(std::vector<long long int> _vector)
{
     std::thread::id id_number = std::this_thread::get_id();
     bool output_thread;
     std::unique_lock<std::mutex> lck(time_mutex);

     std::cout << "Thread[" << id_number << "] Check if the numbers are prime." << std::endl;
     for (auto &i : _vector)
     {
          output_thread = MillerPrime(i, 1);
          std::cout << i << "-" << ((output_thread) ? "yes;" : "no;");
     }
     std::cout << std::endl;
}

//################################
//        MAIN
//################################

int main(int argc, char *argv[])
{
     ::testing::InitGoogleTest(&argc,argv);
     RUN_ALL_TESTS();

     std::vector<long long int> numbers_to_check;
     int number_length = 20;
     char number_output[20];
     char *ptr_end;

     std::fstream _file;
     try
     {
          _file.open("./Values.txt", std::fstream::in);
          while (!_file.eof())
          {
               _file.getline(number_output, number_length);
               numbers_to_check.push_back(strtoll(number_output, &ptr_end, 10));
          }
     }
     catch (std::ifstream::failure &e)
     {
          std::cerr << e.what() << '\n';
     }
     auto vector_size = numbers_to_check.size();

     std::cout << "Numbers(" << vector_size << "numbers) from the file: \n"
               << numbers_to_check << std::endl;

     // #########################
     //    Thread calculations
     // #########################

     auto core_count = std::thread::hardware_concurrency();

     std::cout << "On the unit we have: " << core_count << " cores." << std::endl;

     std::vector<std::vector<long long int>> divided_vectors(core_count);

     auto it = numbers_to_check.begin();
     for (unsigned int i = 0; i < core_count; i++)
     {
          divided_vectors[i] = std::vector<long long int>(it, (it + (vector_size / core_count)));
          it += vector_size / core_count;
     }

     std::vector<std::thread> threads;
     int thread_number = core_count;

     //######################
     //   Trial-division
     //######################

     std::cout << "Threads make Trial-Division if the numbers are prime." << std::endl;

     steady_clock::time_point t1 = steady_clock::now();
     for (int i = 0; i < thread_number; i++)
     {
          threads.push_back(thread(Thread_handler, divided_vectors[i]));
     }
     steady_clock::time_point t2 = steady_clock::now();

     for (auto &thread : threads)
     {
          thread.join();
     }
     std::cout << "It takes time: " << duration_cast<duration<double>>(t2 - t1).count() * 1000 << "miliseconds. " << std::endl;

     threads.clear();

     //######################
     //   Miller-Rabin
     //######################

     std::cout << "Threads make Miller-Rabin test if the numbers are prime." << std::endl;

     t1 = steady_clock::now();
     for (int i = 0; i < thread_number; i++)
     {
          threads.push_back(thread(Thread_handler_rabin, divided_vectors[i]));
     }
     t2 = steady_clock::now();

     for (auto &thread : threads)
     {
          thread.join();
     }
     std::cout << "It takes time: " << duration_cast<duration<double>>(t2 - t1).count() * 1000 << "miliseconds. " << std::endl;

     return 0;
}