/*
 * benchmark.h
 *
 *  Created on: Apr 11, 2024
 *      Author: KZ
 */

#ifndef BENCHMARK_H_
#define BENCHMARK_H_

#include <string>
#include <iostream>
#include <cstddef>


size_t get_current_virtual_memory();
size_t get_current_physical_memory();

struct Benchmark {
  size_t start_virtual_memory;
  size_t start_physical_memory;
  std::string name;
  Benchmark(std::string name): start_virtual_memory(get_current_virtual_memory()),
      start_physical_memory(get_current_physical_memory()),
      name(name) {}

  ~Benchmark() {
    size_t end_virtual_memory = get_current_virtual_memory();
    size_t end_physical_memory = get_current_physical_memory();

    std::cout<<"Benchmark "<<name<<": virtual "<< end_virtual_memory - start_virtual_memory <<
        " bytes, physical " << end_physical_memory - start_physical_memory << " bytes"<< std::endl;
  }
};


#endif /* BENCHMARK_H_ */
