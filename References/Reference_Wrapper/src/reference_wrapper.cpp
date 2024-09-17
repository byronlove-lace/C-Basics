#include <string>
#include <iostream>
#include <typeinfo>
#include <functional>

class Brick
{
	private:
	std::string color;

	public:
	Brick() : color("Red") {};
};

class Block
{
	private:
	std::string color;
	int length;

	public:
	Block() : color("Grey"), length(50) {};
};

int main ()
{
	Brick brick;
	Block block;

	// reference 
	int x = 5;
	int& y = x;
	const int& z = 5;
	int& w = y;
	// const int& z = z; <- can't rebind

	
	// Pointer
	int* ptr;
	int num = 5;
	ptr = &num;

	// Referece Wrapper
	int k = 5;
	std::reference_wrapper<int> ref1(k);
	std::reference_wrapper<int> ref2(ref1);

	int lmao = 10;
	int& lmaoRef = lmao;

	std::reference_wrapper<int> rwLmao(lmaoRef);
	std::reference_wrapper<int> rw2Lmao(lmao);



	/*
	>>This is not possible
	>>C++ ref can only be bound once 
	newBrick = block;
	std::cout << typeid(newBrick).name() << std::endl;
	*/

	/*
	This is awkward
	auto& specialBrick = [&]() -> auto&
	{
		if (x = 1) {return block;}
		else {return brick;}
	}();
	*/

	/*
	// This is retrograde
	// And it doesn't work
	auto *pBrick = &brick;
	if (x = 0) {pBrick = &block;}
	*/

	/*
	 This is modern but it looks like ass
	std::unique_ptr<what> pBrick(new auto(brick));
	pBrick.reset(new auto(block));
	*/
}
