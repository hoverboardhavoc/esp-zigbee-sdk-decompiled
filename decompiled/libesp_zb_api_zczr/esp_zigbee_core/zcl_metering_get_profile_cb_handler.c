/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_metering_get_profile_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_metering_get_profile_cb_handler(undefined4 param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  byte *pbVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uStack_48;
  ushort uStack_44;
  undefined2 uStack_42;
  uint uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  iVar5 = zb_buf_get_tail_func(0x38);
  iVar6 = zb_buf_get_tail_func(param_1,0x38);
  pbVar3 = *(byte **)(iVar6 + 0x10);
  iVar6 = zb_buf_get_tail_func(param_1,0x38);
  puVar2 = *(undefined1 **)(iVar6 + 0x14);
  iVar6 = zb_buf_get_tail_func(param_1,0x38);
  iVar6 = *(int *)(iVar6 + 0xc);
  uStack_48 = 0;
  _uStack_44 = CONCAT22(0x702,(ushort)*(byte *)(iVar5 + 4));
  uStack_40 = (uint)*pbVar3;
  uStack_3c = *(undefined4 *)(pbVar3 + 1);
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_38 = (uint)pbVar3[5];
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uVar4 = 0;
  if (zb_core_action_cb != (code *)0x0) {
    (*zb_core_action_cb)(8,&uStack_48);
    uVar4 = esp_err_to_zb_ret();
  }
  *puVar2 = (undefined1)uStack_34;
  puVar2[1] = uStack_34._1_1_;
  puVar2[2] = uStack_34._2_1_;
  puVar2[3] = uStack_34._3_1_;
  puVar2[4] = (char)uStack_30;
  puVar2[5] = (char)uStack_2c;
  puVar2[6] = (undefined1)uStack_28;
  uVar1 = *(undefined1 *)(iVar6 + 0xc);
  puVar2[7] = (undefined1)uStack_24;
  puVar2[8] = uStack_24._1_1_;
  puVar2[9] = uStack_24._2_1_;
  puVar2[10] = uStack_24._3_1_;
  iVar5 = zb_zcl_get_attr_desc_a(uVar1,0x702,1,0x500);
  if (iVar5 != 0) {
    if (**(byte **)(iVar5 + 6) < (byte)puVar2[6]) {
      uVar7 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC13,uVar7,"ESP_ZIGBEE_CORE");
    }
  }
  if (puVar2[6] == '\0') {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC14,uVar4,"ESP_ZIGBEE_CORE");
    uVar4 = 0xffffffe4;
  }
  return uVar4;
}

