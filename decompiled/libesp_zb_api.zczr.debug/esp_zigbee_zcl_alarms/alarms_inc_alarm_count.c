/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_alarms.o -> alarms_inc_alarm_count
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void alarms_inc_alarm_count(undefined4 param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = zb_zcl_get_attr_desc_a(9,1,0);
  if (iVar2 != 0) {
    **(short **)(iVar2 + 6) = **(short **)(iVar2 + 6) + 1;
    uVar1 = **(ushort **)(iVar2 + 6);
    uVar3 = alarms_get_alarm_table_size(param_1);
    if (uVar3 < uVar1) {
      zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/zcl/esp_zigbee_zcl_alarms.c"
                ,0x6b);
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  return;
}

