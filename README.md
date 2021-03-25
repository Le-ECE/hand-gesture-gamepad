# hand-gesture-gamepad (WIP)
OpenCV-based gamepad with hand gesture detection.

## Build Instructions

### Installling the ViGEmBus driver
1. Download and run the [installer](https://github.com/ViGEm/ViGEmBus/releases).

### Installling the neccessary libraries
Github's max file size is 100 MB, so you'll need to download the [libraries](https://drive.google.com/file/d/1nXv2xGv0qZw3p3Zejyg9sOplehEtdbnW/view?usp=sharing) independently. 

1. Download [QT 5.13.2](https://download.qt.io/archive/qt/5.13/5.13.2/). Install QT for msvc2017.
2. Read [this](https://www.imatest.com/docs/editing-system-environment-variables/#Windows) if you don't know how to add variables to your system PATH.
3. Drag this folder wherever you want ('C:/libraries' .etc)
4. Add a new system variable called GESTUREPATH that points to the folder.
5. Edit your System Path/add a new line that says %GESTUREPATH%.
6. Add a new system variable called DLLPATH that points to the 'your install folder'/libraries/oepncv/build\x64\vc16\bin
7. Edit your System Path/add a new line that says %DLLPATH%.

### Compiling the program
1. Click Code > Open Visual Studio for the quickest way to clone the project. You'll need Visual Studio 2019.
2. Double click on 'handGesture.sln' if not already open.
3. Change the configuration to Release and x64.
4. Install the [QT VS Tools Extension](https://doc.qt.io/qtvstools/qtvstools-getting-started.html).
5. Click Extensions > QT VS TOOLS > QT Versions.
6. Set the path to 'QT install location'\QT\5.13.2\msvc2017_64\qmake.exe
7. Click Project > handGesture Properties > Qt Project Settings > Qt Installation > 5.13.2_msvc2017_64.
8. Click Build > Build Solution (Rebuild Solution after making changes).

### Running the program
1. Click Local Windows Debugger to run the program.
2. To view console output, right click on 'handGesture' in the Solution Explorer.
  a. Make sure the configuration being edited is set to Release.
  b. Click Linker > System > SubSystem > Console (/SUBSYSTEM:CONSOLE).
  c. To disable console output again, change it back to Windows (/SUBSYSTEM:WINDOWS).
3. You can also run 'handGesture.exe' under /x64/Release after building the program. You'll either need to have the .dlls in the same folder, or have a PATH variable pointing to the vc16\bin folder.
