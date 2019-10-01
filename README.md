# Thuto
Modern header-only library meant to be easy to use without any depency except the std to add some simple and pratical feature. Example: expected, threadpool, timers etc.
Require c++17.

__Work in progress__

# List of all libs
- __Args__: Utilities for handling the arguments of a program => _TO DO_
- __CondVar__: Make it easier to use conditional variable => _TO DO_
- __Expected__: return the expected value or an error (can have multiple error types) => _TO IMPROVE_
- __NContainer__: Array (dynamic or static) wich can have N dimension to avoir use raw c style array or stuff like "std::vector<std::vector<int>>" instead have something like "Thuto::Vector<int, 2>" => _TO DO_
- __StringViewAlgo__: there is a lot of helper functions with std::string or null terminated string (const char*) but not a lot with std::string_view. It is here to fix that: functions to split, convertion etc. => _TO IMPROVE_ and _TO COMPLETE_
- __Threadpool__: A simple easy to use threadpool => _TO DO_
- __ThreadSafeVar__: Wrapper around a variable to make it safer to user in a multi-threaded context. (Even if sending messages between threads is better than sharing ressources between thread)
- __Timer__: timers wich can be pause, launch a callback after a timeout or in a regular interval. => DONE
- __Type__: Check types at compile time. => _TO COMPLETE_
- __Variant__: add features to a std::variant to make it more user friendly. => _TO DO_