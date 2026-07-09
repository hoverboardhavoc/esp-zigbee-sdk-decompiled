/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_srv.o -> nwk_accept_child_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_accept_child_done(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  byte local_20;
  undefined1 uStack_1f;
  undefined2 uStack_1e;
  undefined1 auStack_1c [12];
  
  iVar1 = nwk_neighbor_table_get_by_extended(param_2);
  if (iVar1 == 0) {
    return;
  }
  if (-1 < (int)(*(uint *)(iVar1 + 0xc) << 0x14)) {
    return;
  }
  if (param_1 != 0) {
    nwk_neighbor_table_delete();
    return;
  }
  *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) & 0xfffff7ff;
  if (param_3 < 5) {
    if (param_3 != 2) {
      nwk_neighbor_set_unauth(10);
      goto _L0;
    }
  }
  else if (param_3 != 5) {
    __assert_func(0,0,0,0);
  }
  nwk_neighbor_set_auth(iVar1);
_L0:
  memset(&uStack_1e,0,0xe);
  uStack_1f = (undefined1)param_3;
  local_20 = (byte)(*(uint *)(iVar1 + 0xc) >> 0xd) & 0x1f;
  uStack_1e = nwk_neighbor_get_shortaddr(iVar1);
  nwk_neighbor_get_extaddr(iVar1,auStack_1c);
  nwk_join_indication(&local_20);
  return;
}

