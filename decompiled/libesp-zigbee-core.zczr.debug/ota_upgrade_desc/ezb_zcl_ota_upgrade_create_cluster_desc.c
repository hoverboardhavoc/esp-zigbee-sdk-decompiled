/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_desc.o -> ezb_zcl_ota_upgrade_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_ota_upgrade_create_cluster_desc(undefined1 *param_1,uint param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 auStack_24 [16];
  
  auStack_24[0] = 1;
  local_40 = 0xffffffff;
  uStack_3c = 0xffffffff;
  uStack_38 = 0xffffffff;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  iVar1 = zcl_create_cluster_desc(0x19,0);
  if (iVar1 != 0) {
    if ((param_2 & 1) == 0) {
      puVar2 = &ezb_zcl_ota_upgrade_cluster_client_init;
    }
    else {
      puVar2 = &ezb_zcl_ota_upgrade_cluster_server_init;
    }
    *(undefined **)(iVar1 + 8) = puVar2;
    if (param_1 != (undefined1 *)0x0) {
      auStack_24[0] = *param_1;
    }
    zcl_cluster_desc_add_revision_attr(iVar1,4);
    if ((param_2 & 1) != 0) {
      ezb_zcl_cluster_desc_add_manuf_attr(iVar1,0xeff0,0x20,0x40,0x131b,auStack_24);
      ezb_zcl_cluster_desc_add_manuf_attr(iVar1,0xeff1,0,0x40,0x131b,0);
    }
    if (param_1 != (undefined1 *)0x0) {
      memcpy(&local_40,param_1,0x18);
    }
    zcl_cluster_desc_add_revision_attr(iVar1,4);
    if ((param_2 & 2) != 0) {
      ezb_zcl_ota_upgrade_cluster_desc_add_attr(iVar1,0,&local_40);
      ezb_zcl_ota_upgrade_cluster_desc_add_attr(iVar1,1,&uStack_38);
      ezb_zcl_ota_upgrade_cluster_desc_add_attr(iVar1,6,&uStack_34);
      ezb_zcl_ota_upgrade_cluster_desc_add_attr(iVar1,7,(int)&uStack_34 + 2);
      ezb_zcl_ota_upgrade_cluster_desc_add_attr(iVar1,8,&uStack_30);
      ezb_zcl_cluster_desc_add_manuf_attr(iVar1,0xeff0,0,0x40,0x131b,0);
    }
  }
  return iVar1;
}

