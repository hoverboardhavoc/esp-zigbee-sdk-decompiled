/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_cvc.o -> zcl_cvc_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_cvc_stop(void *param_1)

{
  int iVar1;
  
  if (param_1 != (void *)0x0) {
    iVar1 = milli_timer_is_running((int)param_1 + 0x1c);
    if (iVar1 != 0) {
      milli_timer_stop((int)param_1 + 0x1c);
    }
    memset(param_1,0,0x40);
  }
  return;
}

