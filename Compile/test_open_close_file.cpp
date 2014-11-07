#include "fileworking.h"


int main()
{
    char* buffer = 0;
    long length = 0;
    read_file("input.txt", &buffer, &length);

    write_file("output.txt", &buffer, length);
}