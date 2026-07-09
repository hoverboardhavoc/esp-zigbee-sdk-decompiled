/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_conflicts.o -> nwk_child_address_change_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_child_address_change_request(undefined2 *param_1)

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
    uVar3 = nwk_neighbor_get_shortaddr(param_1);
    nwk_frame_write_hdr(iVar1,uVar2,uVar3,1,1,0);
    iVar4 = core_globals_get();
    *(char *)(iVar4 + 0x9d9) = *(char *)(iVar4 + 0x9d9) + '\x01';
    zmsg_write_bytes(iVar1,7,1,(int)&uStack_24 + 2);
    zmsg_append_bytes(iVar1,1,(int)&uStack_24 + 2);
    zmsg_append_bytes(iVar1,2,(int)&uStack_24 + 2);
    zmsg_append_bytes(iVar1,1,(int)&uStack_24 + 2);
    zmsg_add_footer(iVar1,(int)&uStack_24 + 2,1);
    uVar5 = *(uint *)(param_1 + 6);
    uVar2 = nwk_neighbor_get_shortaddr(param_1);
    nwk_fwd_mac_data_req(iVar1,uVar5 >> 0xd & 0x1f,uVar2,*(uint *)(param_1 + 6) >> 10 & 1 ^ 1);
    return;
  }
  uStack_24 = 1;
  if (param_1 != (undefined2 *)0x0) {
    nwk_neighbor_get_extaddr(auStack_18);
    if ((*(uint *)(param_1 + 6) & 0x3c0) == 0x200) goto _L0;
    do {
      uStack_24 = 0;
      __assert_func(0,0,0);
_L0:
      if (uStack_24 != 0) {
        log_write(2,"nwk_conflicts.c","Failed to request child address change: %d");
        nwk_neighbor_table_delete(param_1);
        return;
      }
      nwk_address_unlock_ref(*param_1);
      iVar1 = nwk_address_update(auStack_18,0xfffe,param_1);
    } while (iVar1 != 0);
    nwk_address_lock_ref(*param_1);
    *(uint *)(param_1 + 6) = *(uint *)(param_1 + 6) & 0xfffffc3f | 0x40;
    nwk_neighbor_table_store_child(param_1);
  }
  return;
}

