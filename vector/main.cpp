#include <iostream>

#include "allocator.h"
#include "vector.h"

int main()
{
    using std::cout;
    using std::endl;
    using namespace myStl;
    using namespace myVectorAllocator;

    //allocator<int> alloc;
    //vector<int, allocator<int>> vec ({1,2,3,4,5}, alloc);

    vector<int> vec = {1,2,3,4,5};
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    cout << "capacity = " << vec.capacity() << endl;
    //vec.pop_back();
    //vec.pop_back();
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    } cout << endl;

    vector<int>::iterator it = vec.begin();
    ++it;
    cout << "*it = " << *it << endl;

    cout << "end..." << endl;
    return 0;
}
