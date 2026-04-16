/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_disc_table.o -> disc_table_ent_match
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool disc_table_ent_match
                (nwk_disc_table_ent_t *ent,nwk_panid_ref_t panid_ref,_Bool is_short,ezb_addr_t *addr
                )

{
  _Bool _Var1;
  int iVar2;
  undefined3 in_register_0000202d;
  undefined3 in_register_00002031;
  
  if ((uint)ent->panid_ref == CONCAT31(in_register_0000202d,panid_ref)) {
    if (((uint)ent->field_7 >> 0x1d & 1) == CONCAT31(in_register_00002031,is_short)) {
      iVar2 = memcmp(ent,addr,8);
      if (iVar2 == 0) {
        _Var1 = true;
      }
      else {
        _Var1 = false;
      }
    }
    else {
      _Var1 = false;
    }
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}

