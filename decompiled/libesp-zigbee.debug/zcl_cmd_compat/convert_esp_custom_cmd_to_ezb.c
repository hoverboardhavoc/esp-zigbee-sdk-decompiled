/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> convert_esp_custom_cmd_to_ezb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void convert_esp_custom_cmd_to_ezb(undefined1 *param_1,undefined1 *param_2)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  byte bVar9;
  undefined4 uVar10;
  
  uVar10 = get_zcl_send_status_cb_handle();
  *(undefined4 *)(param_1 + 0x14) = uVar10;
  *(undefined4 *)(param_1 + 0x18) = 0;
  param_1[0x10] = (byte)((*(uint *)(param_2 + 0x10) >> 2 & 1) << 1) | param_1[0x10] & 0xfd;
  bVar1 = param_1[0x10];
  bVar9 = (byte)((*(uint *)(param_2 + 0x10) >> 3 & 1) << 2);
  param_1[0x10] = bVar9 | bVar1 & 0xfb;
  param_1[0x10] = bVar9 | bVar1 & 0xfa | (byte)*(undefined4 *)(param_2 + 0x10) & 1;
  *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(param_2 + 0x12);
  *param_1 = param_2[10];
  param_1[10] = param_2[8];
  param_1[0xb] = param_2[9];
  *(undefined2 *)(param_1 + 0xc) = *(undefined2 *)(param_2 + 0xe);
  uVar2 = param_2[1];
  uVar3 = param_2[2];
  uVar4 = param_2[3];
  uVar5 = param_2[4];
  uVar6 = param_2[5];
  uVar7 = param_2[6];
  uVar8 = param_2[7];
  param_1[2] = *param_2;
  param_1[3] = uVar2;
  param_1[4] = uVar3;
  param_1[5] = uVar4;
  param_1[6] = uVar5;
  param_1[7] = uVar6;
  param_1[8] = uVar7;
  param_1[9] = uVar8;
  param_1[0x1c] = param_2[0x14];
  *(undefined2 *)(param_1 + 0x1e) = *(undefined2 *)(param_2 + 0x1a);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_2 + 0x1c);
  return;
}

