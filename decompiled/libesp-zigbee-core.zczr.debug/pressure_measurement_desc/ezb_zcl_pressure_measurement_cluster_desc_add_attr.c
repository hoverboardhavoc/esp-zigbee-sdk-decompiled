/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> pressure_measurement_desc.o -> ezb_zcl_pressure_measurement_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_pressure_measurement_cluster_desc_add_attr
              (short *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 local_12;
  undefined1 local_11;
  
  local_11 = 0xff;
  local_12 = 0;
  if (param_1 == (short *)0x0) {
    iVar1 = 2;
  }
  else if (*param_1 == 0x403) {
    iVar1 = zcl_pressure_measurement_cluster_get_attr_properties
                      ((char)param_1[1],&local_11,&local_12);
    if (iVar1 == 0) {
      iVar1 = ezb_zcl_cluster_desc_add_manuf_attr(param_1,param_2,local_11,local_12,0,param_3);
    }
  }
  else {
    iVar1 = 2;
  }
  return iVar1;
}

