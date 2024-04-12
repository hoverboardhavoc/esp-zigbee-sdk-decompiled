/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_ias_zone.o -> zcl_ias_zone_enroll_response_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_ias_zone_enroll_response_handler(void)

{
  undefined2 uVar1;
  int iVar2;
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
  uStack_14 = uVar1;
  esp_zb_core_action_handler_schedule(3,&local_20);
  esp_err_to_zb_ret();
  return;
}

