# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct C:\Users\ifstu\Vitis\Projects\reflowOS\project_files\vitis\reflow_firmware\memory\fw_memory_platform\platform.tcl
# 
# OR launch xsct and run below command.
# source C:\Users\ifstu\Vitis\Projects\reflowOS\project_files\vitis\reflow_firmware\memory\fw_memory_platform\platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {fw_memory_platform}\
-hw {C:\Users\ifstu\Vitis\Projects\reflow\hardware_export\digilent\artya7\arty_basic.xsa}\
-proc {microblaze_0} -os {standalone} -fsbl-target {psu_cortexa53_0} -out {C:/Users/ifstu/Vitis/Projects/reflowOS/project_files/vitis/reflow_firmware/memory}

platform write
platform generate -domains 
platform active {fw_memory_platform}
platform generate
