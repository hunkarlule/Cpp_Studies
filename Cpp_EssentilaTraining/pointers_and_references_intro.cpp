
#include <format>
#include <iostream>

// a variable is a typed and named location in memory.

using std::format;
using std::cout;

int main() {
    
    // a variable is a typed and named location in memory.
    // here, we defined variable i. memory is allocated for a value of type integer and it is associated with the name i.
    // name of a varibale is used as an index to map to a memory address and a specific data type.
    int i;
    //here integer value 1 coped into the memory location associated with integer i.
    i = 1;

    // here, we defined variable j. memory is allocated for a value of type integer and it is associated with the name j.
    // j represents another integer in a different memory location than i.
    int j;
    
    // assignemnt
    // value from i is copied to varibale named j.
    // now j contains a seperate integer  in a sepearte memory location with the same valis as the variable i.
    j = i;

    // pointer type: it is "pointer to a value" as opposed to carrying the value itself.
    // this is a pointer definition.
    // a pointer holds the memory address of another variable.
    // here pointer names as" prt" and it is type is : "pointer to int"(shortly int pointer or integer pointer)
    // so memory is allocated to hold a pointer not an int.
    // pointer is also strognly typed. This means compiler associates this pointer(ptr) with a value of type int.
    int* ptr;
    //int * ptr; // same as above
    //int *ptr; // same as above

    i = 45;

    // here we assing address of variable i to pointer prt.
    // & is "address of" operator. it returns  address of the object that can be assigned to a pointer.
    // so ptr now holds the address of integer variable i. 
    // in another way, ptr points to variable i. 
    ptr = &i;


    // here we deferencing the pointer. * ==> is dereference operator.
    // with this, we access the value pointed by the pointer.
    j = *ptr; // this is same as writing j = i;

  
    int x {7};
    int y {42};
    int* ip = &x; // measn that pointer ip points to variable x.

    cout << format("The value of x is {}\n", x);
    cout << format("The value of y is {}\n", y);
    cout << format("The value of *ip is {}\n", *ip);

    x = 73;
    cout << format("The value of x is {}\n", x);
    cout << format("The value of y is {}\n", y);
    cout << format("The value of *ip is {}\n", *ip); // so this will also pirnt 73 because we assigned x to 73 above.

    ip = &y; // now we reassigned the pointer with the address of y. now, ip points to variable y.

    cout << format("The value of x is {}\n", x);
    cout << format("The value of y is {}\n", y);
    cout << format("The value of *ip is {}\n", *ip); 

    // references are similar to pointers but also very different.
    int m{ 7 };
    int* iprt = &m; // meansthat pointer ip points to variable x.

    // here n is a reference. it is type is reference to int( or shortly: int reference)
    // n is reference to an int. it references n.
    int& n = m;

    cout << format("The value of m is {}\n", m);
    cout << format("The value of n is {}\n", n);
    cout << format("The value of *iprt is {}\n", *iprt);

    m = 42; // we changed the value of m. see that n also changed because it references m.
    cout << format("The value of m is {}\n", m);
    cout << format("The value of n is {}\n", n);
    cout << format("The value of *iprt is {}\n", *iprt);

    // here we assigned n(reference) to 45. 
    // see that value of m is also cahnged to 45.
    // because n is based on m. and it isa namealias/ nickname for the m indeed.
    // difference between pointer and reference: we do not need to dereference operator(*) to deference a reference.
    // value of the reference is always the value of referred variable.
    // there is no syntax for changing the reference. once it is defined it cannot not be changed. For example here:
    // we defined reference n to reference m above. After that point we cannot change it to referenece another vairable.
    // It will alwys reference the m.
    // Indeed, a reference is not a real variable/object. It si just a syntax trick. It like an alias/nickname for a variable.
    // a reference is an enrty in the name space without any value of its own.
    n = 45; 
    cout << format("The value of m is {}\n", m);
    cout << format("The value of n is {}\n", n);
    cout << format("The value of *iprt is {}\n", *iprt);

    // we can reassing the pointer to point to another thing.
    // this is called receeding the pointer.
    int z = { 73 };
    iprt = &z; // not iptr is pointing to z instead of m.

    cout << format("The value of m is {}\n", m);
    cout << format("The value of n is {}\n", n);
    cout << format("The value of *iprt is {}\n", *iprt);


    // here we dereferenced iptr(*iptr) and assigned a new value to it
    // we basically assigned a new value to the variable that iptr points to.
    *iprt = 75; 
     // z = 57 //same as above line because iptr points to z.
    cout << format("The value of m is {}\n", m);
    cout << format("The value of n is {}\n", n);
    cout << format("The value of *iprt is {}\n", *iprt);

    iprt = &m; // now iprt points to m again.
    *iprt = 42; // here dereferenceing implies us that we are cahgning the value of the variable that iprt points to
    cout << format("The value of m is {}\n", m);
    cout << format("The value of n is {}\n", n);
    cout << format("The value of *iprt is {}\n", *iprt);



    // here there is nothing here that tells us we are changing something else(in this case m because n refers to m)
    // it looks like we changing a variable called the n but it not the case.
    // so this could be dangerus to degug if there is any error.
    n  = 47; // there is nothing(not a cule) that impiles that we are changinh m here indeed.
    cout << format("The value of m is {}\n", m);
    cout << format("The value of n is {}\n", n);
    cout << format("The value of *iprt is {}\n", *iprt);

  // therfore it ialways a good practice to define the references as const like below:
   // with const, that means we cannot use the reference r ro cahnge the value of underlying varibale(m)
    const int& r = m;
    cout << format("The value of m is {}\n", m);
    cout << format("The value of r is {}\n", r);
    cout << format("The value of *iprt is {}\n", *iprt);


    m = 44; // this is OK because m is not const.
    //r = 43; // compiler error becase r is const reference.
    cout << format("The value of m is {}\n", m);
    cout << format("The value of r is {}\n", r);
    cout << format("The value of *iprt is {}\n", *iprt);


}
