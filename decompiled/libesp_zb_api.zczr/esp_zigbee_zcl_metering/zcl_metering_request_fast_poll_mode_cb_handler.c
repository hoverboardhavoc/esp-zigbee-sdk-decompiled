/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_metering.o -> zcl_metering_request_fast_poll_mode_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_metering_request_fast_poll_mode_cb_handler(undefined4 param_1)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  ushort *puVar5;
  undefined4 uStack_34;
  ushort uStack_30;
  undefined2 uStack_2e;
  uint uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  puVar5 = *(ushort **)(iVar3 + 0x10);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  puVar1 = *(undefined1 **)(iVar3 + 0x14);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  iVar3 = *(int *)(iVar3 + 0xc);
  uStack_34 = 0;
  _uStack_30 = CONCAT22(0x702,(ushort)*(byte *)(iVar2 + 4));
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_2c = (uint)*puVar5;
  esp_zb_core_action_handler_schedule(10,&uStack_34);
  uVar4 = esp_err_to_zb_ret();
  zb_zcl_get_attr_desc_a(*(undefined1 *)(iVar3 + 0xc),0x702,1,0xb);
  if ((uStack_24 == 0) && ((uStack_28 & 0xff) == 0)) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ZCL_METERING",&_L0,uVar4,"ESP_ZIGBEE_ZCL_METERING");
    uVar4 = 0xffffffe4;
  }
  *puVar1 = (undefined1)uStack_28;
  puVar1[1] = (undefined1)uStack_24;
  puVar1[2] = uStack_24._1_1_;
  puVar1[3] = uStack_24._2_1_;
  puVar1[4] = uStack_24._3_1_;
  return uVar4;
}

