#include<linux/kernel.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");

static int init_func(void)
{
printk(KERN_INFO "%s : In Init Function\n",__func__);
return 0;
}

void exit_func(void)
{
printk(KERN_INFO "%s : In Exit Function\n",__func__);
}

module_init(init_func);
module_exit(exit_func);

