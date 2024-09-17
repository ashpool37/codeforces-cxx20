// Problem: 20C. Dijkstra?
// Problem statement: https://codeforces.com/problemset/problem/20/C?locale=en
// Solution author: Artem Zhurikhin (https://codeforces.com/profile/Ashpool)
// Solution license: the Unlicense (Public Domain)
// More solutions: https://github.com/ashpool37/codeforces-cxx20

/* #region templates */

#include <iostream>
#include <charconv>
#include <ranges>
#include <type_traits>
#include <vector>
#include <algorithm>
#include <list>
#include <forward_list>
#include <array>
#include <limits>
#include <iterator>
#include <unordered_set>

using ll = long long;
using ull = unsigned long long;

unsigned digit_to_unsigned(char c) {
    char cs[2] = "\0";
    cs[0] = c;
    unsigned result;
    std::from_chars(cs, cs+1, result);
    return result;
}

char unsigned_to_digit(unsigned n) {
    char cs[2] = "\0";
    std::to_chars(cs, cs+1, n);
    return cs[0];
}

template<std::integral T>
auto counted(T start, std::size_t count, T step = 1) {
    using namespace std::ranges::views;
    return iota(0u, count) | transform([=](std::size_t i){ return start + step * static_cast<T>(i); });
}

auto counted(std::size_t count) {
    return counted(0ull, count, 1ull);
}

template<std::integral BaseT, std::integral ExponentT>
auto power(BaseT base, ExponentT exponent) {
    std::common_type_t<BaseT, ExponentT> result = 1;
    while(exponent--) result *= base;
    return result;
}

template <typename T>
concept ReadableFromStream = requires(std::istream is, T value) {
    { is >> value };
};

class FromIstreamHelper {
    std::istream& input_stream;
    std::optional<std::size_t> count;

    FromIstreamHelper(FromIstreamHelper const&) = delete;
    FromIstreamHelper(FromIstreamHelper&&) = delete;
    FromIstreamHelper& operator=(FromIstreamHelper const&) = delete;
    FromIstreamHelper& operator=(FromIstreamHelper&&) = delete;

    FromIstreamHelper(std::istream& input_stream, std::size_t count)
        : input_stream(input_stream), count(count)
    {}
    FromIstreamHelper(std::istream& input_stream)
        : input_stream(input_stream), count(std::nullopt)
    {}

    friend auto from_istream(std::istream& input_stream);
    friend auto from_istream(std::istream& input_stream, std::size_t count);

public:
    template<ReadableFromStream T>
    operator T() && {
        T result;
        input_stream >> result;
        return result;
    }

    template<ReadableFromStream T>
    operator std::vector<T>() && {
        std::vector<T> result;
        if(count) {
            result.reserve(*count);
            std::copy_n(std::istream_iterator<T>(input_stream), *count, std::back_inserter(result));
        }
        return result;
    }

    template<ReadableFromStream T>
    operator std::list<T>() && {
        std::list<T> result;
        if(count) {
            std::copy_n(std::istream_iterator<T>(input_stream), *count, std::back_inserter(result));
        }
        return result;
    }

    template<ReadableFromStream T>
    operator std::forward_list<T>() && {
        std::forward_list<T> result;
        auto result_it = result.before_begin();
        auto input_it = std::istream_iterator<T>(input_stream);
        if(count) {
            result_it = result.insert_after(result_it, *input_it);
            for(auto const _ : counted(*count - 1uz)) {
                input_it++;
                result_it = result.insert_after(result_it, *input_it);
            }
        }
        return result;
    }

    template<ReadableFromStream T, std::size_t array_size>
    operator std::array<T, array_size>() && {
        std::array<T, array_size> result;
        std::copy_n(std::istream_iterator<T>(input_stream), array_size, std::begin(result));
        return result;
    }
};

auto from_istream(std::istream& input_stream) {
    return FromIstreamHelper(input_stream);
}

auto from_istream(std::istream& input_stream, std::size_t count) {
    return FromIstreamHelper(input_stream, count);
}

auto from_cin() {
    return from_istream(std::cin);
}

auto from_cin(std::size_t count) {
    return from_istream(std::cin, count);
}

std::string line_from_istream(std::istream& input_stream) {
    std::string result;
    std::getline(input_stream, result);
    return result;
}

std::string line_from_cin() {
    return line_from_istream(std::cin);
}

