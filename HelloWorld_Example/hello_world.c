#include <linux/kernel.h>
#include <linux/module.h>
#include "hello_world.h"

MODULE_LICENSE("GPL");
MODULE_VERSION("1.0.0");
MODULE_AUTHOR("Praveen");
MODULE_DESCRIPTION("This module is used for learning Linux Kernel Programming");
MODULE_INFO(Date,"09 April 2025");    // To add my own info to the Module information list

/*int value = 0;
char* name = "SitaRam";
module_param(value,int,S_IRUGO);
module_param(name,charp,S_IRUGO);*/

struct share_struct share_variable;

int m_array[5];
int argcount;
module_param_array(m_array,int,&argcount,S_IWUSR|S_IRUSR);

void display(void);

int share_symbol_add(int a, int b)
{
    return a+b;
}

static int helloworld_init(void)
{
    printk(KERN_INFO"I'm in init function: %s\n",__func__);
    display();
    // printk(KERN_INFO"The arguments provided to the kernel module are: value=%d, name=%s\n",value,name);
    printk(KERN_INFO"The size of array provided to the kernel module is: size=%d\n",argcount);
    for(int i=0; i<sizeof(m_array)/sizeof(m_array[0]);i++)
        printk(KERN_INFO"m_array[%d] = %d\n",i,m_array[i]);

    share_variable.a = 5;
    share_variable.b = 9;
    share_variable.c = 'R';
    return 0; 
}

static void helloworld_exit(void)
{
    printk(KERN_INFO"I'm in exit function: %s\n",__func__);
}

EXPORT_SYMBOL(share_symbol_add);
EXPORT_SYMBOL(share_variable);

module_init(helloworld_init);
module_exit(helloworld_exit);