/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_price.o -> zcl_price_get_scheduled_prices_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_price_get_scheduled_prices_handler(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uStack_34;
  ushort uStack_30;
  undefined2 uStack_2e;
  undefined4 uStack_2c;
  uint uStack_28;
  int iStack_24;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  puVar1 = *(undefined4 **)(iVar3 + 0x10);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  iVar3 = *(int *)(iVar3 + 0xc);
  uStack_34 = 0;
  iStack_24 = 0;
  _uStack_30 = CONCAT22(0x700,(ushort)*(byte *)(iVar2 + 4));
  uStack_2c = *puVar1;
  uStack_28 = (uint)*(byte *)(puVar1 + 1);
  esp_zb_core_action_handler_schedule(0x15,&uStack_34);
  uVar4 = esp_err_to_zb_ret();
  if (((uStack_28 >> 8 & 0xff) == 0) || (iVar2 = 0, iStack_24 == 0)) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ZCL_PRICE",&_LC2,uVar4,"ESP_ZIGBEE_ZCL_PRICE");
  }
  else {
    while( true ) {
      if ((int)(uStack_28 >> 8 & 0xff) <= iVar2) {
        return uVar4;
      }
      iVar5 = zb_buf_get_out_func();
      if (iVar5 == 0) break;
      iVar5 = iVar2 * 0x3b;
      iVar2 = iVar2 + 1;
      zb_zcl_price_send_cmd_publish_price
                (iVar3 + 1,2,*(undefined1 *)(iVar3 + 0xb),*(undefined1 *)(iVar3 + 0xc),
                 iVar5 + iStack_24,0);
    }
  }
  return 0xffffffe4;
}

