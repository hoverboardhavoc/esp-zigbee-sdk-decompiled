/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> device_nwk_addr_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_nwk_addr_req_cb(int param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (param_1 == 0) {
    param_1 = zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zdo_command.c"
                        ,0x21d);
  }
  puVar2 = (undefined1 *)zb_buf_begin_func();
  uVar1 = *puVar2;
  zb_schedule_alarm_cancel(nwk_addr_req_timeout,uVar1,0);
  iVar3 = esp_zb_zdo_callback_find(uVar1);
  if (iVar3 != 0) {
    if (*(char *)(iVar3 + 1) == '\0') {
      iVar4 = *(int *)(iVar3 + 4);
      uVar5 = *(undefined4 *)(iVar3 + 8);
    }
    else {
      iVar4 = 0;
      uVar5 = 0;
    }
    esp_zb_zdo_callback_remove(uVar1);
    if (iVar4 != 0) {
      zdo_nwk_addr_req_call_user_cb_part_0(param_1,uVar5);
    }
  }
  zb_buf_free_func(param_1);
  return;
}

