/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> compat.o -> esp_zb_platform_config
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_platform_config(uint *param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  if (1 < *param_1) {
    return 0x102;
  }
  if (param_1[0xc] == 0) {
    puVar5 = &s_platform_config;
    puVar1 = param_1 + 0x18;
    do {
      uVar2 = param_1[1];
      uVar3 = param_1[2];
      uVar4 = param_1[3];
      *puVar5 = *param_1;
      puVar5[1] = uVar2;
      puVar5[2] = uVar3;
      puVar5[3] = uVar4;
      param_1 = param_1 + 4;
      puVar5 = puVar5 + 4;
    } while (param_1 != puVar1);
    return 0;
  }
  return 0x102;
}

