#pragma once

inline int64_t nanoToMilli(int64_t nano)
{
	return nano / 1000000;
}

template<typename T, typename U>
bool almost_equal(T t, U u)
{
    if (t <= (u + 5) && t >= (u - 5))
        return true;
    return false;
}