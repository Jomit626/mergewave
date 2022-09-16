#include <cstdio>
#include <getopt.h>
#include <iostream>
#include <vector>

#include "evaluator.hpp"
#include "spdlog/spdlog.h"

using namespace std;
using namespace mergewave;

const char *trace_file = nullptr;

void parse_args(int argc, char *argv[]) {
  static struct option long_options[] = {{"verbose", no_argument, 0, 0},
                                         {"trace", required_argument, 0, 0},
                                         {0, 0, 0, 0}};

  int c;
  int option_id;
  while (true) {
    c = getopt_long(argc, argv, "vt:", long_options, &option_id);

    if (c == -1)
      break;

    switch (c) {
    case 0:
      printf("long option %s\n", long_options[option_id].name);
      if (optarg)
        printf("with arg: %s\n", optarg);
      if (option_id == 1)
        trace_file = optarg;
      break;
    case 'v':
      printf("option v\n");
      break;
    case 't':
      printf("option t with arg %s\n", optarg);
      trace_file = optarg;
      break;
    default:
      break;
    }
  }
}


int main(int argc, char *argv[]) {
  parse_args(argc, argv);
  if (trace_file == nullptr) {
    printf("no trace file\n");
    return 0;
  }
  printf("test for sv file: %s\n", trace_file);

  auto evaluator = make_unique<SVEvaluator>(trace_file);
  auto ports = evaluator->get_top_port();

  for(auto &p: *ports) {
    spdlog::info("port name:{} {}", p.name, p.dir);
  }
  return 0;
}
