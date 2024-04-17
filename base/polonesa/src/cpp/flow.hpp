//--------------------------------------------------------
// BIBLIOTECA HEADER ONLY PARA C++ 
//     MANIPULAÇÃO DE TEXTO
//         FORMAT, TEXT, PRINT, WRITE, SPLIT, JOIN
//     E PROGRAMAÇÃO FUNCIONAL
//         Map, FILTER, Slice, Enumerate
//     EM MODO FUNÇÃO E MODO PIPELINE
//--------------------------------------------------------
//  VERSÃO 1.9.0
//  https://github.com/senapk/cppaux
//--------------------------------------------------------

#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <array>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>


namespace fw {


//-------------------- PIPE -----------------------------
//--------------------------------------------------------
//--------------------------------------------------------

template <typename FN_ONE>
class Pipe {
    FN_ONE fn;
public:
    Pipe(FN_ONE fn): fn(fn) {}
    template <typename T>        auto operator()(T data) const            { return fn(data); }
    template <typename T> friend auto operator| (T data, const Pipe& obj) { return obj(data); }
};

//-------------------- CHAIN -----------------------------
//--------------------------------------------------------
//--------------------------------------------------------

template<typename... Args>
class Chain {
    std::tuple<Args...> args;
public:
    Chain(Args ...args): args(std::forward<Args>(args)...){}
    template <typename T>
    auto operator()(const T& data) const {
        return std::apply([&data](auto&&... fns) { return (fns(data), ...); }, args);
    }
    template <typename T> 
    friend auto operator| (const T& data, Chain obj) { return obj(data); }
};


//-------------------- INPUT -----------------------------
//--------------------------------------------------------
//--------------------------------------------------------

//[[input]]
//LOAD_GUIDE input
inline std::string input(std::istream & is = std::cin)
//[[input]]
{
    std::string line;
    if (std::getline(is, line))
        return line;
    throw std::runtime_error("input empty");
}

struct Input {
//LOAD_GUIDE input
    Input() {}
    std::string        operator()(std::istream& is = std::cin) const { return input(is); }
    friend std::string operator| (std::istream& is, const Input& obj) { return obj(is); }
};

//-------------------- RANGE -----------------------------
//--------------------------------------------------------
//--------------------------------------------------------

// [[range]]
//LOAD_GUIDE range2
inline std::vector<int> range(int init, int end, int step = 1)
//[[range]]
{
    if (step == 0)
        throw std::runtime_error("step cannot be zero");
    std::vector<int> aux;
    if (step > 0) {
        for (int i = init; i < end; i += step) {
            aux.push_back(i);
        }
    } else {
        for (int i = init; i > end; i += step) {
            aux.push_back(i);
        }
    }
    return aux;
}

//LOAD_GUIDE range1
inline std::vector<int> range(int end)
{
    return range(0, end, 1);
}

struct Range {
//LOAD_GUIDE range1
    Range() : init(0), step(1) {};

    std::vector<int> operator()(int end) const {
        return range(init, end, step);
    }

    friend std::vector<int> operator|(int end, const Range& obj) {
        return obj(end);
    }

    int init {0};
    int end {0};
    int step {0};
};

//-------------------- TEXT HEADER  ----------------------
//--------------------------------------------------------
//--------------------------------------------------------

template <typename T>
inline std::string text(const T& data, const std::string& cfmt = "");

//-------------------- JOIN  -----------------------------
//--------------------------------------------------------
//--------------------------------------------------------

namespace hide {
    template <typename CONTAINER, typename FN> 
    std::string __join(const CONTAINER& container, const std::string& separator, FN fn) 
    { 
        std::stringstream ss;
        for (auto it = container.begin(); it != container.end(); ++it) {
            ss << (it == container.begin() ? "" : separator);
            ss << fn(*it);
        }
        return ss.str();
    }

    template <typename FN>
    std::string __join(const char * data, const std::string& separator, FN fn) 
    { 
        (void) separator;
        return fn(data);
    }

