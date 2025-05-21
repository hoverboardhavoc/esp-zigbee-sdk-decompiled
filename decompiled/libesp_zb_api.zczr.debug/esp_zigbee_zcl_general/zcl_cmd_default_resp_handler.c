/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_general.o -> zcl_cmd_default_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_cmd_default_resp_handler(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined4 auStack_38 [8];
  undefined1 uStack_18;
  uint uStack_14;
  
  iVar1 = zb_zcl_basic_message_create(auStack_38);
  if (iVar1 == 0) {
    uVar2 = zb_buf_len_func(param_1);
    if (uVar2 < 2) {
      auStack_38[0] = 1;
      uStack_18 = 0xff;
      uStack_14 = 1;
    }
    else {
      auStack_38[0] = 0;
      puVar4 = (undefined1 *)zb_buf_begin_func(param_1);
      uStack_18 = *puVar4;
      iVar1 = zb_buf_begin_func(param_1);
      uStack_14 = (uint)*(byte *)(iVar1 + 1);
    }
    esp_zb_core_action_handler_schedule(0x1005,auStack_38);
    iVar1 = esp_err_to_zb_ret();
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar3,0x10000,"zcl_cmd_default_resp_handler",0xce);
  }
  return iVar1;
}

