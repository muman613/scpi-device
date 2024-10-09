#include "scpi_device.h"
#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // Create a Digital Oscilloscope object
    OSCDevice osc("settings.ini", "device3");

    // Open the connection to the device
    if (osc.open() == OpenResult::Success) {
        // Start signal acquisition
        osc.startAcquisition();
        qDebug() << "Signal acquisition started.";

        // Measure signal frequency
        QString frequency = osc.measureFrequency();
        qDebug() << "Measured Frequency:" << frequency;

        // Retrieve waveform data
        QString waveform = osc.retrieveWaveform();
        qDebug() << "Retrieved Waveform Data:" << waveform;

        // Stop signal acquisition
        osc.stopAcquisition();
        qDebug() << "Signal acquisition stopped.";
    } else {
        qCritical() << "Failed to open Oscilloscope device!";
    }

    return 0;
}
