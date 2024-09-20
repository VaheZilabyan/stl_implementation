#include <iostream>

#include "allocator.h"
#include "vector.h"

int main()
{
    using std::cout;
    using std::endl;
    using namespace myStl;
    using namespace myVectorAllocator;
    using my_vector = vector<int, allocator<int>>;

    allocator<int> alloc;
    my_vector vec ({1,2,3,4,5}, alloc);

    //vector<int> vec = {1,2,3,4,5};
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    cout << "capacity = " << vec.capacity() << endl;
    //vec.pop_back();
    //vec.pop_back();

    my_vector::iterator it = vec.begin();
    ++it;
    auto pos = vec.insert(it, 99);

    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    } cout << endl;

    cout << "end..." << endl;
    return 0;
}
