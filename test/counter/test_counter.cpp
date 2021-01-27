#include <iostream>
#include <string>
#include <cassert>
#include <list>

#include <Thuto/utils/Counter.hpp>

void test_basic_counter()
{
	thuto::BasicCounter<int> counter;
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

	thuto::BasicCounter<int> cc;
	cc = counter;
	assert(c.get() == 1);
}

void test_atomic_counter()
{
	thuto::BasicAtomicCounter<int> counter;
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

	thuto::BasicAtomicCounter<int> cc;
	cc = counter;
	assert(c.get() == 1);
}

void test_mutex_counter()
{
	thuto::BasicMutexCounter<int> counter;
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

	thuto::BasicMutexCounter<int> cc;
	cc = counter;
	assert(c.get() == 1);
}

void test_shared_mutex_counter()
{
	thuto::BasicSharedMutexCounter<int> counter;
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

	thuto::BasicSharedMutexCounter<int> cc;
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