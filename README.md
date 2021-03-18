# hand-gesture-gamepad
OpenCV-based gamepad with hand gesture detection.

## Build Instructions

### Install neccessary libraries

Github's max file size is 100 MB, so you'll need to download the libraries independently. 

1. Read [this](https://www.imatest.com/docs/editing-system-environment-variables/#Windows) if you don't know how to add variables to your system PATH.
2. Drag this folder wherever you want ('C:/libraries' .etc)
3. Add a new system variable called GESTUREPATH that points to the folder.
4. Edit your System Path/add a new line that says %GESTUREPATH%.
5. Add a new system variable called DLLPATH that points to the 'your install folder'/libraries/oepncv/build\x64\vc16\bin
6. Edit your System Path/add a new line that says %DLLPATH%.

### Compiling the program

1. Click Code > Open Visual Studio for the quickest way to clone the project. You'll need Visual Studio 2019.
2. Double click on 'handGesture.sln' if not already open.
3. Change the configuration to Release and x64.
4. Click Build > Build Solution (Rebuild Solution after making changes).

### Running the program

1. Click Local Windows Debugger to run the program.
2. To view console output, right click on 'handGesture' in the Solution Explorer.
  a. Make sure the configuration being edited is set to Release.
  b. Click Linker > System > SubSystem > Console (/SUBSYSTEM:CONSOLE).
  c. To disable console output again, change it back to Windows (/SUBSYSTEM:WINDOWS).
3. You can also run 'handGesture.exe' under /x64/Release after building the program. You'll need either the 
