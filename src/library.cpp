#include "library.h"
#include <iostream>
#include "OPUS_EDITOR/opusEditor.h"

using namespace std;

void sdl_init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Error\n");
        atexit(SDL_Quit);
        exit(1);
    }
}
void run() {
    char *chosen_key;
    int *chosen_metre;
    int opt;
    Opus *current_OPUS = nullptr, *prev_OPUS = nullptr;
    WindowsManager windowsManager = WindowsManager();
    OpusEditor opusEditor = OpusEditor();
    int k=0;
    while (true) {

        k++;
        cout << k << endl;

        opt = windowsManager.menu_open();
        cout << k << endl;

        chosen_metre = windowsManager.get_chosen_metre();
        chosen_key = windowsManager.get_chosen_key();
        if (opt == CREATING_WINDOW_CODE) {
            cout << "Creating new opus\n";
            current_OPUS = opusEditor.run(chosen_key, chosen_metre, nullptr);
            cout <<"End of editing opus\n";
            printf("Saving opus as txt\n");
            save_OPUS_as_TextFile(current_OPUS);
            cout << "Opus saved\n";
            cout <<"Try to free allocated memory of opus\n";
            delete current_OPUS;
            cout << "Allocated memory for opus freed\n";
        } else if (opt == MENU_LOAD_CODE) {
            cout << "Loading opus\n";
            prev_OPUS = fscanf_opus(nullptr);
            cout << "Opus loaded\n";
            cout << "Start editing loaded opus\n";
            current_OPUS = opusEditor.run(prev_OPUS->key, prev_OPUS->time_sign, prev_OPUS);
            cout << "End of editing loaded opus\n";
            cout << "Saving edited opus\n";
            save_OPUS_as_TextFile(current_OPUS);
            cout << "Edited opus saved\n";
            delete current_OPUS; // also do free_opus(prev_OPUS); prev_OPUS == current_OPUS;
        } else if (opt == MENU_EXIT_CODE) {
            cout << "Ending work\n";
            break;
        }
    }

}




