/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_set_enabled
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_set_enabled(int param_1,byte param_2)

{
  int iVar1;
  
  *(byte *)(param_1 + 0x9c) = *(byte *)(param_1 + 0x9c) & 0xfe | param_2 & 1;
  if ((param_2 & 1) != 0) {
    iVar1 = mac_pal_enable();
    if (iVar1 == 0) {
      return;
    }
    mac_report_poll_result_part_0();
  }
  iVar1 = mac_pal_disable();
  if (iVar1 != 0) {
    __assert_func(0,0,0,0);
  }
  return;
}

