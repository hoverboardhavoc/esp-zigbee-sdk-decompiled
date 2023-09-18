/*
 * Last changed at upstream commit 6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * https://github.com/espressif/esp-zigbee-sdk/commit/6ae0a43e13050e8f86079b96ed5a30faf92bdf3c
 * Upstream date: 2023-09-18 10:30:22 +0800
 * Upstream subject: esp-zigbee-sdk: add zigbee trace support and assert support(8c01f3c7)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> device_leave_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_leave_cb(int param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = (undefined1 *)zb_buf_begin_func();
  uVar1 = *puVar2;
  if (puVar2[1] == '\0') {
    zb_schedule_alarm_cancel(device_leave_req_timeout,0xff,0);
  }
  iVar3 = esp_zb_zdo_callback_find(uVar1);
  if (((iVar3 != 0) && (*(char *)(iVar3 + 1) == '4')) && (*(code **)(iVar3 + 4) != (code *)0x0)) {
    (**(code **)(iVar3 + 4))(puVar2[1],*(undefined4 *)(iVar3 + 8));
  }
  esp_zb_zdo_callback_remove(uVar1);
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

