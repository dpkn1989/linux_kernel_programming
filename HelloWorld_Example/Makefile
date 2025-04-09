obj-m := my_kernel_module.o
obj-m += my_sitaram_module.o
my_kernel_module-objs := hello_world.o display.o
my_sitaram_module-objs := sita_ram.o

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=${PWD} modules

clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=${PWD} clean