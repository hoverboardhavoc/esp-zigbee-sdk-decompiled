/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_dm_compat.o -> esp_zb_meter_identification_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_meter_identification_cluster_create(undefined4 ***param_1)

{
  undefined4 ***pppuVar1;
  undefined4 **ppuStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  uint uStack_18;
  uint uStack_14;
  
  ppuStack_24 = (undefined4 ***)0x0;
  uStack_20 = 0;
  iStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  pppuVar1 = param_1;
  if (param_1 != (undefined4 ***)0x0) {
    uStack_20 = *(undefined4 *)((int)param_1 + 0x12);
    iStack_1c = (int)param_1 + 0x16;
    uStack_18 = (uint)*(byte *)(param_1 + 10) << 8 | (uint)(*(ushort *)((int)param_1 + 0x26) >> 8) |
                (int)*(char *)((int)param_1 + 0x29) << 0x10;
    if (*(char *)((int)param_1 + 0x29) < 0) {
      uStack_18 = uStack_18 | 0xff000000;
    }
    uStack_14 = (uint)*(int3 *)((int)param_1 + 0x2a);
    if (*(char *)(param_1 + 0xb) < '\0') {
      uStack_14 = uStack_14 | 0xff000000;
    }
    pppuVar1 = &ppuStack_24;
    ppuStack_24 = param_1;
  }
  meter_identification_cluster_create(pppuVar1);
  return;
}

