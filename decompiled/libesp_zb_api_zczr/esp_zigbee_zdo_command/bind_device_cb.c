/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
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
  if (*(char *)(iVar2 + 1) == '\0') {
    zb_schedule_alarm_cancel(bind_device_req_timeout,0xff,0);
  }
  iVar4 = esp_zb_zdo_callback_find(uVar1);
  if (((iVar4 != 0) && (*(char *)(iVar4 + 1) == '!')) && (*(code **)(iVar4 + 4) != (code *)0x0)) {
    (**(code **)(iVar4 + 4))(*(undefined1 *)(iVar2 + 1),*(undefined4 *)(iVar4 + 8));
  }
  esp_zb_zdo_callback_remove(uVar1);
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
    return;
  }
  return;
}

