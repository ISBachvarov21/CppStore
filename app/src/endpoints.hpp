#include "CppHttp.hpp"
#include "element.hpp"
#include "dependencies/CppHttp/include/nlohmann/json.hpp"
#include <iostream>
#include <string>
#include <tuple>
#include <optional>
#include <vector>
#include <fstream>
#include <unordered_map>

using returnType = std::tuple<CppHttp::Net::ResponseType, std::string, std::optional<std::vector<std::string>>>;
using json = nlohmann::json;

returnType Index(CppHttp::Net::Request req) {
    std::ifstream file("templates/index.html");

    if (!file.is_open()) {
        return { CppHttp::Net::ResponseType::NOT_FOUND, "404 Not Found", {} };
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    return { CppHttp::Net::ResponseType::HTML, content, {} };
}

