# pyleap
python bindings to LeapMotion API using ctypes

## Requirements

- numpy

## Example

```
cd example
python test.py
```

## Usage

`getLeapInfo()`

    Returns a structure with the following fields.

    Fields
        | **service** -  True if drivers are installed.
        | **connected** - True if the Leap is connected to the computer.
        | **has_focus** - True if the app is currently in the foreground.


`getLeapFrame()`

    Returns a LeapFrame containing 3D position data from the Leap
    sensor for all hands.
    
    Fields
        | **valid** - True if everything is working.
        | **hands** - An array of LeapHands.
    
    Each LeapHand contains the following fields - 

    Fields
        | **id** - An positive integer identifier for the hand, -1 when no hand is detected.
            When a hand exits and re-enters the sensing area, it is assigned a new id.
        | **palm_pos** - A numpy array ``[x, y, z]`` of the palm position in millimeters.
        | **fingers** - A 5-element array of finger positions as numpy arrays ``[x, y, z]`` in millimeters.

## Building libs

Currently, prebuilt binaries are available in the pyleap directory for osx, windows, and linux. I can supply the src code and build steps for these libs if needed.

