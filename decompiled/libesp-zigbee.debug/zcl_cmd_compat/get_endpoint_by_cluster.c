/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> get_endpoint_by_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t get_endpoint_by_cluster(uint16_t cluster_id,uint8_t cluster_role)

{
  uint8_t *puVar1;
  undefined2 in_register_0000202a;
  int iVar2;
  undefined3 in_register_0000202d;
  
  puVar1 = (uint8_t *)0x0;
  do {
    puVar1 = (uint8_t *)ezb_af_get_next_simple_desc(puVar1);
    if (puVar1 == (uint8_t *)0x0) {
      return '\0';
    }
    ezb_af_get_ep_desc(*puVar1);
    iVar2 = ezb_af_endpoint_get_cluster_desc
                      (CONCAT22(in_register_0000202a,cluster_id),
                       CONCAT31(in_register_0000202d,cluster_role));
  } while (iVar2 == 0);
  return *puVar1;
}

