#include <iostream>

#include "foes.h"
#include "general.h"

// Shows the map's message:

std::string territoryMessage (int foeNumber, int territory) {

    std::string mapMessage, empty, fightOrFlee, giantAction;
    int giantActionsQuantity;

    giantActionsQuantity = 2;
    empty = "there is no one there.";

    switch (territory) {

        case 3:
            switch (foeNumber) {
                case 1:
                    mapMessage = empty;
                    break;
                case 2:
                    mapMessage = "you see a furies giant.";
                    fightOrFlee = checkTwoWords ("fight", "flee");
                    if (fightOrFlee == "fight") {
                        giantAction = giantActionGenerator (giantActionsQuantity);
                    }
                    break;
                case 3:
                    mapMessage = "you came into an ambush.";
                    break;
                default:
                    mapMessage = "there are sleepy monkeys in the trees around you.";
                    break;
            }

        case 4:
            switch (foeNumber) {
                case 1:
                    mapMessage = empty;
                    break;
                case 2:
                    mapMessage = "you see a troll.";
                    break;
                case 3:
                    mapMessage = "you see a group of people.";
                    break;
                default:
                    mapMessage = "there are wild bulls all around the field.";
                    break;
            }

        default:
            switch (foeNumber) {
                case 1:
                    mapMessage = empty;
                    break;
                case 2:
                    mapMessage = "you see an orc.";
                    break;
                case 3:
                    mapMessage = "you see a wagon coming at your direction.";
                    break;
                default:
                    mapMessage = "there are sheep blocking the road.";
                    break;
            }
    }

    return mapMessage;

}

std::string giantActionGenerator (int giantActionsQuantity) {

    randomize (giantActionsQuantity);


}