#ifndef GUESS_NUMBER_HIGHER_OR_LOWER_HPP_
#define GUESS_NUMBER_HIGHER_OR_LOWER_HPP_

class GuessNumberHigherOrLower {
public:
    typedef int (*GuessHint)(int);

public:
    GuessNumberHigherOrLower(GuessHint h);

    int guessNumber(int n);

private:
    GuessHint guess;
};

#endif // GUESS_NUMBER_HIGHER_OR_LOWER_HPP_