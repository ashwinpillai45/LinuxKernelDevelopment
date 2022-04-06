#include<linux/kernel.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");
char* name="ASHWIN";
int loop_count=1;
module_param(name,charp,S_IRUGO);
module_param(loop_count,int,S_IRUGO);

static int init_func(void)
{
	int i = 0;
	printk(KERN_INFO "%s : in init function\n",__func__);
	printk(KERN_INFO "%s : Loop Count = %d\n",__func__,loop_count);
	for( i = 0 ; i < loop_count ; i++)
		printk(KERN_INFO "%s : hello %s\n",__func__,name);
	return 0;
}

void exit_func(void)
{
	printk(KERN_INFO "%s : in exit function\n",__func__);
}

module_init(init_func);
module_exit(exit_func);
