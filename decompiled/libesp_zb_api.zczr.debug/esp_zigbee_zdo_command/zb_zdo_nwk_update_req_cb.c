/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zdo_command.o -> zb_zdo_nwk_update_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zdo_nwk_update_req_cb(int param_1)

{
  uint unaff_s1;
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  if (param_1 == 0) {
    iVar2 = zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zdo_command.c"
                      ,0x4b5);
  }
  else {
    uStack_48 = 0;
    uStack_44 = 0;
    uStack_40 = 0;
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    pbVar1 = (byte *)zb_buf_begin_func();
    unaff_s1 = (uint)*pbVar1;
    uStack_48 = CONCAT31(uStack_48._1_3_,pbVar1[1]);
    uStack_44 = *(undefined4 *)(pbVar1 + 2);
    uStack_40 = *(undefined4 *)(pbVar1 + 6);
    uStack_3c = CONCAT31(uStack_3c._1_3_,pbVar1[10]);
    memcpy((void *)((int)&uStack_3c + 1),pbVar1 + 0xb,0x1b);
    zb_schedule_alarm_cancel(nwk_update_req_timeout,unaff_s1,0);
    iVar2 = esp_zb_zdo_callback_find(unaff_s1);
    if (iVar2 == 0) goto _L0;
    if (*(short *)(iVar2 + 2) != 0x38) {
      uVar3 = esp_log_timestamp();
      esp_log(2,"ESP_ZIGBEE_API_ZDO","W (%lu) %s: No NWK Update Request event found for TSN: %d\n",
              uVar3,"ESP_ZIGBEE_API_ZDO",unaff_s1);
      goto _L0;
    }
  }
  pcVar4 = *(code **)(iVar2 + 4);
  uVar3 = *(undefined4 *)(iVar2 + 8);
  esp_zb_zdo_callback_remove(unaff_s1);
  if (pcVar4 != (code *)0x0) {
    (*pcVar4)(&uStack_48,uVar3);
  }
_L0:
  zb_buf_free_func(param_1);
  return;
}

