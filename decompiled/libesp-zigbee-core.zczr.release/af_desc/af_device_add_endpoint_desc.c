/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_device_add_endpoint_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 af_device_add_endpoint_desc(undefined4 *param_1,char *param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  
  uVar1 = 2;
  if (param_1 == (undefined4 *)0x0) {
    return uVar1;
  }
  if (param_2 != (char *)0x0) {
    for (pcVar2 = (char *)*param_1; pcVar2 != (char *)0x0; pcVar2 = *(char **)(pcVar2 + 0x1c)) {
      if (*pcVar2 == *param_2) {
        return 2;
      }
    }
    *(char **)(param_2 + 0x1c) = (char *)*param_1;
    *param_1 = param_2;
    uVar1 = 0;
  }
  return uVar1;
}

