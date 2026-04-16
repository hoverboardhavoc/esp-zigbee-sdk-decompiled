/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_is_addr_in_realm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool nwk_fwd_is_addr_in_realm(ezb_shortaddr_t short_addr)

{
  _Bool _Var1;
  undefined2 in_register_0000202a;
  int iVar2;
  
  iVar2 = nwk_get_short_address();
  if (iVar2 == CONCAT22(in_register_0000202a,short_addr)) {
    _Var1 = true;
  }
  else {
    iVar2 = nwk_neighbor_table_get_by_short(CONCAT22(in_register_0000202a,short_addr));
    if (iVar2 == 0) {
      _Var1 = false;
    }
    else if ((*(uint *)(iVar2 + 0xc) & 0x3c0) == 0x40) {
      _Var1 = true;
    }
    else {
      _Var1 = false;
    }
  }
  return _Var1;
}