    template <typename... Ts, typename FN>
    std::string __join(std::tuple<Ts...> const &the_tuple, const std::string& separator, FN fn)
    {
        std::stringstream ss;
        std::apply( [&](Ts const &...tuple_args) {
                std::size_t n{0};
                ((ss << fn(tuple_args) << (++n != sizeof...(Ts) ? separator : "")), ...);
            }, the_tuple);
        return ss.str();
    }

    template <typename T1, typename T2, typename FN>
    std::string __join(const std::pair<T1, T2>& the_pair, const std::string& separator, FN fn)
    {
        std::stringstream ss;
        ss << fn(the_pair.first) << separator << fn(the_pair.second);
        return ss.str();
    }
}

//[[joinwith]]
//LOAD_GUIDE joinwith
template <typename T, typename FN>
std::string joinwith(const T& container, const std::string& separator, FN fn)
//[[joinwith]]
{
    return hide::__join(container, separator, fn);
}

//[[join]]
//LOAD_GUIDE join
template <typename T>
std::string join(const T& container, const std::string& separator = ", ", const std::string& cfmt = "")
//[[join]]
{
    return joinwith(container, separator, [&](auto x) { return text(x, cfmt);});  //debug
}

struct Join {
    std::string separator;
    std::string cfmt;

//LOAD_GUIDE join
    Join(const std::string& separator = ", ", const std::string& cfmt = "") : separator(separator), cfmt(cfmt) {}
    template <typename CONTAINER> std::string operator()(const CONTAINER& v) const { return join(v, separator, cfmt); }
    template <typename T> friend std::string operator|(const T& v, const Join& obj) { return obj(v); }
};

template <typename FN>
struct JoinWith {
    FN fn;
    std::string separator;

//LOAD_GUIDE joinwith
    JoinWith(const std::string& separator, FN fn) : separator(separator), fn(fn) {}
    template <typename CONTAINER> std::string operator()(const CONTAINER& v) const { return joinwith(v, separator, fn); }
    template <typename T> friend std::string operator|(const T& v, const JoinWith& obj) { return obj(v); }
};


//-------------------- TEXT ------------------------------
//--------------------------------------------------------
//--------------------------------------------------------
namespace hide {
class Braces {
    public:
        //transforma {{ em \a e }} em \b
    static std::string preprocess(std::string data) {
        std::string result1;
        data.push_back('_');
        for (int i = 0; i < (int) data.size() - 1; i++) {
            if (data[i] == '{' && data[i + 1] == '{') {
                result1.push_back('\a');
                i++;
            } else {
                result1.push_back(data[i]);
            }
        }
        std::string result2;
        for (int i = result1.size() - 1; i >= 0; i--) {
            if (result1[i] == '}' && result1[i - 1] == '}') {
                result2.push_back('\b');
                i--;
            } else {
                result2.push_back(result1[i]);
            }
        }
        std::string final_result;
        for (int i = result2.size() - 1; i >= 0; i--) {
            final_result.push_back(result2[i]);
        }
        return final_result;
    }

    static std::pair<std::vector<std::string>, std::vector<std::string>> extract(std::string data)
    {
        data = preprocess(data);
        std::vector<std::string> texts = {""};
        std::vector<std::string> ctrls = {""};
        auto* destiny = &texts;

        for (char c : data) {
            if (c == '{') 
            {
                texts.push_back("");
                destiny = &ctrls;
            }
            else if (c == '}') 
            {
                ctrls.push_back("");
                destiny = &texts;
            }
            else
            {
                if (c == '\a') {
                    c = '{';
                } else if (c == '\b') {
                    c = '}';
                }
                destiny->back().append(std::string(1,c));
            }
        }
        while (texts.size() > ctrls.size())
            ctrls.push_back("");
        return {texts, ctrls};
    }

    static std::string combine(const std::vector<std::string>& texts, const std::vector<std::string>& vars) {
        if(vars.size() < texts.size() - 1) {
            throw std::out_of_range("");
        }
        std::stringstream ss;
        for (size_t i = 0; i < vars.size(); i++)
            ss << texts[i] << vars[i];
        ss << texts.back(); //ultimo texto
        return ss.str();
    }
};

class Align {
    char align_mode { 0 }; //< > or ^, default is center
    int  align_size { 0 }; //size of the field
    char pad_char   { ' ' }; //char used to pad the field
    std::string format { "" }; //filtered format string

