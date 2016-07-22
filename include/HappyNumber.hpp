#ifndef HAPPY_NUMBER_HPP_
#define HAPPY_NUMBER_HPP_

class HappyNumber {
public:
    bool isHappy(int n);
private:
    int digitSquareSum(int n);
    bool isHappyHash(int n);
    bool isHappyTwoPointers(int n);
};

#endif // HAPPY_NUMBER_HPP_
