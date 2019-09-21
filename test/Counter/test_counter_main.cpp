#include <iostream>
#include <string>
#include <cassert>
#include <list>

#include "Counter.hpp"

void test_basic_counter()
{
	Thuto::BasicCounter<int> counter;
	assert(counter.get() == 0);

	++counter;
	assert(counter.get() == 1);

	counter++;
	assert(counter.get() == 2);

	counter--;
	assert(counter.get() == 1);

	counter.reset();
	assert(counter.get() == 0);

	++counter;

	auto c = counter;
	assert(c.get() == 1);

	Thuto::BasicCounter<int> cc;
	cc = counter;
	assert(c.get() == 1);
}

void test_atomic_counter()
{
	Thuto::BasicAtomicCounter<int> counter;
	assert(counter.get() == 0);

	++counter;
	assert(counter.get() == 1);

	counter++;
	assert(counter.get() == 2);

	counter--;
	assert(counter.get() == 1);

	counter.reset();
	assert(counter.get() == 0);

	++counter;

	auto c = counter;
	assert(c.get() == 1);

	Thuto::BasicAtomicCounter<int> cc;
	cc = counter;
	assert(c.get() == 1);
}

void test_mutex_counter()
{
	Thuto::BasicMutexCounter<int> counter;
	assert(counter.get() == 0);

	++counter;
	assert(counter.get() == 1);

	counter++;
	assert(counter.get() == 2);

	counter--;
	assert(counter.get() == 1);

	counter.reset();
	assert(counter.get() == 0);

	++counter;

	auto c = counter;
	assert(c.get() == 1);

	Thuto::BasicMutexCounter<int> cc;
	cc = counter;
	assert(c.get() == 1);
}

void test_shared_mutex_counter()
{
	Thuto::BasicSharedMutexCounter<int> counter;
	assert(counter.get() == 0);

	++counter;
	assert(counter.get() == 1);

	counter++;
	assert(counter.get() == 2);

	counter--;
	assert(counter.get() == 1);

	counter.reset();
	assert(counter.get() == 0);

	++counter;

	auto c = counter;
	assert(c.get() == 1);

	Thuto::BasicSharedMutexCounter<int> cc;
	cc = counter;
	assert(c.get() == 1);
}

int main()
{
	test_basic_counter();
	test_atomic_counter();
	test_mutex_counter();
	test_shared_mutex_counter();
	std::cout << "All tests passed." << std::endl;
}