#include "InputRecordAndPlay.h"
#include "chrono"
namespace utilities
{

void InputRecordAndPlay::loadRecording(std::ifstream &recordingFile)
{
    m_recording = &recordingFile;
}

void InputRecordAndPlay::playLoadedRecordingToAndExec(HandlesChecksAndExecs &probablyARobot)
{
    m_player.load(*m_recording);
    m_player.playToAndExec(probablyARobot);

}
void InputRecordAndPlay::stopRecording(std::chrono::duration<double> &delta)
{
    m_recorder.stopRecording(delta);
}

void InputRecordAndPlay::recordFromAndTo(HandlesChecksAndExecs &probablyARobot, std::ofstream &outputFile)
{
    m_recorder.designateFile(outputFile);
    m_recorder.recordFrom(probablyARobot);
}
void InputRecordAndPlay::snapFromAndWrite(HandlesChecksAndExecs *probablyARobot)
{
    m_recorder.snapFrom(probablyARobot);
}

void InputRecordAndPlay::designateFile(std::ofstream &recordingFile)
{
    m_recorder.designateFile(recordingFile);
}


}