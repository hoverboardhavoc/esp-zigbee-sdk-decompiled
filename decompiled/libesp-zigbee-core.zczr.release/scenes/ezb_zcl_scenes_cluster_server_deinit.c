/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> ezb_zcl_scenes_cluster_server_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_zcl_scenes_cluster_server_deinit(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  
  iVar2 = scenes_srv_get_attr_desc_part_0(0xeff1);
  if (iVar2 != 0) {
    pbVar3 = *(byte **)(iVar2 + 8);
    uVar1 = 0;
    if (pbVar3 != (byte *)0x0) {
      for (; uVar1 < *pbVar3; uVar1 = uVar1 + 1 & 0xff) {
        scene_table_remove_entry(param_1,pbVar3 + uVar1 * 0x20 + 8);
      }
      mm_free(pbVar3);
    }
    *(undefined4 *)(iVar2 + 8) = 0;
  }
  return;
}

