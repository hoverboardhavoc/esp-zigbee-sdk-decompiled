/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_metering.o -> zcl_metering_get_profile_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_metering_get_profile_cb_handler(undefined4 param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  byte *pbVar7;
  undefined4 uStack_48;
  undefined1 uStack_44;
  undefined3 uStack_43;
  uint uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  iVar3 = zb_buf_get_tail_func(0x38);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  pbVar7 = *(byte **)(iVar4 + 0x10);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar2 = *(undefined1 **)(iVar4 + 0x14);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  iVar4 = *(int *)(iVar4 + 0xc);
  uStack_48 = 0;
  _uStack_44 = CONCAT31(0x70200,*(undefined1 *)(iVar3 + 4));
  uStack_40 = (uint)*pbVar7;
  uStack_3c = *(undefined4 *)(pbVar7 + 1);
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_38 = (uint)pbVar7[5];
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  esp_zb_core_action_handler_schedule(8,&uStack_48);
  uVar5 = esp_err_to_zb_ret();
  *puVar2 = (undefined1)uStack_34;
  puVar2[1] = uStack_34._1_1_;
  puVar2[2] = uStack_34._2_1_;
  puVar2[3] = uStack_34._3_1_;
  puVar2[4] = (char)uStack_30;
  puVar2[5] = (char)uStack_2c;
  puVar2[6] = (undefined1)uStack_28;
  uVar1 = *(undefined1 *)(iVar4 + 0xc);
  puVar2[7] = (undefined1)uStack_24;
  puVar2[8] = uStack_24._1_1_;
  puVar2[9] = uStack_24._2_1_;
  puVar2[10] = uStack_24._3_1_;
  iVar3 = zb_zcl_get_attr_desc_a(uVar1,0x702,1,0x500);
  if (iVar3 != 0) {
    if (**(byte **)(iVar3 + 6) < (byte)puVar2[6]) {
      uVar6 = esp_log_timestamp();
      esp_log(1,"ESP_ZIGBEE_ZCL_METERING",
              "E (%lu) %s: Number of periods delivered cannot exceed the MaxNumberOfPeriodsDelivered attribute\n"
              ,uVar6,"ESP_ZIGBEE_ZCL_METERING");
    }
  }
  if (puVar2[6] == '\0') {
    uVar5 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_ZCL_METERING",
            "E (%lu) %s: No appropriate interval for get profile command\n",uVar5,
            "ESP_ZIGBEE_ZCL_METERING");
    uVar5 = 0xffffffe4;
  }
  return uVar5;
}

