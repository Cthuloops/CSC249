#ifndef SORTING_SORTSTRATEGYFACTORY_HPP_
#define SORTING_SORTSTRATEGYFACTORY_HPP_

#include "./interfaces/SortStrategy.hpp"
#include "./strategies/SelectionSort.hpp"

namespace SF {
enum Strategy {
    SELECTION
};
}  // namespace SF


namespace StrategyFactory {
template<typename T>
inline SortStrategy<T>* create_strategy(const SF::Strategy& strategy) {
    switch (strategy) {
        case SF::SELECTION:
            return new Selection<T>();
        default:
            return nullptr;  // Should never have a nullptr returned
    }
}
}  // namespace StrategyFactory

#endif  // SORTING_SORTSTRATEGYFACTORY_HPP_
