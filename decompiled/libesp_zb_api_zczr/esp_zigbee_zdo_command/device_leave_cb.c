/*
 * Last changed at upstream commit 0de2da5bd0b050dcc5b1f7f4c5eba0b5eeccfd85
 * https://github.com/espressif/esp-zigbee-sdk/commit/0de2da5bd0b050dcc5b1f7f4c5eba0b5eeccfd85
 * Upstream date: 2023-07-14 11:30:10 +0800
 * Upstream subject: esp-zigbee-sdk: release v0.7.1(5785a2c)
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
  undefined4 uVar4;
  
  puVar2 = (undefined1 *)zb_buf_begin_func();
  uVar1 = *puVar2;
  if ((puVar2[1] == '\0') &&
     (iVar3 = zb_schedule_alarm_cancel(device_leave_req_timeout,0xff,0), iVar3 != 0)) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_L0,uVar4,0x10000,"device_leave_cb",0x2b2);
  }
  else {
    iVar3 = esp_zb_zdo_callback_find(uVar1);
    if (((iVar3 != 0) && (*(char *)(iVar3 + 1) == '4')) && (*(code **)(iVar3 + 4) != (code *)0x0)) {
      (**(code **)(iVar3 + 4))(puVar2[1],*(undefined4 *)(iVar3 + 8));
    }
    esp_zb_zdo_callback_remove(uVar1);
    if (param_1 != 0) {
      zb_buf_free_func(param_1);
    }
  }
  return;
}

