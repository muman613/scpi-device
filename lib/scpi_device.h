
#ifndef SCPIDEVICE_H
#define SCPIDEVICE_H

#include <QSerialPort>
#include <QString>

enum class OpenResult {
    Success,
    PortNotFound,
    FailedToOpen,
    ConfigurationError
};

// Abstract base class for SCPI devices
class SCPIDevice {
public:
    // Pure virtual destructor for an abstract class
    virtual ~SCPIDevice() = 0;

    // Common method to open the serial port
    OpenResult open();

    // Common method to send a command to the device
    bool sendCommand(const QString& command);

    // Common method to receive a reply from the device
    QString getReply();

protected:
    SCPIDevice(const QString& iniFilePath, const QString& deviceName);

    virtual void configureDevice() = 0; // Pure virtual function for device-specific configuration

    QSerialPort serialPort;
    QString serialDeviceName;
    QString iniFilePath;
    QString deviceName;
    bool isPortOpen;

    // Utility method to log errors
    void logError(const QString& message);
};

// Digital Multimeter subclass
class DVMDevice : public SCPIDevice {
public:
    DVMDevice(const QString& iniFilePath, const QString& deviceName);
    ~DVMDevice();

    // Device-specific commands
    QString measureVoltageDC();
    QString measureCurrentDC();
    QString measureResistance();

protected:
    void configureDevice() override;
};

// Programmable Power Supply subclass
class PSDevice : public SCPIDevice {
public:
    PSDevice(const QString& iniFilePath, const QString& deviceName);
    ~PSDevice();

    // Device-specific commands
    bool setVoltage(double voltage);
    bool setCurrent(double current);
    QString measureOutputVoltage();
    QString measureOutputCurrent();
    void enableOutput(bool enable);

protected:
    void configureDevice() override;
};

// Oscilloscope subclass
class OSCDevice : public SCPIDevice {
public:
    OSCDevice(const QString& iniFilePath, const QString& deviceName);
    ~OSCDevice();

    // Device-specific commands
    void startAcquisition();
    void stopAcquisition();
    QString measureFrequency();
    QString retrieveWaveform();

protected:
    void configureDevice() override;
};

#endif // SCPIDEVICE_H
