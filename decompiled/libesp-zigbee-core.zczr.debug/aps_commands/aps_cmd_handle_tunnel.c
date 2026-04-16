/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_cmd_handle_tunnel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: src_addr */
/* WARNING: Unknown calling convention */

void aps_cmd_handle_tunnel(aps_header_t *aps_hdr,zmsg_t *msg)

{
  int iVar1;
  ezb_err_t eVar2;
  uint uVar3;
  undefined1 local_20 [4];
  ezb_extaddr_t dst_addr;
  ezb_extaddr_t src_addr;
  
  iVar1 = aps_secur_is_tc();
  if (iVar1 == 0) {
    iVar1 = zmsg_get_offset(msg);
    uVar3 = iVar1 + 1U & 0xffff;
    iVar1 = zmsg_get_length(msg);
    if (((7 < (int)(iVar1 - uVar3)) &&
        (iVar1 = nwk_address_extended_by_short
                           ((aps_hdr->addr_info).src_addr,(undefined1 *)((int)&dst_addr.field_0 + 4)
                           ), iVar1 == 0)) &&
       (iVar1 = aps_secur_is_addr_tc((undefined1 *)((int)&dst_addr.field_0 + 4)), iVar1 != 0)) {
      local_20 = (undefined1  [4])0x0;
      dst_addr.field_0.u64._0_4_ = 0;
      zmsg_read_bytes(msg,uVar3,8,local_20);
      if ((local_20 != (undefined1  [4])0x0 || dst_addr.field_0.u64._0_4_ != 0) &&
         ((local_20 != (undefined1  [4])0xffffffff || (dst_addr.field_0.u64._0_4_ != -1)))) {
        zmsg_remove_header(msg,0xb);
        eVar2 = aps_relay_cmd(msg,(ezb_extaddr_t *)local_20);
        if (eVar2 == 0) {
          return;
        }
      }
    }
  }
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return;
}

