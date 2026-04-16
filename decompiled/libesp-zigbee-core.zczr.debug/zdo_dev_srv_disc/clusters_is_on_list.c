/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> clusters_is_on_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool clusters_is_on_list(uint16_t *cluster_list,uint8_t list_len,uint16_t *clusters,
                         uint8_t num_of_clusters)

{
  undefined3 in_register_0000202d;
  undefined3 in_register_00002035;
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    if (CONCAT31(in_register_0000202d,list_len) <= uVar2) {
      return false;
    }
    for (uVar1 = 0; uVar1 < CONCAT31(in_register_00002035,num_of_clusters); uVar1 = uVar1 + 1 & 0xff
        ) {
      if (cluster_list[uVar2] == clusters[uVar1]) {
        return true;
      }
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while( true );
}

