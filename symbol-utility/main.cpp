/*
 * Quick and dirty utility for generating symbols from SVGs
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

std::string replace_until(std::string str, std::string to_replace_start, std::string to_replace_end, std::string replace_with) {
    std::string ret = str;

    size_t last_pos = 0;
    size_t pos = std::string::npos;
    size_t end_pos = std::string::npos;

    while(
        ((pos = ret.find(to_replace_start, last_pos)) != std::string::npos) &&
        ((end_pos = ret.find(to_replace_end, pos + to_replace_start.length())) != std::string::npos)
    ) {
        ret = ret.replace(pos, end_pos - pos + to_replace_end.length(), replace_with);
        last_pos = pos - to_replace_start.length() + replace_with.length() + 1;
    }

    return ret;
}
typedef char T;
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
                    "    namespace symbols {\n";

    for(const auto& folder : std::filesystem::directory_iterator("raw_svgs/")) {
        std::ofstream output;
        output.open("../src/symbols/" + folder.path().string().substr(9) + ".cpp", std::ios::out);
        if(!output.is_open()) {
            std::cerr << "Could not open file \"../src/symbols/" << folder.path().string().substr(9) << ".cpp\"" << std::endl;
            exit(EXIT_FAILURE);
        }

        symbols_list << "\n"
                        "        /*\n"
                        "         * "
                     << folder.path().string().substr(9)
                     << "\n"
                        "         */\n"
                        "\n";

        output << "/*\n"
                  " * Generated with symbol-utility\n"
                  " */\n"
                  "\n"
                  "#include <string>\n"
                  "#include <vector>\n"
                  "#include <initializer_list>\n"
                  "#include <functional>\n"
                  "\n"
                  "#include <SDL/SDL_opengl.h>\n"
                  "#include <SDL/SDL_image.h>\n"
                  "\n"
                  "#include <cxxgui/color.hpp>\n"
                  "#include <cxxgui/style.hpp>\n"
                  "#include <cxxgui/view.hpp>\n"
                  "#include <cxxgui/symbols.hpp>\n"
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
            data = replace(data, "\"512pt\"", "\"512\"");
            data = replace(data, "\"768pt\"", "\"768\"");
            data = replace(data, "stroke-width=\"128\"", "stroke-width=\"16\"");
            data = replace(data, "stroke-width=\"64\"", "stroke-width=\"16\"");
            data = replace(data, "stroke-linejoin=\"miter\"", "stroke-linejoin=\"round\"");
            data = replace(data, "stroke-linecap=\"square\"", "stroke-linecap=\"round\"");
            data = replace_until(data, "<defs>", "</defs>", "");
            data = replace_until(data, "<mask ", "</mask>", "");
            data = replace_until(data, "<g clip-path", ">", "<g>");
            data = replace_until(data, "mask=\"", "\"", "");

            data = replace(data, "<g>", "");
            data = replace(data, "</g>", "");
            data = replace(data, " stroke-miterlimit=\"3\"", "");

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

            output << "        symbol* "
                   << symbol_name
                   << "() { return new symbol(\""
                   << replace(data, "\"", "\\\"")
                   << "\"); }\n";

            symbols_list << "        extern symbol* "
                         << symbol_name
                         << "();\n";

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
