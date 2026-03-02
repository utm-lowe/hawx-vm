#include "types.h"
#include "riscv.h"
#include "console.h"
#include "port.h"
#include "trap.h"
#include "mem.h"
#include "proc.h"
#include "scheduler.h"
#include "disk.h"
#include "string.h"
#include "tests.h"

// start() jumps here in supervisor mode
void
main()
{
  // initialize ports
  port_init();

  // initialize uart
  uartinit();
  printf("\n");
  printf("HAWX kernel is booting\n");
  printf("\n");
  uartflush();

  //initialize virtual memory
  vm_init();
  vm_test();
  
  panic("All Done, for now...");
}