    bool extract_align() {
        std::string align_str_size;

        size_t i {0}, j {0};
        for (i = 0; i < format.size(); ++i) {
            if (format[i] == '<' || format[i] == '>' || format[i] == '^') { //achei o alinhamento
                this->align_mode = format[i];

                for (j = i + 1; j < format.size(); ++j) { //extraindo o tamanho do alinhamento
                    if (format[j] >= '0' && format[j] <= '9') {
                        align_str_size += format[j];
                    } else { // terminou o tamanho
                        break;
                    }
                }
                if (align_str_size.empty()) {
                    this->align_size = 0;
                    std::cout << "fail: format symbol `" << format[i] << "` must be followed by a size\n";
                    exit(1);
                }
                this->align_size = std::stoi(align_str_size);
                this->format.erase(i, j - i);
                return true;
            }
        }
        return false;
    }

    void extract_pad() {
        // search for : char in format, if exists and is followed by a char, 
        // then use that char as padding, and remove both from string
        auto pos = this->format.find(':');
        if (pos != std::string::npos) {
            if (pos + 1 < format.size()) {
                this->pad_char = format[pos + 1];
                this->format.erase(pos, 2);
            } else {
                std::cout << "fail: format symbol `:` must be followed by a padding char\n";
                exit(1);
            }
        }
    }
public:

    Align(const std::string& format) {
        this->format = format;
        this->extract_pad();
        this->extract_align();
    }

    std::string align_text(const std::string& str) {
        int len = str.length();
        if(this->align_mode == 0 || this->align_size < len) { 
            return str; 
        }
        int diff = this->align_size - len;
        
        //default is center
        int padleft = diff/2;
        int padright = diff - padleft;
        if(this->align_mode == '>') {
            padleft = diff;
            padright = 0;
        }
        else if(this->align_mode == '<') {
            padleft = 0;
            padright = diff;
        }
        return std::string(padleft, this->pad_char) + str + std::string(padright, this->pad_char);
    }

    const std::string& get_filtered_format() {
        return this->format;
    }
    int get_align_size() {
        return this->align_size;
    }
    char get_pad_char() {
        return this->pad_char;
    }
    char get_align_mode() {
        return this->align_mode;
    }
};
}

class Text {

    template <typename T>
    static inline std::string ss_transform(const T& data) {
        std::ostringstream ss;
        ss << data;
        return ss.str();
    }

    template <typename... Ts>
    static inline std::string cformat(const std::string &fmt, Ts... vs) {
        auto __format = [](const std::string &fmt, auto... vs) {
            char b;
            size_t required = std::snprintf(&b, 0, fmt.c_str(), vs...) + 1;
            char bytes[required];
            std::snprintf(bytes, required, fmt.c_str(), vs...);
            return std::string(bytes);
        };
        return __format(fmt, [&vs](){
            if constexpr (std::is_same_v<std::string, Ts>) {
                return vs.c_str();
            } else {
                return vs;
            }
        }()...);
    }

    template <typename T>
    static inline std::string process(const T& data, const std::string& cfmt) {
        hide::Align align(cfmt);
        std::string filtered = align.get_filtered_format();

        if (filtered == "") {
            return align.align_text(ss_transform(data));
        }
        if (filtered.find(" ") != std::string::npos) {
            std::cout << "fail: cfmt não pode conter espaços ou %\n";
            exit(1);
        }
        return align.align_text(cformat(filtered, data));
    }

    template <typename A, typename B>
    static inline std::string process(const std::pair<A, B>& pair, const std::string& cfmt) {
        return join(pair, ", ", cfmt) | Text("({})");
    }

