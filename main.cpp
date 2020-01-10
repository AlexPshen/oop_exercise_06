#include <iostream>
#include <algorithm>
#include <map>

#include "triangle.h"
#include "que.h"
#include "allocator.h"

int main() {
    int pos;
    queue<triangle<double>, my_allocator<triangle<double>, 10000>> q;
    for (;;) {
        std::string comm;
        std::cin >> comm;
        if (comm == "push") {
            triangle<double> tr(std::cin);
            q.push(tr);
        } else if (comm == "top") {
            q.top().print(std::cout);
        } else if (comm == "pop") {
            q.pop();
        } else if (comm == "erase") {
            std::cin >> pos;
            q.erase_to_num(pos);
        } else if (comm == "all") {
            std::for_each(q.begin(), q.end(), [](triangle<double> &tr) { return tr.print(std::cout); });
        } else if (comm == "exit") {
            break;
        } else if (comm == "map") {
            std::map<int, int, std::less<>, my_allocator<std::pair<const double, double>, 100000>> mp;
            for (int i = 0; i < 10; i++) {
                mp[i] = i;
            }
            std::for_each(mp.begin(), mp.end(), [](std::pair<double, double> X) {std::cout << X.first << " " << X.second << ", ";});
            std::cout << '\n';
        } else {
            std::cout << "ERROR" << std::endl;
            continue;
        }
    }

    return 0;
}
