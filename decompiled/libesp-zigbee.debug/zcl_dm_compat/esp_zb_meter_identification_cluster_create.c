/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_dm_compat.o -> esp_zb_meter_identification_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_meter_identification_cluster_create(undefined4 ***param_1)

{
  undefined4 **ppuStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ushort uStack_18;
  undefined1 uStack_16;
  undefined2 uStack_14;
  undefined1 uStack_12;
  
  ppuStack_2c = (undefined4 ***)0x0;
  uStack_28 = 0;
  iStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  if (param_1 != (undefined4 ***)0x0) {
    uStack_28 = *(undefined4 *)((int)param_1 + 0x12);
    iStack_24 = (int)param_1 + 0x16;
    uStack_18 = (ushort)*(byte *)(param_1 + 10) << 8 | *(ushort *)((int)param_1 + 0x26) >> 8;
    uStack_16 = *(undefined1 *)((int)param_1 + 0x29);
    ppuStack_2c = param_1;
    uStack_20 = convert_int24_to_int32(&uStack_18);
    uStack_14 = *(undefined2 *)((int)param_1 + 0x2a);
    uStack_12 = *(undefined1 *)(param_1 + 0xb);
    uStack_1c = convert_int24_to_int32(&uStack_14);
    param_1 = &ppuStack_2c;
  }
  meter_identification_cluster_create(param_1);
  return;
}

