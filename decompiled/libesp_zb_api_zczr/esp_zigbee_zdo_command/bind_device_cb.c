/*
 * Last changed at upstream commit 0de2da5bd0b050dcc5b1f7f4c5eba0b5eeccfd85
 * https://github.com/espressif/esp-zigbee-sdk/commit/0de2da5bd0b050dcc5b1f7f4c5eba0b5eeccfd85
 * Upstream date: 2023-07-14 11:30:10 +0800
 * Upstream subject: esp-zigbee-sdk: release v0.7.1(5785a2c)
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
  undefined4 uVar5;
  
  iVar2 = zb_buf_begin_func();
  puVar3 = (undefined1 *)zb_buf_begin_func(param_1);
  uVar1 = *puVar3;
  if ((*(char *)(iVar2 + 1) == '\0') &&
     (iVar4 = zb_schedule_alarm_cancel(bind_device_req_timeout,0xff,0), iVar4 != 0)) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_L0,uVar5,0x10000,"bind_device_cb",0x1bb);
  }
  else {
    iVar4 = esp_zb_zdo_callback_find(uVar1);
    if (((iVar4 != 0) && (*(char *)(iVar4 + 1) == '!')) && (*(code **)(iVar4 + 4) != (code *)0x0)) {
      (**(code **)(iVar4 + 4))(*(undefined1 *)(iVar2 + 1),*(undefined4 *)(iVar4 + 8));
    }
    esp_zb_zdo_callback_remove(uVar1);
    if (param_1 != 0) {
      zb_buf_free_func(param_1);
    }
  }
  return;
}

