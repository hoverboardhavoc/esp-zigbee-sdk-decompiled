/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_cmd_handle_transport_key_sent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_cmd_handle_transport_key_sent(zmsg_t *msg,ezb_err_t error)

{
  ushort uVar1;
  aps_device_key_pair_t *key_pair;
  uint uVar2;
  uint uVar3;
  short sVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  uint uStack_44;
  ezb_extaddr_t dst_addr;
  ezb_extaddr_t src_addr;
  aps_cmd_transport_key_s pl;
  
  if (error == 0) {
    sVar4 = zmsg_get_offset();
    zmsg_read_bytes(msg,sVar4 + 1,0x22,(undefined1 *)((int)&src_addr.field_0 + 4));
    if (src_addr.field_0.u8[4] == '\x04') {
      uStack_44 = pl.field_1._15_4_ << 0x18 | (uint)pl.field_1._11_4_ >> 8;
      dst_addr.field_0.u64._0_4_ = (uint)pl.field_1._15_4_ >> 8 | pl.field_1._19_4_ << 0x18;
      uVar3 = pl.field_1._23_4_ << 0x18 | (uint)pl.field_1._19_4_ >> 8;
      uVar2 = (uint)(byte)pl.field_1._27_1_ << 0x18 | (uint)pl.field_1._23_4_ >> 8;
      dst_addr.field_0.u64._4_4_ = uVar3;
      src_addr.field_0.u64._0_4_ = uVar2;
      puVar5 = (uint *)nwk_get_extended_address();
      if (((uVar3 == *puVar5) && (uVar2 == puVar5[1])) &&
         (iVar6 = aps_secur_get_key_pair_by_addr(&uStack_44), iVar6 != 0)) {
        uVar1 = *(ushort *)(iVar6 + 0x34);
        *(ushort *)(iVar6 + 0x34) = uVar1 & 0xfffe;
        *(ushort *)(iVar6 + 0x34) = uVar1 & 0xfff8 | 2;
        memcpy((void *)(iVar6 + 0x12),(void *)((int)&src_addr.field_0 + 5),0x10);
        iVar7 = core_globals_get();
        aps_secur_key_pair_set_timeout(iVar6,*(undefined1 *)(iVar7 + 0x9b4));
      }
    }
  }
  return;
}

