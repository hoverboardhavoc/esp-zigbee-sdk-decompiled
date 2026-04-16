/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_check_assigned_shortaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool nwk_check_assigned_shortaddr(ezb_shortaddr_t short_addr)

{
  _Bool _Var1;
  ezb_shortaddr_t eVar2;
  undefined2 in_register_0000202a;
  uint uVar3;
  undefined2 extraout_var;
  int iVar4;
  undefined1 auStack_12 [4];
  nwk_addr_ref_t ref;
  
  uVar3 = CONCAT22(in_register_0000202a,short_addr);
  if (uVar3 < 0xfff8) {
    if (uVar3 == 0) {
      _Var1 = false;
    }
    else {
      eVar2 = nwk_get_short_address();
      if (CONCAT22(extraout_var,eVar2) == uVar3) {
        _Var1 = false;
      }
      else {
        iVar4 = nwk_address_ref_by_short(uVar3,auStack_12);
        if (iVar4 == 0) {
          _Var1 = true;
        }
        else {
          _Var1 = false;
        }
      }
    }
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}

