/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_dm_compat.o -> esp_zb_ep_list_add_ep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_ep_list_add_ep(undefined1 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uStack_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  
  if (param_1 != (undefined1 *)0x0) {
    param_1 = param_1 + -4;
  }
  uStack_18 = (undefined1)param_2;
  param_1[0xc] = uStack_18;
  uStack_16 = (undefined2)((uint)param_2 >> 0x10);
  *(undefined2 *)(param_1 + 0xe) = uStack_16;
  uStack_14 = (undefined2)param_3;
  *(undefined2 *)(param_1 + 0x10) = uStack_14;
  param_1[0x12] = param_1[0x12] & 0xf0 | (byte)((uint)param_3 >> 0x10) & 0xf;
  *param_1 = uStack_18;
  *(undefined2 *)(param_1 + 2) = uStack_16;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  ezb_af_device_add_endpoint_desc();
  esp_zigbee_err_to_esp();
  return;
}

