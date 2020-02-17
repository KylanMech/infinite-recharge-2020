#include "InputRecorder.h"

namespace utilities
{
    void InputRecorder::designateFile(std::ofstream &recordingFile)
    {
        m_recording = &recordingFile;
    }

}