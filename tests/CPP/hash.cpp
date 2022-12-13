#include <iostream>
#include <unordered_map>

struct Person {
    std::string name, surname;
    int age;
};

int main() {
    std::unordered_map<std::string, Person> map;
    map["Paolo"] = Person { "Paolo", "Cannone", 22 };

    // for (auto& kv : map) {
    //     std::string name = kv.first;
    //     Person p = kv.second;
    //     std::cout << name << " " << p.surname << " " << p.age << "\n";
    // }

    for (auto& [k, v] : map)
        std::cout << k << " " << v.name << " " << v.age << "\n";

    if (map.find("Paolo") != map.end()) {
        Person& p = map.at("Paolo");
        std::cout << p.name << " " << p.surname << " " << p.age << "\n";
    }
}