/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> zcl_ias_zone_enroll_response_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_ias_zone_enroll_response_handler(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_20;
  undefined1 uStack_1c;
  undefined2 uStack_1a;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined2 uStack_14;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  uVar1 = *(undefined2 *)(iVar2 + 0xc);
  local_20 = 0;
  uStack_1c = *(undefined1 *)(iVar2 + 4);
  uStack_1a = 0x500;
  uStack_14._0_1_ = (undefined1)uVar1;
  uStack_18 = (undefined1)uStack_14;
  uStack_14._1_1_ = (undefined1)((ushort)uVar1 >> 8);
  uStack_17 = uStack_14._1_1_;
  if (zb_core_action_cb == (code *)0x0) {
    uVar3 = 0;
  }
  else {
    uStack_14 = uVar1;
    (*zb_core_action_cb)(3,&local_20);
    uVar3 = esp_err_to_zb_ret();
  }
  return uVar3;
}

