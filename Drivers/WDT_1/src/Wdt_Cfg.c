2 WDT PIOSC (internal oscillator) or system clock

lock and unlock WDT to edit

enable or disable reset 

debugging doesn't stop WDT


when reaching zero first time generate interrupt:
        standard
        NMI
type is determined in WDTCTL register(INTTYPE)

reload first value (doesn't wait for ISR)

if second time out -> reset (enabled or disabled from WDTCTL)

refresh watch dog time by one of those methods:
        write a value to WDTLOAD
        clear interrupt flag from WDTICR
        re-enable interrupt from WDTCTL(write 1 to bit 0 WDTCTL)

EN/disable WDT from bit 0 in WDTCTL.

disable WDT after enable can't be done unless you reset.

 




