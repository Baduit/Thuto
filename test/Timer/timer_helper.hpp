#pragma once

inline int64_t nanoToMilli(int64_t nano)
{
	return nano / 1000000;
}

template<typename T, typename U>
bool almost_equal(T t, U u)
{
    if (t <= (u + 2) && t >= (u - 2))
        return true;
    return false;
}