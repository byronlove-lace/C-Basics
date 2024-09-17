#include <iostream>

using std::cout;
using std::endl;

class BaseClass
{
        public:
                int _public_member;

        protected:
                int _protected_member;

        private:
                int _private_member;
};

// Can access public and protected members
// Can't access private members of base class
// public = public / protected = protected / private = private
class PublicDerived : public BaseClass
{
        public:
                void member()
                {
                        // _private_member = 20; /* NOT POSSIBLE */
                        _protected_member = 40;
                        _public_member = 60;
                }
};

// Can access public and protected.
// Can't access private members of base class
// public = protected / protected = protected / private = private
// **We use this when we want to make it so that the variables of our 
//   subclass cannot be modified outside of that class**
class ProtectedDerived : protected BaseClass
{
        public:
                void member()
                {
                        // _private_member = 20; /* NOT POSSIBLE */
                        _protected_member = 40;
                        _public_member = 60;
                }
};

// Can access public and protected members
// Can't access private members of base class
// public = private / protected = private / private = private
// NB The variables all become private members OF THIS CLASS!
class PrivateDerived : private BaseClass
{
        public:
                void member()
                {
                        // _private_member = 20; /* NOT POSSIBLE */
                        _protected_member = 40; /*POSSIBLE*/
                        _public_member = 60; /*POSSIBLE*/
                }
};

class PublicNextLevel : public PublicDerived
{
        public:
                void member()
                {
                        //  _private_member = 20; /* NOT POSSIBLE */
                        _protected_member = 40; /*POSSIBLE*/
                        _public_member = 60; /*POSSIBLE*/
                }
};

class ProtectedNextLevel : public ProtectedDerived
{
        public:
                void member()
                {
                        //  _private_member = 20; /* NOT POSSIBLE */
                        _protected_member = 40; /*POSSIBLE*/
                        _public_member = 60; /*POSSIBLE*/
                }
};

class PrivateNextLevel : public PrivateDerived
{
                void member()
                {
                        // _private_member = 20; /* NOT POSSIBLE */
                        // _protected_member = 40; /*NOT POSSIBLE*/
                        // _public_member = 60; /*NOT POSSIBLE*/
                }
};


int main()
{
        PublicDerived pubDerived;
        pubDerived._public_member = 5;
        // pubDerived._protected_member = 66; /* NOT POSSIBLE */
        // pubDerived._private_member = 400; /* NOT POSSIBLE */

        ProtectedDerived protDerived;
        // protDerived._public_member = 5; /* NOT POSSIBLE */
        // protDerived._protected_member = 66; /* NOT POSSIBLE */
        // protDerived._private_member = 400; /* NOT POSSIBLE */
        
        PrivateDerived privDerived;
        // privDerived._public_member = 5; /* NOT POSSIBLE */
        // privDerived._protected_member = 66; /* NOT POSSIBLE */
        // privDerived._private_member = 400; /* NOT POSSIBLE */
}
