/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_price_get_scheduled_prices_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_price_get_scheduled_prices_handler(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uStack_34;
  ushort uStack_30;
  undefined2 uStack_2e;
  undefined4 uStack_2c;
  uint uStack_28;
  int iStack_24;
  
  iVar3 = zb_buf_get_tail_func(0x38);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar1 = *(undefined4 **)(iVar4 + 0x10);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  iVar4 = *(int *)(iVar4 + 0xc);
  uStack_34 = 0;
  iStack_24 = 0;
  _uStack_30 = CONCAT22(0x700,(ushort)*(byte *)(iVar3 + 4));
  uStack_2c = *puVar1;
  uVar2 = 0;
  uStack_28 = (uint)*(byte *)(puVar1 + 1);
  if (zb_core_action_cb != (code *)0x0) {
    (*zb_core_action_cb)(0x15,&uStack_34);
    uVar2 = esp_err_to_zb_ret();
  }
  if (((uStack_28 >> 8 & 0xff) == 0) || (iVar3 = 0, iStack_24 == 0)) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar2,"ESP_ZIGBEE_CORE");
  }
  else {
    while( true ) {
      if ((int)(uStack_28 >> 8 & 0xff) <= iVar3) {
        return uVar2;
      }
      iVar5 = zb_buf_get_out_func();
      if (iVar5 == 0) break;
      iVar5 = iVar3 * 0x3b;
      iVar3 = iVar3 + 1;
      zb_zcl_price_send_cmd_publish_price
                (iVar4 + 1,2,*(undefined1 *)(iVar4 + 0xb),*(undefined1 *)(iVar4 + 0xc),
                 iVar5 + iStack_24,0);
    }
  }
  return 0xffffffe4;
}

