# test01
Simple example of a c++ component in Amazon Lumberyard.
Clone this repo directly into your Lumberyard/Dev folder, and then make it the default project using the Project Configurator.
The level for the sample is "level_test"
Once everything is built, launch the game with /Lumberyard/Dev/Bin64vc140/test01Launcher.exe +map level_test

The TickTock Component lives in /Gem/Code/Source/Components.

The component has to be defined in the test01.waf_files file :
Every time you change the .waf_files, you have to re-generate the project solution.
    ```
           "Components": [
            "Source/Components/TickTockComponent.cpp",
            "Source/Components/TickTockComponent.h"
        ]	
    ```
  
The component has to be instanced in the Source/test01Module.cpp file too:

    ```
    ....
    #include "Components/TickTockComponent.h"
    ....
    // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
     m_descriptors.insert(m_descriptors.end(), {
        test01SystemComponent::CreateDescriptor(),
				TickTockComponent::CreateDescriptor()
     });
     ....
     ```
     
The new component will show up in the editor as "TickTockComponent" once you compile the project.

Here is what it looks like when the game is running in the editor:
You can see the component entry on the side menu, and also the "tick" printing in the game console.
#
![Alt text](GitReadmePics/EditorView.PNG?raw=true "Title")
