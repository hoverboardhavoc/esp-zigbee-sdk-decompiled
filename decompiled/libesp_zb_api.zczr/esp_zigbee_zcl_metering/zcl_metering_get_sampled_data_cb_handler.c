/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_metering.o -> zcl_metering_get_sampled_data_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_metering_get_sampled_data_cb_handler(undefined4 param_1)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined2 *puVar5;
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
  
  iVar2 = zb_buf_get_tail_func(0x38);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  puVar5 = *(undefined2 **)(iVar3 + 0x10);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  puVar1 = *(undefined1 **)(iVar3 + 0x14);
  memset(auStack_3c,0,0x18);
  uStack_38 = *(undefined1 *)(iVar2 + 4);
  uStack_36 = 0x702;
  uStack_34 = *puVar5;
  uStack_30 = *(undefined4 *)(puVar5 + 1);
  uStack_2c = (uint)*(byte *)(puVar5 + 3);
  uStack_28 = *(undefined2 *)((int)puVar5 + 7);
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  esp_zb_core_action_handler_schedule(0xe,auStack_3c);
  uVar4 = esp_err_to_zb_ret();
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
    uVar4 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_ZCL_METERING","E (%lu) %s: No appropriate sampled data!\n",uVar4,
            "ESP_ZIGBEE_ZCL_METERING");
    uVar4 = 0xffffffe4;
  }
  return uVar4;
}

