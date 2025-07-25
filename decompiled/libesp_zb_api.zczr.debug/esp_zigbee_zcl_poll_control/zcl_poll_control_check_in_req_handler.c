/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_poll_control.o -> zcl_poll_control_check_in_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_poll_control_check_in_req_handler(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  local_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uVar1 = get_endpoint_by_cluster(0x20,2);
  uStack_1c = CONCAT31(uStack_1c._1_3_,uVar1);
  uStack_1c = CONCAT22(0x20,(undefined2)uStack_1c);
  uStack_18 = CONCAT13(uStack_18._3_1_,*(undefined3 *)(iVar2 + 0xe));
  uStack_14 = CONCAT22(uStack_14._2_2_,*(undefined2 *)(iVar2 + 0xc));
  esp_zb_core_action_handler_schedule(0x45,&local_20);
  esp_err_to_zb_ret();
  return;
}

