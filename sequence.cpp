#include "sequence2.h"
#include <cassert>

using namespace main_savitch_4;

sequence::sequence(sequence::size_type initial_capacity)
{
    data = new value_type[initial_capacity];
    used = 0;
    capacity = initial_capacity;
}

sequence::sequence(const sequence& source)
{
    data = new value_type[source.size()];
    std::memcpy(data, source.data, sizeof(size_type) * source.size());
    used = source.used;
    current_index = source.current_index;
    capacity = source.capacity;
}

sequence::~sequence()
{
    delete[] data;
}

void sequence::resize(size_type new_capacity)
{
    value_type* tempData = new value_type[new_capacity];
    memcpy(tempData, data, sizeof(size_type) * capacity);
    data = new value_type[new_capacity];
    memcpy(data, tempData, sizeof(size_type) * capacity);
    
    capacity = new_capacity;
}

void sequence::start()
{
   current_index = 0;
}

void sequence::advance()
{
    assert(is_item() == true);
    current_index++;
}

void sequence::insert(const value_type& entry)
{
    if (used == capacity && capacity != 0)
    {
        resize(capacity + ((capacity) / 10)); // increses the size of the array by 10%
    }
    
    if (current_index == used)
    {
        current_index = 0;
    }
    
    assert(used < capacity);
    if (used > 0)
    {
        for (size_type i = used + 1; i > current_index; i--)
        {
            data[i] = data[i - 1];
        }
        
        data[current_index] = entry;
    }
    else
    {
        start();
        data[current_index] = entry;
    }
    used++;
}

void sequence::attach(const value_type& entry)
{
    if (used == capacity && capacity != 0)
    {
        resize(capacity + ((capacity) / 10)); // increses the size of the array by 10%
    }
    
    if (current_index == used)
    {
        current_index = used - 1;
    }
    
    assert(used < capacity);
    if (used > 0)
    {
        for (size_type i = used + 1; i > current_index + 1; i--)
        {
            data[i] = data[i - 1];
        }
        
        data[current_index + 1] = entry;
        current_index++;
    }
    else
    {
        start();
        data[current_index] = entry;
        current_index = 0;
    }
    
    used++;
}

void sequence::remove_current()
{
    assert(is_item() == true);
    for (size_type i = current_index; i < used; i++)
    {
        data[i] = data[i + 1];
    }
    used--;
}

void sequence::operator=(const sequence& other)
{
    if (this != &other)
    {
        data = new value_type[other.size()];
        std::memcpy(data, other.data, sizeof(size_type) * other.size());
        used = other.used;
        current_index = other.current_index;
        capacity = other.capacity;
    }
}

sequence::size_type sequence::size() const
{
    return used;
}

bool sequence::is_item() const
{
    if (current_index < used) { return true; }
    else                      { return false; }
}

sequence::value_type sequence::current() const
{
    return data[current_index];
}


