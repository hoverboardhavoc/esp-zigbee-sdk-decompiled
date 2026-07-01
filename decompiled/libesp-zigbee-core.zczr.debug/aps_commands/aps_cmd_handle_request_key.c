/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_cmd_handle_request_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: ind */
/* WARNING: Unknown calling convention */

void aps_cmd_handle_request_key(aps_header_t *aps_hdr,zmsg_t *msg)

{
  short sVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_24 [4];
  apsme_request_key_ind_t ind;
  
  iVar3 = aps_secur_is_tc();
  if (iVar3 != 0) {
    if ((msg->flags & 4) == 0) goto _L0;
    auStack_24 = (undefined1  [4])0x0;
    ind.src_address.field_0.u64._0_4_ = 0;
    ind.src_address.field_0.u64._4_4_ = 0;
    ind._8_4_ = 0;
    ind.partner_address.field_0.u8[3] = '\0';
    sVar1 = zmsg_get_offset(msg);
    iVar3 = nwk_address_extended_by_short((aps_hdr->addr_info).src_addr,auStack_24);
    if (iVar3 == 0) {
      sVar2 = zmsg_read_bytes(msg,sVar1 + 1,1,(undefined1 *)((int)&ind.src_address.field_0 + 4));
      uVar4 = (uint)(ushort)(sVar2 + sVar1 + 1);
      if ((ind.src_address.field_0.u64._4_4_ & 0xff) == 2) {
        iVar3 = zmsg_get_length(msg);
        if (7 < (int)(iVar3 - uVar4)) {
          zmsg_read_bytes(msg,uVar4,8,(undefined1 *)((int)&ind.src_address.field_0 + 5));
          goto _L0;
        }
      }
      else if ((ind.src_address.field_0.u64._4_4_ & 0xff) == 4) {
_L0:
        apsme_request_key_indication((apsme_request_key_ind_t *)auStack_24);
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

