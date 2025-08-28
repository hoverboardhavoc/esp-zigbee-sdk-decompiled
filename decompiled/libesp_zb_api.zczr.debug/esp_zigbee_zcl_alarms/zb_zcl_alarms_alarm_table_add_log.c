/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_alarms.o -> zb_zcl_alarms_alarm_table_add_log
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_alarms_alarm_table_add_log(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  zb_af_get_endpoint_desc();
  iVar1 = get_cluster_desc(10,1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = zb_zcl_get_attr_desc(0);
    uVar2 = **(undefined4 **)(iVar1 + 6);
  }
  alarms_alarm_table_add_entry(param_1,param_2,param_3,uVar2);
  return;
}

