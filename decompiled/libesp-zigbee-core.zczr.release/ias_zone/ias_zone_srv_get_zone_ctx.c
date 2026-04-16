/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ias_zone.o -> ias_zone_srv_get_zone_ctx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ias_zone_srv_zone_ctx_t * ias_zone_srv_get_zone_ctx(uint8_t ep_id)

{
  int iVar1;
  ias_zone_srv_zone_ctx_t *piVar2;
  ushort *puVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  puVar3 = (ushort *)__assert_func(0,0,0,0);
  iVar1 = zmsg_read_bytes(*puVar3,2,uVar4);
  if (iVar1 == 0) {
    piVar2 = (ias_zone_srv_zone_ctx_t *)0xffff;
  }
  else {
    piVar2 = (ias_zone_srv_zone_ctx_t *)(iVar1 + (uint)*puVar3 & 0xffff);
  }
  *puVar3 = (ushort)piVar2;
  return piVar2;
}

