#include "scpi_device.h"
#include <QSettings>
#include <QDebug>
#include <QFile>
#include <QTextStream>

// Pure virtual destructor for abstract base class
SCPIDevice::~SCPIDevice() {}

SCPIDevice::SCPIDevice(const QString& iniFilePath, const QString& deviceName)
    : iniFilePath(iniFilePath), deviceName(deviceName), isPortOpen(false) {
    QSettings settings(iniFilePath, QSettings::IniFormat);
    settings.beginGroup(deviceName);
    serialDeviceName = settings.value("serialport", "").toString();
    settings.endGroup();
}

OpenResult SCPIDevice::open() {
    if (serialDeviceName.isEmpty()) {
        logError("Configuration error: Serial port not found for " + deviceName);
        return OpenResult::ConfigurationError;
    }

    // Configure the serial port
    serialPort.setPortName(serialDeviceName);
    serialPort.setBaudRate(QSerialPort::Baud115200);
    serialPort.setDataBits(QSerialPort::Data8);
    serialPort.setParity(QSerialPort::NoParity);
    serialPort.setStopBits(QSerialPort::OneStop);
    serialPort.setFlowControl(QSerialPort::NoFlowControl);

    // Try to open the serial port
    if (!serialPort.open(QIODevice::ReadWrite)) {
        logError("Failed to open serial port: " + serialDeviceName);
        return OpenResult::FailedToOpen;
    }

    isPortOpen = true;
    qDebug() << "Serial port" << serialDeviceName << "opened successfully";
    configureDevice();  // Device-specific configuration
    return OpenResult::Success;
}

bool SCPIDevice::sendCommand(const QString& command) {
    if (isPortOpen) {
        QByteArray cmd = command.toUtf8() + "\n";  // Add newline for SCPI
        serialPort.write(cmd);
        if (serialPort.waitForBytesWritten(1000)) {
            return true;
        } else {
            logError("Failed to write command to device");
            return false;
        }
    }
    logError("Serial port is not open");
    return false;
}

QString SCPIDevice::getReply() {
    if (isPortOpen) {
        if (serialPort.waitForReadyRead(2000)) {
            QByteArray response = serialPort.readAll();
            while (serialPort.waitForReadyRead(100)) {
                response += serialPort.readAll();
            }
            return QString::fromUtf8(response).trimmed();
        } else {
            logError("No response from device");
        }
    } else {
        logError("Serial port is not open");
    }
    return QString();
}

void SCPIDevice::logError(const QString& message) {
    qCritical() << message;
    QFile file("scpi_device_errors.log");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << message << "\n";
    }
}
