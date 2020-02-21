#include "RoboCheckExec.h"
#include "XboxInputHandler.h"

#include <thread>
#include <chrono>
#include <string>
#include <fstream>

void RoboCheckExec::recordActionsExec(utilities::XboxInputHandler &leInputHandler, duration_t delta)
{
    if (leInputHandler.getButtonStartState() && recordingEnabled)
    {
        isRecording = true;
        recordingEnabled = false;
        meanDelta = delta.count();
    }
    if (leInputHandler.getButtonBackState() && isRecording) //Do not use elseif!!! If is for better response!!!
    {
        isRecording = false;
        duration_t meanDeltaFinal{meanDelta};
        m_robo->m_leRecordScribe.stopRecording(meanDeltaFinal);
        
        m_robo->m_recordFile.close();
    }

    if (isRecording)
    {
        std::cout << "recording" << '\n';
        meanDelta = (meanDelta + delta.count()) / 2;
        m_robo->m_leRecordScribe.snapFromAndWrite(m_robo);
    }
    if (leInputHandler.getButtonXPressed())
    {
        recordingEnabled = true;
        std::cout << "Recording Resetted";
    }
}