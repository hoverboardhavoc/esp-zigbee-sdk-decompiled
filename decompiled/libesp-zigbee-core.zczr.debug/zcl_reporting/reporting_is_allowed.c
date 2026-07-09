/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> reporting_is_allowed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010300) */

undefined4 reporting_is_allowed(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0 && param_2 == 0) {
    uVar1 = 1;
  }
  else if (param_1 == 0) {
    if (param_2 == 0xffff) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else if (param_1 == 0xffff) {
    if (param_2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0;
    }
  }
  else if (param_2 == 0) {
    uVar1 = 1;
  }
  else if (param_2 == 0xffff) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

