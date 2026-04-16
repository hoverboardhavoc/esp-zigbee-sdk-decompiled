/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk.o -> nwk_is_device_in_bcast_group
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool nwk_is_device_in_bcast_group(ezb_shortaddr_t bcast_addr)

{
  byte bVar1;
  _Bool _Var2;
  undefined2 in_register_0000202a;
  int iVar3;
  undefined3 extraout_var;
  
  iVar3 = CONCAT22(in_register_0000202a,bcast_addr);
  if (iVar3 == 0xffff) {
    return true;
  }
  if (iVar3 == 0xfffd) {
    iVar3 = core_globals_get();
    bVar1 = *(byte *)(iVar3 + 0x9ee);
  }
  else if (iVar3 == 0xfffc) {
    bVar1 = nwk_is_device_zczr();
  }
  else {
    if (iVar3 == 0xfffb) {
      _Var2 = nwk_is_device_zr();
      if (CONCAT31(extraout_var,_Var2) != 0) {
        iVar3 = core_globals_get();
        bVar1 = *(byte *)(iVar3 + 0x9ee) ^ 1;
        goto _L0;
      }
    }
    bVar1 = 0;
  }
_L0:
  return (_Bool)(bVar1 & 1);
}

