/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_alarms.o -> zcl_alarms_reset_all_alarms_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_alarms_reset_all_alarms_handler(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uStack_18;
  undefined1 uStack_14;
  undefined2 uStack_12;
  
  uStack_18 = 0;
  iVar1 = zb_buf_get_tail_func(0x38);
  uStack_14 = *(undefined1 *)(iVar1 + 4);
  uStack_12 = 9;
  esp_zb_core_action_handler_schedule(0x51,&uStack_18);
  iVar1 = esp_err_to_zb_ret();
  if (iVar1 == 0) {
    alarms_alarm_table_free(uStack_14);
  }
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  *(int *)(iVar2 + 8) = iVar1;
  return iVar1;
}

