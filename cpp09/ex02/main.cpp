#include "PmergeMe.hpp"

long long getTimeInMicroseconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return static_cast<long long>(tv.tv_sec) * 1000000 + tv.tv_usec;
}

int main( int argc, char **argv) {
    if (argc == 1) {
        std::cout << "This program ask for a sequence of integers as argument." << std::endl;
        return (0);
    }
    argv++;
    std::list<int>	lst;
    std::deque<int>	dqe;
    try {
        parseInput<std::list<int> >(lst, argv);
        parseInput<std::deque<int> >(dqe, argv);
    } catch (std::exception & e) {
        std::cout << "Error: " << e.what() << std::endl;
        return (0);
    }
    std::cout << "Before:\t";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << " " << *it;
    std::cout << std::endl;

    std::clock_t list_start_time = std::clock();
    fordJohnsonAlgorithm(lst);
    std::clock_t  list_end_time = std::clock();


    std::clock_t  deque_start_time = std::clock();
    fordJohnsonAlgorithm(dqe);
    std::clock_t  deque_end_time = std::clock();

    std::cout << list_start_time << " " << list_end_time << std::endl;

    std::cout << "After:\t";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << " " << *it;
    std::cout << std::endl;

    double list_res_time = (static_cast<double>(list_end_time - list_start_time) * 1000) / (double)CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << lst.size()  << " elements with std::list<int>  : " << list_res_time << " ms" << std::endl;
	
    double deque_res_time = (static_cast<double>(deque_end_time - deque_start_time) * 1000) / (long double)CLOCKS_PER_SEC  ;
    std::cout << "Time to process a range of " << lst.size()  << " elements with std::deque<int> : " << deque_res_time << " ms" << std::endl;

    return (0);
}