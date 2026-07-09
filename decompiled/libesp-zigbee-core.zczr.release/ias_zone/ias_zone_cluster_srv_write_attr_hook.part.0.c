/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ias_zone.o -> ias_zone_cluster_srv_write_attr_hook.part.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ias_zone_cluster_srv_write_attr_hook_part_0(void)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  psVar3 = (short *)__assert_func(0,0,0,0);
  iVar2 = zmsg_read_bytes(*psVar3,2,uVar4);
  if (iVar2 == 0) {
    sVar1 = -1;
  }
  else {
    sVar1 = (short)iVar2 + *psVar3;
  }
  *psVar3 = sVar1;
  return;
}

