#ifndef YEET_INPUT_RECORDER_H 
#define YEET_INPUT_RECORDER_H
#include "HandlesChecksAndExecs.h"

#include <fstream>
namespace utilities
{
    class InputRecorder
    {
    public:
    InputRecorder() {}

    void designateFile(std::ofstream &recordingFile);
    void recordFrom(HandlesChecksAndExecs &probablyARobot);
    private:
    std::ofstream *m_recording{};
    };
}
#endif