/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_price.o -> zcl_price_get_tier_labels_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_price_get_tier_labels_handler(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 uStack_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined1 uStack_35;
  undefined1 uStack_34;
  undefined1 uStack_33;
  undefined1 uStack_32;
  undefined4 uStack_30;
  ushort uStack_2c;
  undefined2 uStack_2a;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uStack_18;
  int iStack_14;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  puVar1 = *(undefined4 **)(iVar3 + 0x10);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  iVar3 = *(int *)(iVar3 + 0xc);
  uStack_30 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  iStack_14 = 0;
  _uStack_2c = CONCAT22(0x700,(ushort)*(byte *)(iVar2 + 4));
  uStack_28 = *puVar1;
  esp_zb_core_action_handler_schedule(0x16,&uStack_30);
  uVar4 = esp_err_to_zb_ret();
  if (((uStack_18 & 0xff) == 0) || (iStack_14 == 0)) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ZCL_PRICE",&_LC1,uVar4,"ESP_ZIGBEE_ZCL_PRICE");
    uVar4 = 0xffffffe4;
  }
  else {
    iVar2 = zb_buf_get_out_func();
    if (iVar2 == 0) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ZCL_PRICE",&_LC2,uVar4,"ESP_ZIGBEE_ZCL_PRICE",
                    "zcl_price_get_tier_labels_handler",0xb3);
      uVar4 = 0xffffffe4;
    }
    else {
      uStack_44 = uStack_24;
      uStack_40 = uStack_20;
      uStack_3c = uStack_1c;
      uStack_38 = 0;
      uStack_37 = 1;
      uStack_36 = (undefined1)uStack_18;
      uStack_35 = (undefined1)iStack_14;
      uStack_34 = (undefined1)((uint)iStack_14 >> 8);
      uStack_33 = (undefined1)((uint)iStack_14 >> 0x10);
      uStack_32 = (undefined1)((uint)iStack_14 >> 0x18);
      zb_zcl_price_send_cmd_publish_tier_labels
                (iVar3 + 1,2,*(undefined1 *)(iVar3 + 0xb),*(undefined1 *)(iVar3 + 0xc),&uStack_44,0)
      ;
    }
  }
  return uVar4;
}

