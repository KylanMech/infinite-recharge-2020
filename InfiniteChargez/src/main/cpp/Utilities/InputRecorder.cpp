#include "InputRecorder.h"

#include <thread>

namespace utilities
{
    void InputRecorder::designateFile(std::ofstream &recordingFile)
    {
        m_recording = &recordingFile;
    }

    void InputRecorder::recordFrom(HandlesChecksAndExecs &probablyARobot)
    {
    }

    void InputRecorder::snapFrom(HandlesChecksAndExecs &probablyARobot)
    {
        *m_recording << probablyARobot.getInputHandler().getSnapshot() << '\n';
    }


}