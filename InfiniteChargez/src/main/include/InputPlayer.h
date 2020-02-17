#ifndef YEET_INPUT_PLAYER_H
#define YEET_INPUT_PLAYER_H
#include "HandlesChecksAndExecs.h"
#include "InputHandler.h"

#include <fstream>
namespace utilities
{
    class InputRecorder
    {
    public:
        InputRecorder() {};

        void load(std::ifstream &recordingFile);
        void playTo(InputHandler &inputhandler);
        void playToAndExec(InputHandler &inputHandler, HandlesChecksAndExecs &probablyARobot);
        void stop();
    };
}
#endif