/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_srv.o -> nwk_check_shortaddr_conflict
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool nwk_check_shortaddr_conflict(ezb_extaddr_t *extaddr,ezb_shortaddr_t shortaddr)

{
  bool bVar1;
  int iVar2;
  undefined2 in_register_0000202e;
  int iStack_18;
  ezb_extaddr_t local_extaddr;
  
  iVar2 = nwk_address_extended_by_short(CONCAT22(in_register_0000202e,shortaddr),&iStack_18);
  if (iVar2 == 0) {
    bVar1 = iStack_18 == *(int *)&extaddr->field_0 &&
            *(int *)((int)&extaddr->field_0 + 4) == local_extaddr.field_0.u64._0_4_;
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}

