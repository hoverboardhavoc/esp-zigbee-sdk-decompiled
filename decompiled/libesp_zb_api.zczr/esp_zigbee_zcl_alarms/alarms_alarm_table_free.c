/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_alarms.o -> alarms_alarm_table_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void alarms_alarm_table_free(undefined4 param_1)

{
  undefined4 *puVar1;
  void *__ptr;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)alarms_get_alarm_table();
  if (puVar1 != (undefined4 *)0x0) {
    while (__ptr = (void *)*puVar1, __ptr != (void *)0x0) {
      uVar3 = *(undefined4 *)((int)__ptr + 8);
      free(__ptr);
      *puVar1 = uVar3;
    }
    iVar2 = zb_zcl_get_attr_desc_a(param_1,9,1,0);
    if (iVar2 != 0) {
      **(undefined2 **)(iVar2 + 6) = 0;
    }
  }
  return;
}

