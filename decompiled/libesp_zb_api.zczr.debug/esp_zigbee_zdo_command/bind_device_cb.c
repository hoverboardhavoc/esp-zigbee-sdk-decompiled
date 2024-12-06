/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zdo_command.o -> bind_device_cb
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
  if (*(char *)(iVar2 + 1) == '\0') {
    zb_schedule_alarm_cancel(bind_device_req_timeout,uVar1,0);
  }
  iVar4 = esp_zb_zdo_callback_find(uVar1);
  if (((iVar4 != 0) && ((byte)(*(char *)(iVar4 + 1) - 0x21U) < 2)) &&
     (*(code **)(iVar4 + 4) != (code *)0x0)) {
    (**(code **)(iVar4 + 4))(*(undefined1 *)(iVar2 + 1),*(undefined4 *)(iVar4 + 8));
  }
  esp_zb_zdo_callback_remove(uVar1);
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

