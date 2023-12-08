/*
 * Last changed at upstream commit 4d04940dfac4dc79b166836b46beea711ac71a6a
 * https://github.com/espressif/esp-zigbee-sdk/commit/4d04940dfac4dc79b166836b46beea711ac71a6a
 * Upstream date: 2023-12-08 17:14:31 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.6(654c5874)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_metering_request_fast_poll_mode_cb_handler
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
  undefined4 uVar5;
  uint uVar6;
  ushort *puVar7;
  undefined4 uStack_34;
  ushort uStack_30;
  undefined2 uStack_2e;
  uint uStack_2c;
  uint uStack_28;
  int iStack_24;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  puVar7 = *(ushort **)(iVar3 + 0x10);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  puVar1 = *(undefined1 **)(iVar3 + 0x14);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  iVar3 = *(int *)(iVar3 + 0xc);
  uStack_34 = 0;
  uStack_28 = 0;
  iStack_24 = 0;
  _uStack_30 = CONCAT22(0x702,(ushort)*(byte *)(iVar2 + 4));
  uStack_2c = (uint)*puVar7;
  if (zb_core_action_cb == (code *)0x0) {
    uVar4 = 0;
  }
  else {
    (*zb_core_action_cb)(10,&uStack_34);
    uVar4 = esp_err_to_zb_ret();
  }
  iVar2 = zb_zcl_get_attr_desc_a(*(undefined1 *)(iVar3 + 0xc),0x702,1,0xb);
  if (iVar2 == 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC48,uVar5,"ESP_ZIGBEE_CORE");
    uVar6 = 5;
  }
  else {
    uVar6 = (uint)**(byte **)(iVar2 + 6);
  }
  if ((iStack_24 == 0) && ((uStack_28 & 0xff) == 0)) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC49,uVar4,"ESP_ZIGBEE_CORE");
    uVar4 = 0xffffffe4;
  }
  else if (((uStack_28 & 0xff) < uVar6) || ((uint)(byte)*puVar7 < (uStack_28 & 0xff))) {
    uVar5 = esp_log_timestamp();
    esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC50,uVar5,"ESP_ZIGBEE_CORE");
  }
  *puVar1 = (undefined1)uStack_28;
  puVar1[1] = (char)iStack_24;
  puVar1[2] = (char)((uint)iStack_24 >> 8);
  puVar1[3] = (char)((uint)iStack_24 >> 0x10);
  puVar1[4] = (char)((uint)iStack_24 >> 0x18);
  return uVar4;
}

