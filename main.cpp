//
//  main.cpp
//  Algorithms
//
//  Created by Jiandong Huang on 7/9/2018.
//  Copyright © 2018 Jiandong Huang. All rights reserved.
//

#include <iostream>
#include "LinkListChapter.hpp"
#include "recursion.hpp"
#include "practiceConfig.h"
#include "DynamicProgramming.hpp"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <vector>
#include <string>

int main(int argc, const char * argv[]) {
    if (argc < 2) {
    	// report version
    	std::cout << argv[0] << " Version " << practice_VERSION_MAJOR << "."
        	      << practice_VERSION_MINOR << std::endl;
    	std::cout << "Usage: " << argv[0] << " number" << std::endl;
    	return 1;
  	}
  	// insert code here...
    std::cout << "Hello, World!\n";
    auto t_start = std::chrono::high_resolution_clock::now();
    int fib_ret = fib(100);
    auto t_end = std::chrono::high_resolution_clock::now();
    int fib_forward_ret = fib_forward(100);
    auto t_end_f = std::chrono::high_resolution_clock::now();
    int fib_s = fib_speed(100);
    auto t_end_s = std::chrono::high_resolution_clock::now();
    std::cout << "fib ret " << std::to_string(fib_ret)
              << "time: " <<  std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_start).count()
              <<std::endl;
    std::cout << "fibforward ret " << std::to_string(fib_forward_ret)
              << "time: " << std::chrono::duration_cast<std::chrono::microseconds>(t_end_f - t_end).count()
              << std::endl;
    std::cout << "fibspeed ret " << std::to_string(fib_s)
              << "time: " << std::chrono::duration_cast<std::chrono::microseconds>(t_end_s - t_end_f).count()
              << std::endl;
    
    // largest of increasing dsequences
    int inputSeq[22] = {1,2,2,3,2,4,5,9,3,5,2,67,4,7,5,32,5,7,2,4,65,3};
    std::vector<int> testSeq(inputSeq, inputSeq + 22);
    //for (int i = 0; i < testSeq.size(); i ++) {
    //    std::cout << "test input sequence: " << testSeq[i] << std::endl;
    //}
    
    int ret = LengthOfLIS(testSeq);
    std::cout << "LengthOfLIS: " << ret << std::endl;
    std::cout << "int(1.9): " << int(1.9) << std::endl;
    
    return 0;
}
