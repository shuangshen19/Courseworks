#include <linux/kernel.h>

asmlinkage long sys_hello(void)
{
	printk("Hello Sunshine!\n");
	return 0;
}
