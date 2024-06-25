#include <iostream>
#include <set>
#include <string>

std::set<std::string> normal_responses = {
    "great!",
    "don't think so",
    "not bad",
    "cool",
    "don't touch me!",
};

std::set<std::string> grumpy_responses = {
    "don't even",
    "are you serious?",
    "go die in a hole",
    "worse",
    "terrible",
    "no way",
};

int main() {
    int nos_count = 0;
    for(int segment = 0; segment < 10; segment++) {
        std::cout << segment << std::endl;
        std::string response;
        std::getline(std::cin, response);
        if(normal_responses.contains(response)) {
            std::cout << "normal" << std::endl;
            break;
        }
        else if (grumpy_responses.contains(response)) {
            std::cout << "grumpy" << std::endl;
            break;
        }
        else if (response == "no") {
            nos_count++;
            if(nos_count > 3) {
                std::cout << "normal" << std::endl;
                break;
            }
        }
    }
}
