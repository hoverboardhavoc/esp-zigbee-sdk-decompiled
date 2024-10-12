/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zdo_command.o -> device_nwk_addr_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_nwk_addr_req_cb(int param_1)

{
  int unaff_s0;
  int unaff_s1;
  undefined4 uVar1;
  byte *unaff_s2;
  uint unaff_s3;
  code *pcVar2;
  undefined2 uStack_22;
  
  if (param_1 == 0) {
    zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zdo_command.c",
              0x1ed);
_L0:
    uVar1 = esp_log_timestamp();
    esp_log_write(2,"ESP_ZIGBEE_API_ZDO",&_LC14,uVar1,"ESP_ZIGBEE_API_ZDO",
                  *(undefined1 *)(unaff_s1 + 1),unaff_s3);
    pcVar2 = (code *)0x0;
    uVar1 = 0;
    param_1 = unaff_s0;
  }
  else {
    unaff_s2 = (byte *)zb_buf_begin_func();
    unaff_s3 = (uint)*unaff_s2;
    zb_schedule_alarm_cancel(nwk_addr_req_timeout,unaff_s3,0);
    unaff_s1 = esp_zb_zdo_callback_find(unaff_s3);
    if (unaff_s1 == 0) goto _L0;
    unaff_s0 = param_1;
    if (*(char *)(unaff_s1 + 1) != '\0') goto _L0;
    pcVar2 = *(code **)(unaff_s1 + 4);
    uVar1 = *(undefined4 *)(unaff_s1 + 8);
  }
  esp_zb_zdo_callback_remove(unaff_s3);
  if (pcVar2 != (code *)0x0) {
    uStack_22 = ZDO_INVALID_SHORT_ADDR;
    if (unaff_s2[1] == 0) {
      uStack_22 = *(undefined2 *)(unaff_s2 + 10);
    }
    (*pcVar2)(unaff_s2[1],uStack_22,uVar1);
  }
_L0:
  zb_buf_free_func(param_1);
  return;
}

