/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_find_on_off_light
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_find_on_off_light(undefined2 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  uVar2 = zb_buf_get_out_func();
  puVar3 = (undefined1 *)zb_buf_initial_alloc_func(0xc);
  uVar1 = *param_1;
  *puVar3 = (char)uVar1;
  puVar3[1] = (char)((ushort)uVar1 >> 8);
  uVar1 = param_1[1];
  puVar3[2] = (char)uVar1;
  puVar3[3] = (char)((ushort)uVar1 >> 8);
  puVar3[4] = 4;
  puVar3[5] = 1;
  puVar3[6] = 1;
  puVar3[7] = 0;
  puVar3[8] = 6;
  puVar3[9] = 0;
  uVar2 = zb_zdo_match_desc_req(uVar2,find_device_cb);
  zb_schedule_app_alarm(match_desc_req_device_timeout,uVar2,0x14a,0);
  esp_zb_zdo_callback_register(uVar2,6,param_2,param_3);
  return;
}

