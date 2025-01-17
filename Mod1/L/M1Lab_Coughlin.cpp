/**
 * CSC249
 * M1Lab - Optimization
 * Harley Coughlin
 * 01/13/2025
 */

#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Food {
 private:
    string name;
    int value;
    int calories;
    double density;

 public:
    Food(string n, int v, int c) : name(n), value(v), calories(c) {}

    const string get_name() const { return name; }
    const int get_value() const { return value; }
    const int get_cost() const { return calories; }
    const double get_density() const { return static_cast<double>(value) / calories; }

    friend ostream& operator<<(ostream& os, const Food& f) {
        os << f.name << ": <" << f.value << ", " << f.calories << ">";
        return os;
    }
};

vector<Food> build_menu(const vector<string>& names, const vector<int>& values,
                        const vector<int>& calories) {
    vector<Food> menu;
    for (int i = 0; i < values.size(); i++) {
        menu.emplace_back(Food(names[i], values[i], calories[i]));
    }
    return std::move(menu);
}

pair<vector<Food>, double> greedy(vector<Food>* items, int max_cost,
                                  function<double(const Food&)> key_function) {
    // Sort in place using the key_function
    sort(items->begin(), items->end(),
         [&key_function](const Food& a, const Food& b) {
         return key_function(a) > key_function(b);
        });

    vector<Food> result;
    double total_value = 0.0;
    int total_cost = 0;

    for (const Food& item : *items) {
        if (total_cost + item.get_cost() <= max_cost) {
            result.push_back(item);
            total_cost += item.get_cost();
            total_value += item.get_value();
        }
    }

    return make_pair(result, total_value);
}

void test_greedy(vector<Food>* items, int constraint,
                 function<double(const Food&)> key_function) {
    auto [taken, val] = greedy(items, constraint, key_function);
    cout << "Total value of items taken = " << val << endl;
    for (const Food& item : taken) {
        cout << setw(4) << item << '\n';
    }
    cout << endl;
}

void test_greedys(vector<Food>* foods, int max_units) {
    cout << "Use greedy by value to allocate " << max_units << " calories\n";
    test_greedy(foods, max_units, [](const Food& f) { return f.get_value(); });
    cout << "Use greedy by cost to allocate " << max_units << " calories\n";
    test_greedy(foods, max_units, [](const Food& f) { return 1.0 / f.get_cost(); });
    cout << "Use greedy by density to allocate " << max_units << " calories\n";
    test_greedy(foods, max_units, [](const Food& f) { return f.get_density(); });
}

int main() {
    vector<string> names = {"wine", "beer", "pizza", "burger", "fries", 
                           "cola", "apple", "donut"};
    vector<int> values = {89, 90, 95, 100, 90, 79, 50, 10};
    vector<int> calories = {123, 154, 258, 354, 365, 150, 95, 195};
    
    vector<Food> foods = build_menu(names, values, calories);
    test_greedys(&foods, 750);
    
    return 0;
}
