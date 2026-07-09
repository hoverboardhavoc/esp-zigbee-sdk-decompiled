/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_dm_compat.o -> zb_zcl_custom_cluster_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_custom_cluster_init(void)

{
  int iVar1;
  undefined1 uVar2;
  short sVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined *puStack_14;
  
  uVar5 = ezb_af_get_ep_desc();
  iVar1 = 0;
  while (iVar1 = ezb_af_ep_desc_get_next_cluster_desc(uVar5,iVar1), iVar1 != 0) {
    sVar3 = ezb_zcl_cluster_desc_get_id(iVar1);
    if (sVar3 < 0) {
      uStack_24 = 0;
      uStack_20 = 0;
      uStack_1c = 0;
      uStack_18 = 0;
      puStack_14 = (undefined *)0x0;
      uVar4 = ezb_zcl_cluster_desc_get_id(iVar1);
      uStack_24 = CONCAT22(uStack_24._2_2_,uVar4);
      uVar2 = ezb_zcl_cluster_desc_get_role(iVar1);
      uStack_24._0_3_ = CONCAT12(uVar2,(undefined2)uStack_24);
      puStack_14 = &zb_zcl_custom_cluster_cmd_handler;
      ezb_zcl_custom_cluster_handlers_register(&uStack_24);
    }
  }
  return;
}

