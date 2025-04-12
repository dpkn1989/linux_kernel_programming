#include <linux/kernel.h>
#include <linux/module.h>
//#include "hello_world.h"

MODULE_LICENSE("GPL");

// extern int share_symbol_add(int a, int b);

static int sitaram_init(void)
{
    printk(KERN_INFO"I'm in init function: %s\n",__func__);
    printk(KERN_INFO"I'm executing dump stack call now: %s\n",__func__);
    dump_stack();
    //printk(KERN_INFO"The addition of 5,4 is: %d in init function: %s\n",share_symbol_add(5,4),__func__);
    //printk(KERN_INFO"The data of share_varibale struct is: %d\t%d\t%c\n",share_variable.a, share_variable.b, share_variable.c);
    //pr_info("The data of share_varibale struct is: %d\t%d\t%c\n",share_variable.a, share_variable.b, share_variable.c);
    return 0; 
}

static void sitaram_exit(void)
{
    //printk(KERN_INFO"I'm in exit function: %s\n",__func__);
    pr_info("I'm in exit function: %s\n",__func__);
}

module_init(sitaram_init);
module_exit(sitaram_exit);