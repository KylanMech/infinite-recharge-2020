#include "InputPlayer.h"

#include <fstream>
#include <string>
#include <thread>

namespace utilities
{
    void InputPlayer::load(std::ifstream &recordingFile)
    {
        m_recordingFile = &recordingFile;

    }

    void InputPlayer::playToAndExec(InputHandler &inputHandler, HandlesChecksAndExecs &probablyARobot)
    {
        std::string delta{""};

        std::getline(*m_recordingFile, delta);

        m_recordingThread = std::thread{InputPlayer::playRecordingExec, this, inputHandler, probablyARobot, delta};
        m_recordingThread.detach();

    }
    
    void InputPlayer::stop()
    {

    }
    
    void InputPlayer::playRecordingExec(InputHandler &inputHandler, HandlesChecksAndExecs &probablyARobot, double delta)
    {

    }

}
