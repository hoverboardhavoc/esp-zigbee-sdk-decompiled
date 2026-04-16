/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_extaddr_cmp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool nwk_extaddr_cmp(ezb_extaddr_t *e,nwk_extaddr_c_t *c)

{
  _Bool _Var1;
  nwk_oui_t *__s2;
  int iVar2;
  
  __s2 = oui_table_get_oui(c->oui_ref);
  iVar2 = memcmp((void *)((int)&e->field_0 + 5),__s2,3);
  if (iVar2 == 0) {
    iVar2 = memcmp(e,c,5);
    _Var1 = false;
    if (iVar2 == 0) {
      _Var1 = true;
    }
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}

