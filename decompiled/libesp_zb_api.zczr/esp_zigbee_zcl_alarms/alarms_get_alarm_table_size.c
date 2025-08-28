/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_alarms.o -> alarms_get_alarm_table_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined2 alarms_get_alarm_table_size(void)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = zb_zcl_get_attr_desc_a(9,1,0xeffe);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = **(undefined2 **)(iVar2 + 6);
  }
  return uVar1;
}

