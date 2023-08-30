/*
 * Last changed at upstream commit c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * https://github.com/espressif/esp-zigbee-sdk/commit/c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * Upstream date: 2023-08-30 15:00:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.3(6da46788)
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
  undefined4 uVar4;
  
  puVar2 = (undefined1 *)zb_buf_begin_func();
  uVar1 = *puVar2;
  if ((puVar2[1] == '\0') &&
     (iVar3 = zb_schedule_alarm_cancel(permit_join_req_timeout,0xff,0), iVar3 != 0)) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_L0,uVar4,0x10000,"permit_joining_cb",0x2b4);
  }
  else {
    iVar3 = esp_zb_zdo_callback_find(uVar1);
    if (((iVar3 != 0) && (*(char *)(iVar3 + 1) == '6')) && (*(code **)(iVar3 + 4) != (code *)0x0)) {
      (**(code **)(iVar3 + 4))(puVar2[1],*(undefined4 *)(iVar3 + 8));
    }
    esp_zb_zdo_callback_remove(uVar1);
    if (param_1 != 0) {
      zb_buf_free_func(param_1);
    }
  }
  return;
}

