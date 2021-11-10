/*
 * Quick and dirty utility for generating symbols from SVGs
 * 
 * As I made this, I did realize that the thicknesses could've been incorporated into the
 * symbols renderer, instead of in this, but I already did this and it's technically
 * gonna be slightly faster since they're created ahead of time
 */

#include <iostream>
#include <fstream>
#include <filesystem>

std::string replace(std::string str, std::string to_replace, std::string replace_with) {
    std::string ret = str;

    size_t last_pos = 0;
    size_t pos = std::string::npos;

    while((pos = ret.find(to_replace, last_pos)) != std::string::npos) {
        ret = ret.replace(pos, to_replace.length(), replace_with);
        last_pos = pos - to_replace.length() + replace_with.length() + 1;
    }

    return ret;
}

int main(int argc, const char* argv[]) {
    std::ofstream symbols_list;
    symbols_list.open("../src/include/cxxgui/symbols_list.hpp", std::ios::out);
    if(!symbols_list.is_open()) {
        std::cerr << "Could not open file \"../src/include/cxxgui/symbols_list.hpp\"" << std::endl;
        exit(EXIT_FAILURE);
    }

    symbols_list << "/*\n"
                    " * Generated with symbol-utility\n"
                    " */\n"
                    "\n"
                    "namespace cxxgui {\n"
                    "\n"
                    "    namespace symbols {\n"
                    "\n";

    for(const auto& folder : std::filesystem::directory_iterator("raw_svgs/")) {
        std::ofstream output;
        output.open("../src/symbols/" + folder.path().string().substr(9) + ".cpp", std::ios::out);
        if(!output.is_open()) {
            std::cerr << "Could not open file \"../src/symbols/" << folder.path().string().substr(9) << ".cpp\"" << std::endl;
            exit(EXIT_FAILURE);
        }

        symbols_list << "        /*\n"
                        "         * "
                     << folder.path().string().substr(9)
                     << "\n"
                        "         */\n"
                        "\n";

        output << "/*\n"
                  " * Generated with symbol-utility\n"
                  " */\n"
                  "\n"
                  "#include <cxxgui/cxxgui.hpp>\n"
                  "\n"
                  "namespace cxxgui {\n"
                  "\n"
                  "    namespace symbols {\n"
                  "\n";

        std::filesystem::create_directory(std::string("../symbols/") + folder.path().string().substr(9));

        for(const auto& svg : std::filesystem::directory_iterator(folder.path())) {
            std::ifstream input;
            input.open(svg.path().string(), std::ios::in);
            if(!input.is_open()) {
                std::cerr << "Could not open file \"" << svg.path().string() << "\"" << std::endl;
                exit(EXIT_FAILURE);
            }

            std::string data;
            std::string temp;
            while(std::getline(input, temp)) data += temp;

            input.close();

            data = replace(data, "<!-- Generator: Gravit.io -->", "");
            data = replace(data, " vector-effect=\"non - scaling - stroke\"", "");
            data = replace(data, "fill=\"white\"", "fill=\"none\"");
            data = replace(data, "fill=\"black\"", "fill=\"none\"");
            data = replace(data, "<mask ", "<!--<mask ");
            data = replace(data, "</mask>", "</mask>-->");
            data = replace(data, "stroke-width=\"128\"", "stroke-width=\"16\"");
            data = replace(data, "stroke-width=\"64\"", "stroke-width=\"16\"");

            std::string symbol_name = svg.path().string().substr(folder.path().string().length() + 1);
            symbol_name = replace(symbol_name, ".", "_");
            symbol_name = symbol_name.substr(0, symbol_name.length() - 4);
            
            std::ofstream svgout;
            svgout.open(std::string("../symbols/") + svg.path().string().substr(9), std::ios::out);

            if(!svgout.is_open()) {
                std::cerr << "Could not open file \"../symbols/" << svg.path().string().substr(9) << "\"" << std::endl;
                exit(EXIT_FAILURE);
            }

            svgout << data;
            svgout.close();

            if(symbol_name.substr(symbol_name.length() - 4) != "fill") {
                std::string name = svg.path().string().substr(9);
                name = name.substr(0, name.length() - 4) + ".thin.svg";

                std::string old_name = symbol_name;
                symbol_name = old_name + "_thin";

                svgout.open(std::string("../symbols/") + name, std::ios::out);

                if(!svgout.is_open()) {
                    std::cerr << "Could not open file \"../symbols/" << name << "\"" << std::endl;
                    exit(EXIT_FAILURE);
                }

                data = replace(data, "stroke-width=\"16\"", "stroke-width=\"4\"");

                svgout << data;
                svgout.close();

                output << "        symbol* "
                       << symbol_name
                       << "() { return new symbol(\""
                       << replace(data, "\"", "\\\"")
                       << "\"); }\n";

                symbols_list << "        extern symbol* "
                             << symbol_name
                             << "();\n";

                name = svg.path().string().substr(9);
                name = name.substr(0, name.length() - 4) + ".extralight.svg";

                symbol_name = old_name + "_extralight";

                svgout.open(std::string("../symbols/") + name, std::ios::out);

                if(!svgout.is_open()) {
                    std::cerr << "Could not open file \"../symbols/" << name << "\"" << std::endl;
                    exit(EXIT_FAILURE);
                }

                data = replace(data, "stroke-width=\"4\"", "stroke-width=\"8\"");

                svgout << data;
                svgout.close();

                output << "        symbol* "
                       << symbol_name
                       << "() { return new symbol(\""
                       << replace(data, "\"", "\\\"")
                       << "\"); }\n";

                symbols_list << "        extern symbol* "
                             << symbol_name
                             << "();\n";

                name = svg.path().string().substr(9);
                name = name.substr(0, name.length() - 4) + ".light.svg";

                symbol_name = old_name + "_light";

                svgout.open(std::string("../symbols/") + name, std::ios::out);

                if(!svgout.is_open()) {
                    std::cerr << "Could not open file \"../symbols/" << name << "\"" << std::endl;
                    exit(EXIT_FAILURE);
                }

                data = replace(data, "stroke-width=\"8\"", "stroke-width=\"12\"");

                svgout << data;
                svgout.close();

                output << "        symbol* "
                       << symbol_name
                       << "() { return new symbol(\""
                       << replace(data, "\"", "\\\"")
                       << "\"); }\n";

                symbols_list << "        extern symbol* "
                             << symbol_name
                             << "();\n";

                data = replace(data, "stroke-width=\"12\"", "stroke-width=\"16\"");

                output << "        symbol* "
                       << old_name
                       << "() { return new symbol(\""
                       << replace(data, "\"", "\\\"")
                       << "\"); }\n";

                symbols_list << "        extern symbol* "
                             << old_name
                             << "();\n";

                name = svg.path().string().substr(9);
                name = name.substr(0, name.length() - 4) + ".medium.svg";

                symbol_name = old_name + "_medium";

                svgout.open(std::string("../symbols/") + name, std::ios::out);

                if(!svgout.is_open()) {
                    std::cerr << "Could not open file \"../symbols/" << name << "\"" << std::endl;
                    exit(EXIT_FAILURE);
                }

                data = replace(data, "stroke-width=\"16\"", "stroke-width=\"20\"");

                svgout << data;
                svgout.close();

                output << "        symbol* "
                       << symbol_name
                       << "() { return new symbol(\""
                       << replace(data, "\"", "\\\"")
                       << "\"); }\n";

                symbols_list << "        extern symbol* "
                             << symbol_name
                             << "();\n";

                name = svg.path().string().substr(9);
                name = name.substr(0, name.length() - 4) + ".semibold.svg";

                symbol_name = old_name + "_semibold";

                svgout.open(std::string("../symbols/") + name, std::ios::out);

                if(!svgout.is_open()) {
                    std::cerr << "Could not open file \"../symbols/" << name << "\"" << std::endl;
                    exit(EXIT_FAILURE);
                }

                data = replace(data, "stroke-width=\"20\"", "stroke-width=\"24\"");

                svgout << data;
                svgout.close();

                output << "        symbol* "
                       << symbol_name
                       << "() { return new symbol(\""
                       << replace(data, "\"", "\\\"")
                       << "\"); }\n";

                symbols_list << "        extern symbol* "
                             << symbol_name
                             << "();\n";

                name = svg.path().string().substr(9);
                name = name.substr(0, name.length() - 4) + ".bold.svg";

                symbol_name = old_name + "_bold";

                svgout.open(std::string("../symbols/") + name, std::ios::out);

                if(!svgout.is_open()) {
                    std::cerr << "Could not open file \"../symbols/" << name << "\"" << std::endl;
                    exit(EXIT_FAILURE);
                }

                data = replace(data, "stroke-width=\"24\"", "stroke-width=\"28\"");

                svgout << data;
                svgout.close();

                output << "        symbol* "
                       << symbol_name
                       << "() { return new symbol(\""
                       << replace(data, "\"", "\\\"")
                       << "\"); }\n";

                symbols_list << "        extern symbol* "
                             << symbol_name
                             << "();\n";

                name = svg.path().string().substr(9);
                name = name.substr(0, name.length() - 4) + ".extrabold.svg";

                symbol_name = old_name + "_extrabold";

                svgout.open(std::string("../symbols/") + name, std::ios::out);

                if(!svgout.is_open()) {
                    std::cerr << "Could not open file \"../symbols/" << name << "\"" << std::endl;
                    exit(EXIT_FAILURE);
                }

                data = replace(data, "stroke-width=\"28\"", "stroke-width=\"32\"");

                svgout << data;
                svgout.close();

                output << "        symbol* "
                       << symbol_name
                       << "() { return new symbol(\""
                       << replace(data, "\"", "\\\"")
                       << "\"); }\n";

                symbols_list << "        extern symbol* "
                             << symbol_name
                             << "();\n";

                name = svg.path().string().substr(9);
                name = name.substr(0, name.length() - 4) + ".black.svg";

                symbol_name = old_name + "_black";

                svgout.open(std::string("../symbols/") + name, std::ios::out);

                if(!svgout.is_open()) {
                    std::cerr << "Could not open file \"../symbols/" << name << "\"" << std::endl;
                    exit(EXIT_FAILURE);
                }

                data = replace(data, "stroke-width=\"32\"", "stroke-width=\"36\"");

                svgout << data;
                svgout.close();

                output << "        symbol* "
                       << symbol_name
                       << "() { return new symbol(\""
                       << replace(data, "\"", "\\\"")
                       << "\"); }\n";

                symbols_list << "        extern symbol* "
                             << symbol_name
                             << "();\n";
            } else {
                output << "        symbol* "
                       << symbol_name
                       << "() { return new symbol(\""
                       << replace(data, "\"", "\\\"")
                       << "\"); }\n";

                symbols_list << "        extern symbol* "
                             << symbol_name
                             << "();\n";
            }

            output << "\n";
            symbols_list << "\n";

        }

        output << "\n"
                  "    }\n"
                  "\n"
                  "}\n";
    }

    symbols_list << "    }\n"
                    "\n"
                    "}\n";
}
