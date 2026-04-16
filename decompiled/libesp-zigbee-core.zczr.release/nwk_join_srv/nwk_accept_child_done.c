/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_srv.o -> nwk_accept_child_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: join_ind */
/* WARNING: Unknown calling convention */

void nwk_accept_child_done
               (ezb_err_t error,ezb_extaddr_t *joiner_extaddr,nwk_join_method_t join_method)

{
  int iVar1;
  undefined3 in_register_00002031;
  uint uVar2;
  byte local_20;
  nwk_join_method_t nStack_1f;
  undefined2 uStack_1e;
  nwk_join_ind_t join_ind;
  
  uVar2 = CONCAT31(in_register_00002031,join_method);
  iVar1 = nwk_neighbor_table_get_by_extended(joiner_extaddr);
  if (iVar1 == 0) {
    return;
  }
  if (-1 < (int)(*(uint *)(iVar1 + 0xc) << 0x14)) {
    return;
  }
  if (error != 0) {
    nwk_neighbor_table_delete();
    return;
  }
  *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) & 0xfffff7ff;
  if (uVar2 < 5) {
    if (uVar2 != 2) {
      nwk_neighbor_set_unauth(10);
      goto _L0;
    }
  }
  else if (uVar2 != 5) {
    __assert_func(0,0,0,0);
  }
  nwk_neighbor_set_auth(iVar1);
_L0:
  memset(&uStack_1e,0,0xe);
  local_20 = (byte)(*(uint *)(iVar1 + 0xc) >> 0xd) & 0x1f;
  nStack_1f = join_method;
  uStack_1e = nwk_neighbor_get_shortaddr(iVar1);
  nwk_neighbor_get_extaddr(iVar1,&join_ind);
  nwk_join_indication(&local_20);
  return;
}

