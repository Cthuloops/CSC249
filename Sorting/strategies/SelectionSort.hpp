/**
 * Selection sort implementation.
 * Harley Coughlin
 * CSC249
 * 01/25/2025
 */
#ifndef SORTING_SELECTIONSORT_HPP_
#define SORTING_SELECTIONSORT_HPP_

#include <functional>
#include <utility>
#include <vector>
#include "../interfaces/SortStrategy.hpp"

template<typename T>
class Selection : public SortStrategy<T> {
 public:
    std::vector<T> sort(const std::vector<T>& data,
                        std::function<bool(const T&, const T&)> compare) override {
        std::vector<T> sorted = data;
        for (size_t i = 0; i < sorted.size() - 1; i++) {
            size_t smallest_index = i;
            for (size_t j = i + 1; j < sorted.size(); j++) {
                if (compare(sorted[smallest_index], sorted[j])) {
                    smallest_index = j;
                }
            }
            std::swap(sorted[i], sorted[smallest_index]);
        }
        return sorted;
    }
};
#endif  // SORTING_SELECTIONSORT_HPP_
