/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> touchlink.o -> touchlink_initiator_transaction_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_initiator_transaction_timeout(void *arg)

{
  undefined1 uVar1;
  int iVar2;
  
  touchlink_reset_intrp_channel();
  if (arg != (void *)0x0) {
    return;
  }
  iVar2 = core_globals_get();
  if ((*(char *)(iVar2 + 0x13ad) == '\x02') &&
     (((iVar2 = core_globals_get(), *(char *)(iVar2 + 0x13ac) == '\x04' ||
       (iVar2 = core_globals_get(), *(char *)(iVar2 + 0x13ac) == '\x05')) ||
      (iVar2 = core_globals_get(), *(char *)(iVar2 + 0x13ac) == '\x06')))) {
    iVar2 = core_globals_get();
    milli_timer_stop(iVar2 + 0x13bc);
  }
  iVar2 = core_globals_get();
  if (*(int *)(iVar2 + 0x13e4) == 0) {
    return;
  }
  iVar2 = core_globals_get();
  uVar1 = *(undefined1 *)(iVar2 + 0x13ac);
  touchlink_commissioning_set_task('\0');
  iVar2 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x000105c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar2 + 0x13e4))(uVar1,1,*(code **)(iVar2 + 0x13e4));
  return;
}

