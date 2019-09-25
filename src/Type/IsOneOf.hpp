#pragma once

namespace Thuto
{

template <typename...>
struct IsOneOf {
    static constexpr bool value = false;
};

template <typename F, typename S, typename... T>
struct IsOneOf<F, S, T...> {
    static constexpr bool value =
        std::is_same<F, S>::value || IsOneOf<F, T...>::value;
};

}