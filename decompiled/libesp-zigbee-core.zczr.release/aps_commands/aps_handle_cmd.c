/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> aps_commands.o -> aps_handle_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_handle_cmd(short *param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  short sVar3;
  short sVar4;
  undefined4 uVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  undefined1 *puStack_7c;
  uint uStack_78;
  uint uStack_74;
  undefined4 uStack_68;
  uint uStack_64;
  undefined1 uStack_60;
  undefined1 uStack_5f;
  undefined2 uStack_5e;
  undefined2 uStack_5c;
  undefined2 uStack_5a;
  undefined4 uStack_58;
  uint uStack_54;
  undefined4 uStack_50;
  uint uStack_4c;
  ushort uStack_48;
  uint uStack_44;
  uint uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined1 uStack_2b;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined1 uStack_25;
  undefined1 uStack_24;
  undefined1 uStack_23;
  byte bStack_22;
  
  if ((*(byte *)(param_1 + 6) & 0xc) == 0xc) goto _L0;
  bVar1 = *(byte *)(param_1 + 7);
  if (bVar1 == 9) {
    iVar7 = aps_secur_is_tc();
    if (iVar7 == 0) {
      uStack_44 = 0;
      uStack_40 = 0;
      uStack_3c = uStack_3c & 0xffffff00;
      sVar3 = zmsg_get_offset(param_2);
      iVar7 = nwk_address_extended_by_short(*param_1,&uStack_68);
      if ((iVar7 == 0) && (iVar7 = aps_secur_is_addr_tc(&uStack_68), iVar7 != 0)) {
        zmsg_read_u8(param_2,sVar3 + 1,&uStack_3c);
        apsme_switch_key_indication(&uStack_44);
      }
    }
    goto _L0;
  }
  if (bVar1 < 10) {
    if (bVar1 == 7) {
      iVar7 = aps_secur_is_tc();
      if (iVar7 == 0) {
        if ((*(ushort *)(param_2 + 0x16) & 4) != 0) {
          uStack_44 = 0;
          uStack_40 = 0;
          uStack_3c = 0;
          uStack_38 = 0;
          iVar7 = zmsg_get_offset(param_2);
          uVar2 = iVar7 + 1U & 0xffff;
          iVar7 = zmsg_get_length(param_2);
          if (((7 < (int)(iVar7 - uVar2)) &&
              (iVar7 = nwk_address_extended_by_short(*param_1,&uStack_44), iVar7 == 0)) &&
             (iVar7 = aps_secur_is_addr_tc(&uStack_44), iVar7 != 0)) {
            zmsg_read_bytes(param_2,uVar2,8,&uStack_3c);
            apsme_remove_device_indication(&uStack_44);
          }
        }
        goto _L0;
      }
    }
    else if (bVar1 == 8) {
      iVar7 = aps_secur_is_tc();
      if (iVar7 != 0) {
        if ((*(ushort *)(param_2 + 0x16) & 4) != 0) {
          uStack_44 = 0;
          uStack_40 = 0;
          uStack_3c = 0;
          uStack_38 = 0;
          uStack_34 = uStack_34 & 0xffffff00;
          sVar3 = zmsg_get_offset(param_2);
          iVar7 = nwk_address_extended_by_short(*param_1,&uStack_44);
          if (iVar7 == 0) {
            sVar4 = zmsg_read_u8(param_2,sVar3 + 1,&uStack_3c);
            if ((uStack_3c & 0xff) == 2) {
              iVar7 = zmsg_get_length(param_2);
              if ((int)(iVar7 - (uint)(ushort)(sVar3 + 1 + sVar4)) < 8) goto _L0;
              zmsg_read_bytes(param_2,8,(int)&uStack_3c + 1);
            }
            else if ((uStack_3c & 0xff) != 4) goto _L0;
            apsme_request_key_indication(&uStack_44);
          }
        }
        goto _L0;
      }
    }
    else if (bVar1 == 5) {
      iVar7 = aps_secur_is_tc();
      if (iVar7 == 0) {
        iVar7 = core_globals_get();
        if ((*(char *)(iVar7 + 0x9ba) < '\0') && ((*(ushort *)(param_2 + 0x16) & 4) == 0)) goto _L0;
        memset(&uStack_44,0,0x23);
        sVar3 = zmsg_get_offset(param_2);
        sVar4 = zmsg_read_u8(param_2,sVar3 + 1,&uStack_3c);
        uVar2 = uStack_3c & 0xff;
        iVar7 = 0x19;
        if ((uVar2 != 3) && ((iVar7 = 0x20, uVar2 != 4 && (iVar7 = 0x21, uVar2 != 1)))) {
          iVar7 = 0;
        }
        iVar8 = zmsg_read_bytes(param_2,sVar3 + 1 + sVar4,iVar7,(int)&uStack_68 + 1);
        if (iVar7 == iVar8) {
          bStack_22 = bStack_22 & 0xfe | (byte)(*(ushort *)(param_2 + 0x16) >> 2) & 1;
          memcpy((void *)((int)&uStack_3c + 1),(void *)((int)&uStack_68 + 1),0x10);
          uVar2 = uStack_3c & 0xff;
          if (uVar2 == 3) {
            iVar7 = nwk_address_extended_by_short(*param_1,&uStack_44);
            if ((iVar7 == 0) && (iVar7 = aps_secur_is_addr_tc(&uStack_44), iVar7 != 0)) {
              uStack_2b = (undefined1)(uStack_58 >> 8);
              uStack_2a = (undefined1)(uStack_58 >> 0x10);
              uStack_28 = (undefined1)uStack_54;
              uStack_26 = (undefined1)(uStack_54 >> 0x10);
              uStack_24 = (undefined1)(undefined2)uStack_50;
              uStack_29 = (undefined1)(uStack_58 >> 0x18);
              uStack_27 = (undefined1)(uStack_54 >> 8);
              uStack_23 = uStack_50._1_1_ != '\0';
              uStack_25 = (undefined1)(uStack_54 >> 0x18);
_L0:
              zmsg_free(param_2);
              apsme_transport_key_indication(&uStack_44);
              return;
            }
          }
          else if (uVar2 == 4) {
            uStack_78 = uStack_4c << 0x18 | uStack_50 >> 8;
            uStack_74 = (uint)(byte)uStack_48 << 0x18 | uStack_4c >> 8;
            iVar7 = aps_secur_is_addr_tc(&uStack_78);
            if (iVar7 != 0) {
              puVar6 = (uint *)nwk_get_extended_address();
              if (((uStack_54 << 0x18 | uStack_58 >> 8) == *puVar6) &&
                 ((uStack_50 << 0x18 | uStack_54 >> 8) == puVar6[1])) {
                uStack_44 = uStack_78;
                uStack_40 = uStack_74;
                goto _L0;
              }
            }
          }
          else if (uVar2 == 1) {
            uVar2 = uStack_54 << 0x10 | uStack_58 >> 0x10;
            uVar10 = uStack_50 << 0x10 | uStack_54 >> 0x10;
            uStack_78 = uStack_4c << 0x10 | uStack_50 >> 0x10;
            uStack_74 = (uint)uStack_48 << 0x10 | uStack_4c >> 0x10;
            iVar7 = aps_secur_is_centralized();
            if (iVar7 == 0) {
              if ((uStack_78 != 0xffffffff) || (uStack_74 != 0xffffffff)) goto _L0;
            }
            else {
              iVar7 = ezb_eui64_is_invalid(&uStack_78);
              if (iVar7 != 0) goto _L0;
            }
            puVar6 = (uint *)nwk_get_extended_address();
            if ((uVar2 != *puVar6) || (uVar10 != puVar6[1])) {
              if ((ushort)param_1[1] < 0xfff8) {
                return;
              }
              if (uVar2 != 0 || uVar10 != 0) {
                return;
              }
            }
            aps_secur_set_tc_address(&uStack_78);
            if ((uStack_78 != 0xffffffff) || (uStack_74 != 0xffffffff)) {
              iVar7 = nwk_address_update(&uStack_78,0,&puStack_7c);
              if (iVar7 != 0) goto _L0;
              iVar7 = nwk_is_device_zr();
              if ((iVar7 != 0) && (*param_1 != 0)) {
                nwk_route_table_add_rev_route(0,0);
              }
            }
            if ((*(ushort *)(param_2 + 0x16) & 4) != 0) {
              zmsg_get_footer(param_2,&puStack_7c,4);
              iVar7 = aps_secur_is_centralized();
              if (iVar7 == 0) {
                aps_secur_delete_key_pair(puStack_7c);
              }
              else {
                *puStack_7c = (char)uStack_78;
                puStack_7c[1] = (char)(uStack_78 >> 8);
                puStack_7c[3] = (char)(uStack_78 >> 0x18);
                puStack_7c[4] = (char)uStack_74;
                puStack_7c[5] = (char)(uStack_74 >> 8);
                puStack_7c[2] = (char)(uStack_78 >> 0x10);
                puStack_7c[6] = (char)(uStack_74 >> 0x10);
                puStack_7c[7] = (char)(uStack_74 >> 0x18);
              }
            }
            uStack_44 = uStack_78;
            uStack_2b = uStack_58._1_1_;
            uStack_40 = uStack_74;
            goto _L0;
          }
          goto _L0;
        }
      }
    }
    else {
      if (bVar1 != 6) goto _L0;
      iVar7 = aps_secur_is_tc();
      if (iVar7 != 0) {
        memset(&uStack_44,0,0x18);
        iVar7 = zmsg_get_offset(param_2);
        iVar8 = zmsg_get_length(param_2);
        uVar2 = iVar7 + 1U & 0xffff;
        if ((10 < (int)(iVar8 - uVar2)) &&
           (iVar7 = nwk_address_extended_by_short(*param_1,&uStack_44), iVar7 == 0)) {
          if (((*(ushort *)(param_2 + 0x16) & 4) == 0) &&
             ((iVar7 = aps_secur_get_key_pair_by_addr(&uStack_44), iVar7 != 0 &&
              ((*(ushort *)(iVar7 + 0x34) & 1) == 0)))) goto _L0;
          iVar7 = zmsg_read_bytes(param_2,uVar2,8,&uStack_3c);
          uVar2 = uVar2 + iVar7 & 0xffff;
          iVar7 = zmsg_read_bytes(param_2,uVar2,2,&uStack_34);
          zmsg_read_u8(param_2,uVar2 + iVar7 & 0xffff,(int)&uStack_34 + 2);
          sVar3 = *param_1;
          iVar7 = nwk_neighbor_table_get_by_short(sVar3);
          if (iVar7 == 0) {
            iVar7 = nwk_route_table_find(sVar3,0);
            if (iVar7 != 0) {
              sVar3 = *(short *)(iVar7 + 2);
              goto _L306;
            }
          }
          else {
_L306:
            nwk_route_table_add_rev_route(uStack_34 & 0xffff,sVar3,0);
          }
          apsme_update_device_indication(&uStack_44);
          goto _L0;
        }
      }
    }
_L0:
    if (param_2 == 0) {
      return;
    }
_L0:
    zmsg_free(param_2);
    return;
  }
  if (bVar1 == 0x10) {
    if (((ushort)param_1[1] < 0xfff8) && (iVar7 = aps_secur_is_tc(), iVar7 == 0)) {
      if ((*(ushort *)(param_2 + 0x16) & 4) != 0) {
        uStack_44 = 0;
        uStack_40 = 0;
        uStack_3c = 0;
        uStack_38 = 0;
        uStack_34 = 0;
        iVar7 = zmsg_get_offset(param_2);
        iVar8 = nwk_address_extended_by_short(*param_1,&uStack_44);
        if (iVar8 == 0) {
          uVar2 = iVar7 + 1U & 0xffff;
          iVar7 = zmsg_get_length(param_2);
          if (9 < (int)(iVar7 - uVar2)) {
            iVar7 = zmsg_read_u8(param_2,uVar2,(int)&uStack_3c + 1);
            uVar2 = uVar2 + iVar7 & 0xffff;
            iVar7 = zmsg_read_u8(param_2,uVar2,&uStack_3c);
            zmsg_read_bytes(param_2,uVar2 + iVar7 & 0xffff,8,&uStack_68);
            piVar9 = (int *)nwk_get_extended_address();
            if ((((uStack_68 == *piVar9) && (uStack_64 == piVar9[1])) && ((uStack_3c & 0xff) == 4))
               && ((iVar7 = aps_secur_is_addr_tc(&uStack_44), iVar7 != 0 &&
                   (iVar7 = aps_secur_get_key_pair_by_addr(&uStack_44), iVar7 != 0)))) {
              if ((uStack_3c._1_1_ == '\0') && ((*(ushort *)(iVar7 + 0x34) & 6) == 2)) {
                aps_secur_key_pair_set_verified();
              }
              apsme_confirm_key_indication(&uStack_44);
            }
          }
        }
      }
      goto _L0;
    }
    goto _L0;
  }
  if (0x10 < bVar1) {
    if ((byte)(bVar1 - 0x11) < 2) {
      uVar5 = aps_frame_cmd_str(bVar1);
      log_write(2,"aps_commands.c","APS %s Command not supported",uVar5);
      return;
    }
_L0:
    if (param_2 == 0) {
      return;
    }
    zmsg_free(param_2);
    return;
  }
  if (bVar1 == 0xe) {
    iVar7 = aps_secur_is_tc();
    if (iVar7 == 0) {
      iVar7 = zmsg_get_offset(param_2);
      iVar8 = zmsg_get_length(param_2);
      uVar2 = iVar7 + 1U & 0xffff;
      if (((7 < (int)(iVar8 - uVar2)) &&
          (iVar7 = nwk_address_extended_by_short(*param_1,&uStack_68), iVar7 == 0)) &&
         (iVar7 = aps_secur_is_addr_tc(&uStack_68), iVar7 != 0)) {
        uStack_44 = 0;
        uStack_40 = 0;
        zmsg_read_bytes(param_2,uVar2,8,&uStack_44);
        iVar7 = ezb_eui64_is_invalid(&uStack_44);
        if (iVar7 == 0) {
          zmsg_remove_header(param_2,0xb);
          iVar7 = aps_relay_cmd(param_2,&uStack_44);
          if (iVar7 == 0) {
            return;
          }
        }
      }
    }
    goto _L0;
  }
  if (bVar1 != 0xf) goto _L0;
  iVar7 = 0x12;
  if ((ushort)param_1[1] < 0xfff8) {
    memset(&uStack_44,0,0x19);
    iVar7 = zmsg_get_offset(param_2);
    iVar8 = zmsg_get_length(param_2);
    uVar2 = iVar7 + 1U & 0xffff;
    iVar7 = 0x10;
    if ((int)(iVar8 - uVar2) < 0x19) goto _L0;
    iVar7 = zmsg_read_u8(param_2,uVar2,&uStack_3c);
    uVar2 = uVar2 + iVar7 & 0xffff;
    iVar7 = zmsg_read_bytes(param_2,uVar2,8,&uStack_44);
    if ((uStack_3c & 0xff) == 3) {
      iVar7 = aps_secur_is_tc();
      if (iVar7 == 0) {
        iVar7 = aps_secur_is_addr_tc(&uStack_44);
        uStack_5f = 0xaa;
        if (iVar7 == 0) goto _L0;
      }
_L0:
      uStack_5f = 0xa3;
_L0:
      iVar7 = 0;
      if (param_2 == 0) goto _L0;
    }
    else {
      if ((uStack_3c & 0xff) == 4) {
        iVar8 = aps_secur_is_tc();
        if (iVar8 == 0) goto _L0;
        iVar8 = aps_secur_get_key_pair_by_addr(&uStack_44);
        if ((iVar8 != 0) && (((*(ushort *)(iVar8 + 0x34) & 6) - 2) * 0x10000 >> 0x12 == 0)) {
          aps_secur_key_pair_get_hash(&uStack_78);
          iVar7 = zmsg_compare_bytes(param_2,uVar2 + iVar7 & 0xffff,&uStack_78,0x10);
          if (iVar7 != 0) {
            if ((*(ushort *)(iVar8 + 0x34) & 6) == 2) {
              aps_secur_key_pair_set_verified(iVar8);
            }
            apsme_verify_key_indication(&uStack_44);
            uStack_5f = 0;
            goto _L0;
          }
        }
        uStack_5f = 0xad;
        goto _L0;
      }
      uStack_5f = 0xaa;
      if (param_2 == 0) goto _L0;
      iVar7 = 0;
      uStack_5f = 0xaa;
    }
  }
  else {
_L0:
    uStack_5f = 0;
    if (param_2 == 0) {
      return;
    }
  }
  zmsg_free(param_2);
  if (iVar7 != 0) {
    return;
  }
_L0:
  uStack_68 = uStack_44;
  uStack_5e = 0;
  uStack_5c = 0;
  uStack_5a = 0;
  uStack_58 = (uint)uStack_58._2_2_ << 0x10;
  uStack_64 = uStack_40;
  uStack_60 = (undefined1)uStack_3c;
  apsme_confirm_key_request(&uStack_68);
  return;
}

