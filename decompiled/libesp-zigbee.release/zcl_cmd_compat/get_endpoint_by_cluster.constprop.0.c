/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> get_endpoint_by_cluster.constprop.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 get_endpoint_by_cluster_constprop_0(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = (undefined1 *)0x0;
  do {
    puVar1 = (undefined1 *)ezb_af_get_next_simple_desc(puVar1);
    if (puVar1 == (undefined1 *)0x0) {
      return 0;
    }
    ezb_af_get_ep_desc(*puVar1);
    iVar2 = ezb_af_endpoint_get_cluster_desc(0x201,1);
  } while (iVar2 == 0);
  return *puVar1;
}

