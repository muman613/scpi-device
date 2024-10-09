#include "scpi_device.h"
#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // Create a Digital Multimeter object
    DVMDevice dvm("settings.ini", "device1");

    // Open the connection to the device
    if (dvm.open() == OpenResult::Success) {
        // Send a command to measure DC voltage
        QString voltage = dvm.measureVoltageDC();
        qDebug() << "Measured Voltage (DC):" << voltage;

        // Send a command to measure DC current
        QString current = dvm.measureCurrentDC();
        qDebug() << "Measured Current (DC):" << current;

        // Send a command to measure resistance
        QString resistance = dvm.measureResistance();
        qDebug() << "Measured Resistance:" << resistance;
    } else {
        qCritical() << "Failed to open DVM device!";
    }

    return 0;
}
