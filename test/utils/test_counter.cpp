#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <thuto/utils/Counter.hpp>

TEST_CASE("test_basic_counter")
{
	thuto::BasicCounter<int> counter;
	CHECK(counter.get() == 0);

	++counter;
	CHECK(counter.get() == 1);

	counter++;
	CHECK(counter.get() == 2);

	counter--;
	CHECK(counter.get() == 1);

	counter.reset();
	CHECK(counter.get() == 0);

	++counter;

	auto c = counter;
	CHECK(c.get() == 1);

	thuto::BasicCounter<int> cc;
	cc = counter;
	CHECK(c.get() == 1);
}

TEST_CASE("test_atomic_counter")
{
	thuto::BasicAtomicCounter<int> counter;
	CHECK(counter.get() == 0);

	++counter;
	CHECK(counter.get() == 1);

	counter++;
	CHECK(counter.get() == 2);

	counter--;
	CHECK(counter.get() == 1);

	counter.reset();
	CHECK(counter.get() == 0);

	++counter;

	auto c = counter;
	CHECK(c.get() == 1);

	thuto::BasicAtomicCounter<int> cc;
	cc = counter;
	CHECK(c.get() == 1);
}

TEST_CASE("test_mutex_counter")
{
	thuto::BasicMutexCounter<int> counter;
	CHECK(counter.get() == 0);

	++counter;
	CHECK(counter.get() == 1);

	counter++;
	CHECK(counter.get() == 2);

	counter--;
	CHECK(counter.get() == 1);

	counter.reset();
	CHECK(counter.get() == 0);

	++counter;

	auto c = counter;
	CHECK(c.get() == 1);

	thuto::BasicMutexCounter<int> cc;
	cc = counter;
	CHECK(c.get() == 1);
}

TEST_CASE("test_shared_mutex_counter")
{
	thuto::BasicSharedMutexCounter<int> counter;
	CHECK(counter.get() == 0);

	++counter;
	CHECK(counter.get() == 1);

	counter++;
	CHECK(counter.get() == 2);

	counter--;
	CHECK(counter.get() == 1);

	counter.reset();
	CHECK(counter.get() == 0);

	++counter;

	auto c = counter;
	CHECK(c.get() == 1);

	thuto::BasicSharedMutexCounter<int> cc;
	cc = counter;
	CHECK(c.get() == 1);
}