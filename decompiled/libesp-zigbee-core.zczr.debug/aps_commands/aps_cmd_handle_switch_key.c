/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_cmd_handle_switch_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: ind */
/* WARNING: Unknown calling convention */

void aps_cmd_handle_switch_key(aps_header_t *aps_hdr,zmsg_t *msg)

{
  short sVar1;
  int iVar2;
  undefined1 auStack_24 [4];
  ezb_extaddr_t src_addr;
  apsme_switch_key_ind_t ind;
  
  iVar2 = aps_secur_is_tc();
  if (iVar2 == 0) {
    src_addr.field_0.u64._4_4_ = 0;
    ind.src_address.field_0.u64._0_4_ = 0;
    ind.src_address.field_0.u8[4] = '\0';
    sVar1 = zmsg_get_offset(msg);
    iVar2 = nwk_address_extended_by_short((aps_hdr->addr_info).src_addr,auStack_24);
    if ((iVar2 == 0) && (iVar2 = aps_secur_is_addr_tc(auStack_24), iVar2 != 0)) {
      zmsg_read_bytes(msg,sVar1 + 1,1,(undefined1 *)((int)&ind.src_address.field_0 + 4));
      apsme_switch_key_indication((apsme_switch_key_ind_t *)((int)&src_addr.field_0 + 4));
    }
  }
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return;
}

