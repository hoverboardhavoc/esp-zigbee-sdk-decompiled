/*
 * Last changed at upstream commit c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * https://github.com/espressif/esp-zigbee-sdk/commit/c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * Upstream date: 2023-08-30 15:00:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.3(6da46788)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> device_ieee_addr_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_ieee_addr_req_cb(int param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  puVar2 = (undefined1 *)zb_buf_begin_func();
  uVar1 = *puVar2;
  iVar3 = zb_buf_begin_func(param_1);
  uStack_18 = ZDO_INVALID_IEEE_ADDR;
  uStack_14 = DAT_000126d0;
  if (*(char *)(iVar3 + 1) == '\0') {
    zb_memcpy8(&uStack_18,iVar3 + 2);
    iVar4 = zb_schedule_alarm_cancel(ieee_addr_req_timeout,0xff,0);
    if (iVar4 != 0) {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_L0,uVar5,0x10000,"device_ieee_addr_req_cb",0x187);
      return;
    }
  }
  iVar4 = esp_zb_zdo_callback_find(uVar1);
  if (((iVar4 != 0) && (*(char *)(iVar4 + 1) == '\x01')) && (*(code **)(iVar4 + 4) != (code *)0x0))
  {
    (**(code **)(iVar4 + 4))(*(undefined1 *)(iVar3 + 1),&uStack_18,*(undefined4 *)(iVar4 + 8));
  }
  esp_zb_zdo_callback_remove(uVar1);
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

