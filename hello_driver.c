#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>

int value = 0;
char *name = "rcb";

module_param(value, int, 0644);
module_param(name, charp, 0644);

MODULE_PARM_DESC(value, "integer value");
MODULE_PARM_DESC(name, "character string");

static int __init hello_init(void)
{
	printk(KERN_INFO "===================================\n");
	printk(KERN_INFO "INFO: Hello driver loaded\n");
	printk(KERN_ALERT "ALERT: driver loaded\n");
	printk(KERN_ERR "ERROR: driver loaded\n");
	printk(KERN_WARNING "WARNING: driver loaded\n");
	printk(KERN_INFO "value = %d\n", value);
	printk(KERN_INFO "name = %s\n", name);
	printk(KERN_INFO "===================================\n");
	return 0;
}
// KERN_EMERG
// KERN_ALERT
// KERN_CRIT
// KERN_ERR
// KERN_WARNING
// KERN_NOTICE
// KERN_INFO
// KERN_DEBUG

static void __exit hello_exit(void)
{
	printk(KERN_INFO "Hello driver removed\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MANI");
MODULE_DESCRIPTION("FIRST MODULE");
MODULE_VERSION("1.0");

//modinfo hello_driver.ko
//sudo insmod hello_driver.ko value=100 name=virat
//sudo dmesg
//sudo rmmod hello_driver