    template <typename... Ts>
    static inline std::string process(const std::tuple<Ts...>& tuple, const std::string& cfmt) {
        return join(tuple, ", ", cfmt) | Text("({})");
    }
    template <typename PRINTABLE> 
    static inline std::string process(const std::vector<PRINTABLE>& container, const std::string& cfmt) {
        return join(container, ", ", cfmt) | Text("[{}]");
    }
    template <typename PRINTABLE> 
    static inline std::string process(const std::list<PRINTABLE>& container, const std::string& cfmt) {
        return join(container, ", ", cfmt) | Text("[{}]");
    }
    template <typename PRINTABLE, size_t S> 
    static inline std::string process(const std::array<PRINTABLE, S>& container, const std::string& cfmt) {
        return join(container, ", ", cfmt) | Text("[{}]");
    }
    template <typename PRINTABLE> 
    static inline std::string process(const std::set<PRINTABLE>& container, const std::string& cfmt) {
        return join(container, ", ", cfmt) | Text("{{{}}}");
    }
    template <typename PRINTABLE> 
    static inline std::string process(const std::unordered_set<PRINTABLE>& container, const std::string& cfmt) {
        return join(container, ", ", cfmt) | Text("{{{}}}");
    }
    template <typename A, typename B> 
    static inline std::string process(const std::map<A, B>& container, const std::string& cfmt) {
        return join(container, ", ", cfmt) | Text("{{{}}}");
    }
    template <typename A, typename B>
    static inline std::string process(const std::unordered_map<A, B>& container, const std::string& cfmt) {
        return join(container, ", ", cfmt) | Text("{{{}}}");
    }

private:

    std::string cfmt;

public:

//LOAD_GUIDE text
    Text(std::string cfmt = ""): cfmt(cfmt) { }
    
    template <typename T>
    std::string operator()(const T& data) const {
        if (cfmt.find("{") == std::string::npos) {
            return process(data, cfmt);
        }
        auto [texts, controls] = hide::Braces::extract(cfmt);
        try {
            auto result = process(data, controls.at(0));
            return hide::Braces::combine(texts, {result});
        } catch (std::out_of_range& e) {
            std::cout << "fail: verifique a quantidade de parâmetros passado para string: " << cfmt << '\n';
            exit(1);
        }
    }

    template <typename T>
    friend std::string operator|(const T& v, const Text& obj) { return obj(v); }
};

//[[text]]
//LOAD_GUIDE text
template <typename T>
inline std::string text(const T& data, const std::string& cfmt)
//[[text]]
{
    return Text(cfmt)(data);
}

//-------------------- FORMAT ----------------------------
//--------------------------------------------------------
//--------------------------------------------------------

template<typename... Args>
class Format 
{
    std::tuple<Args...> args;

    std::vector<std::string> tuple_to_vector_str(const std::vector<std::string>& controls)
    {
        std::vector<std::string> result;
        std::apply
        (
            [&result, &controls](Args const&... tupleArgs)
            {
                int i = -1;
                ((result.push_back(text(tupleArgs, controls.at(++i)))), ...);
            }, this->args
        );

        return result;
    }
public:

//LOAD_GUIDE format
    Format(Args ...args): args(std::forward<Args>(args)...){}

    std::string operator()(std::string fmt)
    {
        auto [texts, controls] = hide::Braces::extract(fmt);
        try {
            auto vars = tuple_to_vector_str(controls);
            return hide::Braces::combine(texts, vars);
        } catch (std::out_of_range& e) {
            std::cout << "fail: verifique a quantidade de parâmetros passado para string: " << fmt << '\n';
            exit(1);
        }
    }

    friend std::string operator|(std::string fmt, Format<Args...> obj) { return obj(fmt); }
};

//[[format]]
//LOAD_GUIDE format
template<typename... Args>
std::string format(std::string fmt, Args ...args) 
//[[format]]
{
    return Format<Args...>(args...)(fmt); 
}

//-------------------- Write -----------------------------
//--------------------------------------------------------
//--------------------------------------------------------

struct Write {
    std::string end;

