/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_metering_request_fast_poll_mode_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_metering_request_fast_poll_mode_cb_handler(undefined4 param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  undefined4 uStack_34;
  ushort uStack_30;
  undefined2 uStack_2e;
  uint uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  
  iVar3 = zb_buf_get_tail_func(0x38);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar5 = *(ushort **)(iVar4 + 0x10);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar2 = *(undefined1 **)(iVar4 + 0x14);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  iVar4 = *(int *)(iVar4 + 0xc);
  uStack_34 = 0;
  uVar1 = 0;
  _uStack_30 = CONCAT22(0x702,(ushort)*(byte *)(iVar3 + 4));
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_2c = (uint)*puVar5;
  if (zb_core_action_cb != (code *)0x0) {
    (*zb_core_action_cb)(10,&uStack_34);
    uVar1 = esp_err_to_zb_ret();
  }
  zb_zcl_get_attr_desc_a(*(undefined1 *)(iVar4 + 0xc),0x702,1,0xb);
  if ((uStack_24 == 0) && ((uStack_28 & 0xff) == 0)) {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC12,uVar1,"ESP_ZIGBEE_CORE");
    uVar1 = 0xffffffe4;
  }
  *puVar2 = (undefined1)uStack_28;
  puVar2[1] = (undefined1)uStack_24;
  puVar2[2] = uStack_24._1_1_;
  puVar2[3] = uStack_24._2_1_;
  puVar2[4] = uStack_24._3_1_;
  return uVar1;
}

