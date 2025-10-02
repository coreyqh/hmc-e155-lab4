
#include "lab4.h"


int main() {

    uint8_t song; // 1 for fur elise 2 for stone tower

    init();

    while (1) {
        song = readSongChoice();
        if (song == 1) {
            playSong(fur_elise, sizeof(fur_elise));
        } else if (song == 2) {
            playSong(stone_tower, sizeof(stone_tower));
        }
        // no else, keep waiting

    }


}