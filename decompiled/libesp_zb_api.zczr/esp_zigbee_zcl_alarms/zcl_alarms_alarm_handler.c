/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_alarms.o -> zcl_alarms_alarm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_alarms_alarm_handler(undefined4 param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_1c;
  undefined1 uStack_18;
  undefined2 uStack_16;
  undefined1 uStack_14;
  undefined2 uStack_12;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  puVar1 = *(undefined1 **)(iVar2 + 0x10);
  uStack_1c = 0;
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  uStack_18 = *(undefined1 *)(iVar2 + 4);
  uStack_16 = 9;
  uStack_14 = *puVar1;
  uStack_12 = *(undefined2 *)(puVar1 + 1);
  esp_zb_core_action_handler_schedule(0x52,&uStack_1c);
  uVar3 = esp_err_to_zb_ret();
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  *(undefined4 *)(iVar2 + 8) = uVar3;
  return uVar3;
}

