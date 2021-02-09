#include <fstream>
#include <iostream>
#include <iomanip>
using std::ofstream;

#include "nlohmann/json.hpp"
using json = nlohmann::json;

void createHTML();

int main()
{
    createHTML();

    return 0;
}

void createHTML()
{
    ofstream out("func.js", std::ios::trunc);

    json j;
    j["persons"] = {
        {
            {"name", "Arudina"},
            {"age", "?"}
        },
        {
            {"name", "Saito"},
            {"age", 19}
        }
    };

    try
    {
        // Eh possivel fazer assim, dai eu passo os valores pra la :D
        //out << "function touched() {document.write('Kyaaa Someone touched me!'); a = 10; b = 11; document.write(a + b);}";
        out << "function touched() {" << std::endl << "let text = " << std::setw(4) << j << std::endl << "document.write('Kyaaa Someone touched me!');\nlet jso = JSON.parse(text);\nconsole.log(jso)" << std::endl << "}";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    out.close();
}