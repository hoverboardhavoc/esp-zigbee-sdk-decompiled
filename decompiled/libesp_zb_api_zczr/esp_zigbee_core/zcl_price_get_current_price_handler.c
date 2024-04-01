/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_price_get_current_price_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_price_get_current_price_handler(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  void *__dest;
  byte *pbVar4;
  undefined4 local_30;
  ushort uStack_2c;
  undefined2 uStack_2a;
  uint uStack_28;
  void *pvStack_24;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  pbVar4 = *(byte **)(iVar3 + 0x10);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  __dest = *(void **)(iVar3 + 0x14);
  local_30 = 0;
  pvStack_24 = (void *)0x0;
  uVar1 = 0;
  _uStack_2c = CONCAT22(0x700,(ushort)*(byte *)(iVar2 + 4));
  uStack_28 = (uint)*pbVar4;
  if (zb_core_action_cb != (code *)0x0) {
    (*zb_core_action_cb)(0x14,&local_30);
    uVar1 = esp_err_to_zb_ret();
  }
  if (((uStack_28 >> 8 & 0xff) == 0) || (pvStack_24 == (void *)0x0)) {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar1,"ESP_ZIGBEE_CORE");
    uVar1 = 0xffffffe4;
  }
  else {
    memcpy(__dest,pvStack_24,0x3b);
  }
  return uVar1;
}

