/*
 * Last changed at upstream commit e81a64f4a72a1b96e84882b938e8d601ccb424df
 * https://github.com/espressif/esp-zigbee-sdk/commit/e81a64f4a72a1b96e84882b938e8d601ccb424df
 * Upstream date: 2023-06-30 20:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release esp-zigbee-sdk v0.7.0(8b8bde0)
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
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  puVar2 = (undefined1 *)zb_buf_begin_func();
  uVar1 = *puVar2;
  iVar3 = zb_buf_begin_func(param_1);
  uStack_18 = ZDO_INVALID_IEEE_ADDR;
  uStack_14 = DAT_00011c14;
  if (*(char *)(iVar3 + 1) == '\0') {
    zb_memcpy8(&uStack_18,iVar3 + 2);
    iVar4 = zb_schedule_alarm_cancel(ieee_addr_req_timeout,0xff,0);
    if (iVar4 == 0) goto _L0;
    iVar4 = _esp_error_check_failed
                      ("/home/xieqinan/ESP/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zdo_command.c"
                       ,0x13c,"device_ieee_addr_req_cb",
                       "ZB_SCHEDULE_APP_ALARM_CANCEL(ieee_addr_req_timeout, ZB_ALARM_ANY_PARAM)");
  }
  else {
_L0:
    iVar4 = esp_zb_zdo_callback_find(uVar1);
    if ((iVar4 == 0) || (*(char *)(iVar4 + 1) != '\x01')) goto _L0;
  }
  if (*(code **)(iVar4 + 4) != (code *)0x0) {
    (**(code **)(iVar4 + 4))(*(undefined1 *)(iVar3 + 1),&uStack_18,*(undefined4 *)(iVar4 + 8));
  }
_L0:
  esp_zb_zdo_callback_remove(uVar1);
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

