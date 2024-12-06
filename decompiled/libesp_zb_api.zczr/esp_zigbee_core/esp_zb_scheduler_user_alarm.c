/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_core.o -> esp_zb_scheduler_user_alarm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_scheduler_user_alarm(undefined4 param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = zb_buf_get_out_func();
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)zb_buf_get_tail_func(8);
    *puVar2 = param_1;
    puVar2[1] = param_2;
    iVar3 = zb_schedule_app_alarm
                      (esp_zb_schedule_user_cb,iVar1,param_3 * 1000,
                       (int)((ulonglong)param_3 * 1000 >> 0x20));
    if (iVar3 == 0) {
      return iVar1;
    }
  }
  return 0;
}

