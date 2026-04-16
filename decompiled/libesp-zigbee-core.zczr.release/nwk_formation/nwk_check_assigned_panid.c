/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_formation.o -> nwk_check_assigned_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool nwk_check_assigned_panid(ezb_panid_t panid)

{
  ushort uVar1;
  _Bool _Var2;
  undefined2 in_register_0000202a;
  int iVar3;
  nwk_disc_table_lite_ent_t *pnVar4;
  uint8_t uVar5;
  ezb_panid_t *peVar6;
  
  iVar3 = core_globals_get();
  pnVar4 = nwk_disc_table_lite_get_slot(*(uint8_t *)(iVar3 + 0xba4));
  if ((CONCAT22(in_register_0000202a,panid) - 1 & 0xffff) < 0xfffe) {
    peVar6 = pnVar4->panids;
    for (uVar5 = '\0'; pnVar4->pan_cnt != uVar5; uVar5 = uVar5 + '\x01') {
      uVar1 = *peVar6;
      peVar6 = peVar6 + 1;
      if ((uint)uVar1 == CONCAT22(in_register_0000202a,panid)) goto _L0;
    }
    _Var2 = true;
  }
  else {
_L0:
    _Var2 = false;
  }
  return _Var2;
}

