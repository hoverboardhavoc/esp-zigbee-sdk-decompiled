/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_device_leave_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_device_leave_req(undefined1 *param_1,undefined4 param_2,undefined4 param_3)

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
  uVar9 = zdo_mgmt_leave_req(uVar9,device_leave_cb);
  zb_schedule_app_alarm(device_leave_req_timeout,uVar9,0x14a,0);
  esp_zb_zdo_callback_register(uVar9,0x34,param_2,param_3);
  return;
}

