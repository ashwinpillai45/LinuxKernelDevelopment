#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

MODULE_LICENSE("GPL");
int param_array[4];
static int arg_c = 0;
module_param_array(param_array,int,&arg_c,S_IRUSR);

static int init_func(void)
{
int i=0;
printk(KERN_INFO "%s : Entering Init Function\n",__func__);
printk(KERN_INFO "%s : No. of arguments = %d\n",__func__,arg_c);
for(i=0;i<(sizeof(param_array)/sizeof(param_array[i]));i++)
printk(KERN_INFO "%s : Arg[%d] = %d\n",__func__,i,param_array[i]);
return 0;
}

void exit_func(void)
{
printk(KERN_INFO "%s : Exiting Code\n",__func__);
}

module_init(init_func);
module_exit(exit_func);
