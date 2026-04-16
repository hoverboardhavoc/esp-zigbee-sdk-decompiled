/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> ezb_zcl_scenes_cluster_server_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_zcl_scenes_cluster_server_deinit(uint8_t ep_id)

{
  uint uVar1;
  zcl_attr_desc_t *pzVar2;
  byte *pbVar3;
  
  pzVar2 = scenes_srv_get_attr_desc(ep_id,0xeff1);
  if (pzVar2 != (zcl_attr_desc_t *)0x0) {
    pbVar3 = (byte *)pzVar2->data_p;
    uVar1 = 0;
    if (pbVar3 != (byte *)0x0) {
      for (; uVar1 < *pbVar3; uVar1 = uVar1 + 1 & 0xff) {
        scene_table_remove_entry(ep_id,(zcl_scene_table_entry_t *)(pbVar3 + uVar1 * 0x20 + 8));
      }
      mm_free(pbVar3);
    }
    pzVar2->data_p = (void *)0x0;
  }
  return;
}

