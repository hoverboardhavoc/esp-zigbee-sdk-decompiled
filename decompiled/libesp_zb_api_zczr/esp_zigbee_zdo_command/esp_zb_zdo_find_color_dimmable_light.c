/*
 * Last changed at upstream commit edae603135f5169e47a3eae722f314ece18018a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/edae603135f5169e47a3eae722f314ece18018a0
 * Upstream date: 2022-09-28 15:45:52 +0800
 * Upstream subject: Components: Update sdk_lib for support more devices/cluster
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_find_color_dimmable_light
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_find_color_dimmable_light(undefined2 *param_1,undefined4 param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  
  uVar2 = zb_buf_get_out_func();
  puVar3 = (undefined1 *)zb_buf_initial_alloc_func(0x10);
  uVar1 = *param_1;
  *puVar3 = (char)uVar1;
  puVar3[1] = (char)((ushort)uVar1 >> 8);
  uVar1 = param_1[1];
  puVar3[2] = (char)uVar1;
  puVar3[3] = (char)((ushort)uVar1 >> 8);
  puVar3[4] = 4;
  puVar3[5] = 1;
  puVar3[6] = 3;
  puVar3[7] = 0;
  puVar3[8] = 6;
  puVar3[9] = 0;
  puVar3[10] = 8;
  puVar3[0xb] = 0;
  puVar3[0xc] = 0;
  puVar3[0xd] = 3;
  iVar4 = zb_zdo_match_desc_req(uVar2,find_device_cb);
  zb_schedule_app_alarm(match_desc_req_device_timeout,uVar2,0x14a);
  *(undefined4 *)(find_user_cb + iVar4 * 4) = param_2;
  return;
}

