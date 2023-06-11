#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> adj, adj_rev, adj_scc;
std::vector<bool> visited;
std::vector<int> order, component, roots, root_nodes, in, out;

int num_edges, num_vertices;

void top_sort_dfs(int v) {
    visited[v] = true;

    for (auto u : adj[v])
        if (!visited[u])
            top_sort_dfs(u);

    order.push_back(v);
}

void reverse_top_sort() {
    visited.assign(num_vertices, false);

    for (int i = 0; i < num_vertices; i++)
        if (!visited[i])
            top_sort_dfs(i);

    visited.assign(num_vertices, false);
    std::reverse(order.begin(), order.end());
}

void find_component(int v) {
    visited[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!visited[u])
            find_component(u);
}

void find_representants() {
    for (auto v : order) {
        if (!visited[v]) {
            find_component(v);
        
            int root = v;
            for (auto u : component) {
                roots[u] = root;
            }
            root_nodes.push_back(root);
        
            component.clear();
        }
    }
}

void usage() {
    std::cout << "Uso: ./spy <numero_teste>\n";
    std::cout << "numero_teste : [1, 37]\n";
    std::cout << '\n';
    exit(0);
}

void read_data(int argc, char** argv) {
    if(argc != 2) {
        usage();
    }
    
    int num_teste = 1;
    try {
        num_teste = std::stoi(argv[1]);
    } catch(const std::invalid_argument& e) {
        usage();
    }

    std::ifstream input_file{"input/H_" + std::to_string(num_teste)};

    input_file >> num_vertices >> num_edges;
    
    adj = std::vector<std::vector<int>>(num_vertices);
    adj_rev = std::vector<std::vector<int>>(num_vertices);
    roots = std::vector<int>(num_vertices, 0);
    adj_scc = std::vector<std::vector<int>>(num_vertices);

    for (int i = 0; i < num_edges; i++) {
        int u, v; input_file >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }
}

void build_sccs() {
    in = std::vector<int>(num_vertices, 0);
    out = std::vector<int>(num_vertices, 0);
    for (int v = 0; v < num_vertices; v++) {
        for (auto u : adj[v]) {
            if (roots[u] != roots[v]) {
                in[roots[u]]++;
                out[roots[v]]++;
                adj_scc[roots[v]].push_back(roots[u]);
            }
        }
    }
}

void calculate_new_edges() {
    int sinks = 0;
    int sources = 0;
    int isolateds = 0;

    for(int x : root_nodes) {
        if(out[x] == 0 && in[x] == 0) {
            isolateds++;
        } else if(out[x] == 0) {
            sinks++;
        } else if(in[x] == 0) {
            sources++;
        }
    }

    if(sinks + sources + isolateds <= 1) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << std::max(sinks + isolateds, sources + isolateds) << std::endl;
    }
}

void kosaraju_sharir() {
    reverse_top_sort();
    find_representants();
    build_sccs();
    calculate_new_edges();
}

int main(int argc, char** argv) {
    read_data(argc, argv);

    kosaraju_sharir();
}