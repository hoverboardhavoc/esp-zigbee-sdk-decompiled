/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> metering_desc.o -> ezb_zcl_metering_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_metering_create_cluster_desc(void *param_1,uint param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  local_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  iVar1 = zcl_create_cluster_desc(0x702,0);
  if (iVar1 != 0) {
    if ((param_2 & 1) == 0) {
      puVar2 = &ezb_zcl_metering_cluster_client_init;
    }
    else {
      puVar2 = &ezb_zcl_metering_cluster_server_init;
    }
    *(undefined **)(iVar1 + 8) = puVar2;
    if (param_1 != (void *)0x0) {
      memcpy(&local_20,param_1,0x10);
    }
    zcl_cluster_desc_add_revision_attr(iVar1,3);
    if ((param_2 & 1) != 0) {
      ezb_zcl_metering_cluster_desc_add_attr(iVar1,0,&local_20);
      ezb_zcl_metering_cluster_desc_add_attr(iVar1,0x200,&uStack_18);
      ezb_zcl_metering_cluster_desc_add_attr(iVar1,0x300,(int)&uStack_18 + 1);
      ezb_zcl_metering_cluster_desc_add_attr(iVar1,0x303,(int)&uStack_18 + 2);
      ezb_zcl_metering_cluster_desc_add_attr(iVar1,0x306,(int)&uStack_18 + 3);
    }
  }
  return iVar1;
}

