### Project Overview: SCPI Device Control with C++ and Qt

This project provides a C++ framework using Qt for controlling SCPI (Standard Commands for Programmable Instruments) compliant devices via UART. The framework is designed to interact with three types of SCPI instruments: **Digital Multimeter (DVM)**, **Programmable Power Supply (PS)**, and **Digital Oscilloscope (OSC)**. The architecture allows flexible device communication using SCPI commands and handles serial communication via the `/dev/ttyUSBx` interface on Linux systems.

### Class Design

#### 1. **SCPIDevice (Base Class)**
The `SCPIDevice` class is an **abstract base class** that defines the common functionality for SCPI device communication. It provides the foundational methods for serial communication, such as opening the serial port, sending commands, and retrieving responses.

**Key Features:**
- **Serial Port Management**: Handles configuring and opening the serial port, which is defined in an INI settings file. The port is opened with a baud rate of 115200 and 8N1 (8 data bits, no parity, 1 stop bit).
- **Command Transmission**: Provides a method for sending SCPI commands to the device.
- **Response Handling**: Supports receiving and interpreting responses from the device.
- **Error Logging**: Logs errors to a file and outputs them to the console for debugging purposes.

**Key Methods:**
- `OpenResult open()`: Opens the serial port for communication, returning a status enum (`Success`, `FailedToOpen`, etc.).
- `bool sendCommand(const QString& command)`: Sends SCPI commands to the connected device.
- `QString getReply()`: Receives and returns the response from the SCPI device.
- `void configureDevice()`: Pure virtual function to be implemented by subclasses for device-specific configurations.

#### 2. **DVMDevice (Digital Multimeter Subclass)**

The `DVMDevice` class inherits from `SCPIDevice` and represents a **Digital Multimeter (DVM)**. It provides additional methods for executing DVM-specific SCPI commands, such as measuring voltage, current, and resistance.

**Key Methods:**
- `QString measureVoltageDC()`: Measures and returns the DC voltage.
- `QString measureCurrentDC()`: Measures and returns the DC current.
- `QString measureResistance()`: Measures and returns the resistance value.

**Use Case**: This class can be used to control a digital multimeter, execute measurement commands, and retrieve the results.

#### 3. **PSDevice (Programmable Power Supply Subclass)**

The `PSDevice` class inherits from `SCPIDevice` and represents a **Programmable Power Supply (PS)**. It provides methods to control the output voltage and current, as well as enabling/disabling the output.

**Key Methods:**
- `bool setVoltage(double voltage)`: Sets the output voltage to a specified value.
- `bool setCurrent(double current)`: Sets the output current limit.
- `QString measureOutputVoltage()`: Measures and returns the current output voltage.
- `QString measureOutputCurrent()`: Measures and returns the current output current.
- `void enableOutput(bool enable)`: Enables or disables the power supply's output.

**Use Case**: This class is ideal for controlling a programmable power supply, adjusting its output, and measuring its current state.

#### 4. **OSCDevice (Oscilloscope Subclass)**

The `OSCDevice` class inherits from `SCPIDevice` and represents a **Digital Oscilloscope (OSC)**. It provides methods to control signal acquisition, measure signal properties, and retrieve waveform data.

**Key Methods:**
- `void startAcquisition()`: Starts the signal acquisition process.
- `void stopAcquisition()`: Stops the signal acquisition process.
- `QString measureFrequency()`: Measures and returns the signal frequency.
- `QString retrieveWaveform()`: Retrieves the waveform data from the oscilloscope.

**Use Case**: This class is suitable for controlling digital oscilloscopes, allowing the user to start/stop acquisitions and retrieve waveform data.

### SCPI Command Support

Each subclass (`DVMDevice`, `PSDevice`, `OSCDevice`) implements SCPI commands relevant to the specific type of instrument it represents. These commands allow for flexible control and communication with the devices.

- **DVM Commands**: Voltage, current, and resistance measurements.
- **PS Commands**: Voltage/current settings and output control.
- **OSC Commands**: Signal acquisition, frequency measurement, and waveform retrieval.

### INI File Configuration

Devices are defined in an INI file, where each device section specifies the serial port associated with that device. For example:

```ini
[device1]
serialport=/dev/ttyUSB0

[device2]
serialport=/dev/ttyUSB1
```

This allows multiple devices to be managed by the same application, with each device having its own dedicated serial port.

### Example Usage

Here’s an example of how the `SCPIDevice` subclasses can be used:

```cpp
int main(int argc, char *argv[]) {
    // Create a Digital Multimeter object
    DVMDevice dvm("settings.ini", "device1");
    
    // Open the connection to the device
    if (dvm.open() == OpenResult::Success) {
        // Send a command to measure DC voltage
        QString voltage = dvm.measureVoltageDC();
        qDebug() << "Measured Voltage (DC):" << voltage;
    }

    // Create a Programmable Power Supply object
    PSDevice ps("settings.ini", "device2");
    
    // Open the connection to the device
    if (ps.open() == OpenResult::Success) {
        // Set voltage and enable output
        ps.setVoltage(12.5);
        ps.enableOutput(true);
    }

    return 0;
}
```

### Conclusion

This project provides a flexible and extensible framework for communicating with SCPI-compliant devices using UART. It is designed to support different types of lab equipment, each with its own set of SCPI commands, and provides a consistent interface for interacting with various types of instruments. The modular design allows for easy expansion to include additional SCPI devices as needed.