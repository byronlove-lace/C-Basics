# References 

# References vs Pointers
1. References can't be NUll.
    - int &illegalRef = Null; **ILLEGAL**
    - int &illegalRef = intThatExists; **LEGAL**
2. You cannot change the variable that is referenced by a ref.
    - int &ref = i; **LEGAL**
    - int &ref = otheri; **ILLEGAL**
    - Once a ref is associated with a var it is that way forever
3. You cannot do math with references (No pointer arithmatic)
    - int &ref = i; **LEGAL**
    - int &ref2 = &i+4; **ILLEGAL**
4. You cant have references to references 
    **LEGAL**
    - int x = 1;
    - int *pX = &x;
    - int **ppX = &pX;
    **ILLEGAL**
    - int &ref = x;
    - int &&rRef = ref;

Functionally, reference is just a pointer with Syntactic Suger (mmm).
**WHY:** References require less overhead once the ref is set up

**This is a Reference**
- int a = 5;
- int& ref = 5; // note that it's beside the type 
                // (like a pointer declaration)
**This is an address**
- int* b = &a; // note that it's beside the var

