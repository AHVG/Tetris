#include <random>
#include <utility>

#include "brick_generator.h"

BrickGenerator::BrickGenerator() {}

BrickGenerator::~BrickGenerator() {}

std::pair<std::vector<int>, int> BrickGenerator::generate() {
    std::vector<std::pair<std::vector<int>, int>> matrices;

    matrices.push_back(std::make_pair(std::vector<int>{0, 1, 0, 1, 1, 1, 0, 0, 0}, 3));
    matrices.push_back(std::make_pair(std::vector<int>{1, 0, 0, 1, 1, 1, 0, 0, 0}, 3));
    matrices.push_back(std::make_pair(std::vector<int>{0, 0, 1, 1, 1, 1, 0, 0, 0}, 3));
    matrices.push_back(std::make_pair(std::vector<int>{1, 1, 1, 1}, 2));
    matrices.push_back(std::make_pair(std::vector<int>{0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, 4));

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, matrices.size() - 1);
    int chosen_brick = distrib(gen);

    return matrices[chosen_brick];
}
