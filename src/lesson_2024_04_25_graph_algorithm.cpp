/*
 * lesson_2024_04_25_graph_algorithm.cpp
 *
 *  Created on: Apr 25, 2024
 *      Author: KZ
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>
#include <climits>

namespace lesson_2024_04_25_graph_algorithm {

typedef std::vector<std::vector<int>> Matrix;

const int INFINITY = INT_MAX/2; // it should not overflow when adding two values

struct MatrixGraph {
  size_t num_vertices;

  Matrix weight_matrix;

  MatrixGraph(size_t num_vertices): num_vertices(num_vertices), weight_matrix(num_vertices) {
    assert(weight_matrix.size() == num_vertices);
    for(size_t i = 0; i < num_vertices; i++) {
      weight_matrix[i].resize(num_vertices);
      std::fill(weight_matrix[i].begin(), weight_matrix[i].end(), INFINITY);
      weight_matrix[i][i] = 0;
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

void print_vector(const std::vector<int>& vector) {

    for(size_t j=0; j<vector.size(); j++) {
      if (vector[j] == INFINITY) {
        std::cout<<"- ";
      } else {
        std::cout<< vector[j] << " ";
      }
    }
    std::cout<<std::endl;

}

void print_matrix(const Matrix& matrix) {
  for(size_t i=0; i<matrix.size(); i++) {
    print_vector(matrix[i]);
//    for(size_t j=0; j<matrix[i].size(); j++) {
//      if (matrix[i][j] == INFINITY) {
//        std::cout<<"- ";
//      } else {
//        std::cout<< matrix[i][j] << " ";
//      }
//    }
//    std::cout<<std::endl;
  }
}


Matrix all_shortest_paths_Floyd(const MatrixGraph& graph) {
  Matrix result = graph.weight_matrix;
  for(size_t k = 0; k < graph.num_vertices; k++ ) {
    for(size_t i = 0; i < graph.num_vertices; i++ ) {
      for(size_t j = 0; j < graph.num_vertices; j++ ) {
        result[i][j] = std::min({result[i][j], result[i][k] + result[k][j], INFINITY });
      }
    }
  }

  return result;
}

std::vector<int> shortest_paths_from_vertex_Dijkstra(const MatrixGraph& graph, size_t from) {
  std::vector<int> result(graph.num_vertices, INFINITY);
  result[from] = 0;
  std::queue<size_t> visited;
  visited.push(from);
  while (!visited.empty()) {
    size_t current = visited.front();
    visited.pop();
    for(size_t i = 0; i < graph.num_vertices; i++) {
      if (i == current) { continue;} // same vertex
      if (graph.weight_matrix[current][i] == INFINITY) { continue;} // no edge
      if (result[i] < INFINITY) { continue; } // already processed
      result[i] = result[current] + graph.weight_matrix[current][i];
      visited.push(i);
    }
  }


  return result;
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

  std::cout<<"finding all shortest paths"<<std::endl;
  Matrix shortest_paths = all_shortest_paths_Floyd(graph);
  print_matrix(shortest_paths);

  std::cout<<"finding shortest paths from vertex 0"<<std::endl;
  std::vector<int> shortest_from_0 = shortest_paths_from_vertex_Dijkstra(graph,0);
  print_vector(shortest_from_0);
  return 0;
}
}

