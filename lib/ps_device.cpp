
#include "scpi_device.h"

PSDevice::PSDevice(const QString& iniFilePath, const QString& deviceName)
    : SCPIDevice(iniFilePath, deviceName) {}

PSDevice::~PSDevice() {}

void PSDevice::configureDevice() {
    qDebug() << "Configuring Programmable Power Supply device...";
    // Add device-specific configuration logic here if needed
}

bool PSDevice::setVoltage(double voltage) {
    QString command = QString("VOLTage %1").arg(voltage);
    return sendCommand(command);
}

bool PSDevice::setCurrent(double current) {
    QString command = QString("CURRent %1").arg(current);
    return sendCommand(command);
}

QString PSDevice::measureOutputVoltage() {
    sendCommand("MEASure:VOLTage?");
    return getReply();
}

QString PSDevice::measureOutputCurrent() {
    sendCommand("MEASure:CURRent?");
    return getReply();
}

void PSDevice::enableOutput(bool enable) {
    QString command = enable ? "OUTPut ON" : "OUTPut OFF";
    sendCommand(command);
}
