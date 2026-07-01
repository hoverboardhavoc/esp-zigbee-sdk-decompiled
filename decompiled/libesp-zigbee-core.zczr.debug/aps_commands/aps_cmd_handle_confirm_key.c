/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_cmd_handle_confirm_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: dst_addr */
/* WARNING: Unknown calling convention */

void aps_cmd_handle_confirm_key(aps_header_t *aps_hdr,zmsg_t *msg)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined1 auStack_2c [4];
  apsme_confirm_key_ind_t ind;
  ezb_extaddr_t dst_addr;
  
  if (((aps_hdr->addr_info).dst_addr < 0xfff8) && (iVar1 = aps_secur_is_tc(), iVar1 == 0)) {
    if ((msg->flags & 4) == 0) goto _L0;
    auStack_2c = (undefined1  [4])0x0;
    ind.src_address.field_0.u64._0_4_ = 0;
    ind.src_address.field_0.u64._4_4_ = 0;
    ind.key_type = '\0';
    ind.status = '\0';
    ind._10_2_ = 0;
    ind.frame_cntr = 0;
    iVar1 = zmsg_get_offset(msg);
    uVar3 = iVar1 + 1U & 0xffff;
    iVar1 = nwk_address_extended_by_short((aps_hdr->addr_info).src_addr,auStack_2c);
    if ((iVar1 == 0) && (iVar1 = zmsg_get_length(msg), 9 < (int)(iVar1 - uVar3))) {
      iVar1 = zmsg_read_bytes(msg,uVar3,1,(undefined1 *)((int)&ind.src_address.field_0 + 5));
      uVar3 = uVar3 + iVar1 & 0xffff;
      iVar1 = zmsg_read_bytes(msg,uVar3,1,(undefined1 *)((int)&ind.src_address.field_0 + 4));
      zmsg_read_bytes(msg,uVar3 + iVar1 & 0xffff,8,&ind.field_0x10);
      piVar2 = (int *)nwk_get_extended_address();
      if (((ind._16_4_ == *piVar2) &&
          (((dst_addr.field_0.u64._0_4_ == piVar2[1] &&
            ((ind.src_address.field_0.u64._4_4_ & 0xff) == 4)) &&
           (iVar1 = aps_secur_is_addr_tc(auStack_2c), iVar1 != 0)))) &&
         (iVar1 = aps_secur_get_key_pair_by_addr(auStack_2c), iVar1 != 0)) {
        if ((ind.src_address.field_0.u8[5] == '\0') && ((*(ushort *)(iVar1 + 0x34) & 6) == 2)) {
          aps_secur_key_pair_set_verified();
        }
        apsme_confirm_key_indication((apsme_confirm_key_ind_t *)auStack_2c);
      }
    }
  }
  if (msg == (zmsg_t *)0x0) {
    return;
  }
_L0:
  zmsg_free(msg);
  return;
}

