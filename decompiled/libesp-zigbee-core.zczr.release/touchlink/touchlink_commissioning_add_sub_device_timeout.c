/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink.o -> touchlink_commissioning_add_sub_device_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_commissioning_add_sub_device_timeout(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = core_globals_get();
  if (*(char *)(iVar2 + 0x13ac) != '\x02') {
    __assert_func(0,0,0,0);
  }
  if (param_1 == 0) {
    touchlink_reset_intrp_channel();
  }
  else {
    iVar2 = touchlink_commissioning_get_next_device_info(param_1);
    if (iVar2 == 0) {
      return;
    }
    touchlink_reset_intrp_channel();
    uVar3 = 0;
    if (iVar2 == 5) goto _L0;
  }
  touchlink_reset_sub_devices();
  uVar3 = 1;
_L0:
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
  touchlink_commissioning_set_task(0);
  iVar2 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x000105c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar2 + 0x13e4))(uVar1,uVar3,*(code **)(iVar2 + 0x13e4));
  return;
}

