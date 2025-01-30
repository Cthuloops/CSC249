#ifndef SORTING_SORTSTRATEGYFACTORY_HPP_
#define SORTING_SORTSTRATEGYFACTORY_HPP_

#include <utility>
#include "./interfaces/SortStrategy.hpp"
#include "./strategies/SelectionSort.hpp"

typedef enum Strat {
    SELECTION
} Strat;

template<typename T>
class StrategyFactory {
 public:
    static SortStrategy<T>* create_strategy(const Strat& strategy) {
        switch (strategy) {
            case SELECTION:
                return std::move(new Selection<T>);
        }
    }
};


#endif  // SORTING_SORTSTRATEGYFACTORY_HPP_
