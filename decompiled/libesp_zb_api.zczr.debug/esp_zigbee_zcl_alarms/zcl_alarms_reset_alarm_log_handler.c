/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_alarms.o -> zcl_alarms_reset_alarm_log_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_alarms_reset_alarm_log_handler(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = zb_buf_get_tail_func(0x1b);
  alarms_alarm_table_free(*(undefined1 *)(iVar1 + 0xc));
  uVar2 = zb_buf_get_tail_func(param_1,0x1b);
  zb_zcl_send_default_handler(param_1,uVar2,0);
  return 1;
}

