#ifndef YEET_INPUT_RECORD_AND_PLAY
#define YEET_INPUT_RECORD_AND_PLAY
#include "HandlesChecksAndExecs.h"
#include "XboxInputHandler.h"

#include <fstream>
#include <string>
namespace utilities
{
    class InputRecordAndPlay
    {
    public:
        InputRecordAndPlay() {}

        void loadRecording(std::ifstream &recordingFile);

        void playLoadedRecordingTo(utilities::XboxInputHandler);
        void playLoadedRecordingToAndExec(HandlesChecksAndExecs &probablyARobot);
        void pauseLoadedRecording();
        void stopLoadedRecording();

        void recordFromAndTo(HandlesChecksAndExecs &probablyARobot, std::ofstream &outputFile);
    };
}
#endif