#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

#include "foes.h"
#include "general.h"

// Creates the foes' interactions:

void foeInteraction (int foeNumber, int territory, int &life) {

    std::vector <std::string> words2, words3, words4;
    std::vector <int> prob1;
    std::string empty, fightOrFlee, giantAction, talkOrRun;
    int giantLife, manLife;

    giantLife = 100;
    manLife = 100;
    empty = "there is no one there.";

    switch (territory) {

        case 3:
            switch (foeNumber) {
                case 1:
                    std::cout << empty;
                    break;
                case 2:
                    std::cout << "you see a furious giant, choose: ";
                    words2 = {"fight", "flee"};
                    fightOrFlee = checkWords (2, words2);
                    std::cout << std::endl;
                    while (giantLife > 0 && life > 0 && fightOrFlee == "fight") {
                        if (fightOrFlee == "fight") {
                            words3 = {"He tries to grab you, ", "He tries to seize you, "};
                            prob1 = {50, 50};
                            giantAction = randomizeWordsWithProbability (2, prob1, words3);
                        }
                        if (giantAction == "He tries to grab you, " || giantAction == "He tries to seize you, ") {
                            std::cout << giantAction;
                            giantCombat (life, giantLife);
                        }
                        if (giantLife > 0 && life > 0) {
                            fightOrFlee = checkWords (2, words2);
                            std::cout << std::endl;
                        }
                    }
                    if (fightOrFlee == "fight") {
                        if (life > 0) {
                            std::cout << "You've killed the beast!\n";
                        }
                        else {
                            if (giantLife <= 0) {
                                std::cout << "You've killed the beast, but died while doing so!";
                            }
                            else {
                                std::cout << "You've died trying to kill the beast!";
                            }
                        }
                    }
                    break;
                case 3:
                    std::cout << "you came into an ambush, with approximately 20 men, choose: ";
                 /*
                  words4 = {"talk", "run"};
                    talkOrRun = checkWords (2, words4);
                    std::cout << std::endl;
                    if (talkOrRun == "run") {
                        ambushRun (life);
                        if (life < 1) {
                            std::cout << "You've died trying to scape!";
                        }
                    }
                    else {
                        ambushTalk (life, manLife);
                    }
                    break;
                default:
                    std::cout << "there are sleepy monkeys in the trees around you, choose: ";
       */
                    break;
            }
            break;

        case 4:
            switch (foeNumber) {
                case 1:
                    std::cout << empty;
                    break;
                case 2:
                    std::cout << "you see a troll, choose: ";
                    break;
                case 3:
                    std::cout << "you see a group of people, choose: ";
                    break;
                default:
                    std::cout << "there are wild bulls all around the field, choose: ";
                    break;
            }
            break;

        default:
            switch (foeNumber) {
                case 1:
                    std::cout << empty;
                    break;
                case 2:
                    std::cout << "you see an orc, choose: ";
                    break;
                case 3:
                    std::cout << "you see a wagon coming at your direction, choose: ";
                    break;
                default:
                    std::cout << "there are sheep blocking the road, choose: ";
                    break;
            }
            break;
    }

}

// Ambush talk:

void ambushTalk (int &life, int &foeLife) {

    std::vector <std::string> words5, words6;
    std::string answer;
    int i;


    std::cout << "I'm just a pious priest going to the church. / Do you dare to point your weapons to THE GREATEST WARRIOR OF THE KINGDOM!? Choose: ";
    words5 = {"priest", "warrior"};
    answer = checkWords (2, words5);

    if (answer == "priest") {
        std::cout << "Unknown man: \"If you are really a priest, you know how to read and write. So spell the word used to address the king, you have three chances:\" ";
        std::cin >> answer;
        std::transform (answer.begin(), answer.end(), answer.begin(), ::tolower);
        i = 0;
        do {
            i++;
            if (answer != "lord") {
                if (i == 1) {
                    std::cout << "Unknown man: \"That's not right \"priest\", try it again:\" ";
                    std::cin >> answer;
                    std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
                }
                if (i == 2) {
                    std::cout << "Unknown man: \"I'm smelling a lie:\" ";
                    std::cin >> answer;
                    std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
                }
                if (i == 3) {
                    std::cout << "Unknown man: \"And liars must die!\"";
                }
            }
        } while (i < 4 && answer != "lord");
        if (answer != "lord") {
            std::cout << "\nYou've died in the ambush.";
            life = 0;
        }
        else {
            std::cout << "Unknown man: \"Good job priest, you can follow you path safely.\"";
        }
    }
    else {
        std::cout << "Unknown man: \"If you are who you say, you'll not have problems fighting with OUR greatest warrior.\" Choose: ";
        words6 = {"run", "fight"};
        answer = checkWords (2, words6);
        if (answer == "run") {
            ambushRun (life);
        }
        else {
            ambushCombat (life, foeLife);
        }
    }
}

