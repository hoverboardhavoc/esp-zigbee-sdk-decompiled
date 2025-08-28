/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_alarms.o -> alarms_dec_alarm_count
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void alarms_dec_alarm_count(void)

{
  int iVar1;
  
  iVar1 = zb_zcl_get_attr_desc_a(9,1,0);
  if (iVar1 != 0) {
    **(short **)(iVar1 + 6) = **(short **)(iVar1 + 6) + -1;
  }
  return;
}

