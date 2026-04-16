/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_is_shortaddr_loopback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool aps_is_shortaddr_loopback(ezb_shortaddr_t dst_addr)

{
  _Bool _Var1;
  undefined2 in_register_0000202a;
  uint uVar2;
  uint uVar3;
  
  uVar2 = CONCAT22(in_register_0000202a,dst_addr);
  if (uVar2 < 0xfff8) {
    uVar3 = nwk_get_short_address();
    if (uVar3 == uVar2) {
      _Var1 = true;
    }
    else {
      _Var1 = false;
    }
  }
  else if (uVar2 == 0xfffe) {
    _Var1 = true;
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}

