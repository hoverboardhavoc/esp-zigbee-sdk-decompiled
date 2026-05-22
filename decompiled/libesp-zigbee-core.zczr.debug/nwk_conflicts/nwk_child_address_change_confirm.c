/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_conflicts.o -> nwk_child_address_change_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: child_extaddr */
/* WARNING: Unknown calling convention */

void nwk_child_address_change_confirm
               (nwk_neighbor_t *child,ezb_shortaddr_t new_addr,ezb_err_t error)

{
  int iVar1;
  undefined2 in_register_0000202e;
  undefined1 auStack_18 [4];
  ezb_extaddr_t child_extaddr;
  
  if (child == (nwk_neighbor_t *)0x0) {
    return;
  }
  nwk_neighbor_get_extaddr(auStack_18);
  if ((*(uint *)&child->field_0xc & 0x3c0) == 0x200) {
    if (error != 0) goto _L0;
    nwk_address_unlock_ref(child->addr_ref);
    iVar1 = nwk_address_update(auStack_18,CONCAT22(in_register_0000202e,new_addr),child);
    if (iVar1 == 0) {
      nwk_address_lock_ref(child->addr_ref);
      *(uint *)&child->field_0xc = *(uint *)&child->field_0xc & 0xfffffc3f | 0x40;
      nwk_neighbor_table_store_child(child);
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
  log_write(2,"nwk_conflicts.c","Failed to request child address change: %d",error);
  nwk_neighbor_table_delete(child);
  return;
}

