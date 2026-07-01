/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_cmd_handle_transport_key_sent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_cmd_handle_transport_key_sent(zmsg_t *msg,ezb_err_t error)

{
  uint uVar1;
  uint uVar2;
  short sVar3;
  uint *puVar4;
  int iVar5;
  uint uStack_44;
  ezb_extaddr_t dst_addr;
  ezb_extaddr_t src_addr;
  aps_cmd_transport_key_s pl;
  
  if (error == 0) {
    sVar3 = zmsg_get_offset();
    zmsg_read_bytes(msg,sVar3 + 1,0x22,(undefined1 *)((int)&src_addr.field_0 + 4));
    if (src_addr.field_0.u8[4] == '\x04') {
      uStack_44 = pl.field_1._15_4_ << 0x18 | (uint)pl.field_1._11_4_ >> 8;
      dst_addr.field_0.u64._0_4_ = (uint)pl.field_1._15_4_ >> 8 | pl.field_1._19_4_ << 0x18;
      uVar2 = pl.field_1._23_4_ << 0x18 | (uint)pl.field_1._19_4_ >> 8;
      uVar1 = (uint)(byte)pl.field_1._27_1_ << 0x18 | (uint)pl.field_1._23_4_ >> 8;
      dst_addr.field_0.u64._4_4_ = uVar2;
      src_addr.field_0.u64._0_4_ = uVar1;
      puVar4 = (uint *)nwk_get_extended_address();
      if (((uVar2 == *puVar4) && (uVar1 == puVar4[1])) &&
         (iVar5 = aps_secur_get_key_pair_by_addr(&uStack_44), iVar5 != 0)) {
        aps_secur_key_pair_set_unverified((undefined1 *)((int)&src_addr.field_0 + 5));
      }
    }
  }
  return;
}

