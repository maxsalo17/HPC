#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include "mpi.h"

using namespace std;

int main(int argc, char *argv[])
{
    MPI_Init(NULL, NULL);

    // Get the name of the processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    string line;
    ifstream index0("/sys/devices/system/cpu/cpu0/cache/index0/size");
    if (index0.is_open())
    {
        while (getline(index0, line))
        {
            cout << processor_name << ": Level 1 icache size = " << line << "\n";
        }
        index0.close();
    }

    ifstream index1("/sys/devices/system/cpu/cpu0/cache/index1/size");
    if (index1.is_open())
    {
        while (getline(index1, line))
        {
            cout << processor_name << ": Level 1 dcache size = " << line << "\n";
        }
        index1.close();
    }

    ifstream index2("/sys/devices/system/cpu/cpu0/cache/index2/size");
    if (index2.is_open())
    {
        while (getline(index2, line))
        {
            cout << processor_name << ": Level 2 cache size = " << line << "\n";
        }
        index2.close();
    }

    ifstream index3("/sys/devices/system/cpu/cpu0/cache/index3/size");
    if (index3.is_open())
    {
        while (getline(index3, line))
        {
            cout << processor_name << ": Level 3 cache size = " << line << "\n";
        }
        index3.close();
    }

    // Finalize the MPI environment. No more MPI calls can be made after this
    MPI_Finalize();
    return 0;
}