    template <typename PRINTABLE> 
    const PRINTABLE& process(const PRINTABLE& data, std::string end) {
        std::cout << text(data) << end;
        return data;
    }


//LOAD_GUIDE write
    Write(std::string end = "\n"): end(end) { }
    template <typename PRINTABLE>        const PRINTABLE& operator()(const PRINTABLE& data           ) { return process(data, end); }
    template <typename PRINTABLE> friend const PRINTABLE& operator| (const PRINTABLE& data, Write obj) { return obj(data); }
};

//[[write]]
//LOAD_GUIDE write
template <typename PRINTABLE> 
const PRINTABLE& write(const PRINTABLE& data, std::string end = "\n") 
//[[write]]
{
    data | Write(end);
    return data;
}

//-------------------- Map   -----------------------------
//--------------------------------------------------------
//--------------------------------------------------------

//[[map]]
//LOAD_GUIDE map
template<typename CONTAINER, typename FUNCTION>
auto map(const CONTAINER& container, FUNCTION fn)
//[[map]]
{
    std::vector<decltype(fn(*container.begin()))> aux;
    for (const auto& item : container)
        aux.push_back(fn(item));
    return aux;
}

template <typename FUNCTION>
struct Map {
    FUNCTION fn;
//LOAD_GUIDE map
    Map(FUNCTION fn) : fn(fn) {};
    template<typename CONTAINER> auto operator()(const CONTAINER& container) const { return map(container, fn); }
    template<typename CONTAINER> friend auto operator|(const CONTAINER& container, const Map& obj) { return obj(container); }
};

//-------------------- Split -----------------------------
//--------------------------------------------------------
//--------------------------------------------------------

//[[split]]
//LOAD_GUIDE split
inline std::vector<std::string> split(std::string content, std::string delimiter = " ")
//[[split]]
{
    std::vector<std::string> aux;
    size_t pos = 0;
    while ((pos = content.find(delimiter)) != std::string::npos) {
        std::string token = content.substr(0, pos);
        aux.push_back(token);
        content.erase(0, pos + delimiter.length());
    }
    aux.push_back(content);
    return aux;
}

struct Split {
    std::string delimiter;
//LOAD_GUIDE split
    Split(std::string delimiter = " ") : delimiter(delimiter) {}

    std::vector<std::string>        operator()(std::string content) const { return split(content, delimiter); }
    friend std::vector<std::string> operator| (std::string content, const Split& obj) { return obj(content); }
};

//--------------------------------------------------------
//-------------------- Slice -----------------------------
//--------------------------------------------------------

class Slice {

    template<typename CONTAINER>
    static auto new_vec_from(const CONTAINER& container) {
        auto fn = [](auto x) {return x;}; 
        std::vector<decltype(fn(*container.begin()))> aux;
        return aux;
    }

    template<typename CONTAINER>
    std::pair<int, int> calc_limits(const CONTAINER& container) const {
        int size = container.size();
        int begin = 0;
        int end = size;
        if (!this->from_begin && !this->to_end && (this->begin == this->end)) {
            return {0, 0};
        }
        if (!this->from_begin) {
            begin = this->begin;
            if (begin < 0)
                begin = size + begin;
            begin = std::min(begin, size);
        }
        if (!this->to_end) {
            end = this->end;
            if (end < 0)
                end = size + end;
            end = std::min(end, size);
        }
        return {begin, end};
    }

    template<typename CONTAINER>
    auto process(const CONTAINER& container) const {
        auto [begin, end] = calc_limits(container);
        auto aux = Slice::new_vec_from(container);
        auto it = container.begin();
        std::advance(it, begin);
        for (int i = begin; i < end; i++) {
            aux.push_back(*it);
            it++;
        }
        return aux;
    }

    std::string process(const std::string& container) const {
        auto [begin, end] = calc_limits(container);
        std::string aux;
        for (int i = begin; i < end; i++) {
            aux.push_back(container[i]);
        }
        return aux;
    }

    std::string process(const char * container) const {
        return process(std::string(container));
    }


public:
//LOAD_GUIDE slice1
    Slice(int begin = 0) {
        this->from_begin = begin == 0;
        this->begin = begin;
        this->to_end = true;
    }

//LOAD_GUIDE slice2
    Slice(int begin, int end) {
        this->begin = begin;
        this->end = end;
        this->from_begin = false;
        this->to_end = false;
    }

    template<typename CONTAINER>
    auto operator()(const CONTAINER& container) const {
        return process(container);
    }
    