// Calculates the man's damage and character's damage:

void ambushCombat (int &life, int &foeLife) {

    std::vector <std::string> words7, words8;
    std::vector <int> foePenalty, characterPenalty;
    std::string answer;
    int foeDamage, foeDamageChanged, characterDamage, characterDamageChanged, action;

    characterDamage = randomizeNumber (10);
    foeDamage = randomizeNumber (10);

    std::cout << "A furious man comes running at your direction.\n";
    std::cout << "Throw your sword at him, and use your knife for the combat. / Draw you sword and prepare for the fight.\n";
    words7 = {"throw", "prepare"};
    answer = checkWords (2, words7);
    if (answer == "throw") {
        action = randomizeNumber (10);
        if (action < 7) {
            std::cout << "You've missed.\n";
            characterDamage = 0;
            dealsDamage (characterDamage, foeLife);
            characterPenalty[0] = 3;
            std::cout << "He reached you and tried to strike your chest.\n";
            std::cout << "Try to tumble and hit him back while doing so. / Try to parry it with your knife.\n";
            words8 = {"tumble", "parry"};
            answer = checkWords (2, words8);
            if (answer == "tumble") {
                action = randomizeNumber (10);
                if (action < 4) {
                    std::cout << "You are not so good at tumbling, you stabbed your leg while doing so.\n";
                    characterPenalty[1] = 5;
                    foeDamageChanged = foeDamage * 2;
                    receivesDamage (foeDamageChanged, life);
                }
                else {
                    std::cout << "You stroke your knife at your opponent in the leg.\n";
                    foePenalty[0] = 7;
                    characterDamageChanged = characterDamage * 7;
                    characterDamageChanged -= characterPenalty;
                    dealsDamage (characterDamageChanged, foeLife);
                }
                std::cout << "He tries to"
            }
        }
        else {
            std::cout << "Your sword hit his left arm.\n";
            foePenalty = 6;
        }
    }

}

// Calculates the ambush's damage while trying to run:

void ambushRun (int &life) {

    int foeDamage;

    foeDamage = randomizeNumber(10);

    if (foeDamage > 9) {
        std::cout << "You ran but you were pierced by an arrow in the chest.\n";
        foeDamage = round (life * 0.9);
        receivesDamage (foeDamage, life);
    }
    else {
        if (foeDamage > 7) {
            std::cout << "You ran but you were pierced by an arrow in your right leg.\n";
            foeDamage = round (life * 0.4);
            receivesDamage (foeDamage, life);
        }
        else {
            if (foeDamage > 4) {
                std::cout << "You ran but you were pierced by an arrow in your right arm.\n";
                foeDamage = round (life * 0.2);
                receivesDamage (foeDamage, life);
            }
            else {
                std::cout << "You escaped safely.\n";
                foeDamage = 0;
                receivesDamage (foeDamage, life);
            }
        }
    }
}
*/
// Calculates the giant's damage and character's damage:

