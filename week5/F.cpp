#include <iostream>
#include <cstring>

char *resize(const char *buf, size_t size, size_t new_size) 
{ 
    char* new_buf = new char[new_size]; 
    std::memcpy(new_buf, buf, std::min(size, new_size)); 
    delete[] buf; 
    return new_buf; 
} 
 
int main() 
{ 
    char *a = new char[10]; 
    resize(a, 10, 5);
}