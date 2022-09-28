/*
 * Last changed at upstream commit edae603135f5169e47a3eae722f314ece18018a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/edae603135f5169e47a3eae722f314ece18018a0
 * Upstream date: 2022-09-28 15:45:52 +0800
 * Upstream subject: Components: Update sdk_lib for support more devices/cluster
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_device_leave_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_device_leave_req(undefined1 *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined2 uVar8;
  undefined4 uVar9;
  undefined1 *puVar10;
  int iVar11;
  
  uVar9 = zb_buf_get_out_func();
  puVar10 = (undefined1 *)zb_buf_get_tail_func(0xb);
  uVar1 = param_1[1];
  uVar2 = param_1[2];
  uVar3 = param_1[3];
  uVar4 = param_1[4];
  uVar5 = param_1[5];
  uVar6 = param_1[6];
  uVar7 = param_1[7];
  *puVar10 = *param_1;
  puVar10[1] = uVar1;
  puVar10[2] = uVar2;
  puVar10[3] = uVar3;
  puVar10[4] = uVar4;
  puVar10[5] = uVar5;
  puVar10[6] = uVar6;
  puVar10[7] = uVar7;
  uVar8 = *(undefined2 *)(param_1 + 8);
  puVar10[8] = (char)uVar8;
  puVar10[9] = (char)((ushort)uVar8 >> 8);
  puVar10[10] = (byte)((*(uint *)(param_1 + 8) >> 0x17 & 1) << 7) | puVar10[10] & 0x7f;
  puVar10[10] = (byte)((*(uint *)(param_1 + 8) >> 0x16 & 1) << 6) | puVar10[10] & 0xbf;
  iVar11 = zdo_mgmt_leave_req(uVar9,device_leave_cb);
  *(undefined4 *)(device_leave_user_cb + iVar11 * 4) = param_2;
  return;
}

