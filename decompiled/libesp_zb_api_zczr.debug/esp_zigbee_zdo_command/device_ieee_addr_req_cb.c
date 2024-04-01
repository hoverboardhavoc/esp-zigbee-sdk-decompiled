/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zdo_command.o -> device_ieee_addr_req_cb
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
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  puVar2 = (undefined1 *)zb_buf_begin_func();
  uVar1 = *puVar2;
  iVar3 = zb_buf_begin_func(param_1);
  uStack_18 = ZDO_INVALID_IEEE_ADDR;
  uStack_14 = DAT_00012148;
  if (*(char *)(iVar3 + 1) == '\0') {
    zb_memcpy8(&uStack_18,iVar3 + 2);
    zb_schedule_alarm_cancel(ieee_addr_req_timeout,0xff,0);
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

