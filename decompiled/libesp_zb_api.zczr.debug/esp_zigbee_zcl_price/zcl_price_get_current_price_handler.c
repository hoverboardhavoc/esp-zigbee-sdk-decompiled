/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_price.o -> zcl_price_get_current_price_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_price_get_current_price_handler(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  void *__dest;
  undefined4 local_30;
  ushort uStack_2c;
  undefined2 uStack_2a;
  uint uStack_28;
  void *pvStack_24;
  
  iVar1 = zb_buf_get_tail_func(0x38);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  pbVar4 = *(byte **)(iVar2 + 0x10);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  __dest = *(void **)(iVar2 + 0x14);
  local_30 = 0;
  pvStack_24 = (void *)0x0;
  _uStack_2c = CONCAT22(0x700,(ushort)*(byte *)(iVar1 + 4));
  uStack_28 = (uint)*pbVar4;
  esp_zb_core_action_handler_schedule(0x14,&local_30);
  uVar3 = esp_err_to_zb_ret();
  if (((uStack_28 >> 8 & 0xff) == 0) || (pvStack_24 == (void *)0x0)) {
    uVar3 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_ZCL_PRICE","E (%lu) %s: No price data provided!\n",uVar3,
            "ESP_ZIGBEE_ZCL_PRICE");
    uVar3 = 0xffffffe4;
  }
  else {
    memcpy(__dest,pvStack_24,0x3b);
  }
  return uVar3;
}

