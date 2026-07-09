/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_conflicts.o -> nwk_child_address_change_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_child_address_change_confirm(undefined2 *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_18 [8];
  
  if (param_1 == (undefined2 *)0x0) {
    return;
  }
  nwk_neighbor_get_extaddr(auStack_18);
  if ((*(uint *)(param_1 + 6) & 0x3c0) == 0x200) {
    if (param_3 != 0) goto _L0;
    nwk_address_unlock_ref(*param_1);
    iVar1 = nwk_address_update(auStack_18,param_2,param_1);
    if (iVar1 == 0) {
      nwk_address_lock_ref(*param_1);
      *(uint *)(param_1 + 6) = *(uint *)(param_1 + 6) & 0xfffffc3f | 0x40;
      nwk_neighbor_table_store_child(param_1);
      return;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_conflicts.c",0x4b,
                  "nwk_child_address_change_confirm",
                  "child->relationship == NWK_RELATIONSHIP_CONFLICT_CHILD");
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_conflicts.c",0x50,
                "nwk_child_address_change_confirm",
                "(nwk_address_update(&child_extaddr, new_addr, &child->addr_ref)) == 0");
_L0:
  log_write(2,"nwk_conflicts.c","Failed to request child address change: %d",param_3);
  nwk_neighbor_table_delete(param_1);
  return;
}

