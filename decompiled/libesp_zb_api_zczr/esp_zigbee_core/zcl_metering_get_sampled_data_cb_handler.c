/*
 * Last changed at upstream commit f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * https://github.com/espressif/esp-zigbee-sdk/commit/f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * Upstream date: 2024-02-02 22:17:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.0(5362d771)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_metering_get_sampled_data_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_metering_get_sampled_data_cb_handler(undefined4 param_1)

{
  undefined1 *puVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uStack_3c;
  ushort uStack_38;
  undefined2 uStack_36;
  uint uStack_34;
  undefined4 uStack_30;
  uint uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar3 = zb_buf_get_tail_func(0x38);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar2 = *(ushort **)(iVar4 + 0x10);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar1 = *(undefined1 **)(iVar4 + 0x14);
  uStack_3c = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  _uStack_38 = CONCAT22(0x702,(ushort)*(byte *)(iVar3 + 4));
  uStack_34 = (uint)*puVar2;
  uStack_30 = *(undefined4 *)(puVar2 + 1);
  uStack_2c = (uint)(byte)puVar2[3];
  uStack_28 = (uint)*(ushort *)((int)puVar2 + 7);
  if (zb_core_action_cb == (code *)0x0) {
    uVar5 = 0;
  }
  else {
    (*zb_core_action_cb)(0xe,&uStack_3c);
    uVar5 = esp_err_to_zb_ret();
  }
  *puVar1 = (char)uStack_24;
  puVar1[1] = (char)((uint)uStack_24 >> 8);
  puVar1[2] = (char)uStack_20;
  puVar1[3] = (char)((uint)uStack_20 >> 8);
  puVar1[4] = (char)((uint)uStack_20 >> 0x10);
  puVar1[5] = (char)((uint)uStack_20 >> 0x18);
  puVar1[6] = (char)uStack_1c;
  puVar1[7] = (char)uStack_18;
  puVar1[8] = (char)((uint)uStack_18 >> 8);
  puVar1[9] = (char)((uint)uStack_18 >> 0x10);
  puVar1[10] = (char)((uint)uStack_18 >> 0x18);
  puVar1[0xb] = (char)uStack_14;
  puVar1[0xc] = (char)((uint)uStack_14 >> 8);
  puVar1[0xd] = (char)((uint)uStack_14 >> 0x10);
  puVar1[0xe] = (char)((uint)uStack_14 >> 0x18);
  if (uStack_18._2_2_ == 0) {
    uVar5 = esp_log_timestamp(uVar5);
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC49,uVar5,"ESP_ZIGBEE_CORE");
    uVar5 = 0xffffffe4;
  }
  return uVar5;
}

