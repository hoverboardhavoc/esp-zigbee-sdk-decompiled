/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_cmd_handle_remove_device
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: ind */
/* WARNING: Unknown calling convention */

void aps_cmd_handle_remove_device(aps_header_t *aps_hdr,zmsg_t *msg)

{
  int iVar1;
  uint uVar2;
  undefined1 local_20 [4];
  apsme_remove_device_ind_t ind;
  
  iVar1 = aps_secur_is_tc();
  if (iVar1 == 0) {
    if ((msg->flags & 4) == 0) goto _L0;
    local_20 = (undefined1  [4])0x0;
    ind.src_address.field_0.u64._0_4_ = 0;
    ind.src_address.field_0.u64._4_4_ = 0;
    ind.target_address.field_0.u64._0_4_ = 0;
    iVar1 = zmsg_get_offset(msg);
    uVar2 = iVar1 + 1U & 0xffff;
    iVar1 = zmsg_get_length(msg);
    if (((7 < (int)(iVar1 - uVar2)) &&
        (iVar1 = nwk_address_extended_by_short((aps_hdr->addr_info).src_addr,local_20), iVar1 == 0))
       && (iVar1 = aps_secur_is_addr_tc(local_20), iVar1 != 0)) {
      zmsg_read_bytes(msg,uVar2,8,(undefined1 *)((int)&ind.src_address.field_0 + 4));
      apsme_remove_device_indication((apsme_remove_device_ind_t *)local_20);
    }
  }
  if (msg == (zmsg_t *)0x0) {
    return;
  }
_L0:
  zmsg_free(msg);
  return;
}

