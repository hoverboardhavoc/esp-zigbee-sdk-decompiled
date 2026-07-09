/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> zcl_time_get_utc_time
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_time_get_utc_time(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)time_server_get_time_ctx();
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0xffffffff;
  }
  else if ((code *)*puVar1 == (code *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = (*(code *)*puVar1)();
  }
  return uVar2;
}

