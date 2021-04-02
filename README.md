# gotorch
A GDNative wrapper for PyTorch's C++ bindings

Getting Started:

This requires the Pytorch (libtorch) and Godot-cpp libraries in sister files.

The file structure should be:

gotorch
  + gotorch
  + libtorch
  + godot-cpp

The godot-cpp git may be found at: https://github.com/godotengine/godot-cpp.git
Download and build with scons according to the instructions on their page.

The Pytorch libraries may be found at: https://pytorch.org/get-started/locally/
Using the following download settings:
![image](https://user-images.githubusercontent.com/10587741/113425750-55608d80-93ca-11eb-89e0-3284cc54fd28.png)

In principle this should be compiling using CMake Ninja or whatever repository you desire, but I use MSVS to build it at the moment.

Once it's built:

Put it in a godot project under the following filestructure
res://
  + bin
    - gotorch.gdnlib
    - gotorch.gdns
    + win64
      - Copy paste the build .dlls here

Obviously we have yet to make gotorch.gdnlib and .gdns. They are made following other tutorials (notably https://docs.godotengine.org/en/stable/tutorials/plugins/gdnative/gdnative-cpp-example.html ) and contain the following code:

gotorch.gdnlib

[general]

singleton=false
load_once=true
symbol_prefix="godot_"
reloadable=false

[entry]

Windows.64="res://bin/win64/gotorch.dll"

[dependencies]

OSX.64=[  ]
Windows.64=[  ]
X11.64=[  ]


gotorch.gdns

[gd_resource type="NativeScript" load_steps=2 format=2]

[ext_resource path="res://bin/gotorch.gdnlib" type="GDNativeLibrary" id=1]

[resource]
resource_name = "gdexample"
class_name = "GDExample"
library = ExtResource( 1 )

You may then call them from any other gdscript, for instance, using the following commands:

var gdn = load("res://bin/gotorch.gdns").new()
print(gdn.method())

TODO:

The next major addition component is to walk through the pytorch API and add the minimal tools for creating an NN in memory, training it, and saving it.

Cheers!
