/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> aps_commands.o -> aps_send_cmd_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: pl */
/* WARNING: Unknown calling convention */

void aps_send_cmd_confirm(zmsg_t *msg,ezb_err_t error)

{
  short sVar1;
  undefined4 uVar2;
  uint *puVar3;
  int iVar4;
  char cStack_3d;
  uint uStack_3c;
  aps_cmd_id_t cmd_id;
  ezb_extaddr_t dst_addr;
  aps_cmd_transport_key_s pl;
  
  cStack_3d = '\0';
  uVar2 = zmsg_get_offset();
  zmsg_read_bytes(msg,uVar2,1,&cStack_3d);
  if ((cStack_3d == '\x05') && (error == 0)) {
    sVar1 = zmsg_get_offset(msg);
    zmsg_read_bytes(msg,sVar1 + 1,0x22,(undefined1 *)((int)&dst_addr.field_0 + 4));
    if (dst_addr.field_0.u8[4] == '\x04') {
      uStack_3c = pl.field_1._15_4_ << 0x18 | (uint)pl.field_1._11_4_ >> 8;
      dst_addr.field_0.u64._0_4_ = (uint)pl.field_1._15_4_ >> 8 | pl.field_1._19_4_ << 0x18;
      puVar3 = (uint *)nwk_get_extended_address();
      if ((((pl.field_1._23_4_ << 0x18 | (uint)pl.field_1._19_4_ >> 8) == *puVar3) &&
          (((uint)(byte)pl.field_1._27_1_ << 0x18 | (uint)pl.field_1._23_4_ >> 8) == puVar3[1])) &&
         (iVar4 = aps_secur_get_key_pair_by_addr(&stack0xffffffc4), iVar4 != 0)) {
        aps_secur_key_pair_set_unverified((undefined1 *)((int)&dst_addr.field_0 + 5));
      }
    }
  }
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return;
}

