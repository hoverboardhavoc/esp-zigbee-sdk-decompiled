/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> convert_to_esp_zb_zcl_cmd_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void convert_to_esp_zb_zcl_cmd_info(int param_1,undefined1 *param_2)

{
  byte bVar1;
  
  *(undefined1 *)(param_1 + 8) = *param_2;
  memcpy((void *)(param_1 + 0xc),param_2 + 2,8);
  *(undefined1 *)(param_1 + 0x16) = param_2[0x14];
  *(undefined1 *)(param_1 + 0x17) = param_2[0x15];
  *(undefined2 *)(param_1 + 0x18) = *(undefined2 *)(param_2 + 0x16);
  *(undefined2 *)(param_1 + 0x1a) = *(undefined2 *)(param_2 + 0x18);
  bVar1 = param_2[0x1a];
  *(byte *)(param_1 + 2) = bVar1;
  *(undefined2 *)(param_1 + 4) = *(undefined2 *)(param_2 + 0x1c);
  *(undefined1 *)(param_1 + 6) = param_2[0x1e];
  *(undefined1 *)(param_1 + 7) = param_2[0x1f];
  *(undefined1 *)(param_1 + 0x1c) = param_2[0x20];
  *(byte *)(param_1 + 0x1d) = bVar1 >> 3 & 1;
  *(bool *)(param_1 + 0x1e) = (bVar1 & 3) == 0;
  return;
}

