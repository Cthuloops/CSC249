#ifndef SORTING_SORTER_HPP_
#define SORTING_SORTER_HPP_

#include <vector>
#include "./SortStrategy.hpp"


template<typename T>
class Sorter {
 private:
    SortStrategy<T>* strategy;

 public:
    Sorter() : strategy(nullptr) {}
    ~Sorter() { delete strategy; }

    void set_strategy(SortStrategy<T>* new_strategy) {
        delete strategy;
        strategy = new_strategy;
    }

    std::vector<T> sort_ascending(const std::vector<T>& data) const {
        std::vector<T> sorted;
        if (strategy) {
            // Lambda for element comparison
            sorted = strategy->sort(data, [](const T& first, const T& second) {
                return first > second;
            });
        }
        return sorted;
    }

    std::vector<T> sort_descending(const std::vector<T>& data) const {
        std::vector<T> sorted;
        if (strategy) {
            // Lambda for element comparison
            sorted = strategy->sort(data, [](const T& first, const T& second) {
                return first < second;
            });
        }
        return sorted;
    }
};
#endif  // SORTING_SORTER_HPP_
