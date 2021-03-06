/******************************************************************************
 * filename    : start.S
 * author      : QiDianMaker
 * description : I.MX6U-ALPHA/I,MX6ULL 开发板启动文件，完成 C 环境的初始化
 *               然后跳转到 C 代码
 * create date : 2020-06-22
 ******************************************************************************/

.global _start  /* 全局标号 */

/*
 * @brief :	_start 函数，程序从此函数开始执行此函数的主要功能是设置 C 运行环境
 */
_start:
	/* 进入 SVC 模式 */
    mrs r0, cpsr
    bic r0, r0, #0x1f    /* 将 r0 的低 5 位清零，也就是 cpsr 的 M0～M4 */
    orr r0, r0, #0x13    /* r0 或上 0x13，表示使用 SVC 模式 */
    msr cpsr, r0         /* 将 r0 的数据写入到 cpsr_c 中 */

    ldr sp, =0x80200000  /* 设置栈指针 */
    b main               /* 跳转到 main 函数： */
