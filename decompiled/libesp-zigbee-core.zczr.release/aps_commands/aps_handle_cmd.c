/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> aps_commands.o -> aps_handle_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_handle_cmd(aps_header_t *aps_hdr,zmsg_t *msg)

{
  byte bVar1;
  uint uVar2;
  _Bool _Var3;
  short sVar4;
  short sVar5;
  undefined4 uVar6;
  undefined3 extraout_var;
  uint *puVar7;
  int iVar8;
  int iVar9;
  undefined3 extraout_var_00;
  ezb_err_t eVar10;
  int *piVar11;
  ezb_shortaddr_t eVar12;
  uint uVar13;
  undefined1 *puStack_7c;
  nwk_addr_ref_t ref;
  uint8_t hash [16];
  aps_cmd_transport_key_s pl;
  undefined1 uStack_42;
  undefined1 uStack_41;
  apsme_verify_key_ind_t ind;
  
  if ((aps_hdr->fcf & 0xc) == 0xc) goto _L0;
  bVar1 = aps_hdr->cmd_id;
  if (bVar1 == 9) {
    iVar8 = aps_secur_is_tc();
    if (iVar8 == 0) {
      stack0xffffffbc = 0;
      ind.src_address.field_0.u64._0_4_ = 0;
      ind.src_address.field_0.u64._4_4_ = ind.src_address.field_0.u64._4_4_ & 0xffffff00;
      sVar4 = zmsg_get_offset(msg);
      iVar8 = nwk_address_extended_by_short((aps_hdr->addr_info).src_addr,hash + 0xc);
      if ((iVar8 == 0) && (iVar8 = aps_secur_is_addr_tc(hash + 0xc), iVar8 != 0)) {
        zmsg_read_bytes(msg,sVar4 + 1,1,(undefined1 *)((int)&ind.src_address.field_0 + 4));
        apsme_switch_key_indication
                  ((apsme_switch_key_ind_t *)((int)&pl.field_1.nwk.src_addr.field_0 + 6));
      }
    }
    goto _L0;
  }
  if (bVar1 < 10) {
    if (bVar1 == 7) {
      iVar8 = aps_secur_is_tc();
      if (iVar8 == 0) {
        stack0xffffffbc = 0;
        ind.src_address.field_0.u64._0_4_ = 0;
        ind.src_address.field_0.u64._4_4_ = 0;
        ind._8_4_ = 0;
        iVar8 = zmsg_get_offset(msg);
        uVar2 = iVar8 + 1U & 0xffff;
        iVar8 = zmsg_get_length(msg);
        if (((7 < (int)(iVar8 - uVar2)) &&
            (iVar8 = nwk_address_extended_by_short
                               ((aps_hdr->addr_info).src_addr,
                                (undefined1 *)((int)&pl.field_1 + 0x1f)), iVar8 == 0)) &&
           (iVar8 = aps_secur_is_addr_tc((undefined1 *)((int)&pl.field_1 + 0x1f)), iVar8 != 0)) {
          zmsg_read_bytes(msg,uVar2,8,(undefined1 *)((int)&ind.src_address.field_0 + 4));
          apsme_remove_device_indication
                    ((apsme_remove_device_ind_t *)((int)&pl.field_1.nwk.src_addr.field_0 + 6));
        }
      }
    }
    else if (bVar1 == 8) {
      iVar8 = aps_secur_is_tc();
      if (iVar8 != 0) {
        stack0xffffffbc = 0;
        ind.src_address.field_0.u64._0_4_ = 0;
        ind.src_address.field_0.u64._4_4_ = 0;
        ind._8_4_ = 0;
        ind.field_2._3_4_ = ind.field_2._3_4_ & 0xffffff00;
        sVar4 = zmsg_get_offset(msg);
        iVar8 = nwk_address_extended_by_short
                          ((aps_hdr->addr_info).src_addr,(undefined1 *)((int)&pl.field_1 + 0x1f));
        if (iVar8 == 0) {
          sVar5 = zmsg_read_bytes(msg,sVar4 + 1,1,(undefined1 *)((int)&ind.src_address.field_0 + 4))
          ;
          if ((ind.src_address.field_0.u64._4_4_ & 0xff) == 2) {
            iVar8 = zmsg_get_length(msg);
            if (7 < (int)(iVar8 - (uint)(ushort)(sVar4 + 1 + sVar5))) {
              zmsg_read_bytes(msg,8,(undefined1 *)((int)&ind.src_address.field_0 + 5));
              goto _L0;
            }
          }
          else if ((ind.src_address.field_0.u64._4_4_ & 0xff) == 4) {
_L0:
            apsme_request_key_indication
                      ((apsme_request_key_ind_t *)((int)&pl.field_1.nwk.src_addr.field_0 + 6));
          }
        }
      }
    }
    else if (bVar1 == 5) {
      iVar8 = aps_secur_is_tc();
      if (iVar8 == 0) {
        iVar8 = core_globals_get();
        if ((*(char *)(iVar8 + 0x9ba) < '\0') && ((msg->flags & 4) == 0)) goto _L0;
        memset((void *)((int)&pl.field_1 + 0x1f),0,0x23);
        sVar4 = zmsg_get_offset(msg);
        sVar5 = zmsg_read_bytes(msg,sVar4 + 1,1,(undefined1 *)((int)&ind.src_address.field_0 + 4));
        uVar2 = ind.src_address.field_0.u64._4_4_ & 0xff;
        iVar8 = 0x19;
        if ((uVar2 != 3) && ((iVar8 = 0x20, uVar2 != 4 && (iVar8 = 0x21, uVar2 != 1)))) {
          iVar8 = 0;
        }
        iVar9 = zmsg_read_bytes(msg,sVar4 + 1 + sVar5,iVar8,hash + 0xd);
        if (iVar8 == iVar9) {
          memcpy((void *)((int)&ind.src_address.field_0 + 5),hash + 0xd,0x10);
          uVar2 = ind.src_address.field_0.u64._4_4_ & 0xff;
          if (uVar2 == 3) {
            iVar8 = nwk_address_extended_by_short
                              ((aps_hdr->addr_info).src_addr,(undefined1 *)((int)&pl.field_1 + 0x1f)
                              );
            if ((iVar8 == 0) &&
               (iVar8 = aps_secur_is_addr_tc((undefined1 *)((int)&pl.field_1 + 0x1f)), iVar8 != 0))
            {
              ind.field_2.initiator_hash[0xc] = (uint8_t)((uint)pl.field_1._11_4_ >> 8);
              ind.field_2.initiator_hash[0xd] = (uint8_t)((uint)pl.field_1._11_4_ >> 0x10);
              ind.field_2.initiator_hash[0xf] = pl.field_1.nwk.key[0xf];
              ind.field_2.initiator_hash[0xe] = (uint8_t)((uint)pl.field_1._11_4_ >> 0x18);
_L0:
              zmsg_free(msg);
              apsme_transport_key_indication
                        ((apsme_transport_key_ind_t *)((int)&pl.field_1.nwk.src_addr.field_0 + 6));
              return;
            }
          }
          else if (uVar2 == 4) {
            _ref = pl.field_1._23_4_ << 0x18 | (uint)pl.field_1._19_4_ >> 8;
            hash._0_4_ = (uint)(byte)pl.field_1._27_1_ << 0x18 | (uint)pl.field_1._23_4_ >> 8;
            iVar8 = aps_secur_is_addr_tc(&ref);
            if (iVar8 != 0) {
              puVar7 = (uint *)nwk_get_extended_address();
              if (((pl.field_1._15_4_ << 0x18 | (uint)pl.field_1._11_4_ >> 8) == *puVar7) &&
                 ((pl.field_1._19_4_ << 0x18 | (uint)pl.field_1._15_4_ >> 8) == puVar7[1])) {
                register0x0000203c = _ref;
                ind.src_address.field_0.u8[0] = hash[0];
                ind.src_address.field_0.u8[1] = hash[1];
                ind.src_address.field_0.u8[2] = hash[2];
                ind.src_address.field_0.u8[3] = hash[3];
                goto _L0;
              }
            }
          }
          else if (uVar2 == 1) {
            uVar2 = pl.field_1._15_4_ << 0x10 | (uint)pl.field_1._11_4_ >> 0x10;
            uVar13 = pl.field_1._19_4_ << 0x10 | (uint)pl.field_1._15_4_ >> 0x10;
            _ref = pl.field_1._23_4_ << 0x10 | (uint)pl.field_1._19_4_ >> 0x10;
            hash._0_4_ = (uint)(ushort)pl.field_1._27_2_ << 0x10 | (uint)pl.field_1._23_4_ >> 0x10;
            iVar8 = aps_secur_is_centralized();
            if (iVar8 == 0) {
              if ((_ref != 0xffffffff) || (hash._0_4_ != -1)) goto _L0;
            }
            else {
              _Var3 = ezb_eui64_is_invalid((ezb_eui64_s *)&ref);
              if (CONCAT31(extraout_var,_Var3) != 0) goto _L0;
            }
            puVar7 = (uint *)nwk_get_extended_address();
            if ((uVar2 != *puVar7) || (uVar13 != puVar7[1])) {
              if ((aps_hdr->addr_info).dst_addr < 0xfff8) {
                return;
              }
              if (uVar2 != 0 || uVar13 != 0) {
                return;
              }
            }
            aps_secur_set_tc_address(&ref);
            if ((_ref != 0xffffffff) || (hash._0_4_ != -1)) {
              iVar8 = nwk_address_update(&ref,0,&puStack_7c);
              if (iVar8 != 0) goto _L0;
              nwk_address_lock_ref((uint)puStack_7c & 0xffff);
              iVar8 = nwk_is_device_zr();
              if ((iVar8 != 0) && ((aps_hdr->addr_info).src_addr != 0)) {
                nwk_route_table_add_rev_route(0,0);
              }
            }
            if ((msg->flags & 4) != 0) {
              zmsg_get_footer(msg,&puStack_7c,4);
              iVar8 = aps_secur_is_centralized();
              if (iVar8 == 0) {
                aps_secur_delete_key_pair(puStack_7c);
              }
              else {
                *puStack_7c = (char)_ref;
                puStack_7c[1] = (char)((uint)_ref >> 8);
                puStack_7c[3] = (char)((uint)_ref >> 0x18);
                puStack_7c[4] = (uint8_t)hash._0_4_;
                puStack_7c[5] = SUB41(hash._0_4_,1);
                puStack_7c[2] = (char)((uint)_ref >> 0x10);
                puStack_7c[6] = SUB41(hash._0_4_,2);
                puStack_7c[7] = SUB41(hash._0_4_,3);
              }
            }
            stack0xffffffbc = _ref;
            ind.field_2.initiator_hash[0xc] = pl.field_1.nwk.key[0xc];
            ind.src_address.field_0._0_1_ = hash[0];
            ind.src_address.field_0._1_1_ = hash[1];
            ind.src_address.field_0._2_1_ = hash[2];
            ind.src_address.field_0._3_1_ = hash[3];
            goto _L0;
          }
          goto _L0;
        }
      }
    }
    else {
      if (bVar1 != 6) goto _L0;
      iVar8 = aps_secur_is_tc();
      if (iVar8 != 0) {
        memset((void *)((int)&pl.field_1 + 0x1f),0,0x18);
        iVar8 = zmsg_get_offset(msg);
        iVar9 = zmsg_get_length(msg);
        uVar2 = iVar8 + 1U & 0xffff;
        if ((10 < (int)(iVar9 - uVar2)) &&
           (iVar8 = nwk_address_extended_by_short
                              ((aps_hdr->addr_info).src_addr,(undefined1 *)((int)&pl.field_1 + 0x1f)
                              ), iVar8 == 0)) {
          iVar8 = zmsg_read_bytes(msg,uVar2,8,(undefined1 *)((int)&ind.src_address.field_0 + 4));
          uVar2 = uVar2 + iVar8 & 0xffff;
          iVar8 = zmsg_read_bytes(msg,uVar2,2,(undefined1 *)((int)&ind.field_2 + 3));
          zmsg_read_bytes(msg,uVar2 + iVar8 & 0xffff,1,(undefined1 *)((int)&ind.field_2 + 5));
          eVar12 = (aps_hdr->addr_info).src_addr;
          iVar8 = nwk_neighbor_table_get_by_short(eVar12);
          if (iVar8 == 0) {
            iVar8 = nwk_route_table_find(eVar12,0);
            if (iVar8 != 0) {
              eVar12 = *(ezb_shortaddr_t *)(iVar8 + 2);
              goto _L287;
            }
          }
          else {
_L287:
            nwk_route_table_add_rev_route(ind.field_2._3_4_ & 0xffff,eVar12,0);
          }
          apsme_update_device_indication
                    ((apsme_update_device_ind_t *)((int)&pl.field_1.nwk.src_addr.field_0 + 6));
        }
      }
    }
_L0:
    if (msg == (zmsg_t *)0x0) {
      return;
    }
_L0:
    zmsg_free(msg);
    return;
  }
  if (bVar1 == 0x10) {
    if (((aps_hdr->addr_info).dst_addr < 0xfff8) && (iVar8 = aps_secur_is_tc(), iVar8 == 0)) {
      stack0xffffffbc = 0;
      ind.src_address.field_0.u64._0_4_ = 0;
      ind.src_address.field_0.u64._4_4_ = 0;
      ind._8_4_ = 0;
      ind.field_2._3_4_ = 0;
      iVar8 = zmsg_get_offset(msg);
      iVar9 = nwk_address_extended_by_short
                        ((aps_hdr->addr_info).src_addr,(undefined1 *)((int)&pl.field_1 + 0x1f));
      if (iVar9 == 0) {
        uVar2 = iVar8 + 1U & 0xffff;
        iVar8 = zmsg_get_length(msg);
        if (9 < (int)(iVar8 - uVar2)) {
          iVar8 = zmsg_read_bytes(msg,uVar2,1,(undefined1 *)((int)&ind.src_address.field_0 + 5));
          uVar2 = uVar2 + iVar8 & 0xffff;
          iVar8 = zmsg_read_bytes(msg,uVar2,1,(undefined1 *)((int)&ind.src_address.field_0 + 4));
          zmsg_read_bytes(msg,uVar2 + iVar8 & 0xffff,8,hash + 0xc);
          piVar11 = (int *)nwk_get_extended_address();
          if ((((hash._12_4_ == *piVar11) && (pl._0_4_ == piVar11[1])) &&
              ((ind.src_address.field_0.u64._4_4_ & 0xff) == 4)) &&
             ((iVar8 = aps_secur_is_addr_tc((undefined1 *)((int)&pl.field_1 + 0x1f)), iVar8 != 0 &&
              (iVar8 = aps_secur_get_key_pair_by_addr((undefined1 *)((int)&pl.field_1 + 0x1f)),
              iVar8 != 0)))) {
            if ((ind.src_address.field_0.u8[5] == '\0') && ((*(ushort *)(iVar8 + 0x34) & 6) == 2)) {
              aps_secur_key_pair_set_verified();
            }
            apsme_confirm_key_indication
                      ((apsme_confirm_key_ind_t *)((int)&pl.field_1.nwk.src_addr.field_0 + 6));
          }
        }
      }
    }
    goto _L0;
  }
  if (0x10 < bVar1) {
    if ((byte)(bVar1 - 0x11) < 2) {
      uVar6 = aps_frame_cmd_str(bVar1);
      log_write(2,"aps_commands.c","APS %s Command not supported",uVar6);
      return;
    }
_L0:
    if (msg == (zmsg_t *)0x0) {
      return;
    }
    zmsg_free(msg);
    return;
  }
  if (bVar1 == 0xe) {
    iVar8 = aps_secur_is_tc();
    if (iVar8 == 0) {
      iVar8 = zmsg_get_offset(msg);
      iVar9 = zmsg_get_length(msg);
      uVar2 = iVar8 + 1U & 0xffff;
      if (((7 < (int)(iVar9 - uVar2)) &&
          (iVar8 = nwk_address_extended_by_short((aps_hdr->addr_info).src_addr,hash + 0xc),
          iVar8 == 0)) && (iVar8 = aps_secur_is_addr_tc(hash + 0xc), iVar8 != 0)) {
        stack0xffffffbc = 0;
        ind.src_address.field_0.u64._0_4_ = 0;
        zmsg_read_bytes(msg,uVar2,8,(undefined1 *)((int)&pl.field_1 + 0x1f));
        _Var3 = ezb_eui64_is_invalid((ezb_eui64_s *)((int)&pl.field_1.nwk.src_addr.field_0 + 6));
        if (CONCAT31(extraout_var_00,_Var3) == 0) {
          zmsg_remove_header(msg,0xb);
          eVar10 = aps_relay_cmd(msg,(ezb_extaddr_t *)((int)&pl.field_1.nwk.src_addr.field_0 + 6));
          if (eVar10 == 0) {
            return;
          }
        }
      }
    }
    goto _L0;
  }
  if (bVar1 != 0xf) goto _L0;
  iVar8 = 0x12;
  if ((aps_hdr->addr_info).dst_addr < 0xfff8) {
    memset((void *)((int)&pl.field_1 + 0x1f),0,0x19);
    iVar8 = zmsg_get_offset(msg);
    iVar9 = zmsg_get_length(msg);
    uVar2 = iVar8 + 1U & 0xffff;
    iVar8 = 0x10;
    if ((int)(iVar9 - uVar2) < 0x19) goto _L0;
    iVar8 = zmsg_read_bytes(msg,uVar2,1,(undefined1 *)((int)&ind.src_address.field_0 + 4));
    uVar2 = uVar2 + iVar8 & 0xffff;
    iVar8 = zmsg_read_bytes(msg,uVar2,8,(undefined1 *)((int)&pl.field_1 + 0x1f));
    if ((ind.src_address.field_0.u64._4_4_ & 0xff) == 3) {
      iVar8 = aps_secur_is_tc();
      if (iVar8 == 0) {
        iVar8 = aps_secur_is_addr_tc((undefined1 *)((int)&pl.field_1 + 0x1f));
        pl.field_1.nwk.key[4] = 0xaa;
        if (iVar8 == 0) goto _L0;
      }
_L0:
      pl.field_1.nwk.key[4] = 0xa3;
_L0:
      iVar8 = 0;
      if (msg == (zmsg_t *)0x0) goto _L0;
    }
    else {
      if ((ind.src_address.field_0.u64._4_4_ & 0xff) == 4) {
        iVar9 = aps_secur_is_tc();
        if (iVar9 == 0) goto _L0;
        iVar9 = aps_secur_get_key_pair_by_addr((undefined1 *)((int)&pl.field_1 + 0x1f));
        if ((iVar9 != 0) && (((*(ushort *)(iVar9 + 0x34) & 6) - 2) * 0x10000 >> 0x12 == 0)) {
          aps_secur_key_pair_get_hash(&ref);
          iVar8 = zmsg_compare_bytes(msg,uVar2 + iVar8 & 0xffff,&ref,0x10);
          if (iVar8 != 0) {
            if ((*(ushort *)(iVar9 + 0x34) & 6) == 2) {
              aps_secur_key_pair_set_verified(iVar9);
            }
            apsme_verify_key_indication
                      ((apsme_verify_key_ind_t *)((int)&pl.field_1.nwk.src_addr.field_0 + 6));
            pl.field_1.nwk.key[4] = '\0';
            goto _L0;
          }
        }
        pl.field_1.nwk.key[4] = 0xad;
        goto _L0;
      }
      pl.field_1.nwk.key[4] = 0xaa;
      if (msg == (zmsg_t *)0x0) goto _L0;
      iVar8 = 0;
      pl.field_1.nwk.key[4] = 0xaa;
    }
  }
  else {
_L0:
    pl.field_1.nwk.key[4] = '\0';
    if (msg == (zmsg_t *)0x0) {
      return;
    }
  }
  zmsg_free(msg);
  if (iVar8 != 0) {
    return;
  }
_L0:
  hash[0xc] = pl.field_1._31_1_;
  hash[0xd] = pl.field_1._32_1_;
  hash[0xe] = uStack_42;
  hash[0xf] = uStack_41;
  pl.field_1._5_2_ = 0;
  pl.field_1._7_2_ = 0;
  pl.field_1._9_2_ = 0;
  pl.field_1._11_4_ = (uint)(ushort)pl.field_1._13_2_ << 0x10;
  pl._0_4_ = ind.src_address.field_0.u64._0_4_;
  pl.field_1.nwk.key[3] = ind.src_address.field_0.u8[4];
  apsme_confirm_key_request((apsme_confirm_key_req_t *)(hash + 0xc));
  return;
}