void istream_skip_line(std::istream& input_stream) {
    input_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void cin_skip_line() {
    istream_skip_line(std::cin);
}

bool space_p(char ch)
{
    return static_cast<bool>(std::isspace(static_cast<unsigned char>(ch)));
}

void istream_skip_ws(std::istream& input_stream) {
    while(space_p(input_stream.peek())) input_stream.get();
}

void cin_skip_ws() {
    istream_skip_ws(std::cin);
}

template<std::integral T, std::output_iterator<T> OutputIt>
void generate_multiples(T limit, T base, OutputIt it) {
    T multiple;
    for(T i = 2; (multiple = base * i) <= limit; i++) {
        *it = multiple;
        it++;
    }
}

template<std::integral T>
std::vector<T> multiples_to_vector(T limit, T base, bool include_base = true) {
    std::vector<T> result;
    if(include_base) result.push_back(base);
    generate_multiples(limit, base, std::back_inserter(result));
    return result;
}

template<std::integral T, std::output_iterator<T> OutputIt>
void generate_primes(T limit, OutputIt it) {
    std::unordered_set<T> composite;
    for(T i = 2; i <= limit; i++) {
        if(not composite.contains(i)) {
            *it = i;
            it++;
            if(i * i <= limit) generate_multiples(limit, i, std::inserter(composite, composite.begin()));
        }
    }
}

template<std::integral T>
std::vector<T> primes_to_vector(T limit) {
    std::vector<T> result;
    generate_primes(limit, std::back_inserter(result));
    return result;
}

template <typename T>
concept Summable = requires(T lhs, T rhs) {
    { lhs + rhs };
};

template<std::ranges::range R>
requires Summable<std::ranges::range_value_t<R>>
auto sum(R const& range) {
    return std::ranges::fold_left(range, 0, std::plus());
}

template<std::unsigned_integral T>
T ceil_div(T lhs, T rhs) {
    if(rhs == 0u) throw std::runtime_error("Division by zero");
    return (lhs + rhs - 1u) / rhs;
}

template <typename T>
concept WriteableToStream = requires(std::ostream os, T value) {
    { os << value };
};

template<WriteableToStream T, WriteableToStream D>
class OptionalPrintHelper {
    std::optional<T> const& optional;
    D const& default_value;
    OptionalPrintHelper(std::optional<T> const& optional, D const& default_value)
        : optional(optional), default_value(default_value)
    {}

    template<WriteableToStream T_, WriteableToStream D_>
    friend std::ostream& operator<<(std::ostream& output_stream, OptionalPrintHelper<T_, D_> const& opt_print_helper);
    template<WriteableToStream T_, WriteableToStream D_>
    friend OptionalPrintHelper<T_, D_> print_opt(std::optional<T_> const& optional, D_ const& default_value);
};

template<WriteableToStream T, WriteableToStream D>
std::ostream& operator<<(std::ostream& output_stream, OptionalPrintHelper<T, D> const& opt_print_helper) {
    if(opt_print_helper.optional.has_value())
        output_stream << *(opt_print_helper.optional);
    else output_stream << opt_print_helper.default_value;
    return output_stream;
}

template<WriteableToStream T, WriteableToStream D>
OptionalPrintHelper<T, D> print_opt(std::optional<T> const& optional, D const& default_value) {
    return OptionalPrintHelper(optional, default_value);
}

/* #endregion */

#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <utility>

template<std::integral I>
class iint {
    struct infinity_tag {};

    iint(infinity_tag, signed char inf_sign) : value(0), infinity_sign(inf_sign) {}

    I value = 0;
    signed char infinity_sign = 0;
public:
    iint() = default;
    iint(I val) : value(val), infinity_sign(0) {}

    static iint positive_infinity() { return iint(infinity_tag{}, +1); }
    static iint negative_infinity() { return iint(infinity_tag{}, -1); }

    auto operator<=>(iint const& other) const {
        if (infinity_sign == 0 && other.infinity_sign == 0) {
            return value <=> other.value;
        } else if (infinity_sign == 0) {
            return (-other.infinity_sign) <=> 0;
        } else if (other.infinity_sign == 0) {
            return infinity_sign <=> 0;
        } else {
            return infinity_sign <=> other.infinity_sign;
        }
    }

    template<std::integral J>
    auto operator<=>(J const& rhs) const {
        if (infinity_sign == 0) {
            return value <=> rhs;
        } else if (infinity_sign > 0) {
            return std::strong_ordering::greater;
        } else {
            return std::strong_ordering::less;
        }
    }

    template<std::integral J>
    friend auto operator<=>(J const& lhs, iint const& rhs) {
        if (rhs.infinity_sign == 0) {
            return lhs <=> rhs.value;
        } else if (rhs.infinity_sign > 0) {
            return std::strong_ordering::less;
        } else {
            return std::strong_ordering::greater;
        }
    }

    template<std::integral T>
    explicit operator T() const {
        if (infinity_sign == 0) {
            return static_cast<T>(value);
        } else if (infinity_sign > 0) {
            return std::numeric_limits<T>::max();
        } else {
            if constexpr (std::is_signed_v<T>) {
                return std::numeric_limits<T>::min();
            } else {
                throw std::overflow_error("Cannot cast negative infinity to unsigned integral type");
            }
        }
    }

    explicit operator bool() const {
        if (infinity_sign != 0) {
            return true;
        } else {
            return value != 0;
        }
    }
};

struct GraphInputEdge {
    std::pair<unsigned, unsigned> nodes;
    unsigned weight;

    GraphInputEdge sub1() const {
        return GraphInputEdge{.nodes = {nodes.first - 1u, nodes.second - 1u}, .weight = weight};
    }
};

std::istream& operator>>(std::istream& input_stream, GraphInputEdge& edge) {
    input_stream >> edge.nodes.first >> edge.nodes.second >> edge.weight;
    return input_stream;
}

class Graph {
    struct Edge {
        unsigned to;
        unsigned weight;
    };

    std::vector<std::vector<Edge>> nodes;
public:
    template<std::ranges::input_range EdgesR>
    Graph(std::size_t const node_count, std::size_t const edge_count, EdgesR&& edges) 
        : nodes(node_count)
    {
        auto edge_it = std::ranges::begin(edges);
        auto const get_edge = [this, &edge_it]() {
            auto const& edge = *edge_it;
            nodes[edge.nodes.first].push_back(Edge{edge.nodes.second, edge.weight});
            nodes[edge.nodes.second].push_back(Edge{edge.nodes.first, edge.weight});
        };
        if(edge_count > 0u) {
            get_edge();
            for(auto const _ : counted(edge_count - 1u)) {
                edge_it++;
                get_edge();
            }
        }
    }

    [[nodiscard]] std::size_t size() const {
        return nodes.size();
    }

    void remove_single_edge_loops() {
        for(unsigned node_id = 0u; node_id < size(); node_id++) {
            nodes[node_id] =
                std::views::filter(nodes[node_id], [node_id](Edge const& edge) { return edge.to != node_id; })
                | std::ranges::to<std::vector<Edge>>();
        }
    }

    void remove_parallel_edges() {
        for(unsigned node_id = 0u; node_id < size(); node_id++) {
            std::map<unsigned, unsigned> min_edges;
            for(Edge const& edge : nodes[node_id]) {
                auto const dest_it = min_edges.find(edge.to);
                if(dest_it == min_edges.end())
                    min_edges[edge.to] = edge.weight;
                else
                    min_edges[edge.to] = std::min(edge.weight, dest_it->second);
            };
            nodes[node_id] = min_edges
                | std::views::transform([](auto const& pair) {
                    return Edge{.to = pair.first, .weight = pair.second};
                })
                | std::ranges::to<std::vector<Edge>>();
        }
    }

    [[nodiscard]] std::unordered_map<unsigned, unsigned> dijkstra_shortest_paths(unsigned source_id) const {
        std::unordered_map<unsigned, unsigned> previous;
        std::vector<iint<unsigned>> distances(size(), iint<unsigned>::positive_infinity());
        struct DijkstraNode {
            unsigned node_id;
            unsigned distance_seen;

            auto operator<=>(DijkstraNode const& rhs) const {
                return distance_seen <=> rhs.distance_seen;
            }
        };
        std::priority_queue<DijkstraNode, std::vector<DijkstraNode>, std::greater<DijkstraNode>> to_visit;

        previous[source_id] = source_id;
        distances[source_id] = 0u;
        to_visit.push({.node_id = source_id, .distance_seen = 0u});

        while(not to_visit.empty()) {
            DijkstraNode const here = to_visit.top();
            to_visit.pop();

            if(distances[here.node_id] >= here.distance_seen) {
                for(auto const edge : nodes[here.node_id]) {
                    unsigned neighbour_distance_seen = here.distance_seen + edge.weight;
                    if(distances[edge.to] > neighbour_distance_seen) {
                        distances[edge.to] = neighbour_distance_seen;
                        previous[edge.to] = here.node_id;
                        to_visit.push({.node_id = edge.to, .distance_seen = neighbour_distance_seen});
                    }
                }
            }
        }

        return previous;
    }

    [[nodiscard]] static std::optional<std::forward_list<unsigned>>
    dijkstra_reconstruct_path(std::unordered_map<unsigned, unsigned> const& previous, unsigned destination) {
        auto prev_it = previous.find(destination);
        if(prev_it == previous.end()) return std::nullopt;

        std::forward_list<unsigned> result;
        result.push_front(destination);
        while(prev_it->second != prev_it->first) {
            result.push_front(prev_it->second);
            prev_it = previous.find(prev_it->second);
        }
        return result;
    }
};

int main() {
    std::size_t const node_count = from_cin();
    std::size_t const edge_count = from_cin();
    Graph const graph = [node_count, edge_count]() {
        Graph result(node_count, edge_count,
                     std::views::istream<GraphInputEdge>(std::cin)
                        | std::views::transform(&GraphInputEdge::sub1));
        result.remove_parallel_edges();
        result.remove_single_edge_loops();
        return result;
    }();
    std::unordered_map<unsigned, unsigned> dijkstra_previous =
        graph.dijkstra_shortest_paths(0u);
    std::optional<std::forward_list<unsigned>> shortest_path =
        Graph::dijkstra_reconstruct_path(dijkstra_previous, node_count - 1u);
    if(not shortest_path.has_value())
        std::cout << -1 << std::endl;
    else {
        for(auto const node_id : *shortest_path)
            std::cout << node_id + 1u << " ";
        std::cout << std::endl;
    }
}
