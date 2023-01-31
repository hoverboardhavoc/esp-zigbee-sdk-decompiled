/*
 * Last changed at upstream commit 2defb30a96c2ca2505573e1ca35f3ee56a3c9daf
 * https://github.com/espressif/esp-zigbee-sdk/commit/2defb30a96c2ca2505573e1ca35f3ee56a3c9daf
 * Upstream date: 2023-01-31 10:56:39 +0800
 * Upstream subject: example: Support new zdo API(0d9da4e)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_device_bind_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_device_bind_req(undefined1 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  
  uVar8 = zb_buf_get_out_func();
  puVar9 = (undefined1 *)zb_buf_get_tail_func(0x18);
  uVar1 = param_1[1];
  uVar2 = param_1[2];
  uVar3 = param_1[3];
  uVar4 = param_1[4];
  uVar5 = param_1[5];
  uVar6 = param_1[6];
  uVar7 = param_1[7];
  *puVar9 = *param_1;
  puVar9[1] = uVar1;
  puVar9[2] = uVar2;
  puVar9[3] = uVar3;
  puVar9[4] = uVar4;
  puVar9[5] = uVar5;
  puVar9[6] = uVar6;
  puVar9[7] = uVar7;
  puVar9[8] = param_1[8];
  *(undefined2 *)(puVar9 + 10) = *(undefined2 *)(param_1 + 10);
  puVar9[0xc] = 3;
  uVar1 = param_1[0xd];
  uVar2 = param_1[0xe];
  uVar3 = param_1[0xf];
  uVar4 = param_1[0x10];
  uVar5 = param_1[0x11];
  uVar6 = param_1[0x12];
  uVar7 = param_1[0x13];
  puVar9[0xd] = param_1[0xc];
  puVar9[0xe] = uVar1;
  puVar9[0xf] = uVar2;
  puVar9[0x10] = uVar3;
  puVar9[0x11] = uVar4;
  puVar9[0x12] = uVar5;
  puVar9[0x13] = uVar6;
  puVar9[0x14] = uVar7;
  puVar9[0x15] = param_1[0x14];
  *(undefined2 *)(puVar9 + 0x16) = *(undefined2 *)(param_1 + 0x16);
  uVar8 = zb_zdo_bind_req(uVar8,bind_device_cb);
  zb_schedule_app_alarm(bind_device_req_timeout,uVar8,0x14a);
  esp_zb_zdo_callback_register(uVar8,0x21,param_2,param_3);
  return;
}

