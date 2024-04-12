/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_metering.o -> zcl_metering_get_sampled_data_response_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_metering_get_sampled_data_response_cb_handler(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined4 uStack_2c;
  undefined1 uStack_28;
  undefined2 uStack_26;
  undefined2 uStack_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined4 uStack_14;
  
  iVar1 = zb_buf_get_tail_func(0x38);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  puVar3 = *(undefined2 **)(iVar2 + 0x10);
  uStack_2c = 0;
  uStack_28 = *(undefined1 *)(iVar1 + 4);
  uStack_26 = 0x702;
  uStack_24 = *puVar3;
  uStack_20 = *(undefined4 *)(puVar3 + 1);
  uStack_1c = (uint)*(byte *)(puVar3 + 3);
  uStack_18 = *(undefined2 *)((int)puVar3 + 7);
  uStack_16 = *(undefined2 *)((int)puVar3 + 9);
  uStack_14 = *(undefined4 *)((int)puVar3 + 0xb);
  esp_zb_core_action_handler_schedule(0xf,&uStack_2c);
  esp_err_to_zb_ret();
  return;
}

