/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zdo_command.o -> esp_zb_zdo_find_on_off_light
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

