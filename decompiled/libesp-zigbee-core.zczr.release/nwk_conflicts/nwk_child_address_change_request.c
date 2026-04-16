/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_conflicts.o -> nwk_child_address_change_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x0001012a) */
/* WARNING: Removing unreachable block (ram,0x00010138) */
/* WARNING: Removing unreachable block (ram,0x00010148) */
/* WARNING: Removing unreachable block (ram,0x00010164) */
/* WARNING: Unknown calling convention */

void nwk_child_address_change_request(nwk_neighbor_t *child)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined1 auStack_22 [10];
  undefined1 auStack_18 [4];
  
  iVar1 = zmsg_alloc(0x2f);
  if (iVar1 == 0) {
    if (child != (nwk_neighbor_t *)0x0) {
      nwk_neighbor_get_extaddr(auStack_18);
      log_write(2,"nwk_conflicts.c","Failed to request child address change: %d");
      nwk_neighbor_table_delete(child);
    }
    return;
  }
  nwk_assign_shortaddr();
  zmsg_set_offset(iVar1,0);
  uVar2 = nwk_get_short_address();
  uVar3 = nwk_neighbor_get_shortaddr(child);
  nwk_frame_write_hdr(iVar1,uVar2,uVar3,1,1,0);
  iVar4 = core_globals_get();
  *(char *)(iVar4 + 0x9d9) = *(char *)(iVar4 + 0x9d9) + '\x01';
  zmsg_write_bytes(iVar1,7,1,auStack_22);
  zmsg_append_bytes(iVar1,1,auStack_22);
  zmsg_append_bytes(iVar1,2,auStack_22);
  zmsg_append_bytes(iVar1,1,auStack_22);
  zmsg_add_footer(iVar1,auStack_22,1);
  uVar5 = *(uint *)&child->field_0xc;
  uVar2 = nwk_neighbor_get_shortaddr(child);
  nwk_fwd_mac_data_req(iVar1,uVar5 >> 0xd & 0x1f,uVar2,*(uint *)&child->field_0xc >> 10 & 1 ^ 1);
  return;
}

