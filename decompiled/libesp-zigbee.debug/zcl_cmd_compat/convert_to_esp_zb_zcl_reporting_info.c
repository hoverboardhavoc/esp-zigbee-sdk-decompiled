/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> convert_to_esp_zb_zcl_reporting_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void convert_to_esp_zb_zcl_reporting_info(undefined1 *param_1,undefined1 *param_2)

{
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  *(undefined2 *)(param_1 + 2) = *(undefined2 *)(param_2 + 4);
  param_1[4] = param_2[8];
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)(param_2 + 6);
  *(undefined2 *)(param_1 + 0x3e) = *(undefined2 *)(param_2 + 0x30);
  param_1[8] = (byte)((*(uint *)(param_2 + 8) >> 0xc & 0xf) << 4) |
               (byte)(*(uint *)(param_2 + 8) >> 8) & 0xf;
  memcpy(param_1 + 0x18,param_2 + 0x10,0x20);
  *(undefined1 **)(param_1 + 0x40) = param_2;
  return;
}

