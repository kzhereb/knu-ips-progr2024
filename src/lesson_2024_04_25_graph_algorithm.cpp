/*
 * lesson_2024_04_25_graph_algorithm.cpp
 *
 *  Created on: Apr 25, 2024
 *      Author: KZ
 */

#include <iostream>
#include <vector>
#include <cassert>

namespace lesson_2024_04_25_graph_algorithm {

typedef std::vector<std::vector<int>> Matrix;

struct MatrixGraph {
  size_t num_vertices;

  Matrix weight_matrix;

  MatrixGraph(size_t num_vertices): num_vertices(num_vertices), weight_matrix(num_vertices) {
    assert(weight_matrix.size() == num_vertices);
    for(size_t i = 0; i < num_vertices; i++) {
      weight_matrix[i].resize(num_vertices);
      assert(weight_matrix[i].size() == num_vertices);
    }
  }


};

void add_edge(MatrixGraph& graph, size_t from, size_t to, int weight, int offset = 0) {
  from -= offset;
  to -= offset;
  assert(from < graph.num_vertices);
  assert(to < graph.num_vertices);
  graph.weight_matrix[from][to] = weight;
  graph.weight_matrix[to][from] = weight;
}

void print_matrix(const Matrix& matrix) {
  for(size_t i=0; i<matrix.size(); i++) {
    for(size_t j=0; j<matrix[i].size(); j++) {
      std::cout<< matrix[i][j] << " ";
    }
    std::cout<<std::endl;
  }
}


int main() {
  MatrixGraph graph(5);
  add_edge(graph, 1, 2, 8, 1);
  add_edge(graph, 1, 3, 3, 1);
  add_edge(graph, 1, 4, 1, 1);
  add_edge(graph, 2, 3, 4, 1);
  add_edge(graph, 2, 5, 2, 1);
  add_edge(graph, 3, 4, 1, 1);
  add_edge(graph, 3, 5, 1, 1);
  add_edge(graph, 4, 5, 8, 1);

  print_matrix(graph.weight_matrix);
  return 0;
}
}

