#include <stdint.h>
extern uint32_t _etext;
extern uint32_t _srelocate;
extern uint32_t _erelocate;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _estack;
extern void _stack_top(void);

extern int main(void);
/**
 * \brief This is the code that gets called on processor reset.
 * To initialize the device, and call the main() routine.
 */
void Reset_Handler(void);
__attribute__((used, section(".vectors"))) void (*const vectors[])(void) = {
    &_stack_top,
    Reset_Handler,
};

__attribute__ ((used, section(".reset_handler")))
void Reset_Handler(void)
{
    uint32_t *pSrc, *pDest;

    /* Initialize the relocate segment */
    pSrc = &_etext;
    pDest = &_srelocate;

    if (pSrc != pDest) {
        for (; pDest < &_erelocate;) {
            *pDest++ = *pSrc++;
        }
    }

    /* Clear the bss segment */
    for (pDest = &_sbss; pDest < &_ebss;) {
            *pDest++ = 0;
    }

    main();

    while (1);
}