#include "Parser.h"

template<typename Ch, typename Tr, size_t pos, typename ...Args>
void tupleStream(std::basic_ostream<Ch, Tr>& os, std::tuple<Args...> const& t, std::enable_if_t<pos == (sizeof ...(Args) - 1), void>* = nullptr){
    os << std::get<pos>(t);
}

template<typename Ch, typename Tr, size_t pos, typename ...Args>
void tupleStream(std::basic_ostream<Ch, Tr>& os, std::tuple<Args...> const& t, std::enable_if_t<pos < (sizeof ...(Args) - 1), void>* = nullptr){
    os << std::get<pos>(t);
    os << ';';
    tupleStream<Ch, Tr, pos + 1, Args...>(os, t);
}



template<typename Ch, typename Tr, typename ...Args>
auto operator<<(std::basic_ostream<Ch, Tr>& os, std::tuple<Args...> const& t){
    tupleStream<Ch, Tr, 0, Args...>(os, t);
}

int main() {
    //std::tuple<int, double, char, std::string> tuple1(1, 1.0, 'j', "hello world");
    //std::cout << tuple1;
    std::fstream in("in.txt");
    std::fstream in2("in2.txt");
    try {
//        Parser<int, double, char, std::string> parser(in, '\n', ',', '"', 0);
/*        for (auto rs : parser) {
            std::cout << rs;
        }*/
        Parser<char, double, int, std::string> parser2(in2, '\n', ',', '"', 1);
        for (auto rs : parser2) {
            std::cout << rs;
        }
    }
    catch (ParseException& ex){
        std::cout<<ex.Pwhat()<<std::endl;
    }



}
