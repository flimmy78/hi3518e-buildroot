#ifndef ASM_HISI_TIMER
#define ASM_HISI_TIMER

#define CFG_TIMER01_VABASE		IO_ADDRESS(TIMER01_BASE)
#define CFG_TIMER23_VABASE		IO_ADDRESS(TIMER23_BASE)

#define CFG_TIMER_CONTROL		(CFG_TIMER_ENABLE | CFG_TIMER_PERIODIC\
					| CFG_TIMER_INTMASK | CFG_TIMER_32BIT)
#define CFG_TIMER_ONE_CONTROL		(CFG_TIMER_ENABLE | CFG_TIMER_INTMASK\
					| CFG_TIMER_32BIT | CFG_TIMER_ONESHOT)

#define CFG_TIMER_ENABLE		(1 << 7)
#define CFG_TIMER_PERIODIC		(1 << 6)
#define CFG_TIMER_INTMASK		(1 << 5)
#define CFG_TIMER_32BIT			(1 << 1)
#define CFG_TIMER_ONESHOT		(1 << 0)

#define CFG_TIMER_PRESCALE		 2 /* AXI:APB = 2:1 */
#define BUSCLK_TO_TIMER_RELOAD(busclk)	 (((busclk)/CFG_TIMER_PRESCALE)/HZ)
#define BUSCLK_TO_TIMER0_CLK_HZ(busclk)	 ((busclk)/CFG_TIMER_PRESCALE)
#define BUSCLK_TO_TIMER1_CLK_HZ(busclk)	 ((busclk)/CFG_TIMER_PRESCALE)
#define BUSCLK_TO_TIMER0_CLK_KHZ(busclk) (((busclk)/CFG_TIMER_PRESCALE)/1000)
#define BUSCLK_TO_TIMER1_CLK_KHZ(busclk) (((busclk)/CFG_TIMER_PRESCALE)/1000)
#define CFG_TIMER_INTNR			 TIMER01_IRQ

extern unsigned long long sched_clock(void);
#endif