void giantCombat (int &life, int &foeLife) {

    std::vector <std::string> characterPenaltyText, foePenaltyText;
    std::vector <int> foePenalty, foePenaltyTextQuantity, characterPenalty, characterPenaltyTextQuantity;
    int foeDamage, characterDamage;

        characterDamage = randomizeNumber(10);
        foeDamage = randomizeNumber (10);

        if (characterDamage > 9) {
            std::cout << "but while he is trying to do it, you strike him right in the face.\n";
            characterDamage *= 8;
            dealsDamage (characterDamage, foeLife, characterPenalty, characterPenaltyText, characterPenaltyTextQuantity);
        }
        else {
            if (characterDamage > 7) {
                std::cout << "but while he is trying to do it, you strike him right in the chest.\n";
                characterDamage *= 4;
                dealsDamage (characterDamage, foeLife, characterPenalty, characterPenaltyText, characterPenaltyTextQuantity);
            }
            else {
                if (characterDamage > 3) {
                    std::cout << "but while he is trying to do it, you strike him right in the leg.\n";
                    characterDamage *= 2;
                    dealsDamage (characterDamage, foeLife, characterPenalty, characterPenaltyText, characterPenaltyTextQuantity);
                }
                else {
                    std::cout << "you were not able to strike him.\n";
                    characterDamage = 0;
                    dealsDamage (characterDamage, foeLife, characterPenalty, characterPenaltyText, characterPenaltyTextQuantity);
                }
            }
        }

        if (foeDamage > 9) {
            std::cout << "Then, when he finally grabs you, he throws you eight meters away and you hit a sharp edge rock.\n";
            foeDamage *= 4;
            receivesDamage (foeDamage, life, foePenalty, foePenaltyText, foePenaltyTextQuantity);
        }
        else {
            if (foeDamage > 7) {
                    std::cout << "Then, when he finally grabs you, he throws you six meters away and you hit a rotten tree.\n";
                    foeDamage *= 2;
                receivesDamage (foeDamage, life, foePenalty, foePenaltyText, foePenaltyTextQuantity);
            }
            else {
                if (foeDamage > 3) {
                    std::cout << "Then, when he finally grabs you, he throws you three meters away and you hit the ground.\n";
                    receivesDamage (foeDamage, life, foePenalty, foePenaltyText, foePenaltyTextQuantity);
                }
                else {
                    std::cout << "And you successfully evades him.\n";
                    foeDamage = 0;
                    receivesDamage (foeDamage, life, foePenalty, foePenaltyText, foePenaltyTextQuantity);
                }
            }
        }
}


// Informs the damage done by the foe, and reduces your life:

void receivesDamage (int foeDamage, int &life, std::vector <int> foePenalty, std::vector <std::string> foePenaltyText, std::vector <int> foePenaltyTextQuantity) {

    int totalPenalties;

    totalPenalties = foePenalties (foePenalty, foePenaltyText, foePenaltyTextQuantity);
    foeDamage -= totalPenalties;

    if (foeDamage > 0) {
        std::cout << "Receiving " << foeDamage << " of damage.\n";
        life -= foeDamage;
        std::cout << "Your current life is: " << life << "\n\n";
    }
    else {
        std::cout << "Don't receiving any damage.\n";
        std::cout << "Your current life is: " << life << "\n\n";
    }

}

// Informs the damage done by you, and reduces the foes' life:

void dealsDamage (int characterDamage, int &foesLife, std::vector <int> characterPenalty, std::vector <std::string> characterPenaltyText, std::vector <int> characterPenaltyTextQuantity) {

    int totalPenalties;

    totalPenalties = characterPenalties (characterPenalty, characterPenaltyText, characterPenaltyTextQuantity);
    characterDamage -= totalPenalties;

    if (characterDamage > 0) {
        std::cout << "Dealing " << characterDamage << " of damage.\n";
        foesLife -= characterDamage;
        std::cout << "The foes current life is: " << foesLife << "\n\n";
    }
    else {
        std::cout << "Don't dealing any damage.\n";
        std::cout << "The foes current life is: " << foesLife << "\n\n";
    }

}

// Calculates total penalties and show it:

int characterPenalties (std::vector <int> characterPenalty, std::vector <std::string> characterPenaltyText, std::vector <int> characterPenaltyTextQuantity) {

    int totalCharacterPenalty, i;
    totalCharacterPenalty = 0;

    for (i = 0; i <= characterPenalty.size(); i++) {
        totalCharacterPenalty += characterPenalty[i];
    }

    if (totalCharacterPenalty < 1) {
        std::cout << "You aren't hurt yet.\n";
    }
    else {
        std::cout << "Your penalties are:\n";
        for (i = 0; i <= characterPenalty.size(); i++) {
            std::cout << characterPenaltyTextQuantity[i] << " " << characterPenaltyText[i] << " Dealing" << characterPenalty[i]<< " less damage.\n";
        }
    }

    return totalCharacterPenalty;

}

int foePenalties (std::vector <int> foePenalty, std::vector <std::string> foePenaltyText, std::vector <int> foePenaltyTextQuantity) {

    int totalFoePenalty, i;
    totalFoePenalty = 0;

    for (i = 0; i <= foePenalty.size(); i++) {
        totalFoePenalty += foePenalty[i];
    }

    if (totalFoePenalty < 1) {
        std::cout << "The foe isn't hurt yet.\n";
    }
    else {
        std::cout << "The foe's penalties are:\n";
        for (i = 0; i <= foePenalty.size(); i++) {
            std::cout << foePenaltyTextQuantity[i] << " " << foePenaltyText[i] << " Dealing" << foePenalty[i]<< " less damage.\n";
        }
    }

    return totalFoePenalty;

}