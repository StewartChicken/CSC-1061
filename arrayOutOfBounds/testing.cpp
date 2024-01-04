#include <iostream>
#include <cassert>
#include "myArray.h"

using namespace std;

int main(){

    // Testing two parameter constructor
    myArray list1(5, 7);

    // Testing getSize method
    assert(list1.getSize() == 2);

    // Checking start index of array
    assert(list1.getStart() == 5);
    
    // Testing index assignment
    assert(list1[5] == 0);
    assert(list1[6] == 0);

    // Testing index access
    list1[5] = 1;
    list1[6] = 2;
    assert(list1[5] == 1);
    assert(list1[6] == 2);

    // Testing negative index use
    myArray list2(-5, -2);

    // Testing size for array with negative index
    assert(list2.getSize() == 3);

    // Checking start index of array
    assert(list2.getStart() == -5);

    // Test index access for negative index
    assert(list2[-5] == 0);
    assert(list2[-4] == 0);
    assert(list2[-3] == 0);

    // Test negative index assignment
    list2[-5] = 10;
    list2[-4] = 9;
    list2[-3] = 8;
    assert(list2[-5] == 10);
    assert(list2[-4] == 9);
    assert(list2[-3] == 8);

    // Test assignment overload
    myArray list3 = list2;

    //Ensuring list3 functions as expected
    assert(list3.getSize() == 3);
    list3[-5] = 8;
    assert(list3[-5] == 8);
    assert(list3[-4] == 9);
    assert(list3[-3] == 8);

    // Testing single paramater constructor
    myArray list4(3);

    // Checking size
    assert(list4.getSize() == 3);
    
    // Checking first index value
    assert(list4.getStart() == 0);

    // Checking default values
    assert(list4[0] == 0);
    assert(list4[1] == 0);
    assert(list4[2] == 0);

    // Checking assignment
    list4[0] = 20;
    list4[1] = 21;
    list4[2] = 22;
    assert(list4[0] == 20);
    assert(list4[1] == 21);
    assert(list4[2] == 22);

    // Testing index out of bounds messages

    // Expected output: "Index out of bounds! You cannot access indeces outside of the range [-5, 2)"
    int x = list2[-6] = 8;

    // Expected output: "Index out of bounds! You cannot access indeces outside of the range [0, 3)"
    int y = list4[4] = 5;

    std::cout << std::endl;

    std::cout << "All test cases passed\n";

    return 0;
}
