#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");

static struct task_struct* my_task_struct_thread01;
static struct task_struct* my_task_struct_thread02;

int display_thread(void*)
{
    int i = 1;
    while(!kthread_should_stop())
    {
        pr_info("Jai Sri Ram!: %d\n", i);
        pr_info("%s is running on processor number: %d\n",__func__, smp_processor_id());
        msleep(3000);
        i++;
    }

    return 0;
}

static int thread_example_init(void)
{
    printk(KERN_INFO"I'm in init function: %s\n",__func__);
    pr_info("%s is running on processor number: %d\n",__func__, smp_processor_id());

    /*my_task_struct_thread = kthread_create(display_thread,NULL,"my_thread_example");
    if(my_task_struct_thread)
    {
        wake_up_process(my_task_struct_thread);
        return 0;
    }
    else{
        pr_warn("Thread cannot be created.\n");
        return -1;
    }*/

    my_task_struct_thread01 = kthread_run(display_thread,NULL,"my_thread_example01");
    my_task_struct_thread02 = kthread_run(display_thread,NULL,"my_thread_example02");

    return 0;
}

static void thread_example_exit(void)
{
    pr_info("I'm in exit function: %s\n",__func__);
    pr_info("%s is running on processor number: %d\n",__func__, smp_processor_id());
    kthread_stop(my_task_struct_thread01);
    kthread_stop(my_task_struct_thread02);
    pr_info("Threads my_task_struct_thread01 & 02 exited: %s\n",__func__);
}

module_init(thread_example_init);
module_exit(thread_example_exit);