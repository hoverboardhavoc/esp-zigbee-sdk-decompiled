/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone_desc.o -> ezb_zcl_ias_zone_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_ias_zone_create_cluster_desc(void *param_1,uint param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined1 auStack_28 [2];
  undefined2 uStack_26;
  undefined2 auStack_24 [2];
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined1 auStack_18 [8];
  
  auStack_28[0] = 0;
  uStack_26 = 0;
  auStack_24[0] = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  auStack_18[0] = 0xff;
  iVar1 = zcl_create_cluster_desc(0x500,0);
  if (iVar1 != 0) {
    if ((param_2 & 1) == 0) {
      puVar2 = &ezb_zcl_ias_zone_cluster_client_init;
    }
    else {
      puVar2 = &ezb_zcl_ias_zone_cluster_server_init;
    }
    *(undefined **)(iVar1 + 8) = puVar2;
    if (param_1 != (void *)0x0) {
      memcpy(auStack_28,param_1,0x18);
    }
    zcl_cluster_desc_add_revision_attr(iVar1,1);
    if ((param_2 & 1) != 0) {
      ezb_zcl_ias_zone_cluster_desc_add_attr(iVar1,0,auStack_28);
      ezb_zcl_ias_zone_cluster_desc_add_attr(iVar1,1,&uStack_26);
      ezb_zcl_ias_zone_cluster_desc_add_attr(iVar1,2,auStack_24);
      ezb_zcl_ias_zone_cluster_desc_add_attr(iVar1,0x10,&uStack_20);
      ezb_zcl_ias_zone_cluster_desc_add_attr(iVar1,0x11,auStack_18);
      ezb_zcl_cluster_desc_add_manuf_attr(iVar1,0xeff0,0,0x40,0x131b,0);
    }
  }
  return iVar1;
}

