/*
 * Last changed at upstream commit 2defb30a96c2ca2505573e1ca35f3ee56a3c9daf
 * https://github.com/espressif/esp-zigbee-sdk/commit/2defb30a96c2ca2505573e1ca35f3ee56a3c9daf
 * Upstream date: 2023-01-31 10:56:39 +0800
 * Upstream subject: example: Support new zdo API(0d9da4e)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> bind_device_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bind_device_cb(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  
  iVar2 = zb_buf_begin_func();
  puVar3 = (undefined1 *)zb_buf_begin_func(param_1);
  uVar1 = *puVar3;
  if ((*(char *)(iVar2 + 1) == '\0') &&
     (iVar4 = zb_schedule_alarm_cancel(bind_device_req_timeout,0xff,0), iVar4 != 0)) {
    iVar4 = _esp_error_check_failed
                      ("/home/likunqiao/esp/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zdo_command.c"
                       ,0x14a,"bind_device_cb",
                       "ZB_SCHEDULE_APP_ALARM_CANCEL(bind_device_req_timeout, ZB_ALARM_ANY_PARAM)");
  }
  else {
    iVar4 = esp_zb_zdo_callback_find(uVar1);
    if ((iVar4 == 0) || (*(char *)(iVar4 + 1) != '!')) goto _L0;
  }
  if (*(code **)(iVar4 + 4) != (code *)0x0) {
    (**(code **)(iVar4 + 4))(*(undefined1 *)(iVar2 + 1),*(undefined4 *)(iVar4 + 8));
  }
_L0:
  esp_zb_zdo_callback_remove(uVar1);
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

