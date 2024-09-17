# Shared Pointers

1. Automatic memory management 
    - Keeps track of objects that point to the memory space (usecount).
    - When the last shared pointer that points to the memory is destroyed or reset, the memory is automatically freed.
2. Shared ownership
    - multiple objects can point to the same memory
3. Inheritance and Polymorphism
    - shared pointer in a base class that points to an object in a derived class
4. Custom cleanup
    - Can add a cleanup function to better tidy up when deleting pointers
