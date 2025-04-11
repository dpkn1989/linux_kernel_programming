#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

static int printkLimit_init(void)
{
    printk(KERN_INFO"I'm in init function: %s\n",__func__);
    
    for(int i = 0; i<20; i++)
    {
        if(printk_ratelimit())
        {
            pr_info("The value is: %d\n",i+1);
        }
        else
        {
            pr_info("Waiting for 5 seconds which is printk_ratelimit time.\n");
            msleep(5000);
            i--;
        }
    }

    char buff[] = "Jai Sri Ram, Raja Ram!!!";
    print_hex_dump(KERN_INFO, "My Buffer: ", DUMP_PREFIX_ADDRESS, 16, 1, buff, sizeof(buff), 1);
    // print_hex_dump_bytes("My Buffer: ", DUMP_PREFIX_ADDRESS, buff, sizeof(buff));
       // Above macro can be used as a short form of print_hex_dump, where KERN_DEBUG(Log level), 16(Row size), 1(Group size)), 1(ASCII) are default.

    return 0; 
}

static void printkLimit_exit(void)
{
    pr_info("I'm in exit function: %s\n",__func__);
}

module_init(printkLimit_init);
module_exit(printkLimit_exit);