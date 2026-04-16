/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink.o -> touchlink_commissioning_scan_req_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_commissioning_scan_req_timeout(void *arg)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  ezb_err_t eVar4;
  
  iVar2 = core_globals_get();
  if (*(char *)(iVar2 + 0x1400) != '\x01') {
    __assert_func(0,0,0,0);
  }
  iVar2 = core_globals_get();
  if (*(int *)(iVar2 + 0x1410) == 0) {
_L0:
    uVar3 = 0;
  }
  else {
    if (arg != (void *)0x0) {
      eVar4 = touchlink_commissioning_scan_next_channel();
      if (eVar4 == 0) {
        return;
      }
      if (eVar4 == 5) goto _L0;
    }
    touchlink_reset_disc_table();
    uVar3 = 1;
  }
  iVar2 = core_globals_get();
  if ((*(char *)(iVar2 + 0x1401) == '\x02') &&
     (((iVar2 = core_globals_get(), *(char *)(iVar2 + 0x1400) == '\x04' ||
       (iVar2 = core_globals_get(), *(char *)(iVar2 + 0x1400) == '\x05')) ||
      (iVar2 = core_globals_get(), *(char *)(iVar2 + 0x1400) == '\x06')))) {
    iVar2 = core_globals_get();
    milli_timer_stop(iVar2 + 0x1410);
  }
  iVar2 = core_globals_get();
  if (*(int *)(iVar2 + 0x1438) == 0) {
    return;
  }
  iVar2 = core_globals_get();
  uVar1 = *(undefined1 *)(iVar2 + 0x1400);
  touchlink_commissioning_set_task('\0');
  iVar2 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x000105c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar2 + 0x1438))(uVar1,uVar3,*(code **)(iVar2 + 0x1438));
  return;
}

