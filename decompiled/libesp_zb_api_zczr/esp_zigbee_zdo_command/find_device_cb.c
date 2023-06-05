/*
 * Last changed at upstream commit 503c5e49627f84174ce142bf784c3f01532fb5c9
 * https://github.com/espressif/esp-zigbee-sdk/commit/503c5e49627f84174ce142bf784c3f01532fb5c9
 * Upstream date: 2023-06-05 10:37:46 +0800
 * Upstream subject: esp-zigbee-sdk: optimize the zigbee cluster implementation(0f0acd4)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> find_device_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void find_device_cb(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined2 uVar5;
  undefined1 uVar6;
  
  iVar2 = zb_buf_begin_func();
  iVar3 = zb_buf_get_tail_func(param_1,0x1c);
  uVar5 = ZDO_INVALID_SHORT_ADDR;
  uVar6 = ZDO_INVALID_ENDPOINT;
  puVar4 = (undefined1 *)zb_buf_begin_func(param_1);
  uVar1 = *puVar4;
  if ((*(char *)(iVar2 + 1) == '\0') && (*(char *)(iVar2 + 4) != '\0')) {
    uVar6 = *(undefined1 *)(iVar2 + 5);
    uVar5 = *(undefined2 *)(iVar3 + 1);
    iVar3 = zb_schedule_alarm_cancel(match_desc_req_device_timeout,0xff,0);
    if (iVar3 == 0) goto _L0;
    iVar3 = _esp_error_check_failed
                      ("/home/xieqinan/ESP/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zdo_command.c"
                       ,0xec,"find_device_cb","zb_err_code");
  }
  else {
_L0:
    iVar3 = esp_zb_zdo_callback_find(uVar1);
    if ((iVar3 == 0) || (*(char *)(iVar3 + 1) != '\x06')) goto _L0;
  }
  if (*(code **)(iVar3 + 4) != (code *)0x0) {
    (**(code **)(iVar3 + 4))(*(undefined1 *)(iVar2 + 1),uVar5,uVar6,*(undefined4 *)(iVar3 + 8));
  }
_L0:
  esp_zb_zdo_callback_remove(uVar1);
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

