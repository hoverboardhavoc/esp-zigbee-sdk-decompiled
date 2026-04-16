/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk.o -> nwk_check_assigned_shortaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool nwk_check_assigned_shortaddr(ezb_shortaddr_t short_addr)

{
  bool bVar1;
  ezb_shortaddr_t eVar2;
  undefined2 in_register_0000202a;
  undefined2 extraout_var;
  int iVar3;
  undefined1 auStack_12 [4];
  nwk_addr_ref_t ref;
  
  iVar3 = CONCAT22(in_register_0000202a,short_addr);
  if (0xfff6 < (iVar3 - 1U & 0xffff)) {
    return false;
  }
  eVar2 = nwk_get_short_address();
  if (CONCAT22(extraout_var,eVar2) == iVar3) {
    bVar1 = false;
  }
  else {
    iVar3 = nwk_address_ref_by_short(iVar3,auStack_12);
    bVar1 = iVar3 == 0;
  }
  return bVar1;
}

