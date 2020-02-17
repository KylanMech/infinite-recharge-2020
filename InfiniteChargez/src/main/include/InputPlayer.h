#ifndef YEET_INPUT_PLAYER_H
#define YEET_INPUT_PLAYER_H
#include "HandlesChecksAndExecs.h"
#include "InputHandler.h"

#include <thread>
#include <fstream>
namespace utilities
{
    class InputPlayer
    {
    public:
        InputPlayer () {};

        void load(std::ifstream &recordingFile);
        void playTo(InputHandler &inputhandler);
        void playToAndExec(InputHandler &inputHandler, HandlesChecksAndExecs &probablyARobot);
        void stop();
    private:
        std::ifstream *m_recordingFile{};
        std::thread m_recordingThread{};

        void playRecordingExec(InputHandler &inputHandler, HandlesChecksAndExecs &probablyARobot, double delta);
        


    };
}
#endif