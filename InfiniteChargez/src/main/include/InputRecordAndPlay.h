#ifndef YEET_INPUT_RECORD_AND_PLAY
#define YEET_INPUT_RECORD_AND_PLAY
#include "XboxInputHandler.h"

#include <fstream>
#include <string>
namespace utilities
{
    class InputScribe
    {
    public:
        InputScribe() {}

        void loadRecording(std::ifstream &recordingFile);
        void playLoadedRecording();
        void pauseLoadedRecording();
        void stopLoadedRecording();
        void record(std::ofstream &outputFile);
    };
}
#endif