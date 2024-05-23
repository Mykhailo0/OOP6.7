#include <iostream>
#include <vector>
#include <algorithm>


template<typename InputIt1, typename InputIt2>
InputIt1 search_end(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2) {
    if (first2 == last2) {
        return last1;
    }

    InputIt1 result = last1;
    while (true) {
        InputIt1 it = std::find_end(first1, last1, first2, last2);
        if (it == last1) {
            break;
        }
        result = it;
        first1 = std::next(it);
    }
    return result;
}


template<typename InputIt1, typename InputIt2, typename Predicate>
InputIt1 search_end_if(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Predicate pred) {
    if (first2 == last2) {
        return last1;
    }

    InputIt1 result = last1;
    while (true) {
        InputIt1 it = std::find_end(first1, last1, first2, last2, pred);
        if (it == last1) {
            break;
        }
        result = it;
        first1 = std::next(it);
    }
    return result;
}

int main() {
    std::vector<int> sequence1 = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 2, 4, 6 };
    std::vector<int> pattern = { 2, 4, 6 };

    auto result = search_end(sequence1.begin(), sequence1.end(), pattern.begin(), pattern.end());

    if (result != sequence1.end()) {
        std::cout << "Last occurrence of pattern found at index: " << std::distance(sequence1.begin(), result) << std::endl;
    }
    else {
        std::cout << "Pattern not found." << std::endl;
    }


    auto even_predicate = [](int a, int b) { return a == b && a % 2 == 0; };
    auto result_if = search_end_if(sequence1.begin(), sequence1.end(), pattern.begin(), pattern.end(), even_predicate);

    if (result_if != sequence1.end()) {
        std::cout << "Last occurrence of pattern with even condition found at index: " << std::distance(sequence1.begin(), result_if) << std::endl;
    }
    else {
        std::cout << "Pattern with even condition not found." << std::endl;
    }

    return 0;
}