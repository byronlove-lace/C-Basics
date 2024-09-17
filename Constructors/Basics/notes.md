In Java, primatives are initialized by default.
This is **not** the case for C++. 
You need to manually initialize your primitive types.
With initializer lists, you need to add the members in order.
Initializer lists can make it easer to make compact initialization.
If you don't use an initializer list and you have another class object within your class:

class Entity
{
    private:
        Example mExample;
    public:
        Entity()
        {
            mExample = Example(8)
        }
}

You will create two instances of Example. One in for mExample with the default initializer and one for Example(8). **This is shit; don't do this** Use init lists.
