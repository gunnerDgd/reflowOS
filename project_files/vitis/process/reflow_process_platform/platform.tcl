# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct C:\Users\ifstu\Vitis\Projects\reflowOS\project_files\vitis\process\reflow_process_platform\platform.tcl
# 
# OR launch xsct and run below command.
# source C:\Users\ifstu\Vitis\Projects\reflowOS\project_files\vitis\process\reflow_process_platform\platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {reflow_process_platform}\
-hw {C:\Users\ifstu\Vitis\Projects\reflow\hardware_export\digilent\artya7\arty_basic.xsa}\
-proc {microblaze_0} -os {standalone} -fsbl-target {psu_cortexa53_0} -out {C:/Users/ifstu/Vitis/Projects/reflowOS/project_files/vitis/process}

platform write
platform generate -domains 
platform active {reflow_process_platform}
platform generate
