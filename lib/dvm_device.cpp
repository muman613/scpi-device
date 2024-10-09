#include "scpi_device.h"
#include <QDebug>

DVMDevice::DVMDevice(const QString& iniFilePath, const QString& deviceName)
    : SCPIDevice(iniFilePath, deviceName) {}

DVMDevice::~DVMDevice() {}

void DVMDevice::configureDevice() {
    qDebug() << "Configuring DVM device...";
    // Add device-specific configuration logic here if needed
}

QString DVMDevice::measureVoltageDC() {
    sendCommand("MEASure:VOLTage:DC?");
    return getReply();
}

QString DVMDevice::measureCurrentDC() {
    sendCommand("MEASure:CURRent:DC?");
    return getReply();
}

QString DVMDevice::measureResistance() {
    sendCommand("MEASure:RESistance?");
    return getReply();
}
