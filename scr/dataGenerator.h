//
// Created by Lasse Lauritsen on 04/02/2017.
//

#ifndef RANDOMNUMBERDISTRIBUTION_DATAGENERATOR_H
#define RANDOMNUMBERDISTRIBUTION_DATAGENERATOR_H

#include <random>
class dataGenerator {
 public:
  dataGenerator(int dataSize);
  void addNumberUniform(int data[], int dataSize);
  void addNumberNormal(int data[], int dataSize);
 private:
  std::random_device rd_;
  std::mt19937 rnd_;
  std::uniform_int_distribution<int> uni_dist_;
  std::normal_distribution<> norm_dist_;
};

#endif //RANDOMNUMBERDISTRIBUTION_DATAGENERATOR_H
