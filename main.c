#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "fmod.h"

#define NB_CHANNELS 3


// gcc main.c -L. -lfmod && install_name_tool -change "@rpath/libfmod.dylib" "libfmod.dylib"  a.out
int main(int argc, char *argv[])
{
    FMOD_SYSTEM *system;
    FMOD_SOUND *tir;
    FMOD_RESULT ret;

    FMOD_System_Create(&system);
    FMOD_System_Init(system, NB_CHANNELS, FMOD_INIT_NORMAL, NULL);

    ret = FMOD_System_CreateSound(system, "pan.wav", FMOD_CREATESAMPLE, 0, &tir);
    if (ret != FMOD_OK)
    {
        fprintf(stderr, "Impossible de lire pan.wav\n");
        exit(EXIT_FAILURE);
    }
        FMOD_System_PlaySound(system, tir, NULL, 0, NULL);
        sleep(1);
        FMOD_System_PlaySound(system, tir, NULL, 0, NULL);
    while (1)
        ;

    FMOD_Sound_Release(tir);
    FMOD_System_Close(system);
    FMOD_System_Release(system);

    return EXIT_SUCCESS;
}

// https://khayyam.developpez.com/articles/cpp/fmodex/
// https://www.fmod.com/resources/documentation-api?version=1.10&page=/content/generated/common/lowlevel_introduction.html#initialization
// https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c/19432-jouer-du-son-avec-fmod
// https://fmod.com/resources/documentation-api?version=2.0&page=core-api-common.html#fmod_3d
