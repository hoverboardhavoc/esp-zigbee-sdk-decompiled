/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_price.o -> zcl_price_get_current_price_handler
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
  void *__dest;
  byte *pbVar4;
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
    esp_log_write(1,"ESP_ZIGBEE_ZCL_PRICE",&_LC2,uVar3,"ESP_ZIGBEE_ZCL_PRICE");
    uVar3 = 0xffffffe4;
  }
  else {
    memcpy(__dest,pvStack_24,0x3b);
  }
  return uVar3;
}

