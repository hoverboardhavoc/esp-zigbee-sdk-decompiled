/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> pm2_5_measurement_desc.o -> ezb_zcl_pm2_5_measurement_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_pm2_5_measurement_create_cluster_desc(undefined4 *param_1,uint param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_1c = __divsf3(0);
  uStack_18 = uStack_1c;
  uStack_14 = uStack_1c;
  iVar1 = zcl_create_cluster_desc(0x42a,param_2,0);
  if (iVar1 != 0) {
    if ((param_2 & 1) == 0) {
      puVar2 = &ezb_zcl_pm2_5_measurement_cluster_client_init;
    }
    else {
      puVar2 = &ezb_zcl_pm2_5_measurement_cluster_server_init;
    }
    *(undefined **)(iVar1 + 8) = puVar2;
    if (param_1 != (undefined4 *)0x0) {
      uStack_1c = *param_1;
      uStack_18 = param_1[1];
      uStack_14 = param_1[2];
    }
    zcl_cluster_desc_add_revision_attr(iVar1,2);
    if ((param_2 & 1) != 0) {
      ezb_zcl_pm2_5_measurement_cluster_desc_add_attr(iVar1,0,&uStack_1c);
      ezb_zcl_pm2_5_measurement_cluster_desc_add_attr(iVar1,1,&uStack_18);
      ezb_zcl_pm2_5_measurement_cluster_desc_add_attr(iVar1,2,&uStack_14);
    }
  }
  return iVar1;
}

