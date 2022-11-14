/*
 * Last changed at upstream commit 7abab98979b3ea95f88c7b3687103b07986e5dd5
 * https://github.com/espressif/esp-zigbee-sdk/commit/7abab98979b3ea95f88c7b3687103b07986e5dd5
 * Upstream date: 2022-11-14 17:26:16 +0800
 * Upstream subject: examples: support rename esp32h2 to esp32h4
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> find_device_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void find_device_cb(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  undefined2 uVar5;
  undefined1 uVar6;
  
  iVar2 = zb_buf_begin_func();
  iVar3 = zb_buf_get_tail_func(param_1,0x1c);
  uVar5 = ZDO_INVALID_SHORT_ADDR;
  uVar6 = ZDO_INVALID_ENDPOINT;
  pbVar4 = (byte *)zb_buf_begin_func(param_1);
  bVar1 = *pbVar4;
  if ((*(char *)(iVar2 + 1) == '\0') && (*(char *)(iVar2 + 4) != '\0')) {
    uVar6 = *(undefined1 *)(iVar2 + 5);
    uVar5 = *(undefined2 *)(iVar3 + 1);
    iVar3 = zb_schedule_alarm_cancel(match_desc_req_device_timeout,0xff,0);
    if (iVar3 != 0) {
      _esp_error_check_failed
                ("/home/likunqiao/esp/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zdo_command.c",
                 0x5a,"find_device_cb","zb_err_code");
      goto _L0;
    }
  }
  if (*(code **)(find_user_cb + (uint)bVar1 * 4) != (code *)0x0) {
    (**(code **)(find_user_cb + (uint)bVar1 * 4))(*(undefined1 *)(iVar2 + 1),uVar5,uVar6);
    *(undefined4 *)(find_user_cb + (uint)bVar1 * 4) = 0;
  }
  if (param_1 == 0) {
    return;
  }
_L0:
  zb_buf_free_func(param_1);
  return;
}