    template<typename CONTAINER> friend auto operator|(const CONTAINER& container, const Slice& obj) { return obj(container); }

private:
    int begin;
    int end;
    bool from_begin {false};
    bool to_end {false};
};

//[[slice1]]
//LOAD_GUIDE slice1
template<typename CONTAINER>
auto slice(const CONTAINER& container, int begin = 0)
//[[slice1]]
{
    return Slice(begin)(container);
}

//LOAD_GUIDE slice2
template<typename CONTAINER>
auto slice(CONTAINER container, int begin, int end)
{
    return Slice(begin, end)(container);
}

//-------------------- FILTER ----------------------------
//--------------------------------------------------------
//--------------------------------------------------------

//[[filter]]
//LOAD_GUIDE filter
template<typename CONTAINER, typename FUNCTION>
auto filter(const CONTAINER& container, FUNCTION fn)
//[[filter]]
{
    auto aux = slice(container, 0, 0);
    for(const auto& x : container) {
        if(fn(x))
            aux.push_back(x);
    }
    return aux;
}

template <typename FUNCTION>
struct Filter {
    FUNCTION fn;

//LOAD_GUIDE filter
    Filter(FUNCTION fn) : fn(fn) {};
    template<typename CONTAINER> auto operator()(const CONTAINER& container) const { return filter(container, fn); }
    template<typename CONTAINER> friend auto operator|(const CONTAINER& container, const Filter& obj) { return obj(container); }
};

//-------------------- Enumerate -------------------------
//--------------------------------------------------------
//--------------------------------------------------------

//[[enumerate]]
//LOAD_GUIDE enumerate
template<typename CONTAINER>
auto enumerate(const CONTAINER& container)
//[[enumerate]]
{
    auto fn = [](auto x) {return x;}; 
    std::vector<std::pair<int, decltype(fn(*container.begin()))>> aux;
    int i = 0;
    for (const auto& item : container) {
        aux.push_back(std::make_pair(i, item));
        i++;
    }
    return aux;
}

struct Enumerate {
//LOAD_GUIDE enumerate
    Enumerate() {};
    template<typename CONTAINER> auto operator()(const CONTAINER& container) const { return enumerate(container); }
    template<typename CONTAINER> friend auto operator|(const CONTAINER& container, const Enumerate& obj) { return obj(container); }
};

//-------------------- PARSE -----------------------------
//--------------------------------------------------------
//--------------------------------------------------------

//[[parse]]
//LOAD_GUIDE parse
template <typename READABLE>
READABLE parse(std::string value)
//[[parse]]
{
    std::istringstream iss(value);
    READABLE aux;
    if (iss >> aux) {
        return aux;
    }
    throw std::runtime_error("parse: invalid conversion from " + value);
}

template <typename READABLE>
struct Parse {
//LOAD_GUIDE parse
    Parse(){};
    READABLE operator()(std::string value) const { return parse<READABLE>(value); }
    friend READABLE operator|(std::string value, const Parse& obj) { return obj(value); }
};

//-------------------- UNPACK -----------------------------
//---------------------------------------------------------
//---------------------------------------------------------

template <typename... Types>
struct Unpack {
    char delimiter;

//LOAD_GUIDE unpack
    Unpack(char delimiter) : delimiter(delimiter) {}

    template<typename Head, typename... Tail>
    std::tuple<Head, Tail...> tuple_read_impl(std::istream& is, char delimiter) const {
        Head val;
        std::string token;
        std::getline(is, token, delimiter);
        std::stringstream ss_token(token);
        ss_token >> val;
        if constexpr (sizeof...(Tail) == 0) // this was the last tuple value
            return std::tuple{val};
        else
            return std::tuple_cat(std::tuple{val}, tuple_read_impl<Tail...>(is, delimiter));
    }

    std::tuple<Types...> operator()(std::string content) const {
        std::stringstream ss(content);
        return tuple_read_impl<Types...>(ss, this->delimiter);
    }
    
