/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_is_addr_tc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool aps_secur_is_addr_tc(ezb_extaddr_t *extaddr)

{
  int iVar1;
  _Bool _Var2;
  ezb_extaddr_t *peVar3;
  
  iVar1 = *(int *)((int)&extaddr->field_0 + 4);
  if (*(int *)&extaddr->field_0 == 0 && iVar1 == 0) {
    _Var2 = false;
  }
  else if ((*(int *)&extaddr->field_0 == -1) && (iVar1 == -1)) {
    _Var2 = false;
  }
  else {
    peVar3 = aps_secur_get_tc_address();
    if ((*(int *)&extaddr->field_0 == *(int *)&peVar3->field_0) &&
       (*(int *)((int)&extaddr->field_0 + 4) == *(int *)((int)&peVar3->field_0 + 4))) {
      _Var2 = true;
    }
    else {
      _Var2 = false;
    }
  }
  return _Var2;
}

