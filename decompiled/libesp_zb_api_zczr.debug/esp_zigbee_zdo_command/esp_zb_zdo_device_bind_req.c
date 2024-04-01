/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zdo_command.o -> esp_zb_zdo_device_bind_req
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
  char cVar8;
  undefined2 uVar9;
  undefined4 uVar10;
  undefined1 *puVar11;
  
  uVar10 = zb_buf_get_out_func();
  puVar11 = (undefined1 *)zb_buf_get_tail_func(0x18);
  uVar1 = param_1[1];
  uVar2 = param_1[2];
  uVar3 = param_1[3];
  uVar4 = param_1[4];
  uVar5 = param_1[5];
  uVar6 = param_1[6];
  uVar7 = param_1[7];
  *puVar11 = *param_1;
  puVar11[1] = uVar1;
  puVar11[2] = uVar2;
  puVar11[3] = uVar3;
  puVar11[4] = uVar4;
  puVar11[5] = uVar5;
  puVar11[6] = uVar6;
  puVar11[7] = uVar7;
  puVar11[8] = param_1[8];
  *(undefined2 *)(puVar11 + 10) = *(undefined2 *)(param_1 + 10);
  cVar8 = param_1[0xc];
  puVar11[0xc] = cVar8;
  if (cVar8 == '\x01') {
    uVar9 = *(undefined2 *)(param_1 + 0xe);
    puVar11[0xd] = (char)uVar9;
    puVar11[0xe] = (char)((ushort)uVar9 >> 8);
  }
  else {
    uVar1 = param_1[0xf];
    uVar2 = param_1[0x10];
    uVar3 = param_1[0x11];
    uVar4 = param_1[0x12];
    uVar5 = param_1[0x13];
    uVar6 = param_1[0x14];
    uVar7 = param_1[0x15];
    puVar11[0xd] = param_1[0xe];
    puVar11[0xe] = uVar1;
    puVar11[0xf] = uVar2;
    puVar11[0x10] = uVar3;
    puVar11[0x11] = uVar4;
    puVar11[0x12] = uVar5;
    puVar11[0x13] = uVar6;
    puVar11[0x14] = uVar7;
  }
  puVar11[0x15] = param_1[0x16];
  *(undefined2 *)(puVar11 + 0x16) = *(undefined2 *)(param_1 + 0x18);
  uVar10 = zb_zdo_bind_req(uVar10,bind_device_cb);
  zb_schedule_app_alarm(bind_device_req_timeout,uVar10,0x14a,0);
  esp_zb_zdo_callback_register(uVar10,0x21,param_2,param_3);
  return;
}

