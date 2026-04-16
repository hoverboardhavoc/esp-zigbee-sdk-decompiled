/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_desc.o -> zcl_get_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_cluster_desc_t * zcl_get_cluster_desc(uint8_t ep_id,uint16_t cluster_id,uint8_t cluster_role)

{
  undefined3 in_register_00002029;
  int iVar1;
  zcl_cluster_desc_t *pzVar2;
  undefined2 in_register_0000202e;
  undefined3 in_register_00002031;
  
  iVar1 = af_get_ep_desc(CONCAT31(in_register_00002029,ep_id));
  if (iVar1 != 0) {
    pzVar2 = (zcl_cluster_desc_t *)
             af_endpoint_get_cluster_desc
                       (CONCAT22(in_register_0000202e,cluster_id),
                        CONCAT31(in_register_00002031,cluster_role));
    return pzVar2;
  }
  return (zcl_cluster_desc_t *)0x0;
}

