#pragma once

namespace thuto::functors
{

class OneEvery
{
	public:
		OneEvery(int frequence, int offset):
			_frequence(frequence),
			_offset(offset),
			_i(0)
		{}

		bool operator()(const auto&)
		{
			bool result = ((_i % _frequence) == _offset);
			++_i;
			return result;
		}
	private:
		int _frequence;
		int _offset;
		int _i;
};

}