/*
 * benchmark.cpp
 *
 *  Created on: Apr 11, 2024
 *      Author: KZ
 */

#include "benchmark.h"

#include "windows.h"
#include "psapi.h"

size_t get_current_virtual_memory() {
  PROCESS_MEMORY_COUNTERS_EX pmc;
  GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
  SIZE_T virtualMemUsedByMe = pmc.PrivateUsage;
  return virtualMemUsedByMe;
}

size_t get_current_physical_memory() {
  PROCESS_MEMORY_COUNTERS_EX pmc;
  GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
  SIZE_T physMemUsedByMe = pmc.WorkingSetSize;
  return physMemUsedByMe;
}
