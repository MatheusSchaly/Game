#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include <vector>

#include "general.h"

// Validates four words:

std::string checkFourWords (std::string word1, std::string word2, std::string word3, std::string word4) {

    std::string wordChecked;

    do {
        std::cout << word1 << " / " << word2 << " / " << word3 << " / " << word4 << ": ";
        std::cin >> wordChecked;
        std::transform (wordChecked.begin(), wordChecked.end(), wordChecked.begin(), ::tolower);
    } while (wordChecked != word1 && wordChecked != word2 && wordChecked != word3 & wordChecked != word4);

    return wordChecked;

}

// Validates two words:

std::string checkTwoWords (std::string word1, std::string word2) {

    std::string wordChecked;

    do {
        std::cout << word1 << " / " << word2 << ": ";
        std::cin >> wordChecked;
        std::transform (wordChecked.begin(), wordChecked.end(), wordChecked.begin(), ::tolower);
    } while (wordChecked != word1 && wordChecked != word2);

    return wordChecked;

}

// Validates a positive integer number:

int readIntPositiveNumber () {

    int n;

    do {
        std::cin >> n;
        if (n < 1) {
            std::cout << "The number has to be positive:";
        }
    } while (n < 1);

    return n;

}

// Validates a number between limits:

int readIntIntervalNumber (int lowerLimit, int upperLimit) {

    int n;

    do {
        std::cin >> n;
        if (n < lowerLimit || n > upperLimit) {
            std::cout << "The number has to be between " << lowerLimit << " and " << upperLimit;
        }
    } while (n < lowerLimit || n > upperLimit);

    return n;

}

// Randomizes a number:

int randomizeNumber (int n) {

    return rand() % n + 1;

}

// Randomizes two words:

std::string randomizeUpToFiveWords (std::string word1, std::string word2, std::string word3, std::string word4, std::string word5)  {

    srand (time(0));
    std::string word;

    do {
    const std::string wordList[5] = {word1, word2, word3, word4, word5};
    word = wordList [rand() % 5];
    } while (word == "0");

    return word;

}

// Randomizes an vector with probabilities:

int randomizeNumberWithProbability (int nQuantity, int* probability) {

    int val, i, j, n;

    val = rand() % 100;
    n = 1;

    std::cout << "OWW!!\n";
    for (i = 1; i < nQuantity + 1; i++) {
        std::cout << probability[i] << std::endl;
    }

    for (i = 1; i < nQuantity; i++) {
        probability [i] += probability [i - 1];
    }

    for (i =1; i < nQuantity; i++) {
        if (val < probability [i] && val > probability [i - 1]) {
            n = i + 1;
            i = nQuantity;
        }
    }

    std::cout << "HEY!!\n";
    for (i = 1; i < nQuantity + 1; i++) {
        std::cout << probability[i] << std::endl;
    }

    return n;

}
