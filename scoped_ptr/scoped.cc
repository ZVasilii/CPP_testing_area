#include "scoped.hh"

struct Load_t
{
	int integer_;
	double real_;

	Load_t(int integer = 0, double real = 0) : integer_(integer), real_(real)
	{}
};

Pointer::ScopedPtr<Load_t> foo()
{
	Pointer::ScopedPtr<Load_t> tmp{0};
	return tmp;
}

int main()
{
	Pointer::ScopedPtr<Load_t> sc(10);
	Pointer::ScopedPtr<Load_t> copy_1{sc};
	Pointer::ScopedPtr<Load_t> copy_2 = sc;
	copy_1 = copy_2;
	Pointer::ScopedPtr<Load_t> move_2{foo()};
	Pointer::ScopedPtr<Load_t> move_3 = foo();
	copy_1 = foo();

	return 0;

}