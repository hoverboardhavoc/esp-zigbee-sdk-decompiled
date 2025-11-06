/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zdo_command.o -> zb_zdo_power_desc_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zdo_power_desc_req_cb(int param_1)

{
  byte *unaff_s1;
  int iVar1;
  undefined4 uVar2;
  uint unaff_s2;
  code *pcVar3;
  undefined4 uStack_28;
  ushort uStack_24;
  
  if (param_1 == 0) {
    iVar1 = zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zdo_command.c"
                      ,0x28a);
  }
  else {
    uStack_28 = 0;
    uStack_24 = 0;
    unaff_s1 = (byte *)zb_buf_begin_func();
    unaff_s2 = (uint)*unaff_s1;
    zb_schedule_alarm_cancel(power_desc_req_timeout,unaff_s2,0);
    iVar1 = esp_zb_zdo_callback_find(unaff_s2);
    if (iVar1 == 0) goto _L0;
    if (*(short *)(iVar1 + 2) != 3) {
      uVar2 = esp_log_timestamp();
      esp_log(2,"ESP_ZIGBEE_API_ZDO","W (%lu) %s: No Power Desc Request event found for TSN: %d\n",
              uVar2,"ESP_ZIGBEE_API_ZDO",unaff_s2);
      goto _L0;
    }
  }
  pcVar3 = *(code **)(iVar1 + 4);
  uVar2 = *(undefined4 *)(iVar1 + 8);
  esp_zb_zdo_callback_remove(unaff_s2);
  if (pcVar3 != (code *)0x0) {
    uStack_28 = CONCAT31(uStack_28._1_3_,unaff_s1[1]);
    if (unaff_s1[1] == 0) {
      uStack_28 = CONCAT13(unaff_s1[3],CONCAT12(unaff_s1[2],(undefined2)uStack_28));
      uStack_24 = (ushort)((*(ushort *)(unaff_s1 + 4) >> 4 & 0xf) << 4) | unaff_s1[4] & 0xf |
                  (ushort)((unaff_s1[5] & 0xf) << 8) | (ushort)(unaff_s1[5] >> 4) << 0xc;
    }
    (*pcVar3)(&uStack_28,uVar2);
  }
_L0:
  zb_buf_free_func(param_1);
  return;
}

