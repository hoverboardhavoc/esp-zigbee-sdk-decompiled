/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_groups.o -> zcl_groups_get_remove_group_res
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_groups_get_remove_group_res(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  undefined4 uVar4;
  uint auStack_34 [8];
  undefined2 uStack_14;
  
  iVar1 = zb_zcl_basic_message_create(auStack_34);
  if (iVar1 == 0) {
    uVar2 = zb_buf_len_func(param_1);
    if (uVar2 < 3) {
      pbVar3 = (byte *)0x0;
      auStack_34[0] = 1;
    }
    else {
      pbVar3 = (byte *)zb_buf_begin_func(param_1);
      if (pbVar3 == (byte *)0x0) {
        auStack_34[0] = 1;
      }
      else {
        auStack_34[0] = (uint)*pbVar3;
      }
    }
    if (pbVar3 == (byte *)0x0) {
      uStack_14 = 0xffff;
    }
    else {
      uStack_14 = *(undefined2 *)(pbVar3 + 1);
    }
    iVar1 = esp_zb_core_action_handler_schedule(0x1010,auStack_34);
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC2,uVar4,0x10000,"zcl_groups_get_remove_group_res",0x44);
  }
  return iVar1;
}

