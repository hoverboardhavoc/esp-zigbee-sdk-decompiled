/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_formation.o -> nwk_check_assigned_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool nwk_check_assigned_panid(ezb_panid_t panid)

{
  _Bool _Var1;
  undefined2 in_register_0000202a;
  int iVar2;
  nwk_disc_table_lite_ent_t *pnVar3;
  uint uVar4;
  
  iVar2 = core_globals_get();
  pnVar3 = nwk_disc_table_lite_get_slot(*(uint8_t *)(iVar2 + 0xba4));
  if ((CONCAT22(in_register_0000202a,panid) - 1 & 0xffff) < 0xfffe) {
    for (uVar4 = 0; uVar4 < pnVar3->pan_cnt; uVar4 = uVar4 + 1 & 0xff) {
      if ((uint)pnVar3->panids[uVar4] == CONCAT22(in_register_0000202a,panid)) {
        return false;
      }
    }
    _Var1 = true;
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}

