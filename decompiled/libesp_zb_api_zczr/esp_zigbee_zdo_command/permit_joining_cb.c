/*
 * Last changed at upstream commit 2defb30a96c2ca2505573e1ca35f3ee56a3c9daf
 * https://github.com/espressif/esp-zigbee-sdk/commit/2defb30a96c2ca2505573e1ca35f3ee56a3c9daf
 * Upstream date: 2023-01-31 10:56:39 +0800
 * Upstream subject: example: Support new zdo API(0d9da4e)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> permit_joining_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void permit_joining_cb(int param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = (undefined1 *)zb_buf_begin_func();
  uVar1 = *puVar2;
  if ((puVar2[1] == '\0') &&
     (iVar3 = zb_schedule_alarm_cancel(permit_join_req_timeout,0xff,0), iVar3 != 0)) {
    iVar3 = _esp_error_check_failed
                      ("/home/likunqiao/esp/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zdo_command.c"
                       ,0x1f0,"permit_joining_cb",
                       "ZB_SCHEDULE_APP_ALARM_CANCEL(permit_join_req_timeout, ZB_ALARM_ANY_PARAM)");
  }
  else {
    iVar3 = esp_zb_zdo_callback_find(uVar1);
    if ((iVar3 == 0) || (*(char *)(iVar3 + 1) != '6')) goto _L0;
  }
  if (*(code **)(iVar3 + 4) != (code *)0x0) {
    (**(code **)(iVar3 + 4))(puVar2[1],*(undefined4 *)(iVar3 + 8));
  }
_L0:
  esp_zb_zdo_callback_remove(uVar1);
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

