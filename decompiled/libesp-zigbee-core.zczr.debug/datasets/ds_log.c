/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> datasets.o -> ds_log
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ds_log(uint param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    return;
  }
  if (param_1 != 3) {
    if (param_1 < 4) {
      if (param_1 == 0) {
        return;
      }
      goto _L0;
    }
    if (1 < (param_1 - 5 & 0xff)) goto _L0;
  }
  if (param_2 == 5) {
    return;
  }
_L0:
  uVar1 = ds_action_to_str();
  uVar2 = ds_key_to_str(param_3);
  log_write(2,"datasets.c","%s %s failed: %d",uVar1,uVar2,param_2);
  return;
}