    friend std::tuple<Types...> operator|(std::string content, const Unpack& obj) {
        return obj(content);
    }
};

//[[unpack]]
//LOAD_GUIDE unpack
template <typename... TS>
std::tuple<TS...> unpack(const std::string& line, char delimiter)
//[[unpack]]
{
    return Unpack<TS...>(delimiter)(line);
}


//-------------------- ZIP   -----------------------------
//--------------------------------------------------------
//--------------------------------------------------------

//[[zip]]
//LOAD_GUIDE zip
template<typename CONTAINER_A, typename CONTAINER_B>
auto zip(const CONTAINER_A& A, const CONTAINER_B& B)
//[[zip]]
{
    auto fn = [](auto x) { return x; };
    using type_a = decltype(fn(*A.begin()));
    using type_b = decltype(fn(*B.begin()));
    std::vector<std::pair<type_a, type_b>> aux;

    auto ita = A.begin();
    auto itb = B.begin();
    while(ita != A.end() &&  itb != B.end()) {
        aux.push_back({*ita, *itb});
        ita++;
        itb++;
    }
    return aux;
};

template <typename CONTAINER_B>
struct Zip {
    CONTAINER_B container_b;

//LOAD_GUIDE zip
    Zip(const CONTAINER_B& container_b) : container_b(container_b) {}

    template<typename CONTAINER_A>
    auto operator()(const CONTAINER_A& container_a) const { return zip(container_a, container_b); }
    template<typename CONTAINER_A>
    friend auto operator|(const CONTAINER_A& container_a, const Zip& obj) { return obj(container_a); }
};

//-------------------- ZIPWITH ---------------------------
//--------------------------------------------------------
//--------------------------------------------------------

//[[zipwith]]
//LOAD_GUIDE zipwith
template<typename CONTAINER_A, typename CONTAINER_B, typename FNJOIN>
auto zipwith(const CONTAINER_A& A, const CONTAINER_B& B, FNJOIN fnjoin)
//[[zipwith]]
{
    auto idcopy = [](auto x) { return x; };
    using type_out = decltype( fnjoin( idcopy(*A.begin()), idcopy(*B.begin()) ));
    std::vector<type_out> aux;

    auto ita = A.begin();
    auto itb = B.begin();
    while(ita != A.end() &&  itb != B.end()) {
        aux.push_back(fnjoin(*ita, *itb));
        ita++;
        itb++;
    }
    return aux;
};


template<typename CONTAINER_B, typename FNJOIN>
struct Zipwith {
    CONTAINER_B container_b;
    FNJOIN fnjoin;

//LOAD_GUIDE zipwith
    Zipwith(const CONTAINER_B& container_b, FNJOIN fnjoin) : container_b(container_b), fnjoin(fnjoin) {}

    template<typename CONTAINER_A>        auto operator()(const CONTAINER_A& container_a) const { return zipwith(container_a, container_b, fnjoin); }
    template<typename CONTAINER_A> friend auto operator| (const CONTAINER_A& container_a, const Zipwith& obj) { return obj(container_a); }
};

//-------------------- FOREACH ---------------------------
//--------------------------------------------------------
//--------------------------------------------------------

//[[foreach]]
//LOAD_GUIDE foreach
template <typename CONTAINER, typename FN>
void foreach(const CONTAINER& container, FN fn)
//[[foreach]]
{
    for (const auto& item : container) {
        fn(item);
    }
}

template <typename FN>
struct Foreach {
    FN fn;

//LOAD_GUIDE foreach
    Foreach(FN fn) : fn(fn) {}

    template<typename CONTAINER> void operator()(const CONTAINER& container) const { foreach(container, fn); }
    template<typename CONTAINER> friend void operator|(const CONTAINER& container, const Foreach& obj) { obj(container); }
};
} // namespace fw

using namespace std::string_literals;


//[[operator+]]
//LOAD_GUIDE operator+
inline double operator+(std::string text)
//[[operator+]]

{
    return fw::parse<double>(text);
}

#define EXTRA
#include <algorithm>

namespace fw {
#ifdef EXTRA

inline auto Sort() {
    return fw::Pipe([](auto container) {
        std::sort(container.begin(), container.end());
        return container;
    });
};

template <typename T>
inline auto Find(const T& value) {
    return fw::Pipe([value](auto container) {
        return std::find(container.begin(), container.end(), value);
    });
};

} // namespace fw
#endif
