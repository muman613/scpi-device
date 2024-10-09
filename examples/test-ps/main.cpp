#include "scpi_device.h"
#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // Create a Programmable Power Supply object
    PSDevice ps("settings.ini", "device2");

    // Open the connection to the device
    if (ps.open() == OpenResult::Success) {
        // Set the output voltage to 12.5V
        if (ps.setVoltage(12.5)) {
            qDebug() << "Voltage set to 12.5V.";
        }

        // Enable the output
        ps.enableOutput(true);
        qDebug() << "Power supply output enabled.";

        // Measure the output voltage
        QString outputVoltage = ps.measureOutputVoltage();
        qDebug() << "Output Voltage:" << outputVoltage;

        // Measure the output current
        QString outputCurrent = ps.measureOutputCurrent();
        qDebug() << "Output Current:" << outputCurrent;

        // Disable the output
        ps.enableOutput(false);
        qDebug() << "Power supply output disabled.";
    } else {
        qCritical() << "Failed to open Power Supply device!";
    }

    return 0;
}
