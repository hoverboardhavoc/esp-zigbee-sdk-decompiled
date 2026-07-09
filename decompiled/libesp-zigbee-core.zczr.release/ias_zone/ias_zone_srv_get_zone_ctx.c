/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ias_zone.o -> ias_zone_srv_get_zone_ctx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ias_zone_srv_get_zone_ctx(void)

{
  int iVar1;
  
  iVar1 = ezb_zcl_get_attr_desc(0x500,1,0xeff0,0x131b);
  if (iVar1 == 0) {
    iVar1 = ias_zone_cluster_srv_write_attr_hook_part_0();
  }
  return *(undefined4 *)(iVar1 + 8);
}

