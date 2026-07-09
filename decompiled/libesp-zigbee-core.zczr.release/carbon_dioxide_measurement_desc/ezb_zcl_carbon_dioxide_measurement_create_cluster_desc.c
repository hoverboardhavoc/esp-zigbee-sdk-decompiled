/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> carbon_dioxide_measurement_desc.o -> ezb_zcl_carbon_dioxide_measurement_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_carbon_dioxide_measurement_create_cluster_desc(void *param_1,uint param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_1c = __divsf3(0);
  uStack_18 = uStack_1c;
  uStack_14 = uStack_1c;
  iVar1 = zcl_create_cluster_desc(0x40d,param_2,0);
  if (iVar1 != 0) {
    if ((param_2 & 1) == 0) {
      puVar2 = &ezb_zcl_carbon_dioxide_measurement_cluster_client_init;
    }
    else {
      puVar2 = &ezb_zcl_carbon_dioxide_measurement_cluster_server_init;
    }
    *(undefined **)(iVar1 + 8) = puVar2;
    if (param_1 != (void *)0x0) {
      memcpy(&uStack_1c,param_1,0xc);
    }
    zcl_cluster_desc_add_revision_attr(iVar1,2);
    if ((param_2 & 1) != 0) {
      ezb_zcl_carbon_dioxide_measurement_cluster_desc_add_attr(iVar1,0,&uStack_1c);
      ezb_zcl_carbon_dioxide_measurement_cluster_desc_add_attr(iVar1,1,&uStack_18);
      ezb_zcl_carbon_dioxide_measurement_cluster_desc_add_attr(iVar1,2,&uStack_14);
    }
  }
  return iVar1;
}

