/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> on_off.o -> on_off_timer_start.constprop.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void on_off_timer_start_constprop_0(uint param_1)

{
  int iVar1;
  
  iVar1 = on_off_srv_get_attr_desc_part_0();
  if (iVar1 != 0) {
    if (**(byte **)(iVar1 + 8) == param_1) {
      milli_timer_start(*(byte **)(iVar1 + 8) + 4,100);
      return;
    }
  }
  return;
}

