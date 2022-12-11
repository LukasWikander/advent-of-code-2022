#include <iostream>

#include "CommandListing.hpp"
#include "FileSystemMap.hpp"

int main(int argc, char** argv)
{
    CommandListing listing{argv[1]};
    FileSystemMap map{listing};
    return 0;
}