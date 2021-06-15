#include "mlib.h"
#include <iostream>

using namespace std;

void sdl_init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cout << "Error\n";
        atexit(SDL_Quit);
        exit(1);
    }
}

void run() {
    char *chosen_key;
    int *chosen_metre;
    int opt;
    Opus *current_opus, *prev_opus;
    WindowsManager windowsManager = WindowsManager();
    OpusEditor opusEditor = OpusEditor();
    while (true) {
        opt = windowsManager.open();

        chosen_metre = windowsManager.get_chosen_metre();
        chosen_key = windowsManager.get_chosen_key();
        if (opt == CREATING_WINDOW_CODE) {
            cout << "Creating new opus\n";
            current_opus = opusEditor.run(chosen_key, chosen_metre, nullptr);
            cout <<"End of editing opus\n";
            printf("Saving opus as txt\n");
            save_Opus_as_TextFile(current_opus);
            cout << "Opus saved\n";
            cout <<"Try to free allocated memory of opus\n";
            delete current_opus;
            cout << "Allocated memory for opus freed\n";
        } else if (opt == MENU_LOAD_CODE) {
            cout << "Loading opus\n";
            prev_opus = fscanf_opus(nullptr);
            cout << "Opus loaded\n";
            cout << "Start editing loaded opus\n";
            current_opus = opusEditor.run(prev_opus->key, prev_opus->metre, prev_opus);
            cout << "End of editing loaded opus\n";
            cout << "Saving edited opus\n";
            save_Opus_as_TextFile(current_opus);
            cout << "Edited opus saved\n";
            delete current_opus; // also do free_opus(prev_OPUS) if prev_OPUS == current_OPUS;
        } else if (opt == MENU_EXIT_CODE) {
            cout << "Ending work\n";
            break;
        }
    }

}




