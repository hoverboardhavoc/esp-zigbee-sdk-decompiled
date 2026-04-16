/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_set_router_started
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_set_router_started(_Bool started)

{
  _Bool _Var1;
  undefined3 in_register_00002029;
  int iVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  
  if ((CONCAT31(in_register_00002029,started) == 1) &&
     (_Var1 = nwk_is_device_zczr(), CONCAT31(extraout_var,_Var1) == 0)) {
    iVar2 = __assert_func("//build/esp-zigbee/src/core/nwk/nwk_internal.h",0x23,
                          "nwk_set_router_started","started == 0 || nwk_is_device_zczr()");
    if ((((iVar2 != 0xffff) &&
         ((iVar2 != 0xfffd || (iVar3 = core_globals_get(), *(char *)(iVar3 + 0x9ee) == '\0')))) &&
        ((iVar2 != 0xfffc || (_Var1 = nwk_is_device_zczr(), CONCAT31(extraout_var_00,_Var1) == 0))))
       && ((iVar2 == 0xfffb && (_Var1 = nwk_is_device_zr(), CONCAT31(extraout_var_01,_Var1) != 0))))
    {
      core_globals_get();
    }
    return;
  }
  iVar2 = core_globals_get();
  *(byte *)(iVar2 + 0xb18) = *(byte *)(iVar2 + 0xb18) & 0xfd | (byte)((started & 1) << 1);
  return;
}

