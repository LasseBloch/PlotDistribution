//
// Created by Lasse Lauritsen on 04/02/2017.
//

#include <iostream>
#include "dataGenerator.h"
dataGenerator::dataGenerator(int dataSize) :  rnd_(rd_()) {
  uni_dist_ = std::uniform_int_distribution<int>(0, dataSize);
  norm_dist_ = std::normal_distribution<> (dataSize/2, 15);
}

void dataGenerator::addNumberUniform(int data[], int dataSize) {
  data[uni_dist_(rnd_)]++;
}

void dataGenerator::addNumberNormal(int data[], int dataSize) {
  // Make sure that N is generated with in the correct range
  int n = -1;
  do {
    n = (int) std::abs(std::round(norm_dist_(rnd_)));
  }
  while ((n < 0 || n > dataSize));
  data[n]++;
}
