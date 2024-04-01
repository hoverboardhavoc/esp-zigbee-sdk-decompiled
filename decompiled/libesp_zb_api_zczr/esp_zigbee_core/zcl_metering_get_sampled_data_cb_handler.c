/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_metering_get_sampled_data_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_metering_get_sampled_data_cb_handler(undefined4 param_1)

{
  undefined1 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 auStack_3c [4];
  undefined1 uStack_38;
  undefined2 uStack_36;
  undefined2 uStack_34;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined2 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar3 = zb_buf_get_tail_func(0x38);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar2 = *(undefined2 **)(iVar4 + 0x10);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar1 = *(undefined1 **)(iVar4 + 0x14);
  memset(auStack_3c,0,0x18);
  uStack_38 = *(undefined1 *)(iVar3 + 4);
  uVar5 = 0;
  uStack_36 = 0x702;
  uStack_34 = *puVar2;
  uStack_30 = *(undefined4 *)(puVar2 + 1);
  uStack_2c = (uint)*(byte *)(puVar2 + 3);
  uStack_28 = *(undefined2 *)((int)puVar2 + 7);
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (zb_core_action_cb != (code *)0x0) {
    (*zb_core_action_cb)(0xe,auStack_3c);
    uVar5 = esp_err_to_zb_ret();
  }
  *puVar1 = (undefined1)uStack_24;
  puVar1[1] = uStack_24._1_1_;
  puVar1[2] = (undefined1)uStack_20;
  puVar1[3] = uStack_20._1_1_;
  puVar1[4] = uStack_20._2_1_;
  puVar1[5] = uStack_20._3_1_;
  puVar1[6] = (char)uStack_1c;
  puVar1[7] = (undefined1)uStack_18;
  puVar1[8] = uStack_18._1_1_;
  puVar1[10] = (char)((uint)uStack_18 >> 0x18);
  puVar1[9] = (char)((uint)uStack_18 >> 0x10);
  puVar1[0xb] = (undefined1)uStack_14;
  puVar1[0xc] = uStack_14._1_1_;
  puVar1[0xd] = uStack_14._2_1_;
  puVar1[0xe] = uStack_14._3_1_;
  if (uStack_18._2_2_ == 0) {
    uVar5 = esp_log_timestamp(uVar5);
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC9,uVar5,"ESP_ZIGBEE_CORE");
    uVar5 = 0xffffffe4;
  }
  return uVar5;
}

