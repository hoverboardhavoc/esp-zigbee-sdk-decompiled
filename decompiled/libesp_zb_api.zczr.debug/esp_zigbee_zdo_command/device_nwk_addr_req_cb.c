/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zdo_command.o -> device_nwk_addr_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_nwk_addr_req_cb(int param_1)

{
  int unaff_s0;
  undefined4 uVar1;
  byte *pbVar2;
  uint unaff_s2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zdo_command.c",
              0x211);
_L0:
    uVar3 = esp_log_timestamp();
    esp_log_write(2,"ESP_ZIGBEE_API_ZDO",&_LC14,uVar3,"ESP_ZIGBEE_API_ZDO",
                  *(undefined1 *)(unaff_s0 + 1),unaff_s2);
    uVar3 = 0;
    uVar1 = 0;
  }
  else {
    pbVar2 = (byte *)zb_buf_begin_func();
    unaff_s2 = (uint)*pbVar2;
    zb_schedule_alarm_cancel(nwk_addr_req_timeout,unaff_s2,0);
    unaff_s0 = esp_zb_zdo_callback_find(unaff_s2);
    if (unaff_s0 == 0) {
      uVar3 = 0;
      uVar1 = 0;
      goto _L0;
    }
    if (*(char *)(unaff_s0 + 1) != '\0') goto _L0;
    uVar3 = *(undefined4 *)(unaff_s0 + 4);
    uVar1 = *(undefined4 *)(unaff_s0 + 8);
  }
  esp_zb_zdo_callback_remove(unaff_s2);
_L0:
  zdo_nwk_addr_req_call_user_cb(param_1,uVar3,uVar1);
  zb_buf_free_func(param_1);
  return;
}

