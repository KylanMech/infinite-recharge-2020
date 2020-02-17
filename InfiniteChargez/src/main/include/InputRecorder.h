#ifndef YEET_INPUT_RECORDER_H 
#define YEET_INPUT_RECORDER_H
#include "HandlesChecksAndExecs.h"

#include <fstream>
#include <string>

namespace utilities
{
    class InputRecorder
    {
    public:
    InputRecorder() {}

    void designateFile(std::ofstream &recordingFile);
    void recordFrom(HandlesChecksAndExecs &probablyARobot);
    void snapFrom(HandlesChecksAndExecs &probablyARobot);
    void stopRecording();

    private:
    std::ofstream *m_recording{};
    std::string m_recordingBuffer{};
    };
}
#endif