/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_filter.o -> mac_filter_apply
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_filter_apply(char *param_1)

{
  int iVar1;
  char cVar2;
  
  iVar1 = mac_filter_find_entry();
  if (iVar1 == 0) {
    cVar2 = '\0';
  }
  else {
    cVar2 = *(char *)(iVar1 + 9);
    if (cVar2 != '\0') {
      cVar2 = '\x01';
    }
  }
  *param_1 = '\0';
  if (s_filter_mode == '\x01') {
    if (cVar2 == '\0') {
      return 0x12;
    }
  }
  else if (s_filter_mode == '\x02') {
    if (cVar2 != '\0') {
      return 0x12;
    }
  }
  else if (s_filter_mode != '\0') {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_filter.c",0x79,
                  "mac_filter_apply",&_LC0);
    return 0;
  }
  if (iVar1 == 0) {
    return 0;
  }
  if (*(char *)(iVar1 + 8) == '\0') {
    return 0;
  }
  *param_1 = *(char *)(iVar1 + 8);
  return 0;
}

