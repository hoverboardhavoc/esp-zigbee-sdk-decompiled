/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> secur_ic.o -> secur_ic_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void secur_ic_set(undefined4 param_1,undefined4 param_2)

{
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_18 = 0;
  uStack_14 = 0;
  secur_ic_add(&uStack_18,param_1,param_2);
  return;
}

