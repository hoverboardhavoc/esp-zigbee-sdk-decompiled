/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_price.o -> zcl_price_get_tier_labels_handler
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
  undefined2 uStack_38;
  char cStack_36;
  undefined1 uStack_35;
  undefined1 uStack_34;
  undefined1 uStack_33;
  undefined1 uStack_32;
  undefined1 auStack_30 [4];
  undefined1 uStack_2c;
  undefined2 uStack_2a;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  char cStack_18;
  int iStack_14;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  puVar1 = *(undefined4 **)(iVar3 + 0x10);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  iVar3 = *(int *)(iVar3 + 0xc);
  memset(auStack_30,0,0x20);
  uStack_2c = *(undefined1 *)(iVar2 + 4);
  uStack_2a = 0x700;
  uStack_28 = *puVar1;
  esp_zb_core_action_handler_schedule(0x16,auStack_30);
  uVar4 = esp_err_to_zb_ret();
  if ((cStack_18 == '\0') || (iStack_14 == 0)) {
    uVar4 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_ZCL_PRICE","E (%lu) %s: No tier label provided!\n",uVar4,
            "ESP_ZIGBEE_ZCL_PRICE");
  }
  else {
    iVar2 = zb_buf_get_out_func();
    if (iVar2 != 0) {
      uStack_44 = uStack_24;
      uStack_35 = (undefined1)iStack_14;
      uStack_40 = uStack_20;
      uStack_3c = uStack_1c;
      uStack_38 = 0x100;
      cStack_36 = cStack_18;
      uStack_34 = (undefined1)((uint)iStack_14 >> 8);
      uStack_33 = (undefined1)((uint)iStack_14 >> 0x10);
      uStack_32 = (undefined1)((uint)iStack_14 >> 0x18);
      zb_zcl_price_send_cmd_publish_tier_labels
                (iVar3 + 1,2,*(undefined1 *)(iVar3 + 0xb),*(undefined1 *)(iVar3 + 0xc),&uStack_44,0)
      ;
      return uVar4;
    }
  }
  return 0xffffffe4;
}

