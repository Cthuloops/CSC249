 #ifndef SORTING_SORTSTRATEGY_HPP_
#define SORTING_SORTSTRATEGY_HPP_

#include <functional>
#include <vector>

template<typename T>
class SortStrategy {
 public:
    virtual std::vector<T> sort(const std::vector<T>& data,
                                std::function<bool(const T&, const T&)> compare) = 0;
    virtual ~SortStrategy() = default;
};

#endif  // SORTING_SORTSTRATEGY_HPP_
