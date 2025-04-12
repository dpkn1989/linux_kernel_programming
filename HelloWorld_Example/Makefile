obj-m := my_kernel_module.o
obj-m += my_sitaram_module.o
obj-m += my_printkLimit_module.o
obj-m += my_processexample_module.o

my_kernel_module-objs := hello_world.o display.o
my_sitaram_module-objs := sita_ram.o
my_printkLimit_module-objs := printk_limit_example.o
my_processexample_module-objs := process_example.o

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=${PWD} modules

clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=${PWD} clean