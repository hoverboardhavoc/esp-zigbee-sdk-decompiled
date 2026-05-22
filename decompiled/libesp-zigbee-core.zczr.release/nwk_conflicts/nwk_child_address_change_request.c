/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_conflicts.o -> nwk_child_address_change_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_child_address_change_request(nwk_neighbor_t *child)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uStack_24;
  undefined1 auStack_18 [4];
  
  iVar1 = zmsg_alloc(0x2f);
  if (iVar1 != 0) {
    nwk_assign_shortaddr();
    zmsg_set_offset(iVar1,0);
    uVar2 = nwk_get_short_address();
    uVar3 = nwk_neighbor_get_shortaddr(child);
    nwk_frame_write_hdr(iVar1,uVar2,uVar3,1,1,0);
    iVar4 = core_globals_get();
    *(char *)(iVar4 + 0x9d9) = *(char *)(iVar4 + 0x9d9) + '\x01';
    zmsg_write_bytes(iVar1,7,1,(int)&uStack_24 + 2);
    zmsg_append_bytes(iVar1,1,(int)&uStack_24 + 2);
    zmsg_append_bytes(iVar1,2,(int)&uStack_24 + 2);
    zmsg_append_bytes(iVar1,1,(int)&uStack_24 + 2);
    zmsg_add_footer(iVar1,(int)&uStack_24 + 2,1);
    uVar5 = *(uint *)&child->field_0xc;
    uVar2 = nwk_neighbor_get_shortaddr(child);
    nwk_fwd_mac_data_req(iVar1,uVar5 >> 0xd & 0x1f,uVar2,*(uint *)&child->field_0xc >> 10 & 1 ^ 1);
    return;
  }
  uStack_24 = 1;
  if (child != (nwk_neighbor_t *)0x0) {
    nwk_neighbor_get_extaddr(auStack_18);
    if ((*(uint *)&child->field_0xc & 0x3c0) == 0x200) goto _L0;
    do {
      uStack_24 = 0;
      __assert_func(0,0,0);
_L0:
      if (uStack_24 != 0) {
        log_write(2,"nwk_conflicts.c","Failed to request child address change: %d");
        nwk_neighbor_table_delete(child);
        return;
      }
      nwk_address_unlock_ref(child->addr_ref);
      iVar1 = nwk_address_update(auStack_18,0xfffe,child);
    } while (iVar1 != 0);
    nwk_address_lock_ref(child->addr_ref);
    *(uint *)&child->field_0xc = *(uint *)&child->field_0xc & 0xfffffc3f | 0x40;
    nwk_neighbor_table_store_child(child);
  }
  return;
}

