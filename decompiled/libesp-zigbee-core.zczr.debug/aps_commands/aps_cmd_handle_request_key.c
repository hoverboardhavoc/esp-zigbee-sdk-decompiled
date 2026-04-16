/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  uint uVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  undefined1 auStack_24 [4];
  apsme_request_key_ind_t ind;
  
  iVar4 = aps_secur_is_tc();
  if (iVar4 != 0) {
    auStack_24 = (undefined1  [4])0x0;
    ind.src_address.field_0.u64._0_4_ = 0;
    ind.src_address.field_0.u64._4_4_ = 0;
    ind._8_4_ = 0;
    ind.partner_address.field_0.u8[3] = '\0';
    sVar2 = zmsg_get_offset(msg);
    iVar4 = nwk_address_extended_by_short((aps_hdr->addr_info).src_addr,auStack_24);
    if (iVar4 == 0) {
      sVar3 = zmsg_read_bytes(msg,sVar2 + 1,1,(undefined1 *)((int)&ind.src_address.field_0 + 4));
      uVar1 = (uint)(ushort)(sVar2 + 1 + sVar3);
      if ((ind.src_address.field_0.u64._4_4_ & 0xff) == 2) {
        iVar4 = zmsg_get_length(msg);
        if ((int)(iVar4 - uVar1) < 8) goto _L0;
        zmsg_read_bytes(msg,uVar1,8,(undefined1 *)((int)&ind.src_address.field_0 + 5));
      }
      else if ((ind.src_address.field_0.u64._4_4_ & 0xff) != 4) goto _L0;
      apsme_request_key_indication((apsme_request_key_ind_t *)auStack_24);
    }
  }
_L0:
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return;
}

