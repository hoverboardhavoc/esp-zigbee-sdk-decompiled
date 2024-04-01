/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_find_color_dimmable_light
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_find_color_dimmable_light(undefined1 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *__ptr;
  undefined4 uVar4;
  undefined1 *puVar5;
  uint uVar6;
  
  uVar4 = zb_buf_get_out_func();
  puVar5 = (undefined1 *)zb_buf_initial_alloc_func(0x10);
  *puVar5 = *param_1;
  puVar5[1] = param_1[1];
  puVar5[2] = param_1[2];
  uVar1 = *(undefined2 *)(param_1 + 2);
  puVar5[8] = 6;
  puVar5[3] = (char)((ushort)uVar1 >> 8);
  puVar5[4] = 4;
  puVar5[5] = 1;
  puVar5[6] = 3;
  puVar5[10] = 8;
  puVar5[0xd] = 3;
  puVar5[7] = 0;
  puVar5[9] = 0;
  puVar5[0xb] = 0;
  puVar5[0xc] = 0;
  uVar6 = zb_zdo_match_desc_req(uVar4,find_device_cb);
  zb_schedule_app_alarm(match_desc_req_device_timeout,uVar6,0x14a,0);
  pbVar2 = zdo_resp_cb_list_head;
  __ptr = (byte *)malloc(0x10);
  if (__ptr != (byte *)0x0) {
    if (pbVar2 == (byte *)0x0) {
      *__ptr = (byte)uVar6;
      __ptr[1] = 6;
      *(undefined4 *)(__ptr + 4) = param_2;
      *(undefined4 *)(__ptr + 8) = param_3;
      __ptr[0xc] = 0;
      __ptr[0xd] = 0;
      __ptr[0xe] = 0;
      __ptr[0xf] = 0;
      zdo_resp_cb_list_head = __ptr;
    }
    else {
      do {
        pbVar3 = pbVar2;
        if (*pbVar3 == uVar6) {
          free(__ptr);
          return;
        }
        pbVar2 = *(byte **)(pbVar3 + 0xc);
      } while (*(byte **)(pbVar3 + 0xc) != (byte *)0x0);
      *__ptr = (byte)uVar6;
      __ptr[1] = 6;
      *(undefined4 *)(__ptr + 4) = param_2;
      *(undefined4 *)(__ptr + 8) = param_3;
      __ptr[0xc] = 0;
      __ptr[0xd] = 0;
      __ptr[0xe] = 0;
      __ptr[0xf] = 0;
      *(byte **)(pbVar3 + 0xc) = __ptr;
    }
  }
  return;
}

