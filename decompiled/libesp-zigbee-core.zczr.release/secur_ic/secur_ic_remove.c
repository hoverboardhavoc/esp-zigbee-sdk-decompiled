/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> secur_ic.o -> secur_ic_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 secur_ic_remove(int param_1)

{
  undefined1 auStack_30 [28];
  undefined2 uStack_14;
  char cStack_12;
  
  if (param_1 != 0) {
    secur_ic_get_stored_ic(auStack_30);
    if (cStack_12 == '\0') {
      ds_internal_remove_entry(7,uStack_14,auStack_30);
    }
    return 0;
  }
  return 2;
}

