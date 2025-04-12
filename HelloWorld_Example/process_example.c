#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/current.h>

MODULE_LICENSE("GPL");

static int process_example_init(void)
{
    struct task_struct *task;

    printk(KERN_INFO"I'm in init function: %s\n",__func__);
    pr_info("The Process running the module is: %s and its PID is: %d\n", current->comm, current->pid);

    pr_info("Now displaying the process hierarchy of current process till init task\n");
    for(task = current; task != &init_task; task = task->parent)
    {
        pr_info("Process: %s, PID: %d\n", task->comm, task->pid);
    }
    pr_info("Process hierarchy display of current process done\n");
    
    return 0; 
}

static void process_example_exit(void)
{
    pr_info("I'm in exit function: %s\n",__func__);
    pr_info("The Process making the module exit is: %s and its PID is: %d\n", current->comm, current->pid);
}

module_init(process_example_init);
module_exit(process_example_exit);