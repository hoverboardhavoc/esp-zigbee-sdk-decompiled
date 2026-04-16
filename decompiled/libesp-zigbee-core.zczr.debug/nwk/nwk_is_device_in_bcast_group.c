/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_is_device_in_bcast_group
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool nwk_is_device_in_bcast_group(ezb_shortaddr_t bcast_addr)

{
  _Bool _Var1;
  undefined2 in_register_0000202a;
  int iVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar3;
  
  iVar3 = CONCAT22(in_register_0000202a,bcast_addr);
  if (iVar3 == 0xffff) {
    _Var1 = true;
  }
  else if ((iVar3 == 0xfffd) && (iVar2 = core_globals_get(), *(char *)(iVar2 + 0x9ee) != '\0')) {
    _Var1 = true;
  }
  else if ((iVar3 == 0xfffc) && (_Var1 = nwk_is_device_zczr(), CONCAT31(extraout_var,_Var1) != 0)) {
    _Var1 = true;
  }
  else if (iVar3 == 0xfffb) {
    _Var1 = nwk_is_device_zr();
    if (CONCAT31(extraout_var_00,_Var1) == 0) {
      _Var1 = false;
    }
    else {
      iVar3 = core_globals_get();
      if (*(char *)(iVar3 + 0x9ee) == '\0') {
        _Var1 = true;
      }
      else {
        _Var1 = false;
      }
    }
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}

