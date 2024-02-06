/*
 * Last changed at upstream commit d7e241034cb0adc2116988a320badb285c391de3
 * https://github.com/espressif/esp-zigbee-sdk/commit/d7e241034cb0adc2116988a320badb285c391de3
 * Upstream date: 2024-02-06 17:30:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.1(0cd72dc5)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_metering_get_profile_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_metering_get_profile_cb_handler(undefined4 param_1)

{
  undefined1 *puVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
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
  
  iVar3 = zb_buf_get_tail_func(0x38);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  pbVar2 = *(byte **)(iVar4 + 0x10);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar1 = *(undefined1 **)(iVar4 + 0x14);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  iVar4 = *(int *)(iVar4 + 0xc);
  uStack_48 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  _uStack_44 = CONCAT22(0x702,(ushort)*(byte *)(iVar3 + 4));
  uStack_40 = (uint)*pbVar2;
  uStack_3c = *(undefined4 *)(pbVar2 + 1);
  uStack_38 = (uint)pbVar2[5];
  if (zb_core_action_cb == (code *)0x0) {
    uVar5 = 0;
  }
  else {
    (*zb_core_action_cb)(8,&uStack_48);
    uVar5 = esp_err_to_zb_ret();
  }
  *puVar1 = (char)uStack_34;
  puVar1[1] = (char)((uint)uStack_34 >> 8);
  puVar1[2] = (char)((uint)uStack_34 >> 0x10);
  puVar1[3] = (char)((uint)uStack_34 >> 0x18);
  puVar1[4] = (char)uStack_30;
  puVar1[5] = (char)uStack_2c;
  puVar1[6] = (undefined1)uStack_28;
  puVar1[7] = (char)uStack_24;
  puVar1[8] = (char)((uint)uStack_24 >> 8);
  puVar1[9] = (char)((uint)uStack_24 >> 0x10);
  puVar1[10] = (char)((uint)uStack_24 >> 0x18);
  iVar3 = zb_zcl_get_attr_desc_a(*(undefined1 *)(iVar4 + 0xc),0x702,1,0x500);
  if (iVar3 != 0) {
    if (**(byte **)(iVar3 + 6) < (byte)puVar1[6]) {
      uVar6 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar6,"ESP_ZIGBEE_CORE");
    }
  }
  if (puVar1[6] == '\0') {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC65,uVar5,"ESP_ZIGBEE_CORE");
    uVar5 = 0xffffffe4;
  }
  return uVar5;
}

