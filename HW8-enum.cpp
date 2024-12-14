#include <cstddef>
#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <vector>
using namespace std;

namespace IPHTC {
template <typename T>  // T is a container
class Enumerate {
   public:
    using TI = decltype(std::begin(declval<T>()));
    using TV = decltype(*declval<TI>());
    class iterator {
       public:
        using value_type = pair<int, TV>;
        using reference = value_type;
        iterator() = default;
        iterator(TI it, int size)
            : it(it), size(size) {}
        iterator& operator++() {
            ++it, ++size;
            return *this;
        }
        bool operator!=(const iterator& other) const { return it != other.it; }
        bool operator==(const iterator& other) const { return it == other.it; }
        reference operator*() { return {size, *it}; }

       private:
        TI it;
        int size;
    };

   public:
    Enumerate(T iter)
        : container_(iter) {
        size_ = std::distance(std::begin(container_), std::end(container_));
    }
    int size() { return size_; }
    iterator begin() { return iterator(std::begin(container_), 0); }
    iterator end() { return iterator(std::end(container_), size_); }

   private:
    T container_;
    int size_;
};

}  // namespace IPHTC

namespace IPHTC {
template <typename T>
Enumerate<T> enumerate(T&& container) {
    return {forward<T>(container)};
}
};  // namespace IPHTC

void test() {
    std::vector<int> vec{3, 2, 7, 6, 7};
    for (auto [i, x] : IPHTC::enumerate(vec)) {
        std::cout << i << ": " << x << '\n';
    }
    std::string s = "Hello, World!";
    for (auto [i, c] : IPHTC::enumerate(s)) {
        std::cout << i << ": " << c << '\n';
        s[i] = '3';
    }
    std::list<int> l{1, 2, 3, 4, 5};
    for (auto [i, x] : IPHTC::enumerate(l)) {
        std::cout << i << ": " << x << '\n';
    }
}

int main() {
    test();
    return 0;
}
