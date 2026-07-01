/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_cmd_handle_transport_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_cmd_handle_transport_key(aps_header_t *aps_hdr,zmsg_t *msg)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  undefined1 uVar7;
  uint uVar8;
  undefined1 *puStack_7c;
  nwk_addr_ref_t ref;
  ezb_extaddr_t dst_addr;
  ezb_extaddr_t src_addr;
  aps_cmd_transport_key_s pl;
  apsme_transport_key_ind_t ind;
  
  iVar3 = aps_secur_is_tc();
  uVar7 = (undefined1)iVar3;
  if ((iVar3 == 0) &&
     ((iVar3 = core_globals_get(), -1 < *(char *)(iVar3 + 0x9ba) || ((msg->flags & 4) != 0)))) {
    stack0xffffffbc = 0;
    ind.src_address.field_0.u64._0_4_ = 0;
    ind.src_address.field_0.u64._4_4_ = 0;
    ind._8_4_ = 0;
    ind.field_2._3_4_ = 0;
    ind.field_2._7_4_ = 0;
    ind.field_2._11_4_ = 0;
    ind.field_2._15_4_ = 0;
    ind.field_2._19_2_ = 0;
    ind.field_2._21_1_ = 0;
    sVar1 = zmsg_get_offset(msg);
    sVar2 = zmsg_read_bytes(msg,sVar1 + 1,1,(undefined1 *)((int)&ind.src_address.field_0 + 4));
    uVar6 = ind.src_address.field_0.u64._4_4_ & 0xff;
    if (uVar6 == 3) {
      iVar3 = 0x19;
    }
    else if (uVar6 == 4) {
      iVar3 = 0x20;
    }
    else if (uVar6 == 1) {
      iVar3 = 0x21;
    }
    else {
      iVar3 = 0;
    }
    iVar4 = zmsg_read_bytes(msg,sVar1 + 1 + sVar2,iVar3,(undefined1 *)((int)&src_addr.field_0 + 5));
    if (iVar4 == iVar3) {
      ind.field_2._21_1_ = ind.field_2._21_1_ & 0xfe | (msg->flags & 4) != 0;
      memcpy((void *)((int)&ind.src_address.field_0 + 5),(void *)((int)&src_addr.field_0 + 5),0x10);
      uVar6 = ind.src_address.field_0.u64._4_4_ & 0xff;
      if (uVar6 == 3) {
        iVar3 = nwk_address_extended_by_short
                          ((aps_hdr->addr_info).src_addr,(undefined1 *)((int)&pl.field_1 + 0x1f));
        if ((iVar3 == 0) &&
           (iVar3 = aps_secur_is_addr_tc((undefined1 *)((int)&pl.field_1 + 0x1f)), iVar3 != 0)) {
          ind.field_2.nwk.key[0xc] = (char)((uint)pl.field_1._11_4_ >> 8);
          ind.field_2.nwk.key[0xd] = (char)((uint)pl.field_1._11_4_ >> 0x10);
          ind.field_2.nwk.key[0xe] = (char)((uint)pl.field_1._11_4_ >> 0x18);
          ind.field_2._15_4_ = pl.field_1._15_4_;
          if (((uint)pl.field_1._19_4_ >> 8 & 0xff) != 0) {
            uVar7 = (undefined1)iVar3;
          }
          ind.field_2._20_1_ = uVar7;
          ind.field_2._19_1_ = (char)pl.field_1._19_4_;
_L0:
          zmsg_free(msg);
          apsme_transport_key_indication
                    ((apsme_transport_key_ind_t *)((int)&pl.field_1.nwk.src_addr.field_0 + 6));
          return;
        }
      }
      else if (uVar6 == 4) {
        uVar6 = pl.field_1._15_4_ << 0x18 | (uint)pl.field_1._11_4_ >> 8;
        uVar8 = pl.field_1._19_4_ << 0x18 | (uint)pl.field_1._15_4_ >> 8;
        dst_addr.field_0.u64._4_4_ = pl.field_1._23_4_ << 0x18 | (uint)pl.field_1._19_4_ >> 8;
        src_addr.field_0.u64._0_4_ =
             (uint)(byte)pl.field_1._27_1_ << 0x18 | (uint)pl.field_1._23_4_ >> 8;
        _ref = uVar6;
        dst_addr.field_0.u64._0_4_ = uVar8;
        iVar3 = aps_secur_is_addr_tc((undefined1 *)((int)&dst_addr.field_0 + 4));
        if (iVar3 != 0) {
          puVar5 = (uint *)nwk_get_extended_address();
          if ((uVar6 == *puVar5) && (uVar8 == puVar5[1])) {
            register0x0000203c = dst_addr.field_0.u64._4_4_;
            ind.src_address.field_0.u64._0_4_ = src_addr.field_0.u64._0_4_;
            goto _L0;
          }
        }
      }
      else if (uVar6 == 1) {
        uVar6 = pl.field_1._15_4_ << 0x10 | (uint)pl.field_1._11_4_ >> 0x10;
        uVar8 = pl.field_1._19_4_ << 0x10 | (uint)pl.field_1._15_4_ >> 0x10;
        dst_addr.field_0.u64._4_4_ = pl.field_1._23_4_ << 0x10 | (uint)pl.field_1._19_4_ >> 0x10;
        src_addr.field_0.u64._0_4_ =
             (uint)(ushort)pl.field_1._27_2_ << 0x10 | (uint)pl.field_1._23_4_ >> 0x10;
        _ref = uVar6;
        dst_addr.field_0.u64._0_4_ = uVar8;
        iVar3 = aps_secur_is_centralized();
        if (iVar3 == 0) {
          if ((dst_addr.field_0.u64._4_4_ & src_addr.field_0.u64._0_4_) != 0xffffffff) goto _L0;
        }
        else if ((dst_addr.field_0.u64._4_4_ == 0 && src_addr.field_0.u64._0_4_ == 0) ||
                ((dst_addr.field_0.u64._4_4_ == -1 && (src_addr.field_0.u64._0_4_ == -1))))
        goto _L0;
        puVar5 = (uint *)nwk_get_extended_address();
        if ((uVar6 != *puVar5) || (uVar8 != puVar5[1])) {
          if ((aps_hdr->addr_info).dst_addr < 0xfff8) {
            return;
          }
          if (uVar6 != 0 || uVar8 != 0) {
            return;
          }
        }
        aps_secur_set_tc_address((undefined1 *)((int)&dst_addr.field_0 + 4));
        if ((dst_addr.field_0.u64._4_4_ != -1) || (src_addr.field_0.u64._0_4_ != -1)) {
          iVar3 = nwk_address_update((undefined1 *)((int)&dst_addr.field_0 + 4),0,&puStack_7c);
          if (iVar3 != 0) goto _L0;
          iVar3 = nwk_is_device_zr();
          if ((iVar3 != 0) && ((aps_hdr->addr_info).src_addr != 0)) {
            nwk_route_table_add_rev_route(0,0);
          }
        }
        if ((msg->flags & 4) != 0) {
          zmsg_get_footer(msg,&puStack_7c);
          iVar3 = aps_secur_is_centralized();
          if (iVar3 == 0) {
            aps_secur_delete_key_pair(puStack_7c);
          }
          else {
            *puStack_7c = (char)dst_addr.field_0.u64._4_4_;
            puStack_7c[1] = (char)((uint)dst_addr.field_0._4_4_ >> 8);
            puStack_7c[2] = (char)((uint)dst_addr.field_0._4_4_ >> 0x10);
            puStack_7c[3] = (char)((uint)dst_addr.field_0._4_4_ >> 0x18);
            puStack_7c[4] = (char)src_addr.field_0.u64._0_4_;
            puStack_7c[5] = (char)((uint)src_addr.field_0._0_4_ >> 8);
            puStack_7c[6] = (char)((uint)src_addr.field_0._0_4_ >> 0x10);
            puStack_7c[7] = (char)((uint)src_addr.field_0._0_4_ >> 0x18);
          }
        }
        ind.field_2.nwk.key[0xc] = pl.field_1.nwk.key[0xc];
        stack0xffffffbc = dst_addr.field_0.u64._4_4_;
        ind.src_address.field_0.u64._0_4_ = src_addr.field_0.u64._0_4_;
        goto _L0;
      }
    }
  }
_L0:
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return;
}

