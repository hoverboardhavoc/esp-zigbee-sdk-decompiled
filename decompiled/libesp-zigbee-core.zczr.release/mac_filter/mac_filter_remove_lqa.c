/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac_filter.o -> mac_filter_remove_lqa
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_filter_remove_lqa(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return;
  }
  iVar1 = mac_filter_find_entry();
  if ((iVar1 != 0) && (*(undefined1 *)(iVar1 + 8) = 0, *(char *)(iVar1 + 9) == '\0')) {
    iVar1 = iVar1 + -0x10464 >> 1;
    __atomic_fetch_and_1
              (s_mac_filter_table + ((uint)(iVar1 * -0x33330000) >> 0x13),
               ~(1 << (iVar1 * -0x33333333 & 7U)) & 0xff,5);
    return;
  }
  return;
}

