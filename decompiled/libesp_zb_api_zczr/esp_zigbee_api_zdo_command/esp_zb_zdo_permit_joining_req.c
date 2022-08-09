/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_zdo_command.o -> esp_zb_zdo_permit_joining_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_permit_joining_req(undefined2 *param_1,undefined4 param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  
  uVar2 = zb_buf_get_out_func();
  puVar3 = (undefined1 *)zb_buf_get_tail_func(4);
  uVar1 = *param_1;
  *puVar3 = (char)uVar1;
  puVar3[1] = (char)((ushort)uVar1 >> 8);
  puVar3[2] = *(undefined1 *)(param_1 + 1);
  puVar3[3] = *(undefined1 *)((int)param_1 + 3);
  iVar4 = zb_zdo_mgmt_permit_joining_req(uVar2,permit_joining_cb);
  *(undefined4 *)(permit_join_user_cb + iVar4 * 4) = param_2;
  return;
}

