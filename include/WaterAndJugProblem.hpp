#ifndef WATER_AND_JUG_PROBLEM_HPP_
#define WATER_AND_JUG_PROBLEM_HPP_

class WaterAndJugProblem {
public:
    bool canMeasureWater(int x, int y, int z);

private:
    int gcd(int x, int y);
};

#endif // WATER_AND_JUG_PROBLEM_HPP_